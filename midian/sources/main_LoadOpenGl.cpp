#include "MyApplication.h"
#include "SDL_opengl.h"
#include "wglext.h"

using namespace std;

bool MyApplication::OnLoadOpenGL(){
	float cur_version = (float)atof((char*)glGetString(GL_VERSION));
	printf("OpenGL %s\n", (char*)glGetString(GL_VERSION));

	bool gl11Supported = cur_version >= 1.1f;
	if (!gl11Supported){
		printf("This application requires OpenGL 1.1, but your current version is %f\n", cur_version);
		return false;	
	}
	

	glEnable( GL_TEXTURE_2D );
	 
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
//	glClearColor( 0.0f, 1.0f, 1.0f, 0.0f );
	 
	glViewport( 0, 0, this->m_screen_width, this->m_screen_height );
	 
	glClear( GL_COLOR_BUFFER_BIT );
	
	glViewport( 0, 0, this->m_screen_width, this->m_screen_height );

	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0,m_screen_width,-m_screen_height,0);
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	glLoadIdentity(); 


	/*
     * Disable stuff that's likely to slow down glDrawPixels.
     * (Omit as much of this as possible, when you know in advance
     * that the OpenGL state will already be set correctly.)
     */
    glDisable(GL_ALPHA_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_DITHER);    
    glDisable(GL_FOG);
    glDisable(GL_LIGHTING);
    glDisable(GL_LOGIC_OP);
    glDisable(GL_STENCIL_TEST);
    glDisable(GL_TEXTURE_1D);
    glDisable(GL_TEXTURE_2D);
    glPixelTransferi(GL_MAP_COLOR, GL_FALSE);
    glPixelTransferi(GL_RED_SCALE, 1);
    glPixelTransferi(GL_RED_BIAS, 0);
    glPixelTransferi(GL_GREEN_SCALE, 1);
    glPixelTransferi(GL_GREEN_BIAS, 0);
    glPixelTransferi(GL_BLUE_SCALE, 1);
    glPixelTransferi(GL_BLUE_BIAS, 0);
    glPixelTransferi(GL_ALPHA_SCALE, 1);
    glPixelTransferi(GL_ALPHA_BIAS, 0);

    /*
     * Disable extensions that could slow down glDrawPixels.
     */
    const GLubyte* extString = glGetString(GL_EXTENSIONS);

    if (extString != NULL) {
       if (strstr((char*) extString, "GL_EXT_convolution") != NULL) {
           glDisable(GL_CONVOLUTION_1D_EXT);
           glDisable(GL_CONVOLUTION_2D_EXT);
           glDisable(GL_SEPARABLE_2D_EXT);
       }
       if (strstr((char*) extString, "GL_EXT_histogram") != NULL) {
           glDisable(GL_HISTOGRAM_EXT);
           glDisable(GL_MINMAX_EXT);
       }
       if (strstr((char*) extString, "GL_EXT_texture3D") != NULL) {
           glDisable(GL_TEXTURE_3D_EXT);
       }
    }

	glDisable(GL_CULL_FACE);

	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST );

	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPointSize(1);

	//glDisable(GL_POINT_SMOOTH);
    //glDisable(GL_LINE_SMOOTH);

	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glLineWidth(2.f);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	PFNWGLSWAPINTERVALEXTPROC       wglSwapIntervalEXT = NULL;
	PFNWGLGETSWAPINTERVALEXTPROC    wglGetSwapIntervalEXT = NULL;
	char *extensions = (char *)glGetString(GL_EXTENSIONS);
 
	// Check your extension
	if (strstr(extensions, "WGL_EXT_swap_control")){
		// Extension is supported, init pointers.
		wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC) SDL_GL_GetProcAddress("wglSwapIntervalEXT");

		// this is another function from WGL_EXT_swap_control extension
		wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC) SDL_GL_GetProcAddress("wglGetSwapIntervalEXT");
	}

	if(wglGetSwapIntervalEXT){
		int i = 1;
		printf("WGL_EXT_swap_control supported. wglSwapIntervalEXT(%i)\n", i);
		wglSwapIntervalEXT(i);
	}else{
		printf("WGL_EXT_swap_control NOT supported...\n");
		printf("List of supported %s\n", extensions);
	}
	
	return true;
}
