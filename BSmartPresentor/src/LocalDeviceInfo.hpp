/*
 * LocalDeviceInfo.hpp
 *
 *  Created on: Feb 21, 2013
 *      Author: aaron
 */

#ifndef LOCALDEVICEINFO_HPP_
#define LOCALDEVICEINFO_HPP_

#include <QObject>

class LocalDeviceInfo : public QObject{
	Q_OBJECT

public:
	LocalDeviceInfo(QObject *parent);

};


#endif /* LOCALDEVICEINFO_HPP_ */
