// Navigation pane project template
import bb.cascades 1.0

NavigationPane {
    id: navigationPane
    Page {
        actions: [
            ActionItem {
                title: qsTr("Search Devices")
                //imageSource: "asset:///images/device_discovery.png"
                ActionBar.placement: ActionBarPlacement.OnBar
                onTriggered: {
                    _cm.deviceListing.discover();
                }
            },
            ActionItem {
                title: qsTr("Device Info.")
                //imageSource: "asset:///images/device_discovery.png"
                ActionBar.placement: ActionBarPlacement.OnBar
                onTriggered: {
                    qsLocalDeviceInfo.open();
                    //_btController.deviceListing.discover();
                }
            }
        ]

        // page with a picture thumbnail
        Container {
            ListView {
                dataModel: _cm.deviceListing.model
                listItemComponents: [
                    ListItemComponent {
                        type: "listItem"
                        StandardListItem {
                            title: ListItemData.deviceName
                            description: ListItemData.deviceAddress
                            //image: "images/picture1.png"
                            status: ListItemData.deviceClass
                        }
                    }
                ]
                onTriggered: {
                    var selectedItem = dataModel.data(indexPath);
                    _cm.connectToServer(selectedItem.deviceAddress)
                    navigationPane.push(mainControl.createObject())
                    /*_cm.setRemoteDevice(selectedItem.deviceAddress);
                     * _cm.connectToServer()
                     * navigationPane.push(remoteDevicePage.createObject())*/
                }
                function itemType(data, indexPath) {
                    if (indexPath.length == 1) {
                        // If the index path contains a single integer, the item
                        // is a "header" type item
                        return "header";
                    } else {
                        // If the index path contains more than one integer, the
                        // item is a "listItem" type item
                        return "listItem";
                    }
                }
            }
        }
        attachedObjects: [
            LocalDeviceInfoSheet {
                id: qsLocalDeviceInfo
            },
            ComponentDefinition {
                id: mainControl
                source: "MainControl.qml"
            }
        ]
    }
    onCreationCompleted: {
        // this slot is called when declarative scene is created
        // write post creation initialization here
        console.log("NavigationPane - onCreationCompleted()");

        // enable layout to adapt to the device rotation
        // don't forget to enable screen rotation in bar-bescriptor.xml (Application->Orientation->Auto-orient)
        OrientationSupport.supportedDisplayOrientation = SupportedDisplayOrientation.All;
    }
}
