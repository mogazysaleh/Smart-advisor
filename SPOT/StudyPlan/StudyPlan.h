#pragma once
#include <vector>
#include "AcademicYear.h"
#include "../GUI/Drawable.h"
#include "../Notes.h"
#include "../Registrar.h"

class Registrar;
//A full study plan for as student
class StudyPlan:public Drawable
{
	int TotalCredits=0;		//total no. of credit hours for courses registred in this year
	int ElecUnivCredits = 0, ReqUnivCredits = 0,
		ReqMajorCredits = 0, ElecMajorCredits = 0,
		TotalTrackCredits=0, TotalConcentrationCredits=0,
		TotalMinorCredits=0;

	int concentration=0;
	int DoubleConcentration=0;
	string major;
	string minor;
	string secondMajor;

	vector<AcademicYear*> plan;	//plan is a list of academic years
	vector<Notes*> PlanNotees;
public:
	StudyPlan();

	void setMajor(string);
	string getMajor() const;
	void setMinor(string);
	string getMinor() const;
	void setSecondMajor(string);
	string getSecondMajor() const;

	//getters
	vector<AcademicYear*>* getSPvector();
	vector<Notes*>* getNvector();
	int getConcentration() const;
	int getConcentration2() const;
	//string getMajor() const;
	vector<Course*> getPetitionCourses() const;

	//setters
	void setConcentration(int);
	void setConcentration2(int);

	//adders
	bool AddCourse(Course*, int year, SEMESTER);
	void addeYearCredits(AcademicYear*);
	bool AddNote(Notes*);

	bool DeleteCourse(Course*);
	bool DeleteNotes(Notes*);

	void virtual DrawMe(GUI*) const;

	int getSemesterCredits(int year, SEMESTER sem) const;
	int getSemesterLHrs(int year, SEMESTER sem) const;
	int getSemesterPHrs(int year, SEMESTER sem) const;

	int getTotalPlanCredits() const;
	int getTotalLHrs() const;
	int getTotalPHrs() const;

	int creditsOfDoneCourses() const;
	double calculateGPA() const;
	string StudentLevel() const;
	Course* searchStudyPlan(Course_Code) const;
	Course* searchYear(Course_Code, int) const;
	Course* searchSemester(Course_Code, int, SEMESTER) const;
	Course* searchSelectedCourse() const;
	
	//checks on the study plan
	vector<string> checkMinor(Rules*) const;
	vector<yearSemPair> CreditsCheck(Rules*) const;
	vector<codeTypePair> ProgReqCheck(Rules*) const;
	bool checkUnivElectiveCrd(Rules*) const;
	bool checkMajorElectiveCrd(Rules*) const;
	bool searchOfferings(Rules*, Course_Code, int, SEMESTER) const;
	vector <vector <Course_Code>> checkConReq(Rules*) const;
	vector <vector <Course_Code>> checkDoubleConReq(Rules*) const;
	vector <vector <Course_Code>> checkPreCo() const;
	vector <Course_Code> checkOfferings(Rules*) const;
	bool checkM2MajElecCrd(Registrar* R) const;
	bool checkM2UnivElecCrd(Registrar* R) const;

	void checkPlan(Registrar* R) const; //exploits checks to show live messages of issues

	void selectOverloadedSemesters(GUI*) const;
	void clearDataFields();
	
	virtual ~StudyPlan();
};

