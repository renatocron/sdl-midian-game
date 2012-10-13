#include "CFPS.h"

CTimeControl::CTimeControl() {
	OldTime     = 0;
	LastTime    = 0;


	Frames      = 0;
	NumFrames   = 0;
}

void CTimeControl::OnLoop() {
	if(OldTime + 1000 < SDL_GetTicks()) {
		OldTime = SDL_GetTicks();

		NumFrames = Frames;

		Frames = 0;
	}

	LastTime = SDL_GetTicks();

	Frames++;
}

int CTimeControl::GetFPS() {
	return NumFrames;
}
