import bb.cascades 1.0

Page {
    id: mainControl
    titleBar: TitleBar {
        id: tb
        title: "Main Control"
    }
    actions: [
        ActionItem {
            id: previous
            ActionBar.placement: ActionBarPlacement.OnBar
            title: "Previous"
            onTriggered: {
                _cm.sendCommand("65521-");
                _cm.clickUpdate("-1");
                slide.text = _cm.s_currentSlide
                note.text = _cm.s_currentNote
            }
        },
        ActionItem {
            id: next
            ActionBar.placement: ActionBarPlacement.OnBar
            title: "Next"
            onTriggered: {
                _cm.sendCommand("65520-");
                _cm.clickUpdate("1");
                slide.text = _cm.s_currentSlide
                note.text = _cm.s_currentNote
            }
        },
        ActionItem {
            id: start
            ActionBar.placement: ActionBarPlacement.OnBar
            title: "Start"
            onTriggered: {
                tb.title = _cm.getFileName()
                _cm.sendCommand("65522-");
                _cm.gotoPageUpdate("1");
                title = "Restart"
                slide.text = _cm.s_currentSlide
                note.text = _cm.s_currentNote
            }
        },
        ActionItem {
            id: go_to
            title: "Go To"
            ActionBar.placement: ActionBarPlacement.InOverflow
            onTriggered: {
                navigationPane.push(swichSlide.createObject())
            }
        },
        ActionItem {
            id: sw
            title: "Switch Window"
            ActionBar.placement: ActionBarPlacement.InOverflow
            onTriggered: {
                _cm.sendCommand("65524-");
            }
        },
        ActionItem {
            id: enter
            title: "Enter"
            ActionBar.placement: ActionBarPlacement.InOverflow
            onTriggered: {
                _cm.sendCommand("65526-");
                slide.text = _cm.s_currentSlide
                note.text = _cm.s_currentNote
            }
        },
        ActionItem {
            id: exit
            title: "Exit"
            ActionBar.placement: ActionBarPlacement.InOverflow
            onTriggered: {
                _cm.sendCommand("65523-");
                start.title = "Start"
            }
        }
    ]
    paneProperties: NavigationPaneProperties {
    }
    attachedObjects: [
        ComponentDefinition {
            id: swichSlide
            source: "SwitchSlide.qml"
        }
    ]
    Container {
        TextArea {
            //preferredHeight: maxHeight
            id: slide
            text: _cm.s_currentSlide
            bottomMargin: 0.0
            textStyle.color: Color.Blue
            editable: false
        }
        TextArea {
            id: note
            text: _cm.s_currentNote
            topMargin: 0.0
            preferredHeight: maxHeight
            editable: false
        }
    }
}
