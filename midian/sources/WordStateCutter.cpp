#include "WordStateCutter.h"
#include "global.h"
#include "appl.h"
#include "SDL_opengl.h"
#include "Render.h"
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;


WordStateCutter::WordStateCutter(): WordState(){
	
	m_blood = new Sprite();
	m_blood->LoadFromFile("data/png/bloods_1.png");
	m_blood->SetXY(100.f, 100.f);


	m_bloods = new VertexSprite();
	m_bloods->LoadFromFile("data/png/bloods_1.png");
	
	m_bloods->LoadVertexFromFile("data/vertex/bloods_1.matrix");
	numteste = 0;

	ammo = 0;
	for (int i = 0; i < 400; i+=10){
		TargetEntity* t = new TargetEntity();
		t->x = (float)Global::random(20, 700);
		t->y = (float)Global::random(20, 500);
		t->setWidthHeight((float) Global::random(10,40),(float) Global::random(10,40) );

		ammo += t->y * (t->x - 1) / 100.0f;

		m_targets.push_back(t);
	}
	show_ammo = ammo;

	points = 0;

}

WordStateCutter::~WordStateCutter(){
	delete m_blood;
	delete m_bloods;
}

void WordStateCutter::OnLoop(){
	numteste++;
	if (numteste > 13) numteste = 0;

	float sw = (float)__GAME__()->get_width();
	float sy = (float)__GAME__()->get_height();

	float box_width  = 720.0f;
	float box_height = 520.0f;
	float box_left   = (sw - box_width) / 2.0f;
	float box_top    = (sy - box_height)  / 2.0f;

	start_viewpoint_y = box_top;
	start_viewpoint_x = box_left;
	end_viewpoint_x   = start_viewpoint_x + box_width;
	end_viewpoint_y   = start_viewpoint_y + box_height;

	if (last_mouse_x > start_viewpoint_x && last_mouse_x < end_viewpoint_x && last_mouse_y > start_viewpoint_y &&  last_mouse_y < end_viewpoint_y){
		SDL_ShowCursor(false);

		int s = m_targets.size();
		for (int i=0; i<s; i++){
			TargetEntity* t = m_targets[i];
			if (t->life <= 0) continue;

			t->in_ain = last_mouse_x > (box_left + t->x) && last_mouse_x < (box_left + t->x + t->w) &&
					    last_mouse_y > (box_top + t->y) && last_mouse_y < (box_top + t->y + t->h);
		}

	}else{
		SDL_ShowCursor(true);

		int s = m_targets.size();
		for (int i=0; i<s; i++){
			TargetEntity* t = m_targets[i];
			t->in_ain = false;
		}
	}
	if (show_ammo != ammo){
		if (ammo < show_ammo){
			if (show_ammo - ammo > 101.0f){
				show_ammo -= 101.0f;
			}else if (show_ammo  - ammo > 11.0f){
				show_ammo -= 11.0f;
			}else if (show_ammo - ammo >= 1.0f){
				show_ammo -= 1.0f;
			}else if (show_ammo - ammo < 1.0f){
				show_ammo = ammo;
			}
		}
	}

}



void WordStateCutter::OnRender(float pInterpolation){

	render->ActiveTextures();

	
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);

	glColor4f(1.f, 0.f, 0.f, 1.f);
	m_blood->SetXY(0,0);

	float sw = (float)__GAME__()->get_width();
	float sy = (float)__GAME__()->get_height();

	m_bloods->SetXY(sw * 0.1f, 0 * 0.1f); 
	render->DrawVertexSprite(m_bloods, 0);

	m_bloods->SetXY(sw * 0.9f, sy * 0.1f); 
	render->DrawVertexSprite(m_bloods, 1);

	m_bloods->SetXY(sw * 0.3f, sy * 0.2f); 
	render->DrawVertexSprite(m_bloods, 2);

	m_bloods->SetXY(sw * 0.8f, sy * 0.3f); 
	render->DrawVertexSprite(m_bloods, 3);

	m_bloods->SetXY(sw * 0.9f, sy * 0.6f); 
	render->DrawVertexSprite(m_bloods, 4);

	m_bloods->SetXY(sw * 0.2f, sy * 0.2f); 
	render->DrawVertexSprite(m_bloods, 5);

	m_bloods->SetXY(sw * 0.1f, sy * 0.8f); 
	render->DrawVertexSprite(m_bloods, 6);

	m_bloods->SetXY(sw * 0.2f, sy * 0.85f); 
	render->DrawVertexSprite(m_bloods, 7);

	m_bloods->SetXY(sw * 0.3f, sy * 0.2f); 
	render->DrawVertexSprite(m_bloods, 8);

	m_bloods->SetXY(sw * 0.15f, sy * 0.3f); 
	render->DrawVertexSprite(m_bloods, 9);

	m_bloods->SetXY(sw * 0.1f, sy * 0.4f); 
	render->DrawVertexSprite(m_bloods, 10);

	m_bloods->SetXY(sw * 0.2f, sy * 0.5f); 
	render->DrawVertexSprite(m_bloods, 11);

	m_bloods->SetXY(sw * 0.2f, sy * 0.7f);  
	render->DrawVertexSprite(m_bloods, 12);

	m_bloods->SetXY(sw * 0.2f, sy * 0.2f); 
	render->DrawVertexSprite(m_bloods, 13); 
	
	/* more, repeated */
	m_bloods->SetXY(sw * 0.1f, sy * 0.8f);  
	render->DrawVertexSprite(m_bloods, 12);

	m_bloods->SetXY(sw * 0.2f, sy * 0.75f);  
	render->DrawVertexSprite(m_bloods, 5);

	m_bloods->SetXY(sw * 0.05f, sy * 0.5f);  
	render->DrawVertexSprite(m_bloods, 4);

	m_bloods->SetXY(sw * 0.5f, sy * 0.6f);  
	render->DrawVertexSprite(m_bloods, 10);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glColor3f(1.0, 1.0, 1.0);



	glColor4f(1.0, 1.0, 1.0, 0.8f);
	

	float box_width  = 720.0f;

	float box_height = 520.0f;
	float box_left   = (sw - box_width) / 2.0f;
	float box_top    = (sy - box_height)  / 2.0f;
	render->DisableTextures();
	render->DrawRect(box_left, box_top, box_width, box_height);
	
	glColor4f(0.0, 0.3f, 0.0, 1.0f);
	string teste = "points";
	__GAME__()->writter->Draw("blood", teste, box_left + 5.0f , box_top);
	
	teste = ":" + Global::IntToStr((int)points);
	__GAME__()->writter->Draw("log", teste, box_left + 50.0f, box_top + 3.0f);

	glColor4f(0.5f, 0.01f, 0.01f, 1.0f);
	teste = "ammo";
	__GAME__()->writter->Draw("blood", teste, box_left + 5.0f, box_top + 20.0f);

	teste = ":"+ Global::IntToStr((int)show_ammo);
	__GAME__()->writter->Draw("log", teste, box_left + 40.0f, box_top + 23.0f);


	int s = m_targets.size();
	for (int i=0; i<s; i++){
		
		TargetEntity* t = m_targets[i];
		if (t->life <= 0) continue;

		if (t->in_ain){
			glLineWidth(2.0f);
			glColor4f(0.8f, 0.0, 0.0, 1.0f);
		}else{
			glLineWidth(1.0f);
			glColor4f(0.0, 0.0, 0.0, 0.8f);
		}

		render->DrawRect(t->x + box_left, t->y + box_top, t->w, t->h);

		render->DisableTextures();
		glColor4f(1.0, 1.0, 1.0, 0.8f);
		
		render->DrawRect(t->x + box_left, t->y + box_top, t->w, t->h, false);

		string vida = Global::IntToStr((int)t->life);
		__GAME__()->writter->Draw("log", vida, t->x + box_left,  t->y + box_top + t->h);

	}

	render->DisableTextures();
	if (last_mouse_x > start_viewpoint_x && last_mouse_x < end_viewpoint_x && last_mouse_y > start_viewpoint_y &&  last_mouse_y < end_viewpoint_y){
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

void WordStateCutter::OnLButtonUp(int mX, int mY){
	numteste++;
	if (numteste > 13) numteste = 0;
	m_bloods->LoadVertexFromFile("data/vertex/bloods_1.matrix");

	if (ammo){
		int s = m_targets.size();
		for (int i=0; i<s; i++){
			TargetEntity* t = m_targets[i];
			if (t->life <= 0) continue;

			if (t->in_ain){

				float energy = (float)Global::random(100, 300);
				if (ammo < energy){
					energy = ammo;
					ammo = 0;
				}else{
					ammo -= energy;
				}
			
				t->life -= energy;
				if (t->life < 0){
					points += t->points;
					t->in_ain = false;
				}
			
			
			}

		}

	}
}

void WordStateCutter::OnRButtonDown(int mX, int mY){
	m_r_x = mX;
	m_r_y = mY;

}
void WordStateCutter::OnRButtonUp(int mX, int mY){
	
	int width  = abs(m_r_x - mX);
	int height = abs(m_r_y - mY);

	/*
	// top left
		GLfloat mx2, my2; // top right 
		GLfloat mx3, my3; // bottom right
		GLfloat mx4, my4; // bottom left
	*/
	// 0,180	180,180 180,0	0,0		180
	VertexSprite::VertexSpriteItem vi;
	
	vi.mangle = 0.f;
	vi.tangle = 0.f;

	vi.mx1 = 0.f;
	vi.my1 = 0.f;

	vi.mx2 = 0 + (float)width;
	vi.my2 = 0.f;

	vi.mx3 = (float)width;
	vi.my3 = (float)height;

	vi.mx4 = 0.f;
	vi.my4 = 0 + (float)height;

	vi.tx1 = (float)mX;
	vi.ty1 = (float)mY;

	vi.tx2 = (float)mX + (float)(m_r_x - mX);
	vi.ty2 = (float)mY;

	vi.tx3 = (float)mX + (float)(m_r_x - mX);
	vi.ty3 = (float)mY + (float)(m_r_y - mY);

	vi.tx4 = (float)mX;
	vi.ty4 = (float)mY + (float)(m_r_y - mY);


	float selfWidth = (float)m_bloods->GetWidth();
	if (selfWidth){
				
		vi.tx1f = vi.tx1 / selfWidth;
		vi.tx2f = vi.tx2 / selfWidth;
		vi.tx3f = vi.tx3 / selfWidth;
		vi.tx4f = vi.tx4 / selfWidth;

		float selfHeight = (float)m_bloods->GetHeight();
		vi.ty1f = vi.ty1 / selfHeight;
		vi.ty2f = vi.ty2 / selfHeight;
		vi.ty3f = vi.ty3 / selfHeight;
		vi.ty4f = vi.ty4 / selfHeight;
	}
	vi.mwidth = abs(vi.mx3 - vi.mx4); // bottom based
	vi.mheight = abs(vi.my2 - vi.mx3); // right based

	printf("%f,%f %f,%f %f,%f %f,%f %f%f,%f %f,%f %f,%f %f,%f %f\n", 
		vi.mx1, vi.my1,
		vi.mx2, vi.my2,
		vi.mx3, vi.my3,
		vi.mx4, vi.my4,
		vi.mangle,

		vi.tx1, vi.ty1,
		vi.tx2, vi.ty2,
		vi.tx3, vi.ty3,
		vi.tx4, vi.ty4,
		vi.tangle
	);

	m_bloods->m_vertex_items.clear();
	
	m_bloods->m_vertex_items.push_back(vi);

	ofstream myfile ("example.txt",  ios::app );
	  if (myfile.is_open())
	  {
		char a[666];

	sprintf_s(a, "%f,%f %f,%f %f,%f %f,%f %f%f,%f %f,%f %f,%f %f,%f %f\n",  
		vi.mx1, vi.my1,
		vi.mx2, vi.my2,
		vi.mx3, vi.my3,
		vi.mx4, vi.my4,
		vi.mangle,

		vi.tx1, vi.ty1,
		vi.tx2, vi.ty2,
		vi.tx3, vi.ty3,
		vi.tx4, vi.ty4,
		vi.tangle
	);

	myfile << a;
		myfile.close();
	  }
	  else cout << "Unable to open file";

}





TargetEntity::TargetEntity(){
	x = 0;
	y = 0;
	
	setWidthHeight(10,10);

	in_ain = false;
}




void TargetEntity::setWidthHeight(float w, float h){
	this->w = w;
	this->h = h;

	this->life = h * (w * 2);

	this->points = h * (w - 1);
}
