#include "global.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>



#pragma warning(disable : 4996)

void Global::debug(std::string str)
{
//#ifdef _DEBUG
#if 1
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	char buffer [80];
	
	struct _timeb timebuffer;
	char *timeline;

	_ftime( &timebuffer );
	timeline = ctime( & ( timebuffer.time ) );

	strftime (buffer,80,"%H:%M:%S.",timeinfo);

	std::cout << buffer << Global::IntToStr(timebuffer.millitm) << " " << str << std::endl << std::flush;

#endif
}

const int Global::random(const int low, const int high)
{ 
	return low + int( rand() % ((high+1) - low)); 
}

std::string Global::FloatToStr(const float num, std::string format)
{
	char* speed = new char[15];
	
	std::sprintf (speed, format.c_str(), num );
	return (std::string)speed;
}

std::string Global::IntToStr(const int x){
	std::ostringstream o;
	o << x;
	return o.str();
}

int Global::StrToInt(const std::string& s){
	return std::atoi(s.c_str());
}

void Global::trim(string& str)
{
  string::size_type pos = str.find_last_not_of(' ');
  if(pos != string::npos) {
    str.erase(pos + 1);
    pos = str.find_first_not_of(' ');
    if(pos != string::npos) str.erase(0, pos);
  }
  else str.erase(str.begin(), str.end());
}