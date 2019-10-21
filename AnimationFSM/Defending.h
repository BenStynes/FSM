#ifndef DEFENDING_H
#define DEFENDING_H

#include <State.h>

class Defending : public State
{
public:
	Defending() {};
	~Defending() {};
	void idle(PlayerFSM* a);
	void defending(PlayerFSM* a);
	void taunting(PlayerFSM* a);
	void attacking(PlayerFSM* a);
};

#endif
