#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Sven.h"
#include "Invoker.h"
#include "Riki.h"
#include "Techies.h"
#include "Monster.h"

using namespace std;

unsigned short TestChoice(unsigned short maxChoice, const string& errorText) {
    unsigned short choice;
    cin >> choice;
    while (choice < 1 || choice > maxChoice) {
        cout << errorText << endl;
        cin >> choice;
    }
    return choice;
}

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    cout << "=== Экспедиция в руинах Доты 2 ===\n";
    cout << "Рошан пробудился и охраняет древние артефакты!\n\n";

    cout << "Выбери героя:\n";
    cout << "1 - Sven (воин ближнего боя)\n";
    cout << "2 - Invoker (маг)\n";
    cout << "3 - Riki (невидимый ассасин)\n";
    cout << "4 - Techies (безумный изобретатель)\n";

    int hero = TestChoice(4, "Выбери число от 1 до 4");

    Npc* player = nullptr;

    if (hero == 1)
        player = new Sven();
    else if (hero == 2)
        player = new Invoker();
    else if (hero == 3)
        player = new Riki();
    else
        player = new Techies();

    player->Create();
    player->ShowInfo();

    cout << "\n--- Бой с Рошаном начинается! ---\n";

    Monster enemy;
    enemy.ShowInfo();

    while (player->IsAlive() && enemy.IsAlive()) {
        cout << "\nТвой ход:\n";
        cout << "1 - Обычная атака\n";
        cout << "2 - Использовать способность\n";

        int act;
        cin >> act;

        if (act == 1) {
            cout << "\nАтака!\n";
            player->Attack(enemy);
            enemy.ShowInfo();
        }
        else if (act == 2) {
            cout << "\nИспользуется способность!\n";
            player->UseAbility(enemy);
            enemy.ShowInfo();
        }
        else {
            cout << "Неверный выбор! Пропускаешь ход.\n";
        }

        if (enemy.IsAlive()) {
            cout << "\nХод Рошана:\n";
            enemy.Attack(*player);
            player->ShowInfo();
        }

        if (!enemy.IsAlive()) {
            cout << "\n=== ПОБЕДА! ===\n";
            cout << "Рошан повержен! Ты получаешь Аегис Бессмертия!\n";
            break;
        }

        if (!player->IsAlive()) {
            cout << "\n=== ПОРАЖЕНИЕ ===\n";
            cout << "Твой герой пал в бою...\n";
            break;
        }
    }

    if (player->IsAlive()) {
        cout << "\nТы победил в этом сражении!\n";
        cout << "Но экспедиция только начинается...\n";
    }

    cout << "\n=== Конец игры ===\n";

    delete player;
    return 0;
}