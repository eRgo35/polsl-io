#ifndef ReLU_H
#define ReLU_H

#include "ActivationFunction.h"

class ReLUActivation : public Activation {
public:
	double ActivationFunction(double Input);

	double Derivative(double Input, double Output);
};

#endif // !ReLU_H
