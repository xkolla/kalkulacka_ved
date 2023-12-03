

#include <math.h>
#include <iostream>
#include <stdio.h>
enum OperationType { Aritmeticka = 1, Funkce, Konverze, KvardatickaRovnice };

enum FunctionType { NaturalLog = 1, Log10, LogChooseBase, Factorial, sinus, cosinus, tangens, exponential };

struct CalcStatus {
	double currentOutcome;
	double numbers[3];
	double memory[4];
	int numOfOperators;
	OperationType operationType;
	int firstWrite;
	FunctionType funcType;
};


int executeArithmeticOperation(CalcStatus* status) {
	// todo arithemtic operations and assign into status->currentOutcome a number
}
double factorial(double input) {
	int converted_input = (int)input;
	int output = 1;
	if (converted_input == 0) {
		return 1;
	}
	for (int i = 1; i <= converted_input; i++) {
		output = output * i;
	}
	return (double)output;
}


int executeFunction(CalcStatus* status) {
	
	switch (status->funcType) {
	case 1:
		status->currentOutcome = log(status->numbers[0]);
		return 0;
	case 2:
		status->currentOutcome = log10(status->numbers[0]);
		return 0;
	case 3:
		status->currentOutcome = log2(status->numbers[0])/log2(status->numbers[1]);
		return 0;
	case 4:
		printf("You chose factorial, converting your input number to closest integer\n");
		status->currentOutcome = factorial(status->numbers[0]);
			return 0;
	case 5:
		status->currentOutcome = sin(status->numbers[0]);
		return 0;
	case 6:
		status->currentOutcome = cos(status->numbers[0]);
		return 0;
	case 7:
		status->currentOutcome = tan(status->numbers[0]);
		return 0;
	case 8:
		status->currentOutcome = pow(status->numbers[0], status->numbers[1]);
		return 0;
	default:
		printf("unexpected error occured...\n");
		return 1;
	}
}