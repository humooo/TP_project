#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "Player.h"
#include "Units.h"
#include "Factories.h"

using namespace std;

class command {
public:
    int num;
    string name;
    command(int _num, string _name) {
        num = _num;
        name = _name;
    }

};

class Print {
public:
    void units(Player* );
    void info(Player* );
    void all_units();
    void game_over(Player* );
};

class Game {
public:
    void do_turn(Player* , AbstractFactory& , Player* );
    void create_unit_from_user(Player* , AbstractFactory& );
    std::string idtoname(int );
    void do_attack(Player* , Player* );
    void set_attack(Player* );
};

void run();

