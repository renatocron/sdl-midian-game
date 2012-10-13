#include "StatisticsHandler.h"
#include "global.h"
#include "appl.h"
#include "SDL_opengl.h"
#include "Render.h"
#include <math.h>

using namespace std;


StatisticsHandler::StatisticsHandler(){
	
}

StatisticsHandler::~StatisticsHandler(){
	
}


void StatisticsHandler::OnRender(float pInterpolation){

	Render::Instance()->ActiveTextures();
	glColor3f(1.0, 1.0, 1.0);

	string teste = "FPS: ";
	teste += Global::IntToStr(Appl::Instance()->getAppl()->FPSControl.GetFPS());
	__GAME__()->writter->Draw("log", teste, 0, 0);

	teste = "LPS: ";
	teste += Global::IntToStr(Appl::Instance()->getAppl()->LPSControl.GetFPS());
	__GAME__()->writter->Draw("log", teste, 0, 18);

	teste = "num_bind_call: ";
	teste += Global::IntToStr(Render::Instance()->get_num_bind_call()+1);//+1 porque a fonte causa 1..., pelo menos...
	__GAME__()->writter->Draw("log", teste, 120, 0);
	
	teste = "num_draw_call: ";
	teste += Global::IntToStr(Render::Instance()->get_num_draw_call());
	__GAME__()->writter->Draw("log", teste, 120, 18);

	
	teste = "window size:  ";
	teste += Global::IntToStr(__GAME__()->get_width()) + "x" +
			Global::IntToStr(__GAME__()->get_height());
	__GAME__()->writter->Draw("log", teste, 300, 0);
		
	teste = "mouse posicao ";

	teste += Global::IntToStr(__GAME__()->GeCurtWordState()->getLastMouseX()) + "/" +
			 Global::IntToStr(__GAME__()->GeCurtWordState()->getLastMouseY());
		
	__GAME__()->writter->Draw("log", teste, 600, 0);
	
	Render::Instance()->ExternalBind();
}