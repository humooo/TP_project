#include "Factories.h"
#include "Units.h"
#include "Player.h"

Unit EngFactory::createUnit(int unitid) {
    Unit res;
    if (unitid == Swordsmen().id) {
        res = idtounit(Swordsmen().id, res);
        res.dmg = 7;
        return res;
    } else {
        return idtounit(unitid, res);
    }
}

Unit FranceFactory::createUnit(int unitid) {
    Unit res;
    if (unitid == Archer().id) {
        res = idtounit(Archer().id, res);
        res.dmg = 5;
        return res;
    } else {
        return idtounit(unitid, res);
    }
}
