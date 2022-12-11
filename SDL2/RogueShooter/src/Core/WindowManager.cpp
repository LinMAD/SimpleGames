#include "WindowManager.h"
#include <stdexcept>

void WindowManager::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		throw std::runtime_error("Unable to init window manager, error: " + *SDL_GetError());
	}

	m_window = SDL_CreateWindow(
		m_title, 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		640, 
		480, 
		SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_MOUSE_FOCUS
	);
	if (!m_window)
	{
		throw std::runtime_error("Unable to create window manager, error: " + *SDL_GetError());
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer)
	{
		throw std::runtime_error("Unable to create renderer for winndow manager, error: " + *SDL_GetError());
	}
}
