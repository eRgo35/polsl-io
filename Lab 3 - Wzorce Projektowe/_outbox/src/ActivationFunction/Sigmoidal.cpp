#include "Sigmoidal.h"

double SigmoidalActivation::ActivationFunction(double Input) {
	return 1 / (1 + exp(-BETA * Input));
}

double SigmoidalActivation::Derivative(double Input, double Output) {
	return BETA * (1 - Output) * Output;
}