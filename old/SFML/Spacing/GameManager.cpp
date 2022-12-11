#include <iostream>
#include "GameManager.h"

void GameManager::initWindow()
{
	_window = new RenderWindow(
		VideoMode(500, 600),
		"Spacing",
		Style::Close | Style::Titlebar
	);

	_window->setFramerateLimit(150);
	_window->setVerticalSyncEnabled(true);
}

void GameManager::initTextures()
{
	_textures["PLAYER_BULLET"] = new Texture();
	if (!_textures["PLAYER_BULLET"]->loadFromFile("assets/sprites/Projectile.png"))
		std::cout << "Error::Game::Bullet -> Failed to load Projectile sprite\n";

	_textures["ENEMY_BULLET"] = new Texture();
	if (!_textures["ENEMY_BULLET"]->loadFromFile("assets/sprites/Projectile_enemy.png"))
		std::cout << "Error::Game::Bullet -> Failed to load Projectile_enemy sprite\n";

	_textures["BACKGROUND"] = new Texture();
	if (!_textures["BACKGROUND"]->loadFromFile("assets/sprites/Background.png"))
		std::cout << "Error::Game::Background -> Failed to load Background sprite\n";
	else
		_background.setTexture(*_textures["BACKGROUND"]);
}

void GameManager::initPlayer()
{
	_player = new Player();
	_player->setPosition(Vector2f(_window->getSize().x >> 1, _window->getSize().y));
}

void GameManager::initEnemies()
{
	_spawnTimeMax = 30.f;
	_spawnTime = _spawnTimeMax;
}

void GameManager::initGui()
{
	_gui = new UserInterface(_player, _window->getSize());
}

GameManager::GameManager()
{
	initWindow();
	initTextures();
	initPlayer();
	initEnemies();
	initGui();
}

GameManager::~GameManager()
{
	delete _window;
	delete _player;

	for (auto& t : _textures) delete t.second;
	for (auto* b : _bullets) delete b;
	for (auto* e : _enemies) delete e;
}

void GameManager::run()
{
	while (_window->isOpen())
	{
		upldatePoolEvents();

		if (!_window->hasFocus()) continue;
		if (!_player->isDead()) update();

		render();
	}
}

void GameManager::upldatePoolEvents()
{
	Event e;
	while (_window->pollEvent(e))
	{
		if (e.type == Event::Closed)
		{
			_window->close();
		}

		if (e.KeyPressed && e.key.code == Keyboard::Escape)
		{
			_window->close();
		}
	}
}

void GameManager::updateIntput()
{
	// Movements
	if (Keyboard::isKeyPressed(Keyboard::A))
		_player->move(-1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		_player->move(1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::W))
		_player->move(0.f, -1.f);
	if (Keyboard::isKeyPressed(Keyboard::S))
		_player->move(0.f, 1.f);

	// Shooting
	if (Mouse::isButtonPressed(Mouse::Left) && _player->isCanAttack())
	{
		Bullet* b = new Bullet(
			_textures["PLAYER_BULLET"],
			Vector2f(_player->getPosition().x, _player->getPosition().y - 50),
			Vector2f(0.f, -1.f),
			5.f
		);
		b->setIsPlayerSource(true);
		_bullets.push_back(b);
	}
}

void GameManager::updateBullets()
{
	unsigned counter = 0;

	for (auto* b : _bullets)
	{
		b->update();

		bool isOutsideScreen = b->getBounds().top + b->getBounds().height <= 0.f || b->getBounds().top + b->getBounds().height >= _window->getSize().y;
		if (isOutsideScreen)
		{
			delete _bullets.at(counter);
			_bullets.erase(_bullets.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void GameManager::updateEnemies()
{
	_spawnTime += 1.f;

	if (_spawnTime >= _spawnTimeMax)
	{
		Enemy* enemy = new Enemy(
			Vector2f(rand() % _window->getSize().x - 100.f, -150.f)
		);

		updateCollision(enemy);
		enemy->setPosition(Vector2f(enemy->getPosition().x + 50, enemy->getPosition().y));
		_enemies.push_back(enemy);
		_spawnTime = 0.f;
	}

	unsigned counter = 0;
	for (auto* e : _enemies)
	{
		e->update();

		if (e->isCanAttack())
			_bullets.push_back(new Bullet(
				_textures["ENEMY_BULLET"],
				Vector2f(e->getPosition().x, e->getPosition().y + 50),
				Vector2f(0.f, -1.f),
				-5.f
			));

		// They moving to outside screen from top
		if (e->getBounds().top >= _window->getSize().y)
		{
			_player->takeDamage(e->getDamage());

			delete _enemies.at(counter);
			_enemies.erase(_enemies.begin() + counter);
			--counter;
		}
		// They hit with player
		else if (e->getBounds().intersects(_player->getBounds()))
		{
			_player->takeDamage(e->getDamage());

			delete _enemies.at(counter);
			_enemies.erase(_enemies.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void GameManager::updateCombat()
{
	for (int ei = 0; ei < _enemies.size(); ++ei)
	{
		bool isEnemyDead = false;

		// It's time for pew pew
		for (int bi = 0; bi < _bullets.size() && isEnemyDead == false; ++bi)
		{
			if (_bullets[bi]->isSourceFromPlayer() && _enemies[ei]->getBounds().intersects(_bullets[bi]->getBounds()))
			{
				_player->addScorePoints(_enemies[ei]->getScorePoint());

				delete _enemies[ei];
				_enemies.erase(_enemies.begin() + ei);

				isEnemyDead = true;

				delete _bullets[bi];
				_bullets.erase(_bullets.begin() + bi);
			}

			if (!isEnemyDead && !_bullets[bi]->isSourceFromPlayer() && _player->getBounds().intersects(_bullets[bi]->getBounds()))
			{
				_player->takeDamage(_enemies[ei]->getDamage());

				delete _bullets[bi];
				_bullets.erase(_bullets.begin() + bi);
			}
		}
	}
}

void GameManager::updateCollision(AbstractProp* prob)
{
	// Left & right
	if (prob->getBounds().left < 0.f)
		prob->setPosition(
			Vector2f(0.f, prob->getBounds().top)
		);
	else if (prob->getBounds().left + prob->getBounds().width >= _window->getSize().x)
		prob->setPosition(
			Vector2f(_window->getSize().x - prob->getBounds().width, prob->getBounds().top)
		);

	// Top and bot
	if (prob->getBounds().top < 0.f)
		prob->setPosition(
			Vector2f(prob->getBounds().left, 0.f)
		);
	else if (prob->getBounds().top + prob->getBounds().height >= _window->getSize().y)
		prob->setPosition(
			Vector2f(prob->getBounds().left, _window->getSize().y - prob->getBounds().height)
		);
}

void GameManager::update()
{
	updateIntput();

	_player->update();
	updateCollision(_player);

	updateBullets();
	updateEnemies();
	updateCombat();

	_gui->update();
}

void GameManager::render()
{
	_window->clear();
	_window->draw(_background);

	_player->render(_window);

	for (auto* b : _bullets) b->render(_window);

	for (auto* e : _enemies) e->render(_window);

	_gui->render(_window);

	if (_player->isDead())
		_gui->showGameOver(_window);

	_window->display();
}
