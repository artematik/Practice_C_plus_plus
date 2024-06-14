#pragma once
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"
class ApexPredator : public Object
{
	friend Cell;
public:
	ApexPredator(Cell* c);
	~ApexPredator() {};
	void copulation();
	void live();
	void move();
	bool eat();
	char getSymbol() override;
};
