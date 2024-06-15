#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <cmath>

class Activation {
protected:
	const double BETA = 1;

public:
	virtual double ActivationFunction(double Input) = 0;

	virtual double Derivative(double Input, double Output) = 0;
};

#endif // !ACTIVATION_H
