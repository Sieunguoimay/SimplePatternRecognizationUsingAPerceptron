#pragma once
#include"GlobalHeader.h"
#include"Window.h"
#include"Clock.h"
#include"Project.h"
class Main
{
public:
	Main();
	~Main();
private:
	void setup();
	void loop();
	Window*window;
	SDL_Renderer*renderer;
	Clock clock;
	Project*project;
};

