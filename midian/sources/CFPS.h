#ifndef _CFPS_H_
#define _CFPS_H_

#include <SDL.h>

class CTimeControl {

private:
	Uint32     OldTime;
	Uint32     LastTime;

	int NumFrames;
	int     Frames;

public:
	CTimeControl();

	void    OnLoop();

public:
	int     GetFPS();
};

#endif
