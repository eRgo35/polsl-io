#include "ReLU.h"

double ReLUActivation::ActivationFunction(double Input) {
	return (Input < 0) ? 0 : Input;
}

double ReLUActivation::Derivative(double Input, double Output) {
	return (Input < 0) ? 0 : Input;
}