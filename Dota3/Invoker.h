#pragma once
#include "Npc.h"

class Invoker : virtual public Npc {
private:
    int mana;
public:
    Invoker();
    void Create() override;
    void ShowInfo() override;
    void Attack(Monster& enemy) override;
    void UseAbility(Monster& enemy) override;
    bool IsAlive() override;
    void TakeDamage(int dmg) override;
};