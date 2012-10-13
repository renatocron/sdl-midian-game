#ifndef _VERTEX_SPRITE_H_
#define _VERTEX_SPRITE_H_

#include "SDL.h"
#include <SDL_opengl.h>
#include "Sprite.h"
#include <GL/gl.h>
#include "SDL_image.h"
#include <vector>
using namespace std;

class VertexSprite: public Sprite
{
		
public:
	struct VertexSpriteItem
	{
		// material
		GLfloat mx1, my1; // top left
		GLfloat mx2, my2; // top right 
		GLfloat mx3, my3; // bottom right
		GLfloat mx4, my4; // bottom left
		GLfloat mangle;

		// texture
		GLfloat tx1, ty1;
		GLfloat tx2, ty2;
		GLfloat tx3, ty3;
		GLfloat tx4, ty4;
		GLfloat tangle;

		// material sizes (used for position rendering)
		GLfloat mwidth;
		GLfloat mheight;

		// precalc texture points base on texture sizes
		GLfloat tx1f, ty1f;
		GLfloat tx2f, ty2f;
		GLfloat tx3f, ty3f;
		GLfloat tx4f, ty4f;

	};
public: // temp, is private
	vector<VertexSpriteItem> m_vertex_items;
public:
    // Constructor
    VertexSprite();

    // Destructor
    virtual ~VertexSprite();

	inline VertexSpriteItem getItem(int itemIdx){return m_vertex_items[itemIdx];};

	bool LoadVertexFromFile(char* filename);

};

#endif