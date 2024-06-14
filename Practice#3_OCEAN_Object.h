#pragma once
#include "common.h"
#define STONE_N 'S'
#define PREY_N 'P'
#define PREDATOR_N 'X'
#define REEF_N 'R'
#define APEXPREDATOR_N 'A'
enum class ObjType { STONE, REEF, PREY, PREDATOR, APEXPREDATOR };
class Ocean;
class Cell;
class Object
{
	friend Ocean;
	friend Cell;
protected:
	int lifetime;
	bool dead;
	Cell* cell;
	ObjType type;
public:
	Object(Cell* = nullptr);
	virtual ~Object() {};
	void setLive(int lifetime);
	void setCell(Cell* cell);
	virtual void live() = 0;
	virtual char getSymbol() = 0;
	unsigned int getLive();
	Cell* getCell();
	bool is_live();
	void readytodie();
	ObjType getType();
};
