#include "run.h"


vector<int> unit_ids;
vector<command> cmd;
Print print;
Game game;

std::string Game::idtoname(int unitid) {
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

void Print::units(Player* player) {
    for (int i = 0; i < player->units.size(); i++) {
        cout << "\t"
        << "(" << i + 1 << ") "
        << game.idtoname(player->units[i].id) << " "
        << player->units[i].dmg << " "
        << player->units[i].hp << " ";
        if (not player->units[i].canAttack)
            cout << "-";
        cout << "\n";
    }
}

void Print::info(Player* player) {
    cout << "\n"
    << player->name
    << "Золото: " << (player->gold) << "\n";
    for (int i = 0; i < cmd.size(); i++)
        cout << cmd[i].name;
}

void Print::all_units() {
    Unit unit;
    for (int i = 0; i < unit_ids.size(); i++)
        if (i != 3)
            cout << "\t"
            << " (" << idtounit(i + 1, unit).id << ") "
            << game.idtoname(i + 1) << " "
            << idtounit(i + 1, unit).dmg << " "
            << idtounit(i + 1, unit).hp
            << " Стоимость: "
            << idtounit(i + 1, unit).price
            << "\n";
}


void Game::create_unit_from_user(Player* player, AbstractFactory& factory) {
    int tt;
    Unit unit;
    do {
        cout << "\tЗолото: "
        << player->gold
        << "\n";
        print.all_units();
        cout << "\t"
        << " (" << unit_ids.size() << ") "
        << "Выход\n";
        do {
            cin >> tt;
            if ((tt < 1) or (tt > unit_ids.size()))
                cout << "Неправильное число\n";
        } while ((tt < 1) or (tt > unit_ids.size()));
        if (tt >= 1 and tt <= unit_ids.size() - 1)
            if (player->gold - idtounit(tt, unit).price >= 0) {
                player->createUnit(tt, factory);
                player->gold -= idtounit(tt, unit).price;
                cout << "\n";
                print.units(player);
                cout << "\n";
            }
        else
            cout << "\tНедостаточно золота\n";
    } while (tt != unit_ids.size());
}

void Game::do_turn(Player* player, AbstractFactory& factory, Player* opp) {
    print.info(player);
    int t = 0;
    while(t != 5) {
        cin >> t;
        switch (t) {
        case 1:
            game.create_unit_from_user(player, factory);
            print.info(player);
            break;
        case 2:
            print.units(player);
            print.info(player);
            break;
        case 3:
            print.units(opp);
            print.info(player);
            break;
        case 4:
            if(player->units.size() > 1)
                game.do_attack(player, opp);
            else
                cout << "Некому атаковать\n";
            print.info(player);
            break;
        }
    }
    game.set_attack(player);
}

void Game::set_attack(Player* player) {
	for (int i = 0; i < player->units.size(); i++)
		player->units[i].canAttack = 1;
}

void Print::game_over(Player* player) {
	cout << "\nИгра окончена.\n"
		<< "Победил игрок " << player->name;
	exit(0);
}

void Game::do_attack(Player* player, Player* opp) {
	do {
		int t1;
		cout << player->name;
		print.units(player);

		cout << opp->name;
        print.units(opp);
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
			if (t2 == 1) print.game_over(player);
			else {
				player->gold += opp->units[t2 - 1].price * 2;
				opp->units.erase(opp->units.begin() + t2 - 1);
			}
		}
        print.units(opp);
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
    cmd.push_back(command(4, "(4) Атаковать юнита врага\n"));
    cmd.push_back(command(5, "(5) Закончить ход\n"));

    while (true) {
        if (turn) {
            game.do_turn(&player1, engfactory, &player2);
        }
        else {
            game.do_turn(&player2, francefactory, &player1);
        }
        turn = not turn;
        cout << '\n';
    }
}
