#pragma once

class Unit {
public:
	int hp = 0;
	int dmg = 0;
	int takendmg = 1;
	int attackdmg = 1;
	int price = 0;
	int id = 0;
	int canAttack = 1;
};

class Archer : public Unit {
public:
	int hp = 4;
	int dmg = 3;
	int takendmg = 0;
	int attackdmg = 0;
	int price = 3;
	int id = 1;
};

class Cavalery : public Unit {
public:
	int hp = 7;
	int dmg = 4;
	int price = 5;
	int id = 2;
};

class Swordsmen : public Unit {
public:
	int hp = 5;
	int dmg = 6;
	int price = 5;
	int id = 3;
};

class Tower : public Unit {
public:
	int hp = 50;
	int id = 4;
};
