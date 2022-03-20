#pragma once

class Unit {
public:
	int getAttack() const;
	int getHealth() const;
	int getCost() const;
	int getLevel() const;
	void setAttack(const int& );
	void setHealth(const int& );
	void setMaxHealth(const int& );
	void setCost(const int&);
protected:
	bool attack;
	int max_health;
	int health;
	int cost;
	int level;
};
