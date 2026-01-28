#include "Monster.h"
#include "Npc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Monster::Monster() {
    name = "Рошан";
    health = 150;
    damage = 25;
}

void Monster::ShowInfo() {
    std::cout << "\n=== " << name << " ===\n";
    std::cout << "Здоровье: " << health << "\n";
    std::cout << "Урон: " << damage << "\n";
    std::cout << "===================\n";
}

void Monster::Attack(Npc& player) {
    int totalDamage = damage;
    if (rand() % 100 < 20) {
        totalDamage *= 1.5;
        std::cout << name << " наносит сокрушительный удар! ";
    }
    player.TakeDamage(totalDamage);
    std::cout << name << " атакует, нанося " << totalDamage << " урона!\n";
}

void Monster::TakeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
    std::cout << name << " получает " << dmg << " урона. ";
    std::cout << "Осталось здоровья: " << health << "\n";
}

bool Monster::IsAlive() const {
    return health > 0;
}