#ifndef ArcTan_H
#define ArcTan_H

#include "ActivationFunction.h"

class ArcTanActivation : public Activation {
public:
	double ActivationFunction(double Input);

	double Derivative(double Input, double Output);
};

#endif // !ArcTan_H
