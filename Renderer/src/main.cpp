/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL OpenGL, standard IO, and, strings
#ifdef _WIN32
    #include <SDL.h>
#else
    #include "SDL2/SDL.h"
#endif

#include <stdio.h>
#include <string>
#include "GLUtils.h"
#include "Shapes.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Input handler
void handleKeys( unsigned char key, int x, int y );

//Per frame update
void update();

//Renders quad to the screen
void render();

//Frees media and shuts down SDL
void close();
//Render flag
bool gRenderQuad = true;


void handleKeys( unsigned char key, int x, int y )
{
  //Toggle quad
  if( key == 'q' )
    {
      gRenderQuad = !gRenderQuad;
    }
}

void update()
{
  //No per frame update needed
}

void render()
{
  //Clear color buffer
  glClear( GL_COLOR_BUFFER_BIT );
  
  Rectangle1 rect(Point(-50, -50), 100, 100);
  rect.draw();
}

void close()
{
  //Destroy window
  SDL_DestroyWindow( BasicWindow::getWindow() );
  BasicWindow::setWindow(NULL);
  
  //Quit SDL subsystems
  SDL_Quit();
}

int main( int argc, char* args[] )
{
  //Start up SDL and create window
  if( !GLUtils::initGraphics(SCREEN_WIDTH, SCREEN_HEIGHT)) //init() )
    {
      printf( "Failed to initialize!\n" );
    }
  else
    {
      //Main loop flag
      bool quit = false;
      
      //Event handler
      SDL_Event e;
      
      //Enable text input
      SDL_StartTextInput();
      
      //While application is running
      while( !quit )
	{
	  //Handle events on queue
	  while( SDL_PollEvent( &e ) != 0 )
	    {
	      //User requests quit
	      if( e.type == SDL_QUIT )
		{
		  quit = true;
		}
	      //Handle keypress with current mouse position
	      else if( e.type == SDL_TEXTINPUT )
		{
		  int x = 0, y = 0;
					SDL_GetMouseState( &x, &y );
					handleKeys( e.text.text[ 0 ], x, y );
		}
	    }
	  
	  //Render quad
	  render();
	  
	  //Update screen
	  SDL_GL_SwapWindow( BasicWindow::getWindow() );
	}
      
      //Disable text input
      SDL_StopTextInput();
    }
  
  //Free resources and close SDL
  close();
  
  return 0;
}
