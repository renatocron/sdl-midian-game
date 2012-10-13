#ifndef _APPL_H_
#define _APPL_H_

#include <string>
#include "MyApplication.h"

class Appl {
private:
	MyApplication* m_appl;

public:
	inline static Appl* Instance(){
		if (!m_pInstance) m_pInstance = new Appl;
		return m_pInstance;
	}

   void setAppl(MyApplication* app);
   inline MyApplication* getAppl(){return m_appl;};
   
private: 
   Appl(){};  // Private so that it can  not be called
   Appl(Appl const&){};             // copy constructor is private
   Appl& operator=(Appl const&){};  // assignment operator is private
   static Appl* m_pInstance;
};

#endif