#include "Sven.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Sven::Sven() {
    name = "Sven";
    health = 100;
    damage = 20;
    abilityDamage = 40;
}

void Sven::Create() {
    std::cout << "Создан Sven - благородный воин!\n";
    std::cout << "Сила и честь ведут его вперед.\n";
}

void Sven::ShowInfo() {
    std::cout << "\n=== Sven ===\n";
    std::cout << "Здоровье: " << health << "\n";
    std::cout << "Урон: " << damage << "\n";
    std::cout << "Урон способности: " << abilityDamage << "\n";
    std::cout << "Способность: Гнев Бога (оглушение + урон)\n";
    std::cout << "================\n";
}

void Sven::Attack(Monster& enemy) {
    int totalDamage = damage;
    if (rand() % 100 < 20) { 
        totalDamage *= 2;
        std::cout << "Критический удар! ";
    }
    enemy.TakeDamage(totalDamage);
    std::cout << name << " бьет мечом, нанося " << totalDamage << " урона!\n";
}

void Sven::UseAbility(Monster& enemy) {
    std::cout << name << " использует ГНЕВ БОГА!\n";
    int totalDamage = abilityDamage;

    
    if (rand() % 100 < 50) {
        std::cout << "Рошан оглушен на следующий ход! ";
    }

    enemy.TakeDamage(totalDamage);
    std::cout << "Мощный удар наносит " << totalDamage << " урона!\n";
}

bool Sven::IsAlive() {
    return health > 0;
}

void Sven::TakeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
    std::cout << name << " получает " << dmg << " урона. ";
    std::cout << "Осталось здоровья: " << health << "\n";
}
