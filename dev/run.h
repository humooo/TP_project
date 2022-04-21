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

void run();
void do_turn(Player* , AbstractFactory& , Player* );
Unit idtounit(int );
void print_units(Player* );
void print_info(Player* );
void print_all_units();
void create_unit_from_user(Player* , AbstractFactory& );
std::string idtoname(int );
void do_attack(Player* , Player* );
void set_attack(Player* );
void game_over(Player* );
