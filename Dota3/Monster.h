#pragma once
#include <string>

class Npc;

class Monster {
private:
    int health;
    int damage;
    std::string name;

public:
    Monster();
    void ShowInfo();
    void Attack(Npc& player);
    void TakeDamage(int dmg);
    bool IsAlive() const;
};