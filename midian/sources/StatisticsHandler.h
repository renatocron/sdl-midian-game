#ifndef _STATISTICS_HANDLER_H_
#define _STATISTICS_HANDLER_H_

#include "WordState.h"
#include "Render.h"

#include <string>
/************/
#include <FTGL/ftgl.h>

class StatisticsHandler {

public:
	StatisticsHandler();
	~StatisticsHandler();

	void OnRender(float pInterpolation);

};

#endif