#pragma once
#include "Invoker.h"
#include "Riki.h"

class Techies : public Invoker, public Riki {
private:
    int bombCharges;

public:
    Techies();
    void Create() override;
    void ShowInfo() override;
    void Attack(Monster& enemy) override;
    void UseAbility(Monster& enemy) override;
    bool IsAlive() override;
    void TakeDamage(int dmg) override;

    int GetBombCharges() const { return bombCharges; }
};