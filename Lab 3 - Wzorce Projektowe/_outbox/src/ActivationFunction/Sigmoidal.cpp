#include "Sigmoidal.h"

double SigmoidalActivation::ActivationFunction(double Input) {
	return 1 / (1 + exp(-Activation::getBeta() * Input));
}

double SigmoidalActivation::Derivative(double Input, double Output) {
	return Activation::getBeta() * (1 - Output) * Output;
}