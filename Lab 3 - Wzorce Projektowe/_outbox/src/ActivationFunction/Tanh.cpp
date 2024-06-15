#include "Tanh.h"

double TanhActivation::ActivationFunction(double Input) {
	return tanh(BETA * Input);
}

double TanhActivation::Derivative(double Input, double Output) {
	return BETA * (1 - Output * Output);
}