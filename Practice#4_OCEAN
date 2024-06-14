#include <iostream>
#include "Ocean.h"
using namespace std;
int main()
{
	int count_prey, count_predator, count_stone, count_apexpredator,count_reef;
	cout << "WELCOME TO SIMALUTION OF OCEAN LIFE!\n\n";
	cout << "To start the simulation, you must enter the number of objects of each type!\n\n";
	cout << "Enter the amount of prey in the ocean: "; cin >> count_prey;
	cout << "Enter the amount of predators in the ocean: "; cin >> count_predator;
	cout << "Enter the amount of stones in the ocean: "; cin >> count_stone;
	cout << "Enter the amount of apexpredators in the ocean: "; cin >> count_apexpredator;
	cout << "Enter the amount of reefs in the ocean: "; cin >> count_reef;

	Ocean* oc = new Ocean;
	oc->addObjects(count_prey, ObjType::PREY);
	oc->addObjects(count_predator, ObjType::PREDATOR);
	oc->addObjects(count_stone, ObjType::STONE);
	oc->addObjects(count_apexpredator, ObjType::APEXPREDATOR);
	oc->addObjects(count_reef, ObjType::REEF);
	oc->run();
	system("pause");
	return 0;
}
