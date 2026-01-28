#pragma once
#include "Npc.h"

class Sven : virtual public Npc {
public:
    Sven();
    void Create() override;
    void ShowInfo() override;
    void Attack(Monster& enemy) override;
    void UseAbility(Monster& enemy) override;
    bool IsAlive() override;
    void TakeDamage(int dmg) override;
};