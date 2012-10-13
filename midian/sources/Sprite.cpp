#include "Sprite.h"
#include <iostream>

using namespace std;

Sprite::Sprite(){
	m_x = m_y = m_angle = 0.0f;

	m_textureName = 0;

	m_width = m_height = 0;

	m_rotate_spot    = Sprite::origin_center;//Sprite::origin_center;

	m_sprite_type = st_normal;
}

Sprite::~Sprite(){
	if (m_textureName){
		glDeleteTextures(1, &m_textureName);
	}
}

bool Sprite::LoadFromFile(char* filename){

	// Read texture file
	SDL_RWops* textureFile = SDL_RWFromFile(filename, "rb");

	// Load the image 
	SDL_Surface* image = IMG_Load_RW(textureFile, TRUE);
	if(!image) {
		printf("IMG_Load_RW: %s\n", IMG_GetError());
		return false;
	}

	m_width  = image->w;
	m_height = image->h;

	GLenum format;
	if (image->format->BytesPerPixel == 4 ){
		if (image->format->Rmask == 0x000000ff)
			format = (GL_RGBA);
		else
			format = (GL_BGRA);
	}else{
		if (image->format->Rmask == 0x000000ff)
			format = (GL_RGB);
		else
			format = (GL_BGR);
	}

	GLenum type;
	if (image->format->BytesPerPixel == 4 ){
		#if __BIG_ENDIAN__
			type = (GL_UNSIGNED_INT_8_8_8_8);
		#else
			type = (GL_UNSIGNED_INT_8_8_8_8_REV);
		#endif
	}else{
		type = (GL_UNSIGNED_BYTE);		
	}

	// Set PixelStore
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// Gen new texture
	glGenTextures(1, &m_textureName);
	
	// active it
	glBindTexture(GL_TEXTURE_2D, m_textureName);

	// Configure it
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

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
	glTexImage2D(GL_TEXTURE_2D, 0, image->format->BytesPerPixel, m_width, m_height, 0, format, type, image->pixels);
	printf("Loading sprite %s\n", filename);
	
   {char *errors = NULL;
    GLenum error;
    /* Get all errors. */
    while ((error = glGetError()) != GL_NO_ERROR) {
        char *error_msg;
        bool unknown_error = FALSE;
        error_msg = (char *) gluErrorString(error);
	
		printf(" -- ERROR WHILE LOADING SPRITE: %i %s\n", error, error_msg);
	}
	free(errors);}

	// free image
	SDL_FreeSurface(image);

	return true;
}



SimpleImage::SimpleImage(){
	m_x = 0;
	m_y = 0;
	image = NULL;
}

SimpleImage::~SimpleImage(void){
	if(image != NULL)
		SDL_FreeSurface(image);
}

bool SimpleImage::LoadFromFile(char* filename){
	SDL_RWops* textureFile = SDL_RWFromFile(filename, "rb");

	// Load the image 
	image = IMG_Load_RW(textureFile, TRUE);
	if(!image) {
		printf("IMG_Load_RW: %s\n", IMG_GetError());
		return false;
	}

	return true;
}

bool SimpleImage::is_not_white(int px, int py){
	if (image == NULL) return false;

	py = (py - m_y);
	px = (px - m_x);

	if ((px < 0|| py < 0 || py > image->h || px > image->w)) return false;

    //Convert the pixels to 8 bit
	Uint8 *pixels = (Uint8 *)image->pixels;
    
    //Get the requested pixel
	return (pixels[4*(py*image->w + px) + 3] > 128);

}

