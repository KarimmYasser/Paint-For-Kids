#pragma once
#include"ApplicationManager.h"
#include<cstdlib>
#include<time.h>
#include<iostream>
#include"Actions/Action.h"
#include"Figures/CFigure.h"
class PickByFig :public Action
{private:
	Point P;
	CFigure* ptrRandom;
	FigureType FigureToPick;
public:
	PickByFig(ApplicationManager* pApp);
	
	CFigure* RandomizeFig();
	virtual void ReadActionParameters();
	virtual void Execute();
	
};
