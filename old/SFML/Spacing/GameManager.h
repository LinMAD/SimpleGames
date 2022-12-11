#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "UserInterface.h"

using namespace sf;

class GameManager
{
private:
	RenderWindow* _window;

	Sprite _background;

	std::map<std::string, Texture*> _textures;
	std::vector<Bullet*> _bullets;
	UserInterface* _gui;

	Player* _player;
	std::vector<Enemy*> _enemies;

	float _spawnTime, _spawnTimeMax;

	void initWindow();
	void initTextures();
	void initPlayer();
	void initEnemies();
	void initGui();
public:
	GameManager();
	~GameManager();

	void run();

	void upldatePoolEvents();
	void updateIntput();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void updateCollision(AbstractProp* prob);
	void update();
	void render();
};

