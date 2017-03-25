#pragma once
#include"Perceptron.h"
class Project
{
public:
	Project(Size windowSize);
	~Project();
	void display(SDL_Renderer**renderer);
private:
	float f(float x) {
		return 2.0f * x - 3.0f;
	}
	Perceptron perceptron;
	std::vector<Trainer*>trainers;
	Size windowSize;
	int count;
};

