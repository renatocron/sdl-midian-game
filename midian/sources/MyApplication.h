#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "CEvent.h"
#include "WordState.h"

#include "CFPS.h"
#include "StatisticsHandler.h"
#include "Writter.h"

#include "WordStateMenu.h"
#include "WordStateCutter.h"


class MyApplication: public CEvent {
private:
	bool Running;

private:
	int m_screen_height, m_screen_width, m_surface_flags;
	SDL_Surface* m_sdl_screen;

	WordState *m_selected_word_state;
	
public:
	MyApplication();
	int OnExecute();

	bool OnLoad();

	bool OnLoadSDL();
	bool OnLoadOpenGL();

	void OnUnload();

	void OnEvent(SDL_Event* Event);

	void OnLoop();
	void OnRender(float pInterpolation);

	void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);

	void OnResize(int w,int h);

	void OnExit();

	void inline SetWordState(WordState* pNewState){m_selected_word_state = pNewState;};
	inline WordState* GeCurtWordState(){return m_selected_word_state;};

public:
	CTimeControl FPSControl;
	CTimeControl LPSControl;
	StatisticsHandler* statisticHandle;
	Writter* writter;

	WordStateMenu *m_menu_word_state;

	WordStateCutter * m_cut_game_state;

	int inline get_width(){return m_screen_width;};
	int inline get_height(){return m_screen_height;};

};


#endif