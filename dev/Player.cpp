#include "Player.h"
#include "Units.h"
#include "Factories.h"

Player::Player(AbstractFactory& factory, std::string _name) {
		createUnit(Tower().id, factory);
		gold = 10;
		name = _name;
}

void Player::createUnit(int unitid, AbstractFactory& factory) {
		units.push_back(factory.createUnit(unitid));
}

Unit& idtounit(int unitid, Unit& res) {
    Archer archer;
    Swordsmen swordsmen;
    Cavalery cavalery;
    Tower tower;
    if (unitid == archer.id) {
	     res.hp = archer.hp;
	     res.dmg = archer.dmg;
	     res.price = archer.price;
	     res.takendmg = archer.takendmg;
	     res.attackdmg = archer.attackdmg;
	     res.id = archer.id;
		 //res.name = Archer().name;
	 }
    else if (unitid == swordsmen.id) {
        res.hp = swordsmen.hp;
        res.dmg = swordsmen.dmg;
		 res.price = swordsmen.price;
		 res.takendmg = swordsmen.takendmg;
		 res.attackdmg = swordsmen.attackdmg;
		 res.id = swordsmen.id;
		 //res.name = Swordsmen().name;
	 }
    else if (unitid == cavalery.id) {
        res.hp = cavalery.hp;
        res.dmg = cavalery.dmg;
        res.price = cavalery.price;
        res.takendmg = cavalery.takendmg;
        res.attackdmg = cavalery.attackdmg;
        res.id = cavalery.id;
		 //res.name = Cavalery().name;
    } else if (unitid == tower.id) {
        res.hp = tower.hp;
        res.dmg = tower.dmg;
        res.price = tower.price;
        res.takendmg = tower.takendmg;
        res.attackdmg = tower.attackdmg;
        res.id = tower.id;
		 //res.name = Tower().name;
	}
	return res;
}
