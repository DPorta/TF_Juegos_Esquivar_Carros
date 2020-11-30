#include "Window.h"
#include "Error.h"


Window::Window()
{
}

void Window::swapBuffer() {
	SDL_GL_SwapWindow(_window);
}

int Window::create(string windowName, int screenWidth, int screenHeight, unsigned int currentFlags) {
	Uint32 flags = SDL_WINDOW_OPENGL;

	if (currentFlags & INVISBLE) {
		flags |= SDL_WINDOW_HIDDEN;
	}
	if (currentFlags & FULLSCREEN) {
		flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
	}
	if (currentFlags & BORDERLESS) {
		flags |= SDL_WINDOW_BORDERLESS;
	}

	_window = SDL_CreateWindow("Juego de Esquivar Carros", 600, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);
	if (_window == nullptr) {
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);

	GLenum error = glewInit();
	if (error != GLEW_OK) {

	}

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	SDL_GL_SetSwapInterval(0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return 0;
}


Window::~Window()
{
}
