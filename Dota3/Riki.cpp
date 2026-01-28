#include "Riki.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Riki::Riki() {
    name = "Riki";
    health = 80;
    damage = 18;
    abilityDamage = 50;
}

void Riki::Create() {
    std::cout << "Создан Riki - невидимый убийца!\n";
    std::cout << "Он появляется из теней, когда его меньше всего ждут.\n";
}

void Riki::ShowInfo() {
    std::cout << "\n=== Riki ===\n";
    std::cout << "Здоровье: " << health << "\n";
    std::cout << "Урон: " << damage << "\n";
    std::cout << "Урон способности: " << abilityDamage << "\n";
    std::cout << "Способность: Удар в спину (высокий шанс крита)\n";
    std::cout << "================\n";
}

void Riki::Attack(Monster& enemy) {
    int totalDamage = damage;
    
    if (rand() % 100 < 30) {
        totalDamage *= 2;
        std::cout << "Критический удар из тени! ";
    }
    enemy.TakeDamage(totalDamage);
    std::cout << name << " наносит удар, нанося " << totalDamage << " урона!\n";
}

void Riki::UseAbility(Monster& enemy) {
    std::cout << name << " использует УДАР В СПИНУ!\n";

    
    if (rand() % 100 < 80) {
        int totalDamage = abilityDamage * 2; 
        enemy.TakeDamage(totalDamage);
        std::cout << "Смертельный удар из тени! Нанесено " << totalDamage << " урона!\n";
    }
    else {
        int totalDamage = abilityDamage;
        enemy.TakeDamage(totalDamage);
        std::cout << "Нанесено " << totalDamage << " урона.\n";
    }
}

bool Riki::IsAlive() {
    return health > 0;
}

void Riki::TakeDamage(int dmg) {
    
    if (rand() % 100 < 25) {
        std::cout << name << " уворачивается от атаки!\n";
        return;
    }

    health -= dmg;
    if (health < 0) health = 0;
    std::cout << name << " получает " << dmg << " урона. ";
    std::cout << "Осталось здоровья: " << health << "\n";
}