#pragma once
#include <SDL2/SDL.h>

class WindowManager
{
public:
	inline WindowManager() {};
	inline WindowManager(const char* title) {
		m_title = title;
	}

	inline ~WindowManager() {
		if (m_renderer != nullptr) {
			SDL_DestroyRenderer(m_renderer);
		}

		if (m_window != nullptr) {
			SDL_DestroyWindow(m_window);
		}

		SDL_Quit();
	}

	void Init();

	inline SDL_Window* GetWindow() { return m_window; }
	inline SDL_Renderer* GetRenderer() { return m_renderer; }
private:
	const char* m_title = "Game Window";

	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
};
