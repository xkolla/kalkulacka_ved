#include "operace.h"
int intro(CalcStatus* status) {

	printf("Vyberte operaci kalkulacky: Aritmeticka operace(1) Funkce(2) Konverze Jednotek(3) Vyresit Kvardaticka Rovnice(4)\n");
	printf("Napiste cislo operace a stiskněte Enter:\n");
	int operation = 0;
	int select_done = 0;
	while (select_done == 0) {
		if (scanf(" %d", &operation) != 1) {
			return -1;
		}
		switch (operation) {
		case 1:
			printf("enter arithmetic");
			status->firstWrite = 0;
			status->numOfOperators = 2;
			status->operationType = Aritmeticka;
			select_done = 1;
			break;

		case 2:
			status->firstWrite = 0;
			status->operationType = Funkce;
			askForFunctionType(status);
			select_done = 1;
			break;

		case 3:
			status->firstWrite = 0;
			status->numOfOperators = 1;
			status->operationType = Konverze;
			select_done = 1;
			break;

		case 4:
			status->firstWrite = 0;
			status->numOfOperators = 3;
			status->operationType = KvardatickaRovnice;
			select_done = 1;
			break;
		default:
			continue;
		}
	}
	return 0;
}

void askForFunctionType(CalcStatus* status) {
	int funcNo;
	printf("vyberte si typ funkce:\n \
		prirozeny logaritmus(1) desitkovy logaritmus(2) vlastni logaritmus: log y (x)(3)\n\
		faktorial (4) sinus (5) kosinus (6) tangens (7) exponencialni funkci (x^y) (8)\n");
	printf("napiste cislo funkce: ");
	scanf(" %d", &funcNo);
	switch (funcNo) {
	case 1:
		status->funcType = NaturalLog;
		break;
	case 2:
		status->funcType = Log10;
		break;
	case 3:
		status->funcType = LogChooseBase;
		break;
	case 4:
		status->funcType = Factorial;
		break;
	case 5:
		status->funcType = sinus;
		break;
	case 6:
		status->funcType = cosinus;
		break;
	case 7:
		status->funcType = tangens;
		break;
	case 8:
		status->funcType = exponential;
		break;
	}
	if (funcNo == 8 || funcNo == 3) {
		status->numOfOperators = 2;
	}
	else {
		status->numOfOperators = 1;
	}

}

int getNumbers(CalcStatus* status) {
	int i = 0;
	char names[3] = { 'x', 'y', 'z' };
	while (i < status->numOfOperators)
	{

		if (askIfMemory() == 'y') {
			getInputFromMemory(status, i);
		}
		else {
			status->numbers[i] = getInputNumber(names[i]);
		}
		i++;
	}
	return 0;
}

double getInputNumber(char name) {
	double inputNum;
	while (true) {


		printf("Write a number and press enter for variable %c:  \n", name);
		if (scanf(" %lf", &inputNum) != 1) {
			system("cls");
			printf("invalid input! \n");
			scanf("%*[^\n]");
			continue;
		}
		break;


	}

	return inputNum;
}

void arithmeticOperation(CalcStatus* status) {

}

char askIfMemory() {
	char useMemory = ' ';
	while (true) {
		printf("Do you want to use a number from memory? y/n\n");
		if (scanf(" %c", &useMemory) != 1) {
			printf("scanf failed!");
		}
		if (useMemory == 'y') {
			return 'y';
		}
		else
			if (useMemory == 'n') {
				return 'n';
			}

		system("cls");
	}
}

void getInputFromMemory(CalcStatus* status, int numberIndex) {
	char memoryIndex;

	while (true) {
		printf("which memory slot you want to use? (A:%lf B:%lf C:%lf D:%lf)\n", status->memory[0], status->memory[1], status->memory[2], status->memory[3]);
		scanf("%c", &memoryIndex);
		switch (toupper(memoryIndex)) {
		case 'A':
			status->numbers[numberIndex] = status->memory[0];
			break;
		case 'B':
			status->numbers[numberIndex] = status->memory[1];
			break;
		case 'C':
			status->numbers[numberIndex] = status->memory[2];
			break;
		case 'D':
			status->numbers[numberIndex] = status->memory[3];
			break;
		default:
			printf("Invalid memory slot given. Please repeat input\n");
			break;
		}
	}
}

void enterIntoMemory(CalcStatus* status) {
	// TODO enter memory question and use answer to fill A,B,C,D
	char memoryIndex;
	printf("which memory slot you want to use? (A:%lf B:%lf C:%lf D:%lf)\n", status->memory[0], status->memory[1], status->memory[2], status->memory[3]);
	scanf("%c", &memoryIndex);
	double newNum;
	printf("\nWrite the number you want to save and press enter:");
	scanf("%lf", &newNum);
	switch (memoryIndex) {
	case 'A':
		status->memory[0] = newNum;
		break;
	case 'B':
		status->memory[1] = newNum;
		break;
	case 'C':
		status->memory[2] = newNum;
		break;
	case 'D':
		status->memory[3] = newNum;
		break;
	}
}