#include "Factories.h"
#include "Units.h"
#include "Player.h"

Unit EngFactory::createUnit(int unitid) {
		if (unitid == Swordsmen().id) {
			Unit res;
			res = idtounit(Swordsmen().id);
			res.dmg = 7;
			return res;
		} else {
			return idtounit(unitid);
		}
	}

Unit FranceFactory::createUnit(int unitid) {
		if (unitid == Archer().id) {
			Unit res;
			res = idtounit(Archer().id);
			res.dmg = 5;
		return res;
		} else {
			return idtounit(unitid);
		}
	}
