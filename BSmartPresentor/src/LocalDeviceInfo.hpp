/*
 * LocalDeviceInfo.hpp
 *
 *  Created on: Feb 21, 2013
 *      Author: aaron
 */

#ifndef LOCALDEVICEINFO_HPP_
#define LOCALDEVICEINFO_HPP_

#include <QObject>

class LocalDeviceInfo: public QObject {
	Q_OBJECT
	Q_PROPERTY(QString name READ name NOTIFY changed)
	Q_PROPERTY(QString address READ address NOTIFY changed)
	Q_PROPERTY(QString deviceClass READ deviceClass NOTIFY changed)
	Q_PROPERTY(QString discoverable READ discoverable NOTIFY changed)
	Q_PROPERTY(QString enabled READ enabled NOTIFY changed)
	Q_PROPERTY(QString deviceType READ deviceType NOTIFY changed)
	Q_PROPERTY(QString apiVersion READ apiVersion NOTIFY changed)
	Q_PROPERTY(QString masterSlaveAllowed READ masterSlaveAllowed NOTIFY changed)
	Q_PROPERTY(QString maximumConnections READ maximumConnections NOTIFY changed)
	Q_PROPERTY(QString maximumL2capMtu READ maximumL2capMtu NOTIFY changed)
	Q_PROPERTY(QString maximumRfcommMtu READ maximumRfcommMtu NOTIFY changed)
	Q_PROPERTY(QString incomingInquiryScan READ incomingInquiryScan NOTIFY changed)
	Q_PROPERTY(QString incomingPageScan READ incomingPageScan NOTIFY changed)
	Q_PROPERTY(QString outgoingInquiryScan READ outgoingInquiryScan NOTIFY changed)
	Q_PROPERTY(QString outgoingPageScan READ outgoingPageScan NOTIFY changed)

	Q_SIGNALS:
	    // The change notification signal
	    void changed();

public:
	LocalDeviceInfo(QObject *parent);
	void update();
private:
    // The accessor methods of the properties
    QString name() const;
    QString address() const;
    QString deviceClass() const;
    QString discoverable() const;
    QString enabled() const;
    QString deviceType() const;
    QString apiVersion() const;
    QString masterSlaveAllowed() const;
    QString maximumConnections() const;
    QString maximumL2capMtu() const;
    QString maximumRfcommMtu() const;
    QString incomingInquiryScan() const;
    QString incomingPageScan() const;
    QString outgoingInquiryScan() const;
    QString outgoingPageScan() const;

    // The property values
    QString m_name;
    QString m_address;
    QString m_deviceClass;
    QString m_discoverable;
    QString m_enabled;
    QString m_deviceType;
    QString m_apiVersion;
    QString m_masterSlaveAllowed;
    QString m_maximumConnections;
    QString m_maximumL2capMtu;
    QString m_maximumRfcommMtu;
    QString m_incomingInquiryScan;
    QString m_incomingPageScan;
    QString m_outgoingInquiryScan;
    QString m_outgoingPageScan;
};

#endif /* LOCALDEVICEINFO_HPP_ */
