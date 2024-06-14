#include "Predator.h"
Predator::Predator(Cell * c) :Object(c)
{
	this->lifetime = LTPredator;
	type = ObjType::PREDATOR;
}
void Predator::live()
{
	if (eat() != true && lifetime > 2)
		lifetime -= 2;
	else
		lifetime--;
	move();
	if (lifetime < 0.1*LTPredator)
		copulation();
}
char Predator::getSymbol()
{
	return PREDATOR_N;
}
void Predator::move()
{
	Cell * newCell = cell->FREE();
	if (newCell != nullptr)
	{
		this->getCell()->Moving();
		newCell->setObject(this);
		this->cell = newCell;
	}
}
bool Predator::eat()
{
	Pair cord = cell->Cord();
	Cell * sacrifice = cell->RADAR(1);
	if (sacrifice && !sacrifice->getObject()->is_live() && sacrifice->getObject()->getType()==ObjType::PREY && cell->CHECK())
	{
		sacrifice->getObject()->readytodie();
		sacrifice->getObject()->setLive(0);
		lifetime += 5;
		return true;
	}
	return false;
}
void Predator::copulation()
{
	Cell * newCell = cell->FREE();//есть свободная ячейка
	Cell * partner = cell->RADAR_Predators(1);//есть в соседней клетке партнёр для размножения
	Cell* danger = cell->RADAR_ApexPredators(2);
	if (newCell && partner != nullptr && danger==nullptr)
	{
	Object * child = new Predator(newCell);
	newCell->setObject(child);
	cell->getOcean()->AddStuff(child);
	}
}
