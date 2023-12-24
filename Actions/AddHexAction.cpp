#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp, bool sound) :Action(pApp), Sound(sound)
{

}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (Sound)
		PlaySound("Sounds\\Hexagon.wav", NULL, SND_ASYNC);

	pOut->PrintMessage("New Hexagon: Click at the Corner");

	//Read the Corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.isFilled = pOut->getisFilled();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();
	pOut->ClearStatusBar();
	pOut->PrintMessage("You draw a new Hexagon ;)");


}

//Execute the action
void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Hexagon with the parameters read from the user
	H = new CHexagon(P1,RectGfxInfo);

	//Add the Hexagon to the list of figures
	H->IsHidden(false);
	pManager->AddFigure(H);




}

Action* AddHexAction::Clone()
{
	return new AddHexAction(*this);
}

void AddHexAction::Undo()
{
	H->IsHidden(true);
	pManager->RecordFigure(H);

}

void AddHexAction::Redo()
{
	H->IsHidden(false);
	pManager->RecordFigure(H);
}
