#pragma once

#include "Units.h"
#include "Factories.h"
#include <vector>
#include <string>

class Player {
public:
	std::vector<Unit> units;
	int gold;
	std::string name;
	Player(AbstractFactory& factory, std::string _name);
	void createUnit(int unitid, AbstractFactory& factory);
};

Unit& idtounit(int , Unit&);
