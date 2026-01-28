#pragma once
#include <string>

class Monster;

class Npc {
protected:
    std::string name;
    int health;
    int damage;
    int abilityDamage;

public:
    Npc() : name("Unknown"), health(0), damage(0), abilityDamage(0) {}
    virtual ~Npc() = default;

    virtual void Create() = 0;
    virtual void ShowInfo() = 0;
    virtual void Attack(Monster& enemy) = 0;
    virtual void UseAbility(Monster& enemy) = 0;
    virtual bool IsAlive() = 0;
    virtual void TakeDamage(int dmg) = 0;

    std::string GetName() const { return name; }
    int GetHealth() const { return health; }
    int GetDamage() const { return damage; }
    int GetAbilityDamage() const { return abilityDamage; }
};