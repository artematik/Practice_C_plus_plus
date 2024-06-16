#include "ApexPredator.h"

ApexPredator::ApexPredator(Cell* c) :Object(c)
{
	this->lifetime = LTApexPredator;
	type = ObjType::APEXPREDATOR;
}
void ApexPredator::live()
{
	if (eat() != true && lifetime > 2)
		lifetime -= 2;
	else
		lifetime--;
	move();
	if (lifetime < 0.1 * LTApexPredator)
		copulation();
}
char ApexPredator::getSymbol()
{
	return APEXPREDATOR_N;
}
void ApexPredator::move()
{
	Cell* newCell = cell->FREE();
	if (newCell != nullptr)
	{
		this->getCell()->Moving();
		newCell->setObject(this);
		this->cell = newCell;
	}
}
//bool ApexPredator::eat()
//{
//	Pair cord = cell->Cord();
//
//	Cell* sacrifice = cell->RADAR(1);
//	if (sacrifice && !sacrifice->getObject()->is_live() && (sacrifice->getObject()->getType() == ObjType::PREY))
//	{
//		sacrifice->getObject()->readytodie();
//		sacrifice->getObject()->setLive(0);
//		lifetime += 5;
//		return true;
//	}
//	return false;
//}

bool ApexPredator::eat()
{
	Pair cord = cell->Cord();
	Cell* sacrifice = cell->RADAR(1);
	if (sacrifice && !sacrifice->getObject()->is_live() && sacrifice->getObject()->getType() == ObjType::PREY && cell->CHECK())
	{
		sacrifice->getObject()->readytodie();
		sacrifice->getObject()->setLive(0);
		lifetime += 5;
		return true;
	}
	return false;
}

void ApexPredator::copulation()
{
	Cell* newCell = cell->FREE();
	Cell* partner = cell->RADAR_ApexPredators(1);
	if (newCell)
	{
		Object* child = new ApexPredator(newCell);
		newCell->setObject(child);
		cell->getOcean()->AddStuff(child);
	}
}
template<>
MemoryPool<ApexPredator> PoolMix<ApexPredator>::p(200);
