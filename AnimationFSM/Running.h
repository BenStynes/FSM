#ifndef RUNNING_H
#define RUNNING_H

#include <State.h>

class Running : public State
{
public:
	Running() {};
	~Running() {};
	void idle(PlayerFSM* a);
	void climbing(PlayerFSM* a);
	void running(PlayerFSM* a);
	void jumping(PlayerFSM* a);
};
#endif