#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H
#include "Action.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <fstream>

class SaveAction : public Action
{
private:
	string filename;
	ofstream fout;
public :
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif