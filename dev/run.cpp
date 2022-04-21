#include <iostream>
#include <vector>
#include "Player.h"
#include "run.h"
#include "Units.h"
#include "Factories.h"
#include <ctime>

using namespace std;

vector<int> unit_ids;
vector<command> cmd;

std::string idtoname(int unitid) {
    switch (unitid) {
    case 1:
        return "Лучник";
    case 2:
        return "Кавалерия";
    case 3:
        return "Мечники";
    case 4:
        return "Башня";
    }
    return 0;
}

void print_units(Player* player) {
    for (int i = 0; i < player->units.size(); i++) {
        cout << "\t"
        << "(" << i + 1 << ") "
        << idtoname(player->units[i].id) << " "
        << player->units[i].dmg << " "
        << player->units[i].hp << " ";
        if (not player->units[i].canAttack)
            cout << "-";
        cout << "\n";
    }
}

void print_info(Player* player) {
    cout << "\n"
    << player->name
    << "Золото: " << (player->gold) << "\n";
    for (int i = 0; i < cmd.size(); i++)
        cout << cmd[i].name;
}

void print_all_units() {
    for (int i = 0; i < unit_ids.size(); i++)
        if (i != 3)
            cout << "\t"
            << " (" << idtounit(i + 1).id << ") "
            << idtoname(i + 1) << " "
            << idtounit(i + 1).dmg << " "
            << idtounit(i + 1).hp
            << " Стоимость: "
            << idtounit(i + 1).price
            << "\n";
}

void create_unit_from_user(Player* player, AbstractFactory& factory) {
    int tt;
    do {
        cout << "\tЗолото: "
        << player->gold
        << "\n";
        print_all_units();
        cout << "\t"
        << " (" << unit_ids.size() << ") "
        << "Выход\n";
        do {
            cin >> tt;
            if ((tt < 1) or (tt > unit_ids.size()))
                cout << "Неправильное число\n";
        } while ((tt < 1) or (tt > unit_ids.size()));
        if (tt >= 1 and tt <= unit_ids.size() - 1)
            if (player->gold - idtounit(tt).price >= 0) {
                player->createUnit(tt, factory);
                player->gold -= idtounit(tt).price;
                cout << "\n";
                print_units(player);
                cout << "\n";
            }
        else
            cout << "\tНедостаточно золота\n";
    } while (tt != unit_ids.size());
}

void do_turn(Player* player, AbstractFactory& factory, Player* opp) {
    print_info(player);
    int t = 0;
    while(t != 5) {
        cin >> t;
        switch (t) {
        case 1:
            create_unit_from_user(player, factory);
            print_info(player);
            break;
        case 2:
            print_units(player);
            print_info(player);
            break;
        case 3:
            print_units(opp);
            print_info(player);
            break;
        case 4:
            if(player->units.size() > 1)
                do_attack(player, opp);
            else
                cout << "Некому атаковать\n";
            print_info(player);
            break;
        }
    }
    set_attack(player);
}

void set_attack(Player* player) {
	for (int i = 0; i < player->units.size(); i++)
		player->units[i].canAttack = 1;
}

void game_over(Player* player) {
	cout << "\nИгра окончена.\n"
		<< "Победил игрок " << player->name;
	exit(0);
}

void do_attack(Player* player, Player* opp) {
	do {
		int t1;
		cout << player->name;
		print_units(player);

		cout << opp->name;
		print_units(opp);
		cout << "\t("
			<< player->units.size() + 1 << ") Выход\n";
		bool b;
		do {
			b = false;
			cin >> t1;
			if (t1 == 1)
				cout << "Нельзя атаковать башней\n";
			else if (t1 < 2 or t1 > player->units.size() + 1)
				cout << "Неправильное число\n";

			if (t1 >= 2 and t1 <= player->units.size())
				if (player->units[t1 - 1].canAttack == 0) {
					b = true;
					cout << "Этот игрок атаковал уже на этом ходу\n";
				}
		} while (t1 < 2 or t1 > player->units.size() + 1 or b);
		if (t1 == player->units.size() + 1)
			break;

		int t2;
		if (opp->units.size() != 1) {
			do {
				cin >> t2;
				if ((t2 < 1) or (t2 > opp->units.size()))
					cout << "Неправильное число\n";
			} while ((t2 < 1) or (t2 > opp->units.size()));
		}
		else t2 = 1;
		opp->units[t2 - 1].hp -= player->units[t1 - 1].dmg;
		player->units[t1 - 1].hp -= opp->units[t2 - 1].dmg * player->units[t1 - 1].takendmg * opp->units[t2 - 1].attackdmg;
		player->units[t1 - 1].canAttack = 0;
		if (opp->units[t2 - 1].hp <= 0) {
			if (t2 == 1) game_over(player);
			else {
				player->gold += opp->units[t2 - 1].price * 2;
				opp->units.erase(opp->units.begin() + t2 - 1);
			}
		}
		print_units(opp);
	} while (1);
}

void run() {
    EngFactory engfactory;
    FranceFactory francefactory;
    Player player1 = Player(engfactory, "Игрок 1\n");
    Player player2 = Player(francefactory, "Игрок 2\n");

    srand(time(0));
    bool turn = true;
    if (rand() % 2 == 0) {
        cout << "Первым ходит игрок 1 (Англия): " << '\n';
    }

    else {
        cout << "Первым ходит игрок 2 (Франция): " << '\n';
        turn = false;
    }

    unit_ids.push_back(Archer().id);
    unit_ids.push_back(Swordsmen().id);
    unit_ids.push_back(Cavalery().id);
    unit_ids.push_back(Tower().id);

    cmd.push_back(command(1, "(1) Создать юнита\n"));
    cmd.push_back(command(2, "(2) Показать ваших юнитов\n"));
    cmd.push_back(command(3, "(3) Показать юнитов соперника\n"));
    cmd.push_back(command(4, "(4) Закончить ход\n"));

    while (true) {
        if (turn) {
            do_turn(&player1, engfactory, &player2);
        }
        else {
            do_turn(&player2, francefactory, &player1);
        }
        turn = not turn;
        cout << '\n';
    }
}
