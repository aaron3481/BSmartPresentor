APP_NAME = BSmartPresentor

CONFIG += qt warn_on debug_and_release cascades

QT += declarative

simulator {
    CONFIG(release, debug|release) {
        DESTDIR = o
    }
    CONFIG(debug, debug|release) {
        DESTDIR = o-g
    }
}

include(config.pri)
