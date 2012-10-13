

#include "main.h"
#include "global.h"
#include "appl.h"



int main(int argc, char* argv[]) {
	MyApplication* app = new MyApplication();
	Appl::Instance()->setAppl(app);
	
	return Appl::Instance()->getAppl()->OnExecute();
}

