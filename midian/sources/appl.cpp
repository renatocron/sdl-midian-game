#include "appl.h"

#include <iostream>
using namespace std;

// Global static pointer used to ensure a single instance of the class.
Appl* Appl::m_pInstance = NULL;  

/** This function is called to create an instance of the class. 
    Calling the constructor publicly is not allowed. The constructor 
    is private and is only called by this Instance function.
*/
 
void Appl::setAppl(MyApplication* app)
{
	m_appl = app;
}

