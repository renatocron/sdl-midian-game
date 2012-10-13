#include "Render.h"

#include <iostream>
#include <math.h>
#include "global.h"
#include "Sprite.h"
#include "VertexSprite.h"

using namespace std;

// Global static pointer used to ensure a single instance of the class.
Render* Render::m_pInstance = NULL;  

/** This function is called to create an instance of the class. 
    Calling the constructor publicly is not allowed. The constructor 
    is private and is only called by this Instance function.
*/
  


/*******************************************************************************************
 ** Draw DrawRoundRect
*******************************************************************************************/
void Render::DrawRect(float x, float y, float width, float height, bool fill, float angle)
{
	y = -(y) - height;
	y += height/2;
	x += width/2;
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(angle,0,0,1);
	glTranslatef(-width/2, -height/2, 0);//center rotate
	glBegin( fill ? GL_QUADS : GL_LINE_LOOP );
		// Top-left vertex (corner)
		glVertex2f( 0, 0);

		// Bottom-left vertex (corner)
		glVertex2f( 0, height);

		// Bottom-right vertex (corner)
		glVertex2f( width, height);

		// Top-right vertex (corner)
		glVertex2f( width, 0);
	glEnd();
	glPopMatrix();
	m_num_draw_call++;
}
/*******************************************************************************************
 ** Draw DrawRoundRect
*******************************************************************************************/
void Render::DrawRoundRect(float x, float y, float w, float h, float radius, bool fill, float angle){

	y = -(y) - h;
	y += h/2;
	x += w/2;

	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(angle,0,0,1);
	glTranslatef(-w/2, -h/2, 0);//center rotate

	glBegin( fill ? GL_POLYGON : GL_LINE_LOOP );
	
	glVertex2f (radius, 0);
	glVertex2f (w-radius, 0);
	for(float t = static_cast<float>(Const::PI) * 1.5f; t < Const::PI * 2; t+=0.1f){
		float sx = w - radius + (float)cosf(t) * radius;
		float sy = radius + (float)sinf(t) * radius;
		glVertex2f (sx, sy);
	}
	glVertex2f (w, radius);
	glVertex2f (w, h-radius);
	for(float t =0; t < static_cast<float>(Const::PI) * 0.5f; t+=0.1f){
		float sx = w - radius + (float)cosf(t) * radius;
		float sy = h -radius + (float)sinf(t) * radius;
		glVertex2f (sx, sy);
	}

	glVertex2f (w -radius, h);
	glVertex2f (radius, h);
	for(float t = static_cast<float>(Const::PI)* 0.5f; t < Const::PI; t+=0.1f){
		float sx = radius + (float)cosf(t) * radius;
		float sy = h - radius + (float)sinf(t) * radius;
	   glVertex2f (sx, sy);
	}
	 
	glVertex2f (0, h - radius);
	glVertex2f (0, radius);
	for(float t = static_cast<float>(Const::PI); t < static_cast<float>(Const::PI) * 1.5f; t+=0.1f){
		float sx = radius + (float)cosf(t) * radius;
		float sy = radius + (float)sinf(t) * radius;
		glVertex2f (sx, sy);
	}
	
	glEnd();
	glPopMatrix();
	m_num_draw_call++;
}
/*******************************************************************************************
 ** Draw Sprite based on spr position
*******************************************************************************************/
void Render::DrawSprite(Sprite *spr){
	
	GLint tid = spr->GetTextureName();
	if (tid != m_last_texture_id){
		glBindTexture(GL_TEXTURE_2D, tid);
		m_last_texture_id = tid;
		m_num_bind_call++;
	}

	float x      = spr->GetX();
	float y      = spr->GetY();
	float width  = static_cast<float>(spr->GetWidth());
	float height = static_cast<float>(spr->GetHeight());
	float angle = spr->GetAngle();
	BYTE r_spot = spr->GetRotateSpot();

/*	if (inverted){*/
		y = -(y) - height;	
	/*}*/
	
	glPushMatrix();
	//glLoadIdentity();
	glTranslatef(x+width/2,y+height/2,0.0f); 
		
		if ((int)angle != 0){
			glRotatef(angle, 0.0, 0.0, 1);
		}
		switch(r_spot)
		{
				case Sprite::origin_top_center   : glTranslatef(-width/2, 0, 0); break;
				case Sprite::origin_top_right    : glTranslatef(-width, 0, 0); break;
				case Sprite::origin_center_left  : glTranslatef(0, -height/2, 0);break;
				case Sprite::origin_center       : glTranslatef(-width/2, -height/2, 0);break;
				case Sprite::origin_center_right : glTranslatef(-width, -height/2, 0);break;
				case Sprite::origin_bottom_left  : glTranslatef(0, -height, 0);break;
				case Sprite::origin_bottom_center: glTranslatef(-width/2, -height, 0);break;
				case Sprite::origin_bottom_right : glTranslatef(-width, -height, 0);break;
		}

		glBegin(GL_QUADS);
		//if (inverted){
			// Lower left corner
			glTexCoord2f(0.0, 1.0);
			glVertex3f(0, 0, 0.0);

			// Lower right corner
			glTexCoord2f(1.0, 1.0);
			glVertex3f(width, 0, 0.0);

			// Upper right corner
			glTexCoord2f(1.0, 0.0);
			glVertex3f(width, height, 0.0);

			// Upper left corner
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0, height, 0.0);

		/*}else{
			// Lower left corner
			glTexCoord2f(0.0, 1.0f);
			glVertex2f(0 , height);

			// Lower right corner
			glTexCoord2f(1.0f, 1.0f);
			glVertex2f(width, height);

			// Upper right corner
			glTexCoord2f(1.0f, 0.0f);
			glVertex2f(width , 0);

			// Upper left corner
			glTexCoord2f(0.0f, 0.0f);
			glVertex2f(0, 0);
		}*/
		glEnd();
	glPopMatrix();
	//glLoadIdentity();

	m_num_draw_call++;
}

/*******************************************************************************************
 ** Reset all counts
*******************************************************************************************/
void Render::ResetCallCount(){
	this->m_num_bind_call = 0;
	this->m_num_draw_call = 0;
}

/*******************************************************************************************
 ** Print (to console) all counts
*******************************************************************************************/
void Render::PrintCallCount(){
	printf("num_bind_call = %03d num_draw_call = %03d \n", m_num_bind_call, m_num_draw_call );
}
/*******************************************************************************************
 ** render vertex sprites based on idx index
*******************************************************************************************/
void Render::DrawVertexSprite(VertexSprite *spr, int idx){
	GLint tid = spr->GetTextureName();
	if (tid != m_last_texture_id){
		glBindTexture(GL_TEXTURE_2D, tid);
		m_last_texture_id = tid;
		m_num_bind_call++;
	}

	VertexSprite::VertexSpriteItem vi = spr->getItem(idx);

	float x      = spr->GetX();
	float y      = spr->GetY();

	float width  = vi.mwidth;
	float height = vi.mheight;
	float angle  = vi.mangle + 180; // dont ask me why
	BYTE r_spot = spr->GetRotateSpot();

	y = -(y) - height;	
	
	glPushMatrix();
	//glLoadIdentity();
	glTranslatef(x+width/2,y+height/2,0.0f); 
		
	
		glRotatef(angle, 0.0, 0.0, 1);
		
		switch(r_spot)
		{
				case Sprite::origin_top_center   : glTranslatef(-width/2, 0, 0); break;
				case Sprite::origin_top_right    : glTranslatef(-width, 0, 0); break;
				case Sprite::origin_center_left  : glTranslatef(0, -height/2, 0);break;
				case Sprite::origin_center       : glTranslatef(-width/2, -height/2, 0);break;
				case Sprite::origin_center_right : glTranslatef(-width, -height/2, 0);break;
				case Sprite::origin_bottom_left  : glTranslatef(0, -height, 0);break;
				case Sprite::origin_bottom_center: glTranslatef(-width/2, -height, 0);break;
				case Sprite::origin_bottom_right : glTranslatef(-width, -height, 0);break;
		}
		if (vi.tangle){
			glMatrixMode( GL_TEXTURE );
			glPushMatrix();
			glRotatef(vi.tangle, 0.0, 0.0, 1);
			glTranslatef(-width/2, -height/2, 0);
		}

		glBegin(GL_QUADS);
			
			glTexCoord2f(vi.tx1f, vi.ty1f);
			glVertex2f(vi.mx1, vi.my1);

			glTexCoord2f(vi.tx2f, vi.ty2f);
			glVertex2f(vi.mx2, vi.my2);
		
			glTexCoord2f(vi.tx3f, vi.ty3f);
			glVertex2f(vi.mx3, vi.my3);
			
			glTexCoord2f(vi.tx4f, vi.ty4f);
			glVertex2f(vi.mx4, vi.my4);

		glEnd();
		if (vi.tangle){
			glPopMatrix();
			glMatrixMode( GL_MODELVIEW );
		}
	glPopMatrix();
	//glLoadIdentity();

	m_num_draw_call++;
}












/*


PointMatrixArray::PointMatrixArray(int pwidth, int pheight, int pskip){
	m_vertices = NULL;
	
	#ifdef _DEBUG
	if (pwidth < 1 || pheight < 1 || pskip < 1){
		printf("width %d and height %d and pskip %d must be at least 1\n", pwidth, pheight, pskip );
		return;
	}
	#endif
	pwidth  /= pskip;
	pheight /= pskip;

	height = pheight;
	width = pwidth;
	skip = pskip;
	m_num_vertices = (height * width);
	m_vertices = new Render::SVertex2D[m_num_vertices]; // [m_num_vertices - 1] works, but i'm not sure!
	m_texture_id =0;
}

PointMatrixArray::~PointMatrixArray(){
	if(m_vertices){
		free(m_vertices);
	}
	m_vertices = NULL;
}
*/
/*
void PointMatrixArray::DrawArray(float offset_x, float offset_y){
*//*
	if (m_vertices != NULL){
		glVertexPointer(	2,   //3 components per vertex (x,y)
							GL_FLOAT,
							sizeof(Render::SVertex2D),
							m_vertices);

		glColorPointer(		4,   //3 components per vertex (r,g,b,a)
							GL_FLOAT,
							sizeof(Render::SVertex2D),
							&m_vertices[0].r);

		glPushMatrix();
		glTranslatef(offset_x + (skip/2), offset_y + (skip/2),0);
		glDrawArrays(GL_POINTS,0,m_num_vertices);
		glPopMatrix();
		
	}*/

/*
	glPushMatrix();
	glTranslatef(offset_x + (skip/2), offset_y + (skip/2),0);
	glBegin(GL_POINTS);
	for(int i = 0; i < m_num_vertices; i++){
		glColor4f(m_vertices[i].r,m_vertices[i].g, m_vertices[i].b, m_vertices[i].a);
		glVertex2d(m_vertices[i].x,m_vertices[i].y);
	}
	glEnd();
	glPopMatrix();
*/
/*
	glPushMatrix();
	//glTranslatef(offset_x + (skip/2), offset_y + (skip/2),0);
	glRasterPos2d(offset_x, offset_y);
	 
	glDrawPixels(width,height, GL_RGB, GL_FLOAT, m_vertices);
	glPopMatrix();
*/
/*
	
	glBindTexture(GL_TEXTURE_2D, m_texture_id);
	//
	//glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_FLOAT, &m_vertices[0]);
	float x      = offset_x;
	float y      = offset_y;

	float angle = 0;
	BYTE r_spot = Sprite::origin_center;
	
	glPushMatrix();
	glTranslatef(offset_x + (skip/2), offset_y + (skip/2),0);
	//glLoadIdentity();
	

		glBegin(GL_QUADS);
		//if (inverted){
			// Lower left corner
			glTexCoord2f(0.0, 1.0);
			glVertex3f(0, 0, 0.0);

			// Lower right corner
			glTexCoord2f(1.0, 1.0);
			glVertex3f(width, 0, 0.0);

			// Upper right corner
			glTexCoord2f(1.0, 0.0);
			glVertex3f(width, height, 0.0);

			// Upper left corner
			glTexCoord2f(0.0, 0.0);
			glVertex3f(0, height, 0.0);

		*//*}else{
			// Lower left corner
			glTexCoord2f(0.0, 1.0f);
			glVertex2f(0 , height);

			// Lower right corner
			glTexCoord2f(1.0f, 1.0f);
			glVertex2f(width, height);

			// Upper right corner
			glTexCoord2f(1.0f, 0.0f);
			glVertex2f(width , 0);

			// Upper left corner
			glTexCoord2f(0.0f, 0.0f);
			glVertex2f(0, 0);
		}*//*
		glEnd();
	glPopMatrix();
}

void PointMatrixArray::Clean(float r, float g, float b, float a){
	if (m_vertices == NULL) return;

	int x = 0;
	int y = 0;
	for (int i = 0; i < m_num_vertices; i++)
	{		
		//m_vertices[i].x = (float)x;
		//m_vertices[i].y = (float)y;
	
		m_vertices[i].r = r;
		m_vertices[i].g = g;
		m_vertices[i].b = b;
		m_vertices[i].a = a;

		// cout << "x = " << x << " y = " << y << " i = " << i << endl;	
		x+=skip;
		if(x >= width*skip) {
			x = 0; y+=skip;	
		}
		
	}	
	//Sleep(10000);

	int m_width  = width;	
	int m_height = height;

	if(!m_texture_id){
		// Set PixelStore
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		// Gen new texture
		glGenTextures(1, &m_texture_id);
	}
	// active it
		glBindTexture(GL_TEXTURE_2D, m_texture_id);
		// Configure it
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );


	// Create new texure AS
	// GL_TEXTURE_2D
	// 0 no level
	// image->format->BytesPerPixel AKA 4 = 32'bits
	// m_width
	// m_height
	// 0 = border	
	// format = GL_BGRA mostly
	// type = GL_UNSIGNED_INT_8_8_8_8_REV mostly
	// image->pixels =  pixels
	
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_FLOAT, &m_vertices[0]);
}

//void PointMatrixArray::SetPixel(int x, int y, float r, float g, float b, float a)

*/