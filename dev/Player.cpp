#include "Player.h"
#include "Units.h"
#include "Factories.h"
#include <vector>

Player::Player(AbstractFactory& factory, std::string _name) {
		createUnit(Tower().id, factory);
		gold = 10;
		name = _name;
}

void Player::createUnit(int unitid, AbstractFactory& factory) {
		units.push_back(factory.createUnit(unitid));
}

Unit idtounit(int unitid) {
	 Unit res;
	 if (unitid == Archer().id) {
		 res.hp = Archer().hp;
		 res.dmg = Archer().dmg;
		 res.price = Archer().price;
		 res.takendmg = Archer().takendmg;
		 res.attackdmg = Archer().attackdmg;
		 res.id = Archer().id;
		 //res.name = Archer().name;
	 }
	 else if (unitid == Swordsmen().id) {
		 res.hp = Swordsmen().hp;
		 res.dmg = Swordsmen().dmg;
		 res.price = Swordsmen().price;
		 res.takendmg = Swordsmen().takendmg;
		 res.attackdmg = Swordsmen().attackdmg;
		 res.id = Swordsmen().id;
		 //res.name = Swordsmen().name;
	 }
	 else if (unitid == Cavalery().id) {
		 res.hp = Cavalery().hp;
		 res.dmg = Cavalery().dmg;
		 res.price = Cavalery().price;
		 res.takendmg = Cavalery().takendmg;
		 res.attackdmg = Cavalery().attackdmg;
		 res.id = Cavalery().id;
		 //res.name = Cavalery().name;
	 }
		else if (unitid == Tower().id) {
		 res.hp = Tower().hp;
		 res.dmg = Tower().dmg;
		 res.price = Tower().price;
		 res.takendmg = Tower().takendmg;
		 res.attackdmg = Tower().attackdmg;
		 res.id = Tower().id;
		 //res.name = Tower().name;
	}

	return res;
}
