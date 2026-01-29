#pragma once
#include <string>

class Creature; 

class Npc {
protected:
    std::string name;
    int health;
    int damage;
    int abilityDamage;

public:
    Npc(const std::string& name, int health, int damage, int abilityDamage)
        : name(name), health(health), damage(damage), abilityDamage(abilityDamage) {}
    
    virtual ~Npc() = default;
    
    virtual void ShowInfo() const = 0;
    virtual void Attack(Creature& enemy) = 0;
    virtual void UseAbility(Creature& enemy) = 0;
    
    bool IsAlive() const { return health > 0; }
    void TakeDamage(int dmg) { health -= dmg; if(health < 0) health = 0; }
    
    // Геттеры
    std::string GetName() const { return name; }
    int GetHealth() const { return health; }
    int GetDamage() const { return damage; }
    int GetAbilityDamage() const { return abilityDamage; }
};
