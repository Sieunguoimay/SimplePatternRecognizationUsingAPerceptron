#include "Project.h"



Project::Project(Size windowSize)
	:perceptron(3),windowSize(windowSize)
{
	for (int i = 0; i < 2000; i++) {
		float x = (float)(rand() % (int)windowSize.w - windowSize.w*0.5f);
		float y = (float)(rand() % (int)windowSize.h - windowSize.h*0.5f);
		//float y = UtilityFunctions::random(-windowSize.h*0.5f, windowSize.h*0.5f);
		int answer = (y<f(x)?-1:1);
		trainers.push_back(new Trainer(x, y, answer));
	}
	count = 0;
}


Project::~Project()
{
	for (size_t i = 0; i < trainers.size(); i++)
	{
		delete trainers.at(i);
		trainers.at(i) = NULL;
	}
}

void Project::display(SDL_Renderer**renderer)
{
	perceptron.train(trainers.at(count)->inputs, trainers.at(count)->answer);
	count = (count + 1) % trainers.size();
	for (int i = 0; i < count; i++) {
		int guess = perceptron.feedForward(trainers.at(i)->inputs);
		if (guess > 0)
			SDL_SetRenderDrawColor(*renderer, 0xff, 0x00, 0x00, 0x00);
		else 
			SDL_SetRenderDrawColor(*renderer,0x00, 0x00, 0xff, 0x00);
		SDL_Rect temp = { trainers.at(i)->inputs[0]+windowSize.w*0.5f,trainers.at(i)->inputs[1]+windowSize.h*0.5f,10,10};
		SDL_RenderFillRect(*renderer, &temp);
	}
	SDL_SetRenderDrawColor(*renderer, 0xaa, 0xaa, 0xaa, 0x00);
	float x1 = -windowSize.w*0.5f;
	float y1 = f(x1);
	float x2 = windowSize.w*0.5f;
	float y2 = f(x2);
	SDL_RenderDrawLine(*renderer, x1+windowSize.w*0.5f, y1+ windowSize.h*0.5f, x2 + windowSize.w*0.5f, y2 + windowSize.h*0.5f);
}
