#pragma once
#include"GlobalHeader.h"

class Perceptron
{
public:
	Perceptron(int n);
	~Perceptron();
	void train(float inputs[],int desired);
	int feedForward(float inputs[]);
	int activate(float sum);
private:
	float*weights;
	int size;
	float c;//learning constant
};

class Trainer {	
public:
	Trainer(float x, float y, int a) {
		inputs = new float[3];
		inputs[0] = x;
		inputs[1] = y;
		inputs[2] = 1.0f;
		answer = a;
	}
	~Trainer() {
		delete[]inputs;
		inputs = NULL;
	}
	float*inputs;
	int answer;
};