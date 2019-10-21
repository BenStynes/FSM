#include "Attacking.h"
#include <Defending.h>
#include <Taunting.h>
#include <Idle.h>
void Attacking::idle(PlayerFSM* a)
{
	std::cout << "Attacking -> idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Attacking::defending(PlayerFSM* a)
{
	std::cout << "Attacking -> Defending" << std::endl;
	a->setCurrent(new Defending());
	delete this;
}

void Attacking::taunting(PlayerFSM* a)
{
	std::cout << "Attacking -> Taunting" << std::endl;
	a->setCurrent(new Taunting());
	delete this;
}

void Attacking::attacking(PlayerFSM* a)
{
	std::cout << "Attacking -> Attacking" << std::endl;
	a->setCurrent(new Attacking());
	delete this;
}
