#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include "CFPS.h"

#include <sstream>
#include <string>
#include <stdio.h>

#include "MyApplication.h"

namespace Const {
	const int TICKS_PER_SECOND = 32;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 6;
	const float PI = 3.1415926535897932384626433832795f;
}

namespace Global {

	void debug(std::string str);

	const int random(const int low, const int high);
	std::string FloatToStr(const float num, const std::string format = "%.2f");
	std::string IntToStr(const int x);
	int StrToInt(const std::string& s);	 
	void trim(string& str);

}

#endif