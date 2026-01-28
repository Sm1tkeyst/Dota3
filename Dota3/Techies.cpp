#include "Techies.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Techies::Techies() : bombCharges(3) {
    name = "Techies";
    // Теперь Npc один, обращаемся напрямую
    health = 75;  // Среднее между Invoker(70) и Riki(80)
    damage = 16;  // Среднее между Invoker(15) и Riki(18)
    abilityDamage = 42; // Среднее между Invoker(35) и Riki(50)
}

void Techies::Create() {
    std::cout << "Создан Techies - сумасшедший изобретатель!\n";
    std::cout << "Объединяет магию и скрытность с любовью к взрывчатке!\n";
}

void Techies::ShowInfo() {
    std::cout << "\n=== Techies ===\n";
    std::cout << "Здоровье: " << health << "\n";
    std::cout << "Урон: " << damage << "\n";
    std::cout << "Урон способности: " << abilityDamage << "\n";
    std::cout << "Заряды бомб: " << bombCharges << "\n";
    std::cout << "Способность: Взрывная ловушка (потребляет 1 заряд)\n";
    std::cout << "===================\n";
}

void Techies::Attack(Monster& enemy) {
    int totalDamage = damage;
    if (rand() % 100 < 30) {
        totalDamage *= 2;
        std::cout << "Критический удар с взрывным усилением! ";
    }
    enemy.TakeDamage(totalDamage);
    std::cout << name << " атакует импровизированной взрывчаткой, нанося "
        << totalDamage << " урона!\n";
}

void Techies::UseAbility(Monster& enemy) {
    if (bombCharges > 0) {
        bombCharges--;
        std::cout << name << " устанавливает ВЗРЫВНУЮ ЛОВУШКУ!\n";

        int totalDamage = abilityDamage;

        if (rand() % 100 < 25) {
            totalDamage += abilityDamage / 2;
            std::cout << "Ловушка срабатывает особенно эффективно! ";
        }

        enemy.TakeDamage(totalDamage);
        std::cout << "Нанесено " << totalDamage << " урона! ";
        std::cout << "Осталось зарядов: " << bombCharges << "\n";
    }
    else {
        std::cout << "Нет зарядов бомб! Используется обычная атака.\n";
        Attack(enemy);
    }
}

bool Techies::IsAlive() {
    return health > 0;
}

void Techies::TakeDamage(int dmg) {
    if (rand() % 100 < 25) {
        std::cout << name << " уклоняется с помощью дымовой завесы!\n";
        return;
    }

    health -= dmg;
    if (health < 0) health = 0;
    std::cout << name << " получает " << dmg << " урона. ";
    std::cout << "Осталось здоровья: " << health << "\n";
}