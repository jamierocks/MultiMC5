#pragma once

#include <minecraft/auth/BaseAccountProvider.h>

class MojangAccountProvider : public BaseAccountProvider {
    Q_OBJECT

public:
    QString getType() const override { return "mojang"; }

    AccountPtr loadFromJson(QJsonObject obj) override { return MojangAccount::loadFromJson(obj); }
};
