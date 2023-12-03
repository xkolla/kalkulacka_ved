// kalkulacka_ved.cpp : Defines the entry point for the application.
//

#include "kalkulacka_ved.h"



int main()
{
	CalcStatus status;
	status.currentOutcome = 0;
	if (intro(&status) == -1) {
		return -1;
	}
	system("cls");
	printf("Intro ended.");
	if (getNumbers(&status) == -1) {
		return -1;
	}
	return 0;
}
