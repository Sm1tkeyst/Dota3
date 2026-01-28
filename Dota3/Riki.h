#pragma once
#include "Npc.h"

class Riki : virtual public Npc {
public:
    Riki();
    void Create() override;
    void ShowInfo() override;
    void Attack(Monster& enemy) override;
    void UseAbility(Monster& enemy) override;
    bool IsAlive() override;
    void TakeDamage(int dmg) override;
};