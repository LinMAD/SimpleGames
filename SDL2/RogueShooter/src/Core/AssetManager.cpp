#include "AssetManager.h"
#include <stdexcept>
#include <fstream>

void AssetManager::AddTexture(const std::string& name, const std::string& file_name, const SDL_FPoint texture_size) {
	if (!std::ifstream(file_name).good()) {
		throw std::runtime_error("Failed to load texture: " + file_name);
	}

	SDL_Surface* surface = SDL_LoadBMP(file_name.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);

	m_textures[name] = texture;
	m_textureSize[name] = texture_size;

	SDL_FreeSurface(surface);
}

