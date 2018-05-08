#ifndef REGEXPPLUGIN_H
#define REGEXPPLUGIN_H

#include <QObject>

#include "regexpinterface.h"

class RegExpPlugin : public QObject, RegExpInterface
{
    Q_OBJECT
    Q_INTERFACES(RegExpInterface)

public:
    QString regexp(const QString &message);
};

#endif // REGEXPPLUGIN_H
