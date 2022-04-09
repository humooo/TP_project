#pragma once

#include "Units.h"

class AbstractFactory {
public:
	virtual ~AbstractFactory(){};
	virtual Unit createUnit(int unitid)=0;
};

class EngFactory : public AbstractFactory {
public:
	Unit createUnit(int unitid);
};

class FranceFactory : public AbstractFactory {
public:
	Unit createUnit(int unitid);
};
