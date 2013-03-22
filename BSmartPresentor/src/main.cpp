// Navigation pane project template
#include "BSmartPresentor.hpp"
#include "ConnectionManager.hpp"
#include "LocalDeviceInfo.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include <QLocale>
#include <QTranslator>
#include <Qt/qdeclarativedebug.h>

using namespace bb::cascades;

Q_DECL_EXPORT int main(int argc, char **argv) {
	qmlRegisterType<ConnectionManager>();
	qmlRegisterType<LocalDeviceInfo>();
	qmlRegisterType<DeviceListing>();

	// this is where the server is started etc
	Application app(argc, argv);

	// localization support
	QTranslator translator;
	QString locale_string = QLocale().name();
	QString filename = QString("BSmartPresentor_%1").arg(locale_string);
	if (translator.load(filename, "app/native/qm")) {
		app.installTranslator(&translator);
	}

	// create the application pane object to init UI etc.
	//new BSmartPresentor(&app);

	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(&app);
	qml->setContextProperty("_cm", new ConnectionManager(&app));

	AbstractPane *root = qml->createRootObject<AbstractPane>();

	// set created root object as a scene
	app.setScene(root);

	return Application::exec();
}
