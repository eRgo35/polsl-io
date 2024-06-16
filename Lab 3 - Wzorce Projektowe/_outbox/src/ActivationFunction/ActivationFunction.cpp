#include "ActivationFunction.h"

Activation::Activation() {}

Activation::Activation(double BETA) : BETA(BETA) {}

void Activation::setBeta(double newBeta) {
	BETA = newBeta;
}

double Activation::getBeta() {
	return BETA;
}
