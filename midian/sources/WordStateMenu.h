#ifndef _WORD_STATE_MENU_H_
#define _WORD_STATE_MENU_H_

#include "WordState.h"
#include "Render.h"

#include "Sprite.h"

#include <string>
/************/
#include <FTGL/ftgl.h>

class Render;

class WordStateMenu: public WordState {

	int m_cur_bar_position;
public:
	Sprite* m_skull;
	Sprite* m_skull_menu;
	Sprite* m_choose;
	Sprite* m_cut_the_photo;
	SimpleImage* m_cut_the_photo_collision;

	Sprite* m_mario;
	SimpleImage* m_mario_collision;

	Sprite* m_candy;
	SimpleImage* m_candy_collision;

	int m_selected_menu;
	
	
	float angle;

	//Render* render;

	// PointMatrixArray* m_va_left;

	//Render::SVertex2D * Vertices2;
	//int NumVertices2;

	FTFont* infoFont;
	std::string myString;
	int current_font;
public:
	Sprite* m_spr;

	WordStateMenu();
	~WordStateMenu();

	void OnLoop();
	void OnRender(float pInterpolation);

	void OnLButtonUp(int mX, int mY);
	void OnResize(int w,int h);
	void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);

};

#endif