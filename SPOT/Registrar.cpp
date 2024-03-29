﻿#include "Registrar.h"
#include "Actions/ActionAddCourse.h"
#include "ImportOffering.h"
#include "../SPOT/Actions/ActionChangeCode.h"
#include "../SPOT/Actions/ActionAddNotes.h"
#include "../SPOT/Actions/ActionDeleteCourse.h"
#include "../SPOT/Actions/ActionSavePlan.h"
#include "../SPOT/Actions/ActionShowCourseInfo.h"
#include "../SPOT/Actions/ActionImportStudyPlan.h"
#include "../SPOT/Actions/ActionCalculateGPA.h"
#include "../SPOT/Actions/ActionMinorDec.h"
#include "../SPOT/Actions/ActionFilters.h"
#include "../SPOT/Actions/ActionErrors.h"
#include "ActionAddPetition.h"
#include "ActionCourseStatus.h"
#include "ActionChangePlan.h"
#include "ImportStudyPlan.h"
#include "Actions/exit.h"
#include "ActionDouble.h"
#include "ActionShowDependencies.h"
#include "ImportRequiements.h"

Registrar::Registrar()
{
	pGUI = new GUI;	//create interface object
	pSPlan = new StudyPlan;	//create a study plan.
}

//returns a pointer to GUI
GUI* Registrar::getGUI() const
{
	return pGUI;
}

Rules* Registrar::getRules()
{
	return &RegRules;
}

Rules* Registrar::getRules2()
{
	return &RegRules2;
}

void Registrar::setMajor(string m)
{
	major = m;
	pSPlan->setMajor(m);
}

string Registrar::getMajor() const
{
	return major;
}

void Registrar::setMinor(string m) {
	minor = m;
	pSPlan->setMinor(m);
}
string Registrar::getMinor() const {
	return minor;
}

void Registrar::setSecondMajor(string m)
{
	secondMajor = m;
	pSPlan->setSecondMajor(m);
}

string Registrar::getSecondMajor() const
{
	return secondMajor;
}


//returns the study plan
StudyPlan* Registrar::getStudyPlay() const
{
	return pSPlan;
}

Action* Registrar::CreateRequiredAction() 
{	
	int Cx, Cy;
	Action* RequiredAction = nullptr;
	string currentMsg;
	pGUI->getPwind()->GetMouseCoord(Cx, Cy);
	//cout << "X = " << Cx << "Y = " << Cy << endl;
	while(Cy <= pGUI->getMenuBarHeight())
	{
		
		if (pGUI->getPwind()->GetButtonState(LEFT_BUTTON, Cx, Cy) == BUTTON_DOWN)
		{
			ActionData actData = pGUI->GetUserActionNoFlush();
			switch (actData.actType)
			{
			case ADD_CRS:	//add_course action
				RequiredAction = new ActionAddCourse(this);
				return RequiredAction;
				break;
			case ADD_NOTES: // add_notes action
				RequiredAction = new ActionAddNotes(this);
				return RequiredAction;
				break;
			case DEL_CRS: // delete_course action
				RequiredAction = new ActionDeleteCourse(this);
				return RequiredAction;
				break;
			case EDIT_CRS: //edit_course action
				RequiredAction = new ActionChangeCode(this);
				return RequiredAction;
				break;
			case IMPORT: //import_study_plan action
				RequiredAction = new ActionImportStudyPlan(this);
				return RequiredAction;
				break;
			case SAVE: //save_study_plan action
				RequiredAction = new ActionSavePlan(this);
				return RequiredAction;
				break;
			case CALC_GPA:
				RequiredAction = new ActionCalculateGPA(this);
				return RequiredAction;
				break;
			case MINOR_DEC:
				RequiredAction = new ActionMinorDec(this);
				return RequiredAction;
				break;
			case SEARCH:
				RequiredAction = new ActionFilters(this);
				return RequiredAction;
				break;
			case EXIT:
				RequiredAction = new ActionExit(this);
				return RequiredAction;
				break;
			case Double:
				RequiredAction = new ActionDouble(this);
				return RequiredAction;
				break;
			case SHOW_DPND:
				RequiredAction = new ActionShowDependencies(this);
				return RequiredAction;
				break;
			case ERRORR:
				RequiredAction = new ActionErrors(this);
				return RequiredAction;
				break;
			case CHANGE_PLAN:
				RequiredAction = new ActionChangePlan(this);
				return RequiredAction;
				break;
			case ADD_PETITION:
				RequiredAction = new ActionAddPetition(this);
				return RequiredAction;
				break;
			}
		}
		else
		{
			ActionData actData = pGUI->mapMenuLocation(Cx);
			switch (actData.actType)
			{
			case ADD_CRS:
				if (currentMsg != "Add Course")
				{
					currentMsg = "Add Course";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case ADD_NOTES:
				if (currentMsg != "Notes Area")
				{
					currentMsg = "Notes Area";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case DEL_CRS: 
				if (currentMsg != "Delete course")
				{
					currentMsg = "Delete course";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case EDIT_CRS: 
				if (currentMsg != "Edit Course Code/Note")
				{
					currentMsg = "Edit Course Code/Note";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case IMPORT: 
				if (currentMsg != "Import Study Plan")
				{
					currentMsg = "Import Study Plan";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case SAVE:
				if (currentMsg != "Save Study Plan")
				{
					currentMsg = "Save Study Plan";
					pGUI->PrintMsg(currentMsg);
				}				break;
			case CALC_GPA:
				if (currentMsg != "Calculate GPA")
				{
					currentMsg = "Calculate GPA";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case MINOR_DEC:
				if (currentMsg != "Declare Minor")
				{
					currentMsg = "Declare Minor";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case SEARCH:
				if (currentMsg != "Filter")
				{
					currentMsg = "Filter";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case EXIT:
				if (currentMsg != "Exit Program")
				{
					currentMsg = "Exit Program";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case Double:
				if (currentMsg != "Declare double Major/Concentration")
				{
					currentMsg = "Declare double Major/Concentration";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case SHOW_DPND:
				if (currentMsg != "Show dependencies")
				{
					currentMsg = "Show dependencies";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case ERRORR:
				if (currentMsg != "Get Check Report")
				{
					currentMsg = "Get Check Report";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case CHANGE_PLAN:
				if (currentMsg != "Change Major")
				{
					currentMsg = "Change Major";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			case ADD_PETITION:
				if (currentMsg != "Add Petition")
				{
					currentMsg = "Add Petition";
					pGUI->PrintMsg(currentMsg);
				}
				break;
			}
		}
	}
	while(Cy > pGUI->getMenuBarHeight())
	{
		
		pGUI->ClearStatusBar();
		pGUI->getPwind()->GetMouseCoord(Cx, Cy);
		if (pGUI->getPwind()->GetButtonState(LEFT_BUTTON, Cx, Cy) == BUTTON_DOWN)
		{
			RequiredAction = new ActionShowCourseInfo(this, Cx, Cy);
			return RequiredAction;
		}
			
	}
	return RequiredAction;
	
}

CourseInfo* Registrar::CatalogSearch(string code, bool& coursefound)
{
	bool z = 0;
    int i= 0;
	for (CourseInfo cr : RegRules.CourseCatalog)
	{
	if (cr.Code == code)
		{
			z = 1;
			coursefound = 1;
			break;
		}
		i++;
	}
	if (z)
	{
		return&(RegRules.CourseCatalog[i]);
	}
	else
	{
		coursefound = 0;
		return nullptr;
	}
}

//Executes the action, Releases its memory, and return true if done, false if cancelled
bool Registrar::ExecuteAction(Action* pAct)
{
	bool done = pAct->Execute();
	delete pAct;	//free memory of that action object (either action is exec or cancelled)
	return done;
}

void Registrar::Initialization() {
	ImportCatalog().readCatalog(&RegRules.CourseCatalog);
	ImportOffering().ImportOfferingFile(&RegRules.OffringsList);
	pGUI->PrintMsg("Enter your Major Number: 1)CIE  2)SPC  3)ENV  4)REE  5)NANENG ");
	/*pGUI->getRangeInput(1, 5, "Enter your Major Number: 1)CIE  2)SPC  3)ENV  4)REE  5)NANENG ");*/
	string Major = pGUI->GetSrting();
	if (Major == "1")
		major = "CIE";
	else if (Major == "2")
		major = "SPC";
	else if (Major == "3")
		major = "ENV";
	else if (Major == "4")
		major = "REE";
	else if (Major == "5")
		major = "NANENG";
	bool flag = true;
	ifstream infile;
	ifstream fin;
	setMajor(ImportRequiements().ImportReqs(fin, pGUI, Major, &RegRules));
	if (RegRules.NofConcentrations != 0) 
	{
		pGUI->PrintMsg("Enter your Concentration number: ");
		string Concentration = pGUI->GetSrting();
		pSPlan->setConcentration(stoi(Concentration));
	}
	fillCoursesType();
	ImportStudyPlan().StudyPlanImport(fin, this);
}

void Registrar::Run()
{
	
	Initialization();
	UpdateInterface();
	while (true)
	{
		

		UpdateInterface();
		
		
		Action* pAct = CreateRequiredAction();
		if (pAct)	//if user doesn't cancel
		{
			if (ExecuteAction(pAct))	//if action is not cancelled
			{
				UpdateInterface();
			}
		}
	}

	
}

void Registrar::fillCoursesType()
{
	for (auto& itr : RegRules.UnivCompulsory)
	{
		for (auto& itr_catalog : RegRules.CourseCatalog)
		{
			if (itr == itr_catalog.Code)
			{
				itr_catalog.type = "Univ Compulsory";
			}
		}
	}
	for (auto& itr : RegRules.UnivElective)
	{
		for (auto& itr_catalog : RegRules.CourseCatalog)
		{
			if (itr == itr_catalog.Code)
			{
				itr_catalog.type = "Univ Elective";
			}
		}
	}
	for (auto& itr : RegRules.TrackCompulsory)
	{
		for (auto& itr_catalog : RegRules.CourseCatalog)
		{
			if (itr == itr_catalog.Code)
			{
				itr_catalog.type = "Track Compulsory";
			}
		}
	}
	for (auto& itr : RegRules.TrackElective)
	{
		for (auto& itr_catalog : RegRules.CourseCatalog)
		{
			if (itr == itr_catalog.Code)
			{
				itr_catalog.type = "Track Elective";
			}
		}
	}
	for (auto& itr : RegRules.MajorCompulsory)
	{
		for (auto& itr_catalog : RegRules.CourseCatalog)
		{
			if (itr == itr_catalog.Code)
			{
				itr_catalog.type = "Major Compulsory";
			}
		}
	}
	for (auto& itr : RegRules.MajorElective)
	{
		for (auto& itr_catalog : RegRules.CourseCatalog)
		{
			if (itr == itr_catalog.Code)
			{
				itr_catalog.type = "Major Elective";
			}
		}
	}
	for (auto& itr_vector : RegRules.ConCompulsory)
	{
		for (auto& itr : itr_vector)
		{
			for (auto& itr_catalog : RegRules.CourseCatalog)
			{
				if (itr == itr_catalog.Code)
				{
					itr_catalog.type = "Concentration Compulsory";
				}
			}
		}
	}
	for (auto& itr_vector : RegRules.ConElective)
	{
		for (auto& itr : itr_vector)
		{
			for (auto& itr_catalog : RegRules.CourseCatalog)
			{
				if (itr == itr_catalog.Code)
				{
					itr_catalog.type = "Concentration Elective";
				}
			}
		}
	}

}



void Registrar::freePlanRules(Rules* rules) {
	
	rules->SemMinCredit = 12;
	rules->SemMaxCredit = 18;
	rules->SummerMaxCredit = 6;
	rules->ReqUnivCredits = 0;
	rules->ElectiveUnivCredits = 0;
	rules->ReqTrackCredits = 0;
	rules->ReqMajorCredits = 0;
	rules->ElectiveMajorCredits = 0;
	rules->TotalMajorCredits = 0;
	rules->NofConcentrations = 0;
	

	rules->UnivCompulsory.clear();	//Univ Compulsory courses//
	rules->UnivElective.clear();	//Univ Elective courses//

	rules->MinorCompulsory.clear(); //And this should add a list of compulsory courses

	rules->TrackCompulsory.clear();//Track Compulsory courses//
	rules->TrackElective.clear();	//Track Elective courses (added for future)

	rules->MajorCompulsory.clear();//Major Compulsory courses//
	rules->MajorElective.clear();	//Major Elective courses//

	rules->ConCompulsoryCr.clear();	//Concentration Compulsory credits//
	rules->ConElectiveCr.clear();		//Concentration Elective credits//

	rules->ConCompulsory.clear();		//concentrations compulsory courses//
	rules->ConElective.clear();		//concentrations Elective courses//
}

void Registrar::UpdateInterface()
{
	pGUI->getPwind()->SetBuffering(true);
	pGUI->UpdateInterface();	//update interface items
	pSPlan->checkPlan(this);	//perform plan checks
	pSPlan->DrawMe(pGUI);		//make study plan draw itself
	pGUI->getPwind()->UpdateBuffer();
	pGUI->getPwind()->SetBuffering(false);
}


Registrar::~Registrar()
{
	delete pGUI;
	delete pSPlan;
}
