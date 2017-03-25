#include "Main.h"

int main(int argc, char**argv) {
	Main _main;
	return 0;
}

Main::Main()
	:clock(10)
{
	//std::cout << "Hello Neural Network.\n";
	setup();
	loop();
	
}


Main::~Main()
{
	delete project;
	project = NULL;
	SDL_DestroyRenderer(renderer);
	delete window;
	renderer = NULL;
	window = NULL;
	IMG_Quit();
	SDL_Quit();
}

void Main::setup()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	window = new Window("Pattern Recognization", 1000, 640, &renderer);
	project = new Project(window->getSize());
}

void Main::loop()
{
	bool done = false;
	SDL_Event mainEvent;
	while (!done) {
		while (SDL_PollEvent(&mainEvent)) {
			if (mainEvent.type == SDLK_ESCAPE|| window->handleEvent(mainEvent, renderer))
				done = true;
		}
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
		//SDL_RenderClear(renderer);
		project->display(&renderer);
		SDL_RenderPresent(renderer);
		clock.work();
	}
}
