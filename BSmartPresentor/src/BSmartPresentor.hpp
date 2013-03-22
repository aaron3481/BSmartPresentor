// Navigation pane project template
#ifndef BSmartPresentor_HPP_
#define BSmartPresentor_HPP_

#include <QObject>

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class BSmartPresentor : public QObject
{
    Q_OBJECT
public:
    BSmartPresentor(bb::cascades::Application *app);
    virtual ~BSmartPresentor() {}
};

#endif /* BSmartPresentor_HPP_ */
