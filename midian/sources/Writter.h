#ifndef _WRITTER_H_
#define _WRITTER_H_

#include "Render.h"

#include <iostream>
#include <string>
#include <map>
/************/
#include <FTGL/ftgl.h>

class Writter {

public:
	Writter();
	~Writter();

	void AddFont(string iname, string fontfile, int fontsize);

	void Draw(string iname, string str, float x, float y, float mangle = 0.0f);

private:
	map<string, FTFont*> m_font_list;

};

#endif