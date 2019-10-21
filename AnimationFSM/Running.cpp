#include <Idle.h>
#include <Jumping.h>
#include <Running.h>
#include <Climbing.h>

void Running::idle(PlayerFSM* a)
{
	std::cout << "Running -> idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}

void Running::climbing(PlayerFSM* a)
{
	std::cout << "Running -> Climbing" << std::endl;
	a->setCurrent(new Climbing());
	delete this;
}

void Running::running(PlayerFSM* a)
{
	std::cout << "Running -> Running" << std::endl;
	a->setCurrent(new Running());
	delete this;
}

void Running::jumping(PlayerFSM* a)
{
	std::cout << "Running -> Jumping" << std::endl;
	a->setCurrent(new Jumping());
	delete this;
}
