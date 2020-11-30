#include <iostream>
#include <random>
#include <ctime>
#include "MainGame.h"
#include "Sprite.h"
#include "ImageLoader.h"
#include "ResourceManager.h"
#include "PapuEngine.h"


using namespace std;

void MainGame::run() {
	init();
	update();
}

void MainGame::init() {
	Papu::init();
	_window.create("Engine", _witdh, _height, 0);
	initShaders();
	initLevel();

}

void MainGame::initLevel() {
	_levels.push_back(new Level("Levels/Nivel_1_de_jueguitos.txt"));
	_player = new Player();
	_currentLevel = 0;
	_player->init(0.3f,
		_levels[_currentLevel]->getPlayerPosition(), &_inputManager);
	_spriteBacth.init();
	const std::vector<glm::vec2>& zombiesPosition = _levels[_currentLevel]->getZombiesPosition();
	const std::vector<glm::vec2>& vidasPosition = _levels[_currentLevel]->getVidaPosition();

	std::mt19937 randomEngine(time(nullptr));
	std::uniform_int_distribution<int>randPosX(1, _levels[_currentLevel]->getWidth() - 2);
	std::uniform_int_distribution<int>randPosY(1, _levels[_currentLevel]->getHeight() - 2);

	for (size_t i = 0; i < zombiesPosition.size(); i++)
	{
		_zombies.push_back(new Zombie());
		_zombies.back()->init(0.2f, zombiesPosition[i]);
	}
	for (size_t i = 0; i < vidasPosition.size(); i++)
	{
		_vidas.push_back(new Vidas());
		_vidas.back()->init(0.1f, vidasPosition[i]);
	}

}

void MainGame::initShaders() {
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}


void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();

	glActiveTexture(GL_TEXTURE0);

	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);

	_spriteBacth.begin();
	_levels[_currentLevel]->draw();


	for (size_t i = 0; i < _zombies.size(); i++)
	{
		_zombies[i]->draw(_spriteBacth);
	}
	for (size_t i = 0; i < _vidas.size(); i++)
	{
		_vidas[i]->draw(_spriteBacth);
	}

	_player->draw(_spriteBacth);

	_spriteBacth.end();
	_spriteBacth.renderBatch();

	glBindTexture(GL_TEXTURE_2D, 0);

	_program.unuse();
	_window.swapBuffer();
}

void MainGame::procesInput() {
	SDL_Event event;
	const float CAMERA_SPEED = 20.0f;
	const float SCALE_SPEED = 0.1f;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			_inputManager.setMouseCoords(event.motion.x, event.motion.y);
			break;
		case  SDL_KEYUP:
			_inputManager.releaseKey(event.key.keysym.sym);
			break;
		case  SDL_KEYDOWN:
			_inputManager.pressKey(event.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			_inputManager.pressKey(event.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			_inputManager.releaseKey(event.button.button);
			break;
		}

		if (_inputManager.isKeyPressed(SDL_BUTTON_LEFT)) {
			glm::vec2 mouseCoords = _camera.convertScreenToWorl(_inputManager.getMouseCoords());
			cout << mouseCoords.x << " " << mouseCoords.y << endl;
		}
	}
}

void MainGame::update() {
	int vidas = 3;
	while (_gameState != GameState::EXIT) {
		procesInput();
		draw();
		_camera.update();
		_time += 0.002f;
		_player->update(_levels[_currentLevel]->getLevelData(), _zombies);
		_camera.setPosition(glm::vec2(300.0f, 350.0f));

		for (size_t i = 0; i < _zombies.size(); i++)
		{
			_zombies[i]->update(_levels[_currentLevel]->getLevelData(), _zombies);

			if (_zombies[i]->collidedWithAgent(_player))
			{
				vidas -= 1;
				std::cout << "Chocaste con el chosicano, te quedan " << vidas << " vidas" << endl;
				_zombies.erase(_zombies.begin() + i);


				if (vidas == 0) {
					SDL_Quit();
					SDL_CreateWindow("GAMEOVER", 600, SDL_WINDOWPOS_CENTERED, 300, 5, SDL_WINDOW_OPENGL);
					return;
				}
			}

		}
		for (size_t i = 0; i < _vidas.size(); i++)
		{
			_vidas[i]->update(_levels[_currentLevel]->getLevelData(), _vidas);

			if (_vidas[i]->collidedWithAgent(_player))
			{
				vidas += 1;
				std::cout << "Encontraste una vida, ahora tienes " << vidas << " vidas" << endl;
				_vidas.erase(_vidas.begin() + i);
			}

		}
	}
}


MainGame::MainGame() :
	_witdh(1200),
	_height(800),
	_gameState(GameState::PLAY),
	_time(0)
{
	_camera.init(_witdh, _height);
}


MainGame::~MainGame()
{
}
