#include "WordStateCandy.h"
#include "global.h"
#include "appl.h"
#include "SDL_opengl.h"
#include "Render.h"
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;


WordStateCandy::WordStateCandy(): WordState(){
	
	
	points = show_points = 0;

	m_box = new TItemBox();
	item_size = 15.0f;
	m_box->my_w = item_size * 40; // 40 items
	m_box->my_h = item_size * 30; // 30 items

	
}

WordStateCandy::~WordStateCandy(){
	delete m_box;
}

void WordStateCandy::OnLoop(){
	float sw = (float)__GAME__()->get_width();
	float sy = (float)__GAME__()->get_height();
	
	m_box->pos_x = (sw - m_box->my_w) / 2.0f;
	m_box->pos_y = (sy - m_box->my_h)  / 2.0f;

	if (last_mouse_x > m_box->pos_x && last_mouse_x < m_box->pos_x + m_box->my_w && last_mouse_y > m_box->pos_y &&  last_mouse_y < m_box->pos_y + m_box->my_h){
		SDL_ShowCursor(false);
	}else{
		SDL_ShowCursor(true);
	}

}



void WordStateCandy::OnRender(float pInterpolation){

	render->ActiveTextures();

	
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
	/* anything draw here will be blended, not replaced*/
	glColor4f(1.f, 0.f, 0.f, 1.f);
	
	float sw = (float)__GAME__()->get_width();
	float sy = (float)__GAME__()->get_height();

	

	/* until here */
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glColor3f(1.0, 1.0, 1.0);



	render->DisableTextures();

	glColor4f(1.0, 1.0, 1.0, 0.8f);
	render->DrawRect(m_box->pos_x, m_box->pos_y- 60.0f, m_box->my_w, m_box->my_h + 60.0f);
	
	glColor4f(0.5f, 0.5f, 0.5f, 0.5f);
	render->DrawRect(m_box->pos_x, m_box->pos_y, m_box->my_w, m_box->my_h);


	glColor4f(0.0, 0.3f, 0.0, 1.0f);
	string teste = "points";
	__GAME__()->writter->Draw("blood", teste, m_box->pos_x, m_box->pos_y - 20.0f);
	
	

	//teste = ":" + Global::IntToStr((int)points);
	//__GAME__()->writter->Draw("log", teste, box_left + 50.0f, box_top + 3.0f);

	

	render->DisableTextures();
	if (last_mouse_x > m_box->pos_x && last_mouse_x < m_box->pos_x + m_box->my_w && last_mouse_y > m_box->pos_y &&  last_mouse_y < m_box->pos_y + m_box->my_h){
	
		glLineWidth(3.0f);

		float from_x, from_y, to_x, to_y;
		from_x = (float)last_mouse_x;
		from_y = (float)last_mouse_y;
		
		to_y = 10.0f;
		to_x = 10.0f;
		glPushMatrix();
		glTranslatef(from_x, -from_y, 0);
	
		glBegin( GL_LINES );
			
			glVertex2f( 0,  (to_y/2.0f));
			glVertex2f( 0, -(to_y/2.0f));

			glVertex2f(  (to_x/2.0f), 0);
			glVertex2f( -(to_x/2.0f), 0);

		glEnd();
		glPopMatrix();

	}

	//glColor4f(1.f, 0.f, 0.f, 1.f);

	//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
	//m_bloods->SetXY(0.f, 0.f);
	//render->DrawSprite(m_bloods);
	/*
	GLint tid = m_bloods->GetTextureName();
	
	glBindTexture(GL_TEXTURE_2D, tid);
	
	float x      = m_bloods->GetX();
	float y      = m_bloods->GetY();
	float width  = static_cast<float>(m_bloods->GetWidth());
	float height = static_cast<float>(m_bloods->GetHeight());
	float angle = m_bloods->GetAngle();
	BYTE r_spot = m_bloods->GetRotateSpot();

	y = -(y) - height;	
	
	glPushMatrix();
	
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
		float left_top_x = 0.f;
		float left_top_y = 0.f;
		float right_top_x = 200.f;
		float right_top_y = 0.f;
		float right_bottom_x = 200.f;
		float right_bottom_y = 180.f;
		float left_bottom_x = 0.f;
		float left_bottom_y = 180.f;

		left_top_x /= width;
		right_top_x /= width;
		right_bottom_x /= width;
		left_bottom_x /= width;

		left_top_y /= height;
		right_top_y /= height;
		right_bottom_y /= height;
		left_bottom_y /= height;

		/*glDisable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glColor4f(1, 0, 1,0.5f);*/
		//glBegin(GL_POLYGON); 
		//glPointSize(30.0f);
	/*
		glBegin(GL_QUADS); 
			
			// 5
			glTexCoord2f(left_top_x, left_top_y);
			glVertex3f(0, height, 0.0);
			
			// 4
			glTexCoord2f(right_top_x, right_top_y);
			glVertex3f(width, height, 0.0);
			// 3
			glTexCoord2f(right_bottom_x, right_bottom_y);
			glVertex3f(width, 0, 0.0);
			
			// 1
			glTexCoord2f(left_bottom_x, left_bottom_y);
			glVertex3f(0, 0, 0.0);
			
		glEnd();
	glPopMatrix();
	*/
	
	//glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void WordStateCandy::OnLButtonUp(int mX, int mY){
 

}

void WordStateCandy::OnRButtonDown(int mX, int mY){
 

}
void WordStateCandy::OnRButtonUp(int mX, int mY){
	
	 
}


TItemBox::TItemBox(){
	this->my_h = this->my_w = this->pos_x = this->pos_y = 0;
}


