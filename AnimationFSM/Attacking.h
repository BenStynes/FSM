#ifndef ATTACKING_H
#define ATTACKING_H

#include <State.h>

class Attacking : public State
{
public:
	Attacking() {};
	~Attacking() {};
	void idle(PlayerFSM* a);
	void defending(PlayerFSM* a);
	void taunting(PlayerFSM* a);
	void attacking(PlayerFSM* a);
};

#endif