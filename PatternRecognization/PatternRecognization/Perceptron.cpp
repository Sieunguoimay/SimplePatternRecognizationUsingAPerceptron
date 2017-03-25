#include "Perceptron.h"



Perceptron::Perceptron(int n)
	:size(n)
{
	weights = new float[size];
	for (int i = 0; i < size; i++)
		weights[i] = (rand() % 2000-1000)*0.001f;
		//UtilityFunctions::random(-1,1);
	c = 0.01f;
}


Perceptron::~Perceptron()
{
	delete[]weights;
	weights = NULL; 
	c = 0.0f;
	size = 0;
}

void Perceptron::train(float inputs[],int desired)
{
	int guess = feedForward(inputs);
	float error = (float)(desired - guess);
	for (int i = 0; i < size; i++)
		weights[i] = error*c*inputs[i];
}

int Perceptron::feedForward(float inputs[])
{
	float sum = 0;
	for (int i = 0; i < size; i++)
		sum+=weights[i] * inputs[i];
	return activate(sum);
}

int Perceptron::activate(float sum)
{
	if (sum > 0)
		return 1;
	return -1;
}
