/*
 * DeviceListing.cpp
 *
 *  Created on: Feb 22, 2013
 *      Author: aaron
 */
#include "DeviceListing.hpp"

#include <bb/system/SystemDialog>

#include <btapi/btdevice.h>
#include <btapi/btspp.h>

//! [0]
DeviceListing::DeviceListing(QObject *parent)
    : QObject(parent)
    , m_model(new bb::cascades::GroupDataModel(QStringList() << "deviceName" << "deviceAddress" << "deviceClass" << "deviceType", this))
{
    m_model->setSortingKeys(QStringList() << "deviceType");
    m_model->setGrouping(bb::cascades::ItemGrouping::ByFullValue);
}
//! [0]

//! [1]
void DeviceListing::update()
{
    m_model->clear();

    bt_remote_device_t **remote_device_array;
    bt_remote_device_t *next_remote_device = 0;

    // Retrieve and show all paired devices.
    remote_device_array = bt_disc_retrieve_devices(BT_DISCOVERY_PREKNOWN, 0);
    if (remote_device_array) {
        for (int i = 0; (next_remote_device = remote_device_array[i]); ++i) {
            QVariantMap map;
            char buffer[128];
            const int bufferSize = sizeof(buffer);

            bt_rdev_get_friendly_name(next_remote_device, buffer, bufferSize);
            map["deviceName"] = QString::fromLatin1(buffer);
            bt_rdev_get_address(next_remote_device, buffer);
            map["deviceAddress"] = QString::fromLatin1(buffer);
            map["deviceClass"] = QString::number(bt_rdev_get_device_class(next_remote_device, BT_COD_DEVICECLASS));
            map["deviceType"] = tr("Bluetooth Devices  Paired");
            m_model->insert(map);
        }

        bt_rdev_free_array(remote_device_array);
    }
}
//! [1]

//! [2]
void DeviceListing::discover()
{
    bb::system::SystemDialog dialog;
    dialog.setTitle(tr("Wait..."));
    dialog.setBody(tr("Searching for Bluetooth devices..."));
    dialog.confirmButton()->setEnabled(false);
    dialog.show();


    bt_disc_start_inquiry(BT_INQUIRY_GIAC);
    delay(5);
    bt_disc_cancel_inquiry();

    dialog.cancel();

    update();

    // Retrieve and show all discovered devices.
    bt_remote_device_t *next_remote_device = 0;

    bt_remote_device_t **remote_device_array = bt_disc_retrieve_devices(BT_DISCOVERY_CACHED, 0);
    if (remote_device_array) {
        for (int i = 0; (next_remote_device = remote_device_array[i]); ++i) {
            QVariantMap map;
            char buffer[128];
            const int bufferSize = sizeof(buffer);

            bt_rdev_get_friendly_name(next_remote_device, buffer, bufferSize);
            map["deviceName"] = QString::fromLatin1(buffer);
            bt_rdev_get_address(next_remote_device, buffer);
            map["deviceAddress"] = QString::fromLatin1(buffer);
            map["deviceClass"] = QString::number(bt_rdev_get_device_class(next_remote_device, BT_COD_DEVICECLASS));
            map["deviceType"] = tr("Bluetooth Devices Nearby");
            m_model->insert(map);
        }

        bt_rdev_free_array(remote_device_array);
    }
}
//! [2]

bb::cascades::DataModel* DeviceListing::model() const
{
    return m_model;
}




