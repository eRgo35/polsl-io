#ifndef ACTIVE_ACTIVATION_FUNCTION_H
#define ACTIVE_ACTIVATION_FUNCTION_H

#include "ActivationFunction.h"

class ActiveActivationFunction {
private:
	Activation* activationFunction;
	ActiveActivationFunction();

public:
	static ActiveActivationFunction& getFunction();

	ActiveActivationFunction(const ActiveActivationFunction &original) = delete;
	ActiveActivationFunction& operator=(const ActiveActivationFunction& original) = delete;

	void setActivationFunction(Activation* newActivationFunction);

	Activation* getActivationFunction();
};

#endif