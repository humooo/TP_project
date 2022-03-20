#include "Unit.h"

int Unit::getAttack() const {
	return attack;
}

int Unit::getHealth() const {
	return health;
}

int Unit::getCost() const {
	return cost;
}

int Unit::getLevel() const {
	return level;
}

void Unit::setAttack(const int& _attack) {
	attack = _attack;
}

void Unit::setHealth(const int& _health) {
	health = _health;
}

void Unit::setMaxHealth(const int& _health) {
	max_health = _health;
}

void Unit::setCost(const int& _cost) {
	cost = _cost;
}
