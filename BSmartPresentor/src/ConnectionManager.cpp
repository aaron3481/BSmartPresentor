/*
 * ConnectionManager.cpp
 *
 *  Created on: Feb 21, 2013
 *      Author: aaron
 */
#include "ConnectionManager.hpp"

#include <QtCore>

ConnectionManager::ConnectionManager(QObject *parent)
	: QObject(parent)
	, m_localDevInfo(new LocalDeviceInfo(this))
{

}

ConnectionManager::~ConnectionManager(){

}

LocalDeviceInfo* ConnectionManager::localDevInfo() const{
	return m_localDevInfo;
}


