#pragma once
#include <map>
#include <string>
#include <SDL2/SDL.h>

class AssetManager {
public:
    AssetManager(SDL_Renderer* renderer) {
        m_renderer = renderer;
    }

    ~AssetManager() {
        for (auto& kv : m_textures) {
            SDL_DestroyTexture(kv.second);
        }
    }

    void AddTexture(
        const std::string& name,
        const std::string& file_name,
        const SDL_FPoint texture_size
    );

    inline SDL_Texture* GetTexture(const std::string& name) {
        return m_textures[name];
    };

    inline SDL_FPoint* GetTextureSize(const std::string& name) {
        return &m_textureSize[name];
    };

private:
    SDL_Renderer* m_renderer;

    std::map<std::string, SDL_Texture*> m_textures;
    /// <summary>
    /// x represents width and y represetns height
    /// </summary>
    std::map<std::string, SDL_FPoint> m_textureSize;
};
