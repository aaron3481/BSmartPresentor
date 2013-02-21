/*
 * ConnectionManager.hpp
 *
 *  Created on: Feb 21, 2013
 *      Author: aaron
 */

#ifndef CONNECTIONMANAGER_HPP_
#define CONNECTIONMANAGER_HPP_

#include <QObject>
#include "LocalDeviceInfo.hpp"

class ConnectionManager : public QObject{

	Q_OBJECT

	Q_PROPERTY(LocalDeviceInfo *localDevInfo READ localDevInfo CONSTANT)

public:
	ConnectionManager(QObject *parent);

	virtual ~ConnectionManager();

private:
	LocalDeviceInfo *localDevInfo() const;

	LocalDeviceInfo *m_localDevInfo;

};



#endif /* CONNECTIONMANAGER_HPP_ */
