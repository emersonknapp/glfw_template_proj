#pragma once

#include "thing.h"
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

class Game
{
public:
	Game();
	void Initialize();
	void KeyHandler(int key, int scancode, int action, int mods);
	void SimulationStep(float dtSeconds);
	void Render(int, int);
	void DrawThing(Thing& thing, glm::mat4&);

	b2Body* createStaticBox(float posX, float posY, float sizeX, float sizeY);
	b2Body* createDynamicBox(float posX, float posY, float sizeX, float sizeY);

	b2Vec2 m_gravity;
	b2World m_world;
	std::vector<Thing> m_staticThings;
	std::shared_ptr<Thing> m_player;
	GLuint m_standardShader;
	const size_t m_nVelocityIterations = 6;
	const size_t m_nPositionIterations = 2;
};