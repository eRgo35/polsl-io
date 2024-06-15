#ifndef Tanh_H
#define Tanh_H

#include "ActivationFunction.h"

class TanhActivation : public Activation {
public:
	double ActivationFunction(double Input);

	double Derivative(double Input, double Output);
};

#endif // !Tanh_H
