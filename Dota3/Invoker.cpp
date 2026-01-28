#include "Invoker.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Invoker::Invoker() {
    name = "Invoker";
    health = 70;
    damage = 15;
    abilityDamage = 35;
    mana = 100;
}

void Invoker::Create() {
    std::cout << "Создан Invoker - мастер магии!\n";
    std::cout << "Сила всех стихий в его распоряжении.\n";
}

void Invoker::ShowInfo() {
    std::cout << "\n=== Invoker ===\n";
    std::cout << "Здоровье: " << health << "\n";
    std::cout << "Мана: " << mana << "\n";
    std::cout << "Урон: " << damage << "\n";
    std::cout << "Урон способности: " << abilityDamage << "\n";
    std::cout << "Способность: Холодная стена (урон + замедление)\n";
    std::cout << "===================\n";
}

void Invoker::Attack(Monster& enemy) {
    int totalDamage = damage;
    enemy.TakeDamage(totalDamage);
    std::cout << name << " атакует магическим снарядом, нанося " << totalDamage << " урона!\n";
}

void Invoker::UseAbility(Monster& enemy) {
    if (mana >= 30) {
        mana -= 30;
        std::cout << name << " призывает ХОЛОДНУЮ СТЕНУ!\n";
        int totalDamage = abilityDamage;

        
        std::cout << "Рошан замедлен! Его скорость атаки снижена. ";

        enemy.TakeDamage(totalDamage);
        std::cout << "Ледяные осколки наносят " << totalDamage << " урона!\n";
        std::cout << "Осталось маны: " << mana << "\n";
    }
    else {
        std::cout << "Недостаточно маны! Используется обычная атака.\n";
        Attack(enemy);
    }
}

bool Invoker::IsAlive() {
    return health > 0;
}

void Invoker::TakeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
    std::cout << name << " получает " << dmg << " урона. ";
    std::cout << "Осталось здоровья: " << health << "\n";
}