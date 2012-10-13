#ifndef _WORD_STATE_CUTTER_H_
#define _WORD_STATE_CUTTER_H_

#include "WordState.h"
#include "Render.h"

#include "Sprite.h"
#include "VertexSprite.h"
#include <vector>
#include <string>

class Render;

class TargetEntity {
public:
	float x, y, w, h, life, points;
	bool in_ain;

	TargetEntity();
	void setWidthHeight(float w, float h);
};

class WordStateCutter: public WordState {
private:

	Sprite* m_blood;
	VertexSprite* m_bloods;

	int numteste;
	int m_r_y;
	int m_r_x;

	float end_viewpoint_x, end_viewpoint_y, start_viewpoint_x, start_viewpoint_y;
	
	float ammo, points, show_ammo;

	vector<TargetEntity*> m_targets;

public:

	WordStateCutter();
	~WordStateCutter();

	void OnLoop();
	void OnRender(float pInterpolation);
	
	void OnLButtonUp(int mX, int mY);
	void OnRButtonUp(int mX, int mY);
	void OnRButtonDown(int mX, int mY);

};

#endif
