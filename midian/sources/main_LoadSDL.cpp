#include "MyApplication.h"

#include "SDL_opengl.h"

#include "global.h"

bool MyApplication::OnLoadSDL(){
	//_putenv("SDL_VIDEO_WINDOW_POS=0,22");
	_putenv("SDL_VIDEO_CENTERED=1");
	
	m_screen_width  = 1024;
	m_screen_height = 768;
	

	Global::debug("Iniciando SDL + OPENGL...");

	if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 ) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return false;
	}
	
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);

	m_surface_flags = SDL_OPENGL|SDL_RESIZABLE;

	m_sdl_screen = SDL_SetVideoMode( m_screen_width, m_screen_height, 0, m_surface_flags );  
	printf("SDL_SetVideoMode: %s\n", SDL_GetError());

	return true;
};

