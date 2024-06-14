#pragma once
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"
class Reef : public Object
{
	friend Cell;
public:
	Reef(Cell* c);
	~Reef() {};
	void live();
	char getSymbol() override;

};
