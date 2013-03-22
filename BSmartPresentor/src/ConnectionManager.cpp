#include "ConnectionManager.hpp"
#include <QtCore>
#include <QThread>
#include <QString>
#include <btapi/btdevice.h>
#include <btapi/btspp.h>
#include <errno.h>
#include <iostream>
#include <fstream>

#define SERVER_UUID "00001101-CADF-FFDC-194D-CCAB3816FFBE"

static ConnectionManager *s_cm = 0;

void CMCallback(const int event, const char *bt_addr, const char *event_data) {
	if (s_cm) {
		s_cm->emitBTDeviceSignal(event, bt_addr, event_data);
	}
}

ConnectionManager::ConnectionManager(QObject *parent) :
		QObject(parent), m_localDevInfo(new LocalDeviceInfo(this)), m_deviceListing(
				new DeviceListing(this)), s_model(
				new bb::cascades::GroupDataModel(
						QStringList() << "slideNum" << "slideType" << "image",
						this)) {
	s_cm = this;
	connect(this, SIGNAL(BTDeviceSignal(int, QString, QString)), this,
			SLOT(handleBTDeviceEvent(int, QString, QString)));
	connect(&m_IDT, SIGNAL(recordHeader(int,QString)),
			SLOT(recordHeader(int,QString)));
	connect(&m_IDT, SIGNAL(slide(int,int,QString)),
			SLOT(slide(int,int,QString)));
	connect(&m_IDT, SIGNAL(received()), SLOT(received()));

	bt_device_init(CMCallback);
	bt_spp_init();

	m_localDevInfo->update();

	m_record = 0;
	s_model->setSortingKeys(QStringList() << "slideType");
	s_model->setGrouping(bb::cascades::ItemGrouping::ByFullValue);
	is_connected = false;
	s_currentSlide = "Slide - ";
	s_currentNote = "";
}

ConnectionManager::~ConnectionManager() {
	// De-initialize the btdevice library.
	bt_device_deinit();

	// De-initialize the library.
	bt_spp_deinit();

	s_cm = 0;
}

void ConnectionManager::connectToServer(QString addr) {
	if (!is_connected) {
		const int fd = bt_spp_open(addr.toAscii().data(), (char*) SERVER_UUID,
				false);

		if (fd >= 0) {
			m_IDT.init(fd);
			m_IDT.start();
			is_connected = true;
		} else
			std::cout << "Open SPP Fail" << std::endl;
	}
}

void ConnectionManager::sendCommand(QString command) {
	if (m_IDT.active()) {
		write(m_IDT.getFD(), command.toAscii().data(), command.size());
	}
}

void ConnectionManager::emitBTDeviceSignal(int event, const QString &btAddr,
		const QString &eventData) {
	emit BTDeviceSignal(event, btAddr, eventData);
}

void ConnectionManager::handleBTDeviceEvent(int event, const QString &btAddr,
		const QString &eventData) {
	(void) btAddr;
	(void) eventData;
	switch (event) {
	case BT_EVT_RADIO_SHUTDOWN:
	case BT_EVT_RADIO_INIT:
	case BT_EVT_ACCESS_CHANGED:
		//emit bluetoothActiveChanged();
		//emit discoverableActiveChanged();
		m_localDevInfo->update();
		break;
	default:
		//logQString("Unknown event " + QString::number(event) + "/" + btAddr);
		break;
	}
}

QString ConnectionManager::getFileName() {
	return m_record->getName();
}

bb::cascades::DataModel* ConnectionManager::model() const {
	return s_model;
}

void ConnectionManager::received() {
	/*std::cout << "Done" << std::endl;
	 m_record->printRecord();*/
	s_model->clear();
	QString last(".png");
	QDir dir;
	QString userDir = dir.currentPath();
	dir.mkpath("data/image/tempData");
	for (int i = m_record->getSlideCount(); i >= 1; i--) {
		QVariantMap map;
		map["slideNum"] = i;
		map["slideType"] = tr("Please Select a Slide");
		QString no;
		no.setNum(i);
		//std::cout<<(first+no+last).toStdString()<<std::endl;
		//map["image"] = (first+no+last);
		map["image"] = "file:///" + userDir + "/data/image/tempData/s" + no
				+ last;
		//map["image"] =
		//		"file:///accounts/1000/appdata/com.example.BSmartPresentor.testDev_rtPresentora30c4706/data/image/tempData/s1.png";
		s_model->insert(map);
	}

}

void ConnectionManager::gotoPageUpdate(QString page) {
	int pagee = page.toInt();
	QString temp = "Slide - ";
	currentSlide = pagee;
	s_currentSlide = temp + page;
	s_currentNote = m_record->getSlide(pagee - 1)->getNote();
	animCount = m_record->getSlide(pagee - 1)->getAnimCount();
	clicked = 0;
}

void ConnectionManager::clickUpdate(QString click) {
	int num = click.toInt();
	//std::cout << num << std::endl;
	if (currentSlide == 1 && clicked == 0 && num == -1) {
	} else if (currentSlide == m_record->getSlideCount() && clicked == animCount
			&& num == 1) {
	} else {
		clicked += num;
		//std::cout << clicked << std::endl;
		if (clicked == animCount) {
			//switch to next page
			if (currentSlide + 1 <= m_record->getSlideCount()) {
				QString page;
				page.setNum(currentSlide + 1);
				gotoPageUpdate(page);
			}
		} else if (clicked == -1) {
			//switch to previous page
			if (currentSlide > 1) {
				QString page;
				page.setNum(currentSlide - 1);
				gotoPageUpdate(page);
				clicked = animCount - 1;
			}
		}
	}
}

QString ConnectionManager::getSCurrentSlide() const {
	return s_currentSlide;
}

QString ConnectionManager::getSCurrentNote() const {
	return s_currentNote;
}

void ConnectionManager::recordHeader(int slideCount, QString fileName) {
	//std::cout<<"Header"<<std::endl;
	if (m_record != 0)
		delete (m_record);

	m_record = new Record(slideCount, fileName);
}

void ConnectionManager::slide(int sildeNum, int animCount, QString note) {
	//std::cout<<"Slide"<<std::endl;
	m_record->addSlide(sildeNum, animCount, note);
}

LocalDeviceInfo* ConnectionManager::localDevInfo() const {
	return m_localDevInfo;
}

DeviceListing* ConnectionManager::deviceListing() const {
	return m_deviceListing;
}

Record* ConnectionManager::record() const {
	return m_record;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
IncomeDataThread::IncomeDataThread(QObject *parent) :
		QThread(parent) {
	fd = -1;
}

void IncomeDataThread::init(int fd) {
	this->fd = fd;
}

int IncomeDataThread::getFD() {
	return fd;
}

bool IncomeDataThread::active() {
	return (fd >= 0);
}

void IncomeDataThread::close() {
	fd = -1;
}

void IncomeDataThread::run() {
	//Receiving Record data from the server.
	//std::cout << "IDT_RUN" << std::endl;
	char buff[2048];
	while (fd >= 0) {
		int temp1, readLen;
		read(fd, &temp1, 4);
		//memcpy(&temp1,buff,4);
		//std::cout << temp1 << std::endl;
		char fn[temp1 + 1];
		read(fd, fn, temp1);
		fn[temp1] = '\0';
		read(fd, &temp1, 4);
		//memcpy(&temp1,buff,4);
		emit recordHeader(temp1, QString::fromLatin1(fn));

		int slideCount = temp1;
		for (int i = 0; i < slideCount; i++) {
			int animCount;
			int noteLen;
			read(fd, &animCount, 4);
			//memcpy(&animCount,buff,4);
			read(fd, &noteLen, 4);
			if (noteLen != 0) {
				char note[noteLen + 1];
				int offset = 0;
				int remain = noteLen;
				while (remain) {
					if (remain < 2048)
						readLen = read(fd, buff, remain);
					else
						readLen = read(fd, buff, 2048);
					memcpy(note + offset, buff, readLen);
					offset += readLen;
					remain -= readLen;
				}
				note[noteLen] = '\0';
				emit slide(i, animCount, QString::fromLatin1(note));
			} else
				emit slide(i, animCount, QString::fromLatin1('\0'));
		}

		emit received();

		QDir dir;
		dir.rmpath("data/image/tempData");
		dir.mkpath("data/image/tempData");
		//dir.mkpath("app/native/assets/images/temp");
		//dir.mkpath("images/tempData");
		QString first("data/image/tempData/s");
		//QString first("app/native/assets/images/temp/s");
		QString last(".png");

		for (int i = 0; i < slideCount; i++) {
			int fileLen;
			read(fd, &fileLen, 4);
			//std::cout << fileLen << std::endl;
			//char bufk[fileLen];
			char *bufk = (char*)malloc(fileLen);
			int remain = fileLen;
			int offset = 0;

			/*readLen = read(fd,bufk,fileLen);
			std::cout<<readLen<<std::endl;
			return;*/
			QString tem("Notify");
			while (remain) {
				if (remain <= 2048)
					readLen = read(fd, buff, remain);
				else
					readLen = read(fd, buff, 2048);
				memcpy(bufk + offset, buff, readLen);
				offset += readLen;
				remain -= readLen;
				std::cout<<remain<<std::endl;
				//usleep(1);
				s_cm->sendCommand(tem);
				usleep(80000);
			}
			QByteArray ba(bufk, fileLen);
			QImage file = QImage::fromData(ba, "PNG");
			QString no;
			no.setNum(i + 1);
			file.save(first + no + last, "PNG");
			std::cout<<"Finish file: "<<i<<std::endl;
			free(bufk);


			//usleep(700000);
			//ba.clear();
		}

		/*long fileLen;
		 read(fd, &fileLen, 8);
		 std::cout << fileLen << std::endl;
		 char bufk[(int) fileLen];
		 int remain = (int) fileLen;
		 int offset = 0;
		 int count = 0;
		 while (remain) {
		 if (remain < 2048)
		 readLen = read(fd, buff, remain);
		 else
		 readLen = read(fd, buff, 2048);
		 memcpy(bufk + offset, buff, readLen);
		 offset += readLen;
		 count += readLen;
		 remain -= readLen;
		 }*/
		//std::cout << count << std::endl;
		//QDir dir;
		//std::cout<<dir.currentPath().toStdString()<<std::endl;
		//dir.mkpath("data/image/tempData");
		/*QFile textfile("data/files/text/newfile.txt");
		 textfile.open(QIODevice::WriteOnly | QIODevice::Text);
		 QTextStream out(&textfile);
		 out << "This is a text file\n";
		 textfile.close();*/

		//QFile file("data/image/tempData/s2.png");
		//QByteArray ba(bufk, (int) fileLen);
		//QImage file = QImage::fromData(ba, "PNG");
		//file.save("data/image/tempData/s2.png", "PNG");
		//file.open(QIODevice::WriteOnly);
		//QDataStream out(&file);
		//out.writeBytes(bufk,(int)fileLen);
		//out<<bufk;
		//file.save(QIODevice::WriteOnly,"PNG");
		/*ofstream outfile;
		 outfile.open("data/images/tempData/s1.png");
		 outfile.write(bufk,(int)fileLen);
		 outfile.close();*/

		/////////Read PNG file
		//Not yet implement.*/
	}
}

