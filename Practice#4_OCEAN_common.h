#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <time.h>
#include <iterator>
#include <algorithm>
#include  <string>

typedef size_t coord_t;

struct Pair
{
	int x;
	int y;
};

const int LTPrey = 10;
const int LTPredator = 10;
const int LTStone = 30;
const int LTApexPredator = 10;
const int LTReef = 30;

//размеры поля
const size_t N = 20;
const size_t M = 40;
