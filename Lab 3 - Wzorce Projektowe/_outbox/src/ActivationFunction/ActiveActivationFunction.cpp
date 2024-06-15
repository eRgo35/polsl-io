#include "ActiveActivationFunction.h"

ActiveActivationFunction &ActiveActivationFunction::getFunction() {
	static ActiveActivationFunction the_only_object;
	return the_only_object;
}

ActiveActivationFunction::ActiveActivationFunction() {}

Activation* ActiveActivationFunction::getActivationFunction() {
	return activationFunction;
}

void ActiveActivationFunction::setActivationFunction(Activation* newActivationFunction) {
	ActiveActivationFunction::activationFunction = newActivationFunction;
}