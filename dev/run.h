#pragma once

#include "Player.h"
#include "Factories.h"
#include "Units.h"
#include <string>
#include <vector>

void run();
void do_turn(Player* player, AbstractFactory& factory, Player* opp);
Unit idtounit(int unitid);
void print_units(Player* player);
void print_info(Player* player);
void print_all_units();
void create_unit_from_user(Player* player, AbstractFactory& factory);
std::string idtoname(int unitid);