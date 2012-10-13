#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "SDL.h"
#include <SDL_opengl.h>
#include <GL/gl.h>
#include "SDL_image.h"

class Sprite
{
public:
	enum Origins
	{
		origin_top_left,
		origin_top_center,
		origin_top_right,
		origin_center_left,
		origin_center,
		origin_center_right,
		origin_bottom_left,
		origin_bottom_center,
		origin_bottom_right
	};
	enum SpriteTypes
	{
		st_normal,
		st_vertex
	};
private:
	int m_width, m_height;
	float m_x, m_y, m_angle;
	
	BYTE m_rotate_spot, m_sprite_type;

private:
    // These members are parameters to the OpenGL
    // function glTexImage2D()
    GLuint m_textureName;
public:
    // Constructor
    Sprite();

    // Destructor
    virtual ~Sprite(void);

    // Accessors
	inline int    GetWidth()      {return m_width;};
	inline int    GetHeight()     {return m_height;};
	inline float  GetX()          {return m_x;};
	inline float  GetY()          {return m_y;};
	inline float  GetAngle()      {return m_angle;};
	inline BYTE   GetType()       {return m_sprite_type;};
	
	inline BYTE  GetRotateSpot()   {return m_rotate_spot;};
	inline void  SetRotateSpot(Origins s)   {m_rotate_spot = s;};
	inline void  setType(SpriteTypes st)       {m_sprite_type = st;};

	inline GLuint GetTextureName(){return m_textureName;};

	// Set
	inline void SetXY   (float nx, float ny ){m_x = nx; m_y = ny;};
	inline void SetX    (float nx           ){m_x = nx;          };
	inline void SetY    (          float ny ){          m_y = ny;};
	inline void SetAngle(float na){m_angle = na;};

    bool LoadFromFile(char* filename);

};

class SimpleImage
{
	int m_x, m_y;
	
public:	
	SDL_Surface* image;

    // Constructor
    SimpleImage();

    // Destructor
    virtual ~SimpleImage(void);


	// Set
	inline void SetXY   (int nx, int ny ){m_x = nx; m_y = ny;};
	inline void SetX    (int nx          ){m_x = nx;          };
	inline void SetY    (        int ny ){          m_y = ny;};

	bool is_not_white(int px, int py);
	
	bool LoadFromFile(char* filename);
};


#endif