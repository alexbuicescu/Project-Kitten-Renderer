/**
    OpenglHeaders.h
    Purpose: Includes all the necessary libraries
    for the OpenGL to work properly.

    @author Alex Buicescu
    @version 1.0
*/
#ifndef OPENGLHEADERS_H_INCLUDED
#define OPENGLHEADERS_H_INCLUDED

#ifdef _WIN32
	#define GLEW_STATIC
	#include "GL/glew.h"
#else
	#include "GL/glew.h"
	#include <GL/glut.h>
#endif

#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>


#endif // OPENGLHEADERS_H_INCLUDED
