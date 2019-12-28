/*
 * Copyright (c) 2019 Tobias Briones.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "NumericalMethodApp.h"

void NumericalMethodApp::clearScreen() const
{
	cout << "\033[2J\033[1;1H";
}

void NumericalMethodApp::showWelcome() const
{
	printf("*********************************************************");
	printf("\n");
	printf("*                                                       *");
	printf("\n");
	printf("*                    EXAMPLE PROJECT                    *");
	printf("\n");
	printf("*                                                       *");
	printf("\n");
	printf("*********************************************************");
	printf("\n");
	printf("*                                                       *");
	printf("\n");
	printf("*                   NUMERICAL ANALYSIS                  *");
	printf("\n");
	printf("*                                                       *");
	printf("\n");
	printf("* %s METHOD", getName().c_str());
	printf("\n");
	printf("*********************************************************");
	printf("\n");
}

bool NumericalMethodApp::showFooter() const
{
	printf("\n");
	printf("Great job by studying the Example Projects!");
	printf("\n");
	printf("Learn more by accessing the Example Projects at https://tobiasbriones.engineer/ or https://github.com/TobiasBriones/");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Press ENTER to continue, other key to exit");
	cin.get();
	return cin.get() == (int) '\n';
}

void NumericalMethodApp::run()
{
	bool isRunning = true;

	do
	{
		clearScreen();
		showWelcome();
		gatherInput();
		execute();
		showResults();
		isRunning = showFooter();
		reset();
	} while (isRunning);
}
