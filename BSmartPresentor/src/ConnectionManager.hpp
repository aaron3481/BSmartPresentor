/*
 * ConnectionManager.hpp
 *
 *  Created on: Feb 21, 2013
 *      Author: aaron
 */

#ifndef CONNECTIONMANAGER_HPP_
#define CONNECTIONMANAGER_HPP_

#include "LocalDeviceInfo.hpp"
#include "DeviceListing.hpp"
#include "Record.hpp"
#include <bb/cascades/GroupDataModel>
#include <QObject>
#include <QThread>

class IncomeDataThread: public QThread {
Q_OBJECT

Q_SIGNALS:
	void recordHeader(int slideCount, const QString fileName);
	void slide(int slideNum, int animCount, const QString note);
	void received();
public:
	IncomeDataThread(QObject *parent = 0);
	void init(int fd);
	int getFD();
	bool active();
	void run();
	void close();
private:
	int fd;
};
///////////////////////////////////////////////////////////////

class ConnectionManager: public QObject {

Q_OBJECT

	Q_PROPERTY(LocalDeviceInfo *localDevInfo READ localDevInfo CONSTANT)
	Q_PROPERTY(DeviceListing *deviceListing READ deviceListing CONSTANT)
	Q_PROPERTY(Record *record READ record CONSTANT)
	Q_PROPERTY(bb::cascades::DataModel* s_model READ model CONSTANT)
	Q_PROPERTY(QString s_currentSlide READ getSCurrentSlide CONSTANT)
	Q_PROPERTY(QString s_currentNote READ getSCurrentNote CONSTANT)

Q_SIGNALS:
	void BTDeviceSignal(int event, const QString &btAddr,
			const QString &eventData);

public Q_SLOTS:
	void handleBTDeviceEvent(int event, const QString &btAddr,
			const QString &eventData);
	void recordHeader(int slideCount, const QString fileName);
	void slide(int slideNum, int animCount, const QString note);
	void connectToServer(QString addr);
	void sendCommand(QString command);
	void received();
	QString getFileName();
	void gotoPageUpdate(QString page);
	void clickUpdate(QString click);

public:
	ConnectionManager(QObject *parent);

	virtual ~ConnectionManager();

	void emitBTDeviceSignal(int event, const QString &btAddr,
			const QString &eventData);

private:
	LocalDeviceInfo *localDevInfo() const;
	DeviceListing *deviceListing() const;
	Record *record() const;
	bb::cascades::DataModel* model() const;
	QString getSCurrentSlide() const;
	QString getSCurrentNote() const;

	LocalDeviceInfo *m_localDevInfo;
	DeviceListing *m_deviceListing;
	bb::cascades::GroupDataModel* s_model;
	Record *m_record;
	IncomeDataThread m_IDT;
	bool is_connected;
	QString s_currentSlide;
	QString s_currentNote;
	int currentSlide;
	int clicked;
	int animCount;

};

#endif /* CONNECTIONMANAGER_HPP_ */
