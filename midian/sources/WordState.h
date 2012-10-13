#ifndef _WORD_STATE_H_
#define _WORD_STATE_H_

#include <SDL.h>
#include <iostream>

#include "CEvent.h"
#include "Render.h"

#define __GAME__() Appl::Instance()->getAppl()

class WordState : public CEvent {
protected: 
	int last_mouse_x, last_mouse_y;
	Render* render;

public:
	WordState(){render = Render::Instance();};
	
	inline void SetLastMousePosition(int lX, int lY){
		last_mouse_x = lX;
		last_mouse_y = lY;
	}
	virtual void OnLoop() = 0;
	virtual void OnRender(float pInterpolation) = 0;

	inline int getLastMouseX(){return last_mouse_x;};
	inline int getLastMouseY(){return last_mouse_y;};
};

#endif