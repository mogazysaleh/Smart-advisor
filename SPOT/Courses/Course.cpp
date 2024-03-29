#include "Course.h"
#include "../GUI/GUI.h"
#include <fstream>

Course::Course(){
	petition = false;
}
Course::Course(Course_Code c_code, string c_title, int c_crd, vector<Course_Code> c_CoReq, vector<Course_Code> c_PreReq):code(c_code),Title(c_title)
{
	credits = c_crd;
	CoReq = c_CoReq;
	PreReq = c_PreReq;
	filter = true;
	Status = "Done";
	Done = true;
	petition = false;
}
Course::Course(Course_Code r_code, string r_title, int crd):code(r_code),Title(r_title)
{
	credits = crd;
	Grade = "NA";
	filter = true;
	Status = "Done";
	Done = true;
	petition = false;
}

Course::~Course()
{
}

void Course::setPreStatus(bool pre)
{
	preReqstatisfied = pre;
}

void Course::setCoStatus(bool Co)
{
	coReqstatisfied = Co;
}

void Course::setLHrs(int l)
{
	lHrs = l;
}

void Course::setPHrs(int p)
{
	pHrs = p;
}

bool Course::getPreStatus() const
{
	return preReqstatisfied;
}

bool Course::getCoStatus() const
{
	return coReqstatisfied;
}



Course_Code Course::getCode() const
{
	return code;
}

string Course::getTitle() const
{
	return Title;
}

//return course credits
int Course::getCredits() const
{
	return credits;
}

int Course::getyear() const
{
	return year;
}

void Course::setyear(int y)
{
	year = y;
}

void Course::setsemester(SEMESTER s)
{
	semester = s;
}

void Course::settype( string newtype)
{
	type = newtype;
}

string Course::gettype() const
{
	return type;
}

SEMESTER Course::getsemester() const
{
	return semester;
}


void Course::saveCourse(ofstream& fout) const
{
	fout << getCode();
}

Course* Course::getptr()
{
	return this;

}

void Course::FillData(Rules* R, int index)
{
	PreReq = R->CourseCatalog.at(index).PreReqList;
	CoReq = R->CourseCatalog.at(index).CoReqList;
	type = R->CourseCatalog.at(index).type;
	lHrs = R->CourseCatalog.at(index).lHrs;
	pHrs = R->CourseCatalog.at(index).pHrs;
}


string Course::getPreq() const
{
	string pre;
	for (auto &itr : PreReq)
	{
		pre += itr;
		pre += " ";
	}
	return pre;
}

string Course::getCoreq() const
{
	string co;
	for (auto &itr : CoReq)
	{
		co += itr;
		co += " ";
	}
	return co;
}

vector<Course_Code> Course::getPreReq() const {
	return PreReq;
}

vector<Course_Code> Course::getCoReq() const {
	return CoReq;
}

void Course::DrawMe(GUI* pG) const
{
	pG->DrawCourse(this);
}

bool Course::setGrade(string grade)
{
	if (grade == "A" || grade == "A-" || grade == "B+" || grade == "B" || grade == "B-" ||
		grade == "C+" || grade == "C" || grade == "C-" || grade == "D+" || grade == "D" || grade == "F" || grade == "P" ||
		grade == "I" || grade == "W" || grade == "WP" || grade == "WF" || grade == "IP")
	{
		this->Grade = grade;
		/*if (grade == "I")
			setStatus("In Progress");
		else if (grade == "W" || grade == "WP" || grade == "WF" || grade == "IP")
			setStatus("Attemeped but Not Done");
		else
		{
			setStatus("Done");
			setDone(true);
		}*/
		return true;
	}
	else
	{
		return false;
	}
}

string Course::getGrade() const
{
	return Grade;
}

int Course::getLHrs() const
{
	return lHrs;
}

int Course::getPHrs() const
{
	return pHrs;
}

double Course::getQpoints()
{
	if (Grade == "A")
		return 4.0 * (double)credits;
	else if (Grade == "A-")
		return 3.7 * (double)credits;
	else if (Grade == "B+")
		return 3.3 * (double)credits;
	else if (Grade == "B")
		return 3.0 * (double)credits;
	else if (Grade == "B-")
		return 2.7 * (double)credits;
	else if (Grade == "C+")
		return 2.3 * (double)credits;
	else if (Grade == "C")
		return 2.0 * (double)credits;
	else if (Grade == "C-")
		return 1.7 * (double)credits;
	else if (Grade == "D+")
		return 1.3 * (double)credits;
	else if (Grade == "D")
		return 1.0 * (double)credits;
	else if (Grade == "F" || Grade == "NA" || Grade == "P" || Grade == "WP" || Grade == "WF" || Grade == "IP" || Grade == "I")
		return 0.0 * (double)credits;
}

bool Course::getFilter() const
{
	return filter;
}

void Course::setFiler(bool filter)
{
	this->filter = filter;
}

void Course::setType(string type)
{
	this->type = type;
}

string Course::getGrad() const
{
	return this->Grade;
}

string Course::getType() const
{
	return type;
}

void Course::setStatus(string status) {
	this->Status = status;
}

string Course::getStatus() const {
	return Status;
}

void Course::setDone(bool descision) {
	this->Done = descision;
}

bool Course::hasPetition() const {
	return petition;
}

void Course::setPetition(bool petition) {

	this->petition = petition;
}
