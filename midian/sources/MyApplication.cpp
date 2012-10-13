#include "MyApplication.h"
#include "CFPS.h"
#include "global.h"
#include "WordState.h"
#include "WordStateMenu.h"
#include "SDL_opengl.h"

#include "Render.h"



MyApplication::MyApplication() {
	Running = true;
	m_selected_word_state = NULL;
	// PLEASE! DONT LOAD ANY OPENGL TEXTURE HERE

	// PLEASE, DO NOT LOAD FONTS HERE (FONTS ARE TEXTURES)
	writter = new Writter();

	statisticHandle = new StatisticsHandler;
	
}

int MyApplication::OnExecute() {
	if(OnLoad() == false) {
		system("pause");
		return -1;
	}

	SDL_Event Event;

	Uint32 next_game_tick = SDL_GetTicks();
    int loops;	
    float interpolation;

    while( Running ) {
        loops = 0;
		while (SDL_GetTicks() > next_game_tick && loops < Const::MAX_FRAMESKIP) {

			while(SDL_PollEvent(&Event)) {
				OnEvent(&Event);
			}

			OnLoop();

			next_game_tick += Const::SKIP_TICKS;
            loops++;
        }

		interpolation = float( SDL_GetTicks() + Const::SKIP_TICKS - next_game_tick ) / float( Const::SKIP_TICKS );

        OnRender( interpolation );
    }

	OnUnload();
	return 0;
}

bool MyApplication::OnLoad(){
	if (!OnLoadSDL()) return false;
	if (!OnLoadOpenGL()) return false;

	writter->AddFont("log","VeraMono.ttf", 12);

	writter->AddFont("blood","blood.ttf", 14);

	m_menu_word_state = new WordStateMenu();

	m_cut_game_state = NULL;

	m_selected_word_state = m_menu_word_state;
	
	return true;
};

void MyApplication::OnUnload(){

	delete statisticHandle;
	delete writter;
	m_selected_word_state = NULL;

	if (m_cut_game_state != NULL) delete m_cut_game_state;
	if (m_menu_word_state != NULL) delete m_menu_word_state;

};

void MyApplication::OnEvent(SDL_Event* Event){
	CEvent::OnEvent(Event);

	if (m_selected_word_state != NULL) {
		m_selected_word_state->OnEvent(Event);
	}
};

void MyApplication::OnExit() {
	Running = false;
}

void MyApplication::OnLoop(){
	LPSControl.OnLoop();

	if (m_selected_word_state != NULL) {
		m_selected_word_state->OnLoop();
	}

	
	/*Global::debug("FPS: " + Global::IntToStr(FPSControl.GetFPS()));
	Global::debug("LPS: " + Global::IntToStr(LPSControl.GetFPS()));
	Render::Instance()->PrintCallCount();*/
};

void MyApplication::OnRender(float pInterpolation){
	FPSControl.OnLoop();
	Render::Instance()->ResetCallCount();

	glClear(GL_COLOR_BUFFER_BIT);

	if (m_selected_word_state != NULL) {
		m_selected_word_state->OnRender(pInterpolation);
	}

	statisticHandle->OnRender(pInterpolation);

	SDL_GL_SwapBuffers();
};


void MyApplication::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle){

	if (m_selected_word_state != NULL) {
		m_selected_word_state->SetLastMousePosition(mX, mY);
	}

}

void MyApplication::OnResize(int w,int h){

	if (m_screen_height == h && m_screen_width == w)
		return;

	m_screen_height = h;
	m_screen_width = w;

	glViewport( 0, 0, this->m_screen_width, this->m_screen_height );

	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0,m_screen_width,-m_screen_height,0);
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	glLoadIdentity(); 

}