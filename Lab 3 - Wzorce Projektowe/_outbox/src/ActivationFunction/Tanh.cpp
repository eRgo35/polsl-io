#include "Tanh.h"

double TanhActivation::ActivationFunction(double Input) {
	return tanh(Activation::getBeta() * Input);
}

double TanhActivation::Derivative(double Input, double Output) {
	return Activation::getBeta() * (1 - Output * Output);
}