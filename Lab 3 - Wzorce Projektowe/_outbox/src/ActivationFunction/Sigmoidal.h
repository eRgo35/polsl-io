#ifndef Sigmoidal_H
#define Sigmoidal_H

#include "ActivationFunction.h"

class SigmoidalActivation : public Activation {
public:
	double ActivationFunction(double Input);

	double Derivative(double Input, double Output);
};

#endif // !Sigmoidal_H
