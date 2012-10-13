#include "Writter.h"
#include "global.h"
#include "appl.h"
#include "SDL_opengl.h"
#include "Render.h"
#include <math.h>

using namespace std;


Writter::Writter(){
	

}

Writter::~Writter(){
	
}

void Writter::AddFont(string iname, string fontfile, int fontsize){

	FTFont* nfont = new FTTextureFont(fontfile.c_str());

	if(nfont->Error())
    {
        fprintf(stderr, "Failed to open font %s", fontfile);
        exit(1);
    }
	nfont->FaceSize(fontsize);
	
	m_font_list[iname] = nfont;
}

void Writter::Draw(string iname, string str, float x, float y, float mangle){
	FTFont* nfont = m_font_list[iname];

	if (nfont != NULL){
		glPushMatrix();

		glTranslatef(x, -y - nfont->LineHeight(), 0);
		glRotatef(mangle, 0.0, 0.0, 1);
		
		nfont->Render(str.c_str());

		glPopMatrix();

	}else{
		fprintf(stderr, "Failed to draw using name '%s': %s\n", iname.c_str(), str.c_str());
	}
}
