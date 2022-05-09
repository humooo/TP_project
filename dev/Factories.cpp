#include "Factories.h"
#include "Units.h"
#include "Player.h"

Unit EngFactory::createUnit(int unitid) {
    Unit res;
    Swordsmen swordsmen;
    if (unitid == swordsmen.id) {
        res = idtounit(swordsmen.id, res);
        res.dmg = 7;
        return res;
    }
    return idtounit(unitid, res);
}

Unit FranceFactory::createUnit(int unitid) {
    Unit res;
    Archer archer;
    if (unitid == archer.id) {
        res = idtounit(archer.id, res);
        res.dmg = 5;
        return res;
    }
    return idtounit(unitid, res);
}
