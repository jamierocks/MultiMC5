#pragma once

#include <QObject>
#include <QJsonObject>
#include "AuthSession.h"

enum AccountStatus {
    NotVerified,
    Verified
};

class BaseAccount : public QObject {
    Q_OBJECT

public:
    explicit BaseAccount(QObject *parent = nullptr) : QObject(parent) {};

    //! Gets the type of the BaseAccount (e.g. "mojang", or "microsoft")
    virtual QString getType() const = 0;

    //! Saves a BaseAccount to a JSON object and returns it.
    QJsonObject saveToJson() const {
        QJsonObject obj;
        obj["type"] = getType();
        return saveToJson(obj);
    }

    virtual const QString &username() const = 0;
    virtual AccountStatus accountStatus() const = 0;

protected:
    //! Saves a BaseAccount to the given JSON object and returns it.
    virtual QJsonObject saveToJson(QJsonObject) const = 0;

private:
    virtual void fillSession(AuthSessionPtr session) = 0;
};

typedef std::shared_ptr<BaseAccount> AccountPtr;
Q_DECLARE_METATYPE(AccountPtr)
