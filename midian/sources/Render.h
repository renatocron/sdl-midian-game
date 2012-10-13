#ifndef _RENDER_H_
#define _RENDER_H_

#include <string>
#include "SDL.h"
#include <SDL_opengl.h>
#include <GL/gl.h>
#include "SDL_image.h"
#include "Sprite.h"
#include "VertexSprite.h"

#include <iostream>
using namespace std;


class Render {
private:
		GLint m_last_texture_id;

		int m_num_bind_call;
		int m_num_draw_call;
public:
	/*struct SVertex2D
	{
		GLfloat x,y;
		GLfloat r,g,b,a;
	};
*/
	struct SVertex2D
	{
	// GL_BGRA
	//	GLfloat b, g, r, a;
		GLfloat r, g, b, a;
	};

	inline static Render* Instance(){
		if (!m_pInstance) m_pInstance = new Render;
		return m_pInstance;
	}

	void DrawRect(float x, float y, float width, float height, bool fill = true, float angle=0);
	void DrawRoundRect(float x, float y, float w, float h, float radius, bool fill = true, float angle=0);
	
	void DrawSprite(Sprite *spr);

	void DrawVertexSprite(VertexSprite *spr, int idx = 0);

	void ResetCallCount();

	void PrintCallCount();

	inline void ExternalBind(){m_last_texture_id = 0; m_num_bind_call++;m_num_draw_call++;};
	
	inline int* getTextureIdAddr(){return &m_last_texture_id;};
	
	inline void ActiveTextures(){
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
	}

	inline int get_num_bind_call(){return m_num_bind_call;};
	inline int get_num_draw_call(){return m_num_draw_call;};

	inline void DisableTextures(){
		glDisable(GL_TEXTURE_2D);
	}
	
private:
	Render(){ResetCallCount();};  // Private so that it can  not be called
	Render(Render const&){};             // copy constructor is private
	Render& operator=(Render const&){};  // assignment operator is private
	static Render* m_pInstance;
};
/*
class PointMatrixArray {
private:
	Render::SVertex2D* m_vertices;
	int m_num_vertices;
	int height, width, skip;

	GLuint m_texture_id;
public:
	PointMatrixArray(int pwidth, int pheight, int pskip=1);
	~PointMatrixArray();
	
	inline Render::SVertex2D* GetArray(){return m_vertices;}

	void DrawArray(float offset_x=0, float offset_y=0);

	void Clean(float r=0, float g=0, float b=0, float a=1);

	inline int GetNumVertices(){return m_num_vertices;}
	inline int GetSkip(){return skip;}

	inline void SetPixel(int x, int y, float r=0, float g=0, float b=0, float a=1){
		if (m_vertices == NULL) return;

		x = (x / skip) * skip;
		y = (y / skip) * skip;
		int i = ((y * width) + x) / skip;
		
		if (i >= 0 && i < m_num_vertices){
			m_vertices[i].r = r;
			m_vertices[i].g = g;
			m_vertices[i].b = b;
			//m_vertices[i].a = a;

		}
	}

	inline int GetWidth(){return width;};
	inline int GetHeight(){return height;};

};
*/

#endif