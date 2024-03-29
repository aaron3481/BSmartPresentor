/* Copyright (c) 2012 Research In Motion Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import bb.cascades 1.0

// A sheet that shows the information about the local bluetooth device
Sheet {
    id: root

    Page {
        Container {
            topPadding: 20
            leftPadding: 20
            rightPadding: 20
            bottomPadding: 20

            Label {
                text: qsTr("Local Device Information")
                horizontalAlignment: HorizontalAlignment.Center
                textStyle {
                    base: SystemDefaults.TextStyles.TitleText
                    fontWeight: FontWeight.Bold
                    color: Color.DarkRed
                }
            }

            Container {
                bottomPadding: 20
                rightPadding: 20

                //! [0]
                LabelLabel {
                    label: qsTr("Name")
                    text: _cm.localDevInfo.name
                }
                LabelLabel {
                    label: qsTr("Address")
                    text: _cm.localDevInfo.address
                }
                //! [0]
                LabelLabel {
                    label: qsTr("Class")
                    text: _cm.localDevInfo.deviceClass
                }
                LabelLabel {
                    label: qsTr("Discoverable")
                    text: _cm.localDevInfo.discoverable
                }
                LabelLabel {
                    label: qsTr("Enabled")
                    text: _cm.localDevInfo.enabled
                }
                LabelLabel {
                    label: qsTr("Device Type")
                    text: _cm.localDevInfo.deviceType
                }
            }

            Container {
                bottomPadding: 20
                rightPadding: 20

                LabelLabel {
                    label: qsTr("API Version")
                    text: _cm.localDevInfo.apiVersion
                }
                LabelLabel {
                    label: qsTr("Master/Slave Allowed")
                    text: _cm.localDevInfo.masterSlaveAllowed
                }
                LabelLabel {
                    label: qsTr("Max Device Connections")
                    text: _cm.localDevInfo.maximumConnections
                }
                LabelLabel {
                    label: qsTr("Max L2CAP Rx MTU")
                    text: _cm.localDevInfo.maximumL2capMtu
                }
                LabelLabel {
                    label: qsTr("Max RFCOMM Rx MTU")
                    text: _cm.localDevInfo.maximumRfcommMtu
                }
            }

            Container {
                bottomPadding: 20
                rightPadding: 20

                LabelLabel {
                    label: qsTr("Incoming Inquiry Scan while Connected")
                    text: _cm.localDevInfo.incomingInquiryScan
                }
                LabelLabel {
                    label: qsTr("Incoming Page Scan while Connected")
                    text: _cm.localDevInfo.incomingPageScan
                }
                LabelLabel {
                    label: qsTr("Outgoing Inquiry Scan while Connected")
                    text: _cm.localDevInfo.outgoingInquiryScan
                }
                LabelLabel {
                    label: qsTr("Outgoing Page Scan while Connected")
                    text: _cm.localDevInfo.outgoingPageScan
                }
            }

            Divider {
            }

            Button {
                horizontalAlignment: HorizontalAlignment.Center
                text: qsTr("Close")
                onClicked: root.close()
            }
        }
    }
}
