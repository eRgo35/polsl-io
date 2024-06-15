#include "ArcTan.h"

double ArcTanActivation::ActivationFunction(double Input) {
	return atan(Input);
}

double ArcTanActivation::Derivative(double Input, double Output) {
	return 1 / (Input * Input + 1);
}