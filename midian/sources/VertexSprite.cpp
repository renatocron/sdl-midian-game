#include "VertexSprite.h"

#include <iostream>
#include <fstream>
#include <string>
#include "global.h"
using namespace std;


VertexSprite::VertexSprite(): Sprite(){

	setType(st_vertex);

}

VertexSprite::~VertexSprite(){
	
}

bool VertexSprite::LoadVertexFromFile(char* filename){

	string eachLine;
	ifstream infile;
	infile.open(filename);

	if (infile.is_open()){
		m_vertex_items.clear();

		while(!infile.eof()){
			getline(infile, eachLine);
			Global::trim(eachLine);

			if (eachLine.empty()){continue;}

			// 0,0 200,0 200,180 0,180:0 => 0,0 200,0 200,180 0,180:45
			
			VertexSpriteItem vsi;

			sscanf_s(eachLine.c_str(), "%f,%f %f,%f %f,%f %f,%f %f %f,%f %f,%f %f,%f %f,%f %f",
					&vsi.mx1, &vsi.my1, &vsi.mx2, &vsi.my2, &vsi.mx3, &vsi.my3, &vsi.mx4, &vsi.my4, &vsi.mangle,
					&vsi.tx1, &vsi.ty1, &vsi.tx2, &vsi.ty2, &vsi.tx3, &vsi.ty3, &vsi.tx4, &vsi.ty4, &vsi.tangle);
			
			vsi.mwidth = abs(vsi.mx3 - vsi.mx4); // bottom based
			vsi.mheight = abs(vsi.my2 - vsi.mx3); // right based
			
			float selfWidth = (float)GetWidth();
			if (selfWidth){
				
				vsi.tx1f = vsi.tx1 / selfWidth;
				vsi.tx2f = vsi.tx2 / selfWidth;
				vsi.tx3f = vsi.tx3 / selfWidth;
				vsi.tx4f = vsi.tx4 / selfWidth;

				float selfHeight = (float)GetHeight();
				vsi.ty1f = vsi.ty1 / selfHeight;
				vsi.ty2f = vsi.ty2 / selfHeight;
				vsi.ty3f = vsi.ty3 / selfHeight;
				vsi.ty4f = vsi.ty4 / selfHeight;
			}

			m_vertex_items.push_back(vsi);
		}
		infile.close();
	}else{
		return false;
	}

	return true;
}