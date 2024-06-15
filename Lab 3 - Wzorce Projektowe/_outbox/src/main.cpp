#include <iostream>
#include "NeuralNetwork/NeuralNet.h"
#include "Dataset.h"
#include "LoadingDatasetFunctions.h"
#include "GeneticAlgorithm/GeneticAlgorithm.h"

#include "ActivationFunction/ActivationFunction.h"
#include "ActivationFunction/ReLU.h"
#include "ActivationFunction/Sigmoidal.h"
#include "ActivationFunction/Tanh.h"
#include "ActivationFunction/ArcTan.h"
#include "ActivationFunction/ActiveActivationFunction.h"
#include <chrono>

const int BIAS_NEURON = 1;

using namespace std;
int main() {
	srand(time(0));
	
	auto start = std::chrono::high_resolution_clock::now();

	ActiveActivationFunction& func = ActiveActivationFunction::getFunction();

	Activation* sel = new ReLUActivation();

	char choice;

	std::cout << "Select Activation Function: " << std::endl
		<< "1. ReLU Activation" << std::endl
		<< "2. Sigmoidal Activation" << std::endl
		<< "3. Tanh Activation" << std::endl
		<< "4. ArcTan Activation" << std::endl;
	std::cout << "Choice: ";

	std::cin >> choice;

	switch (choice) {
	case '2':
		sel = new SigmoidalActivation();
		break;
	case '3':
		sel = new TanhActivation();
		break;
	case '4':
		sel = new ArcTanActivation();
		break;
	case '1':
	default:
		break;
	}

	func.setActivationFunction(sel);

	Dataset<double,double> testSet;
	Dataset<double,double> trainingSet;
	Dataset<double,double> validationSet = LoadSingleDataset("../Datasets/validationSet.txt");
	JoinDatasets(trainingSet,testSet,1);
	GeneticAlgorithm geneticAlgorithm(trainingSet, testSet);
	Individual optimizedIndividual = geneticAlgorithm.run();
	NeuralNet myNet({3,6,3,1},0.6,0.001,0.00001,false);
	myNet.PartialFit(optimizedIndividual.getFeaturesVector(),optimizedIndividual.getLabelsVector(),false);
	fstream resultFile;
	Settings settings;
	resultFile.open(settings.fileForResults, std::ios::app);
	if(resultFile.good()){
		resultFile << myNet.CheckAccuracy(validationSet);
		resultFile.close();
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	printf("\nTime measured: %.3f seconds.\n", diff.count());

	return 0;
}
