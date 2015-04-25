#ifndef BASICWINDOW_H_INCLUDED
#define BASICWINDOW_H_INCLUDED

#include "SDL2/SDL.h"
#include "Logger.h"

class BasicWindow
{

  static SDL_Window* _gWindow;
public:
  static SDL_Window* getWindow();

    static void setWindow(SDL_Window *gWindow);
    static bool initWindow(int _SCREEN_WIDTH, int _SCREEN_HEIGHT);
    //Screen dimension constants
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    static const int SCREEN_FPS = 60;
};

//Screen dimension constants
int BasicWindow::SCREEN_WIDTH;
int BasicWindow::SCREEN_HEIGHT;
const int BasicWindow::SCREEN_FPS;

SDL_Window* BasicWindow::_gWindow;

SDL_Window* BasicWindow::getWindow()
{
    return _gWindow;
}

void BasicWindow::setWindow(SDL_Window *gWindow)
{
    _gWindow = gWindow;
}


bool BasicWindow::initWindow(int _SCREEN_WIDTH, int _SCREEN_HEIGHT)
{
	SCREEN_WIDTH = _SCREEN_WIDTH;
	SCREEN_HEIGHT = _SCREEN_HEIGHT;

    //OpenGL context
    SDL_GLContext gContext;

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 )
	{
		//printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Use OpenGL 2.1
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

		//Create window
		setWindow(SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN ));
		if( getWindow() == NULL )
		{
			Logger::write("Window could not be created! SDL Error: ");
			Logger::write(SDL_GetError());
			//printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create context
			gContext = SDL_GL_CreateContext( getWindow() );
			if( gContext == NULL )
			{
				Logger::write("OpenGL context could not be created! SDL Error: ");
				Logger::write(SDL_GetError());
				//printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Use Vsync
				if( SDL_GL_SetSwapInterval( 1 ) < 0 )
				{
					Logger::write("Warning: Unable to set VSync! SDL Error: ");
					Logger::write(SDL_GetError());
					//printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
				}

				//Initialize OpenGL
//				if( !initGL() )
//				{
//					Logger::write("Unable to initialize OpenGL!\n");
//					printf( "Unable to initialize OpenGL!\n" );
//					success = false;
//				}
			}
		}
	}

	return success;
}


#endif // BASICWINDOW_H_INCLUDED
