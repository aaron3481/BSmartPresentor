/*
 * DeviceListing.hpp
 *
 *  Created on: Feb 22, 2013
 *      Author: aaron
 */

#ifndef DEVICELISTING_HPP_
#define DEVICELISTING_HPP_
#include <bb/cascades/GroupDataModel>

#include <QObject>

/**
 * @short A class that encapsulates the listing of paired and remote bluetooth devices.
 */
//! [0]
class DeviceListing : public QObject
{
    Q_OBJECT

    // Provides the discovered bluetooth devices as data model
    Q_PROPERTY(bb::cascades::DataModel* model READ model CONSTANT)

public:
    // Creates a new DeviceListing object
    DeviceListing(QObject *parent);

public Q_SLOTS:
    // Updates the model property with the available devices
    void update();

    // Updates the model property with the available devices but runs a discovery first
    void discover();

private:
    // The accessor method of the property
    bb::cascades::DataModel* model() const;

    // The property value
    bb::cascades::GroupDataModel* m_model;
};
//! [0]



#endif /* DEVICELISTING_HPP_ */
