#ifndef _WORD_STATE_CANDY_H_
#define _WORD_STATE_CANDY_H_

#include "WordState.h"
#include "Render.h"

#include "Sprite.h"
#include "VertexSprite.h"
#include <vector>
#include <string>

class Render;

class TGameItem {
public:
	float pos_x, pos_y, my_w, my_h;
	float color_r, color_g, color_b;
	int item_x, item_y;


	TGameItem();
	void setWidthHeight(float w, float h);
	void setColor(float r, float g, float b);

};

class TItemBox {
public:
	float pos_x, pos_y, my_w, my_h;
		
	TItemBox();
	
	vector<TGameItem*> m_items;
};

class WordStateCandy: public WordState {
private:

	TItemBox* m_box;
	
	float item_size;
	float points, show_points;

public:

	WordStateCandy();
	~WordStateCandy();

	void OnLoop();
	void OnRender(float pInterpolation);
	
	void OnLButtonUp(int mX, int mY);
	void OnRButtonUp(int mX, int mY);
	void OnRButtonDown(int mX, int mY);

};

#endif
