import bb.cascades 1.0

Page {
    id: switchSlide
    Container {
        ListView {
            dataModel: _cm.s_model
            listItemComponents: [
                ListItemComponent {
                    type: "listItem"
                    StandardListItem {
                        title: ListItemData.slideNum
                        //description: ListItemData.deviceAddress
                        //status: ListItemData.deviceClass
                    }
                }
            ]
            onTriggered: {
                var selectedItem = dataModel.data(indexPath);
                _cm.sendCommand("65525-" + selectedItem.slideNum)
                _cm.gotoPageUpdate(selectedItem.slideNum);
                slide.text = _cm.s_currentSlide
                note.text = _cm.s_currentNote
                navigationPane.pop();
                //_cm.connectToServer(selectedItem.deviceAddress)
                //navigationPane.push(mainControl.createObject())
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
}
