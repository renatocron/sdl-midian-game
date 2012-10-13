#include "WordStateMenu.h"
#include "global.h"
#include "appl.h"
#include "SDL_opengl.h"
#include "Render.h"
#include <math.h>
#include "WordStateCutter.h"
#include "WordStateCandy.h"

//************ TEMP   ********

using namespace std;


WordStateMenu::WordStateMenu(): WordState(){
	m_cur_bar_position = 0;

	m_spr = new Sprite();
//	m_spr->LoadFromFile("data/png/i0.png");

	m_skull = new Sprite();
	m_skull->SetAngle(45);
	m_skull->LoadFromFile("data/png/skull.png");
	

	m_choose = new Sprite();
	m_choose->LoadFromFile("data/png/choose.png");

	m_cut_the_photo = new Sprite();
	m_cut_the_photo->LoadFromFile("data/png/cut_the_photo.png");

	m_cut_the_photo_collision = new SimpleImage();
	m_cut_the_photo_collision->LoadFromFile("data/png/cut_the_photo_collision.png");

	m_mario = new Sprite();
	m_mario->LoadFromFile("data/png/mario.png");

	m_mario_collision = new SimpleImage();
	m_mario_collision->LoadFromFile("data/png/mario_collision.png");

	m_candy = new Sprite();
	m_candy->LoadFromFile("data/png/candy_menu.png");

	m_candy_collision = new SimpleImage();
	m_candy_collision->LoadFromFile("data/png/candy_menu_collision.png");

	m_skull_menu = new Sprite();
	m_skull_menu->LoadFromFile("data/png/skull_menu.png");
	
	this->OnResize(__GAME__()->get_width(),__GAME__()->get_height());




	int n = 1;
	
//	int NumVertices = (((Appl::Instance()->getAppl()->get_width()/2)*(Appl::Instance()->getAppl()->get_height())) / n);

	/*m_va_left = new PointMatrixArray(512, 512, 1);
	//m_va_left = new PointMatrixArray(64, 64);

	m_va_left->Clean(1,0,0,1);
	//Render::SVertex2D* Vertices = m_va_left->GetArray();
*/
	//int x = 0, y = 0;
	//m_va_left->SetPixel(63, 63, 0, 1, 1);
/*
	for (int i = 0; i < NumVertices; i++)
	{		
			Vertices[i].x = (float)x+1;
			Vertices[i].y = (float)y+1;
		
			Vertices[i].r = 1.f;
			Vertices[i].g = 1.f;
			Vertices[i].b = 1.f;
			Vertices[i].a = 0.01f + ((float)y / (768.f*3.f));
		
		x+=n;
		if(x > Appl::Instance()->getAppl()->get_width()/2) {
		x = 1;y+=n;	
		}
	}
*/

	angle =0;
	//free(Vertices2);
	glEnable(GL_LINE_SMOOTH);
	
	//glPointSize((float)m_va_left->GetSkip() );
	



	current_font = 1;
	myString = "OpenGL is atenção ";
}

WordStateMenu::~WordStateMenu(){
	delete m_spr;
	delete m_skull;
	delete m_skull_menu;
	delete m_cut_the_photo;
	delete m_cut_the_photo_collision;

	delete m_candy;
	delete m_candy_collision;

	delete m_mario;
	delete m_mario_collision;
	//delete m_va_left;
}

void WordStateMenu::OnLoop(){
	
	m_cur_bar_position += 5;

	if(m_cur_bar_position > Appl::Instance()->getAppl()->get_width()){
		m_cur_bar_position = -100;
		current_font = current_font ? 0 : 1;
	}
	/*
	int max_x = m_va_left->GetWidth();
	int max_y = m_va_left->GetHeight(); 
	int NumVertices = max_y * max_x;
	int x = 0; int y = 0;
	Render::SVertex2D* Vertices = m_va_left->GetArray();

	int pogx = last_mouse_x;
	int pogy = last_mouse_y;
	last_mouse_x /= m_va_left->GetSkip();
	last_mouse_y /= m_va_left->GetSkip();
	
	static bool need_loop = true;
	static int last_mouse_pos_x = last_mouse_x;
	static int last_mouse_pos_y = last_mouse_y;
	static int overloops = 0;


	if (last_mouse_pos_x != last_mouse_x || last_mouse_pos_y != last_mouse_y){
		last_mouse_pos_y = last_mouse_y;
		last_mouse_pos_x = last_mouse_x;
		overloops = 0;
		need_loop = true;
	}
	if(need_loop || overloops < 1000){
		overloops++;
		for (int i = 0; i < NumVertices; i++){		
			
			Vertices[i].a = Vertices[i].a <= 0.1f ? 0.1f : Vertices[i].a - 0.01f;

				int dist = abs(last_mouse_y - y);
				float gain = (float)dist / ((float)max_y *2.f);
				Vertices[i].a += gain;

				dist = abs(last_mouse_x - x);
				gain = (float)dist / ((float)max_x /4.f);

				Vertices[i].a -= gain;

				if (Vertices[i].a > 0.6f){
					Vertices[i].r += 0.08f;
					Vertices[i].g += 0.02f;
					Vertices[i].b += 0.01f;
					
					if(Vertices[i].r>1) Vertices[i].r =1;
					if(Vertices[i].g>1) Vertices[i].g =1;
					if(Vertices[i].b>1) Vertices[i].b =1;

				}
		
			Vertices[i].r = Vertices[i].r < 0 ? 0 : Vertices[i].r - 0.01f;
			Vertices[i].g = Vertices[i].g < 0 ? 0 : Vertices[i].g - 0.01f;
			Vertices[i].b = Vertices[i].b < 0 ? 0 : Vertices[i].b - 0.01f;
//Vertices[i].a =1;
			x+=1;
			if(x >= max_x) {
				x = 0;
				y+=1;
			}

		}
		last_mouse_x = pogx;
	last_mouse_y = pogy;

	}*/
/*
	
	int max_x = m_va_left->GetWidth();
	int s = m_va_left->GetSkip();
	int left = (Appl::Instance()->getAppl()->get_width() / 2) - (m_va_left->GetWidth() * m_va_left->GetSkip() / 2);
	int NumVertices = m_va_left->GetHeight() * max_x;
	Render::SVertex2D* Vertices = m_va_left->GetArray();
	/*for (int i = 0; i < NumVertices; i++){		
		
		Vertices[i].r = 0;
		Vertices[i].g = 0;
		Vertices[i].b = (int)last_mouse_x / s == 
			(
			
			30 + left
			
			) / s ? 0.6f : 1;
		
	}*/
	//m_va_left->Clean(cosf(angle),1,1,0.5);
	
	//angle = 0.0f;
	angle += 2;
	if(angle > 360.f) angle = 0.0f;

	
}

void WordStateMenu::OnRender(float pInterpolation){

	const float objHeight = 120.0f;
	const float ojbTop    = 100.0f;
	const float objLeft   = static_cast<float>(m_cur_bar_position) + ( 1.0f * pInterpolation);
	const float objWidth  = 100.0f;
	
	//render->ActiveTextures();
	glColor4f(1.f, 1.f, 1.f, 1.f);
	
/*
	render->DisableTextures();
	
	glBegin(GL_LINES);
	glColor4f(0.4f, 0.4f, 0.4f, 1.f);
	glLineWidth(1.0f);
	for (int a = 0; a < Appl::Instance()->getAppl()->get_width(); a += 32){
		glVertex2f((float)a, 0);
		glVertex2f((float)a, (float)Appl::Instance()->getAppl()->get_height());
	}

	for (int y = 0; y < Appl::Instance()->getAppl()->get_height(); y += 32){
		glVertex2f(0, (float)y);
		glVertex2f((float)Appl::Instance()->getAppl()->get_width(), (float)y);
	}
	
	glColor4f(0.9f, 0.9f, 0.9f, 1.f);
	for (int a = 0; a < Appl::Instance()->getAppl()->get_width(); a += 64){
		glVertex2f((float)a, 0);
		glVertex2f((float)a, (float)Appl::Instance()->getAppl()->get_height());
	}

	for (int y = 0; y < Appl::Instance()->getAppl()->get_height(); y += 64){
		glVertex2f(0, (float)y);
		glVertex2f((float)Appl::Instance()->getAppl()->get_width(), (float)y);
	}
	glEnd();
*/
	
	render->ActiveTextures();
	//glColor4f(1.f,1.f,1.f,0.5);
	m_spr->SetAngle(angle);
	
		glColor4f(1.f,1.f,1.f,1);
	
	m_spr->SetXY(30, 40);
	//render->DrawSprite(m_spr);
	/*
	*/
	/*
	m_spr2->SetAngle(angle - 5);
	for (int a = 100; a < 700; a+=80){
		for (int i = 0; i < 480; i+=20){
			m_spr2->SetX(i * 2.0f);
			m_spr2->SetY(cosf(i * 5.f) * 55.0f + a);

			glColor4f(1.f,1.f,1.f,cosf((float)a) * sinf(objLeft / (10*cosf((float)Const::PI))) );

			render->DrawSprite(m_spr2);			
		}
	}
	glColor4f(1,1,1,1);	
*/


//	render->DrawRect(objLeft, ojbTop,  objWidth, objHeight);

	
	m_spr->SetAngle(0);
	m_spr->SetXY(64, 64);
	render->DrawSprite(m_spr);

	
	render->DrawSprite(m_skull);
	render->DrawSprite(m_choose);
	
	render->DrawSprite(m_cut_the_photo);

	render->DrawSprite(m_mario);
	render->DrawSprite(m_candy);

	if(m_selected_menu==0){
		glColor4f(1.0, 1.0, 1.0, 1.f);
	}else{
		glColor4f(1.0, 0.0, 0.0, 1.f);
	}
	render->DrawSprite(m_skull_menu);

	glColor4f(1.0, 1.0, 1.0, 1.f);

	render->DisableTextures();

	//render->DrawRoundRect((float)m_cur_bar_position, 64.f*2.5,  64.f, 64.f, 4, true, angle);
	glColor4f(1.f,0.f,0.f,0.5f);

	glLineWidth(1.0f);
	//render->DrawRoundRect(64.f, 0,  64.f, 64.f, 16.f);

	//render->DrawRoundRect(64.f*2, 0,  64.f, 64.f, 16.f, false);

	glColor4f(0.f,1.f,1.f,0.5f);
	//render->DrawRect((float)last_mouse_x, (float)last_mouse_y, 64.f, 64.f, true, angle);

	//render->DrawRect(64.f*3, 0,  64.f, 64.f, false);

	//if(m_cur_bar_position < 400)
	render->ActiveTextures();
	//glPointSize((float)m_va_left->GetSkip());
	//glDisable(GL_POINT_SMOOTH);

	glColor4f(1.0, 1.0, 1.0, 1.f);
/*
	m_va_left->DrawArray((float)(
		(Appl::Instance()->getAppl()->get_width() / 2) - (m_va_left->GetWidth() * m_va_left->GetSkip() / 2)
	), (float)-(m_va_left->GetHeight() * m_va_left->GetSkip() ) + 1.0f - 250.0f);
*/
	//glEnable(GL_POINT_SMOOTH);
/*
	render->ActiveTextures();
	glColor4f(1.f,1.f,1.f,1.f);
	m_spr->SetAngle(angle);
	for (int a = 0; a < Appl::Instance()->getAppl()->get_width(); a+=64){
		for (int i = 0; i < Appl::Instance()->getAppl()->get_height(); i+=64){
			//m_spr->SetX(i * 2.0f);
			//m_spr->SetY(cosf(i * 5.f) * 55.0f + a); 
			
			Sprite* some = m_spr;
			some->SetXY((float)a, (float)i);
			//glColor4f(1.f,1.f,1.f,1);
			const int m =64;
			int distance_y = (i - last_mouse_y);
				if ( (a / m) + 2 > (last_mouse_x / m) && (a / m) - 2 < (last_mouse_x / m) ){ 

				if ( (i / m) + 2 > (last_mouse_y / m) && (i / m) - 2 < (last_mouse_y / m) ){ 
					
					int distance_x = (a - last_mouse_x);
					
					some = m_spr2;
					some->SetAngle(angle);
					some->SetXY((float)a+(cosf(distance_x * (float)Const::PI/90.f) * m), 
						(float)i + (sinf(distance_y * (float)Const::PI/90.f) * m));	

					//glColor4f(1.f,1.f,1.f,cosf(distance_y) );

				}
			}

			render->DrawSprite(some);
		}
	}*/

	/*
	glColor3f(col,col,col );

	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glTranslatef(0.5,0.5,0.0);
	glRotatef(angle,0.0,0.0,1.0);
	//m_tex->DrawNoFlush(objLeft + (cosf(objLeft)  * 0.8f), ojbTop + 32.0f + (sinf(objLeft * 0.2f)  * (32.0f)), 64.0f, 64.0f);
	
	//m_tex->DrawNoFlush(300.0f, 200.0f, objHeight*5, objWidth*5);

	glTranslatef(-0.5,-0.5,0.0);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW); 
	glColor3f(1.0f,1.0f,1.0f);
*/ 

/*
string teste = "FPS: ";
		teste += Global::IntToStr(Appl::Instance()->getAppl()->FPSControl.GetFPS());
	//	infoFont->Render(teste.c_str());

	glPushMatrix();
		glColor4f(1.0, 1.0, 1.0, 1.f);
		glRasterPos2i(200, 100);
		fonts[1]->Render(teste.c_str());        
	glPopMatrix();
*/
	/*glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, Appl::Instance()->getAppl()->get_width(), 0, Appl::Instance()->getAppl()->get_height());
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
*/
    // draw mode
	glEnable(GL_TEXTURE_2D);
  

	/*
	glMatrixMode (GL_MODELVIEW);
    glViewport (0, 0, Appl::Instance()->getAppl()->get_width(), Appl::Instance()->getAppl()->get_height());
    glLoadIdentity();
	*/		
	
	
	
	m_spr->SetAngle(angle);
	m_spr->SetXY(64*2, 64);
	
	string teste = Global::FloatToStr(m_skull_menu->GetAngle());
	__GAME__()->writter->Draw("log", teste, 50.0f, 30.0f);
	
	glColor3f(cosf(angle/10.f), 1.0, 1.0);
//	render->DrawSprite(m_spr);
	

	
	glColor3f(1.0, 1.0, 1.0);

	/*
	glPushMatrix();
		// draw font type
		glPushMatrix();
		glTranslatef(2, (float)-(int)infoFont->LineHeight(),0);
		string teste = "FPS: ";
		teste += Global::IntToStr(Appl::Instance()->getAppl()->FPSControl.GetFPS());
		infoFont->Render(teste.c_str());
		glPopMatrix();

		glPushMatrix();glTranslatef(2, -(float)(infoFont->LineHeight()*2),0);
		teste = "LPS: ";
		teste += Global::IntToStr(Appl::Instance()->getAppl()->LPSControl.GetFPS());
		infoFont->Render(teste.c_str());
		glPopMatrix();

		glPushMatrix();glTranslatef(120, -(float)(infoFont->LineHeight()*1),0);
		teste = "num_bind_call: ";
		teste += Global::IntToStr(render->get_num_bind_call()+1);//+1 porque a fonte causa 1..., pelo menos...
		infoFont->Render(teste.c_str());glPopMatrix();

		glPushMatrix();glTranslatef(120, -(float)(infoFont->LineHeight()*2),0);
		teste = "num_draw_call: ";
		teste += Global::IntToStr(render->get_num_draw_call());
		infoFont->Render(teste.c_str());glPopMatrix();

		glPushMatrix();glTranslatef(300, -(float)(infoFont->LineHeight()*1),0);
		teste = "window size: ";
		teste += Global::IntToStr(Appl::Instance()->getAppl()->get_width()) + "x" +
				Global::IntToStr(Appl::Instance()->getAppl()->get_height());
		infoFont->Render(teste.c_str());glPopMatrix();
		
		glPushMatrix();

		glTranslatef(300, -(float)(infoFont->LineHeight()*2),0);
		teste = "mouse posição: ";

		teste += Global::IntToStr(last_mouse_x) + "/" +
				Global::IntToStr(last_mouse_y);
		
		infoFont->Render(teste.c_str());
		glPopMatrix();
	
	glPopMatrix();

	//glMatrixMode( GL_PROJECTION );
	//glLoadIdentity();
	 
	//glOrtho(0.0f, Appl::Instance()->getAppl()->get_width(), Appl::Instance()->getAppl()->get_height(), 0.0f, -1.0f, 1.0f);
		
	//glMatrixMode( GL_MODELVIEW );
	//glLoadIdentity();
	*/

	


	
    //infoFont->Render(file);
}



void WordStateMenu::OnLButtonUp(int mX, int mY){

	if (m_selected_menu == 1){
		WordState* ss = __GAME__()->m_cut_game_state;

		if (ss != NULL && ss != this){
			delete ss;
		}
		ss = new WordStateCutter();
		__GAME__()->SetWordState(ss);
	}else if (m_selected_menu == 3){
		WordState* ss = __GAME__()->m_cut_game_state;

		if (ss == NULL && ss != this){
			delete ss;
		}
		ss = new WordStateCandy();
		__GAME__()->SetWordState(ss);
	}

}

void WordStateMenu::OnResize(int w,int h){
	m_skull->SetXY(w-512.0f, h-512.0f);
	
	m_choose->SetXY(((w-512)/2.f), (h-128) * 0.1f);

	m_cut_the_photo->SetXY((w-512) * 0.2f, (h-220) * 0.3f );
	m_cut_the_photo_collision->SetXY((int)((w-512) * 0.2), (int)((h-220) * 0.3f));

	m_mario->SetXY((w-512) * 0.2f, (h-220) * 0.6f );
	m_mario_collision->SetXY((int)((w-512) * 0.2), (int)((h-220) * 0.6f));

	m_candy->SetXY((w-512) * 0.2f, (h-220) * 0.95f );
	m_candy_collision->SetXY((int)((w-512) * 0.2), (int)((h-220) * 0.95f));



	m_skull_menu->SetXY(((w-512) * 0.2f) - 80.f, ((h-220) * 0.75f));

}

void WordStateMenu::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle){
	m_selected_menu = 0;

	if (m_cut_the_photo_collision->is_not_white(mX, mY)){
		m_selected_menu = 1;
	}
	else if (m_mario_collision->is_not_white(mX, mY)){
		m_selected_menu = 2;
	}
	else if (m_candy_collision->is_not_white(mX, mY)){
		m_selected_menu = 3;
	}

	int w = __GAME__()->get_width();
	float h = (float)__GAME__()->get_height();

	/* angulos entre 2 vetores */
	float vector_x = m_skull_menu->GetX() - (float)last_mouse_x;
	float vector_y = m_skull_menu->GetY() - (float)last_mouse_y;
	float up_x = 0.0f;
	float up_y = 1.0f;

	float vector_length = sqrt(vector_x*vector_x+vector_y*vector_y);

	float up_length = sqrt(up_x*up_x+up_y*up_y);

	float dot = vector_x * up_x + vector_y * up_y;
		
	float angle_by_mouse = (float)acosf(
			float( 
					dot / ( vector_length * up_length)
				)
			);

	angle_by_mouse = angle_by_mouse * 180.0f / float(Const::PI);

	// aki ja eh ajuste para ficar bom neste caso, mas o angulo eh o de cima
	angle_by_mouse = -(angle_by_mouse-90.0f);
	// limitando a 80
	angle_by_mouse = min(angle_by_mouse , 80.0f);
	angle_by_mouse = max(angle_by_mouse, -80.0f);
	// soh muda se o mouse estiver na frente da cara
	if (m_skull_menu->GetX() < (float)last_mouse_x){
		m_skull_menu->SetAngle(angle_by_mouse);
	}	

} 