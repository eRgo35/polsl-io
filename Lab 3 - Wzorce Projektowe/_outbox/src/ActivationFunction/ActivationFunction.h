#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <cmath>

class Activation {
private:
	double BETA = 1;

public:
	Activation();

	Activation(double BETA);

	virtual double ActivationFunction(double Input) = 0;

	virtual double Derivative(double Input, double Output) = 0;

	void setBeta(double newBeta);

	double getBeta();
};

#endif // !ACTIVATION_H
