#pragma once
#include <GL/freeglut.h>
#include <string>
class Textura {
public:
	Textura() : w(0), h(0), id(0) {};
	~Textura() { glDeleteTextures(1, &id); };
	void init() {
		glGenTextures(1, &id); // generar un nombre
		activar(); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)/*�*/;
	}; // establecer filtros
	void activar() {
		glBindTexture(GL_TEXTURE_2D, id); 
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE/*�*/); 
	};

	void desactivar() { 
		glBindTexture(GL_TEXTURE_2D, 0); 
	};
	bool load(const std::string & BMP_Name); // cargar y transferir a openGL
	void save(const std::string & BMP_Name); // obtener de openGL y guardar
public:
	GLuint w, h; // dimensiones de la imagen
	GLuint id; // identificador interno de la textura
	GLubyte* pA;
	//CText2
};

