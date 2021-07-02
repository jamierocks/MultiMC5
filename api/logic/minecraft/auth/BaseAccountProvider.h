#pragma once

#include <QJsonObject>
#include "BaseAccount.h"

class BaseAccountProvider : public QObject {
    Q_OBJECT

public:
    //! Gets the type of the BaseAccount (e.g. "mojang", or "microsoft")
    virtual QString getType() const = 0;

    virtual AccountPtr loadFromJson(QJsonObject) = 0;
};
