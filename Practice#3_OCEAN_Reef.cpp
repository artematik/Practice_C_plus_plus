#include "Reef.h"
Reef::Reef(Cell* c) :Object(c)
{
	this->lifetime = LTReef;
	type = ObjType::REEF;
};
void Reef::live()
{
	lifetime--;
};
char Reef::getSymbol()
{
	return REEF_N;
};
