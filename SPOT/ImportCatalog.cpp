#include "ImportCatalog.h"
using namespace std;

void ImportCatalog::readCatalog(vector<CourseInfo>* catalog) {
	CourseInfo c;
	string Req, token, temp = "";
	istringstream sstream, sstream2;
	ifstream finput("info files/Catalog - 2020 12 19.txt");
	const int size = 300;
	char line[size];

	while (finput.getline(line, size)) {
		sstream.str(line);
		getline(sstream, c.Code, ',');
		getline(sstream, c.Title, ',');
		getline(sstream, token, ',');
		c.Credits = stoi(token);
		getline(sstream, token, ',');
		c.lHrs = stoi(token);
		getline(sstream, token, ',');
		c.pHrs = stoi(token);
		getline(sstream, token, ',');

		if (token[0] == 'C') { //remember to check the input file if the C in Coreq is capital or small
			sstream2.str(token);
			getline(sstream2, Req, ' ');
			while (sstream2.good()) {
				getline(sstream2, Req, ' ');
				temp = Req;
				getline(sstream2, Req, ' ');
				temp = temp + " " + Req;
				c.CoReqList.push_back(temp);
				getline(sstream2, Req, ' ');
			}
			Req.clear();
			temp.clear();
			sstream2.clear();
		}

		getline(sstream, token, ',');

		if (token[0] == 'P') { //remember to check the input file if the P in Prereq is capital or small
			sstream2.str(token);
			getline(sstream2, Req, ' ');
			while (sstream2.good()) {
				getline(sstream2, Req, ' ');
				temp = Req;
				getline(sstream2, Req, ' ');
				temp = temp + " " + Req;
				c.PreReqList.push_back(temp);
				getline(sstream2, Req, ' ');
			}
			Req.clear();
			temp.clear();
			sstream2.clear();
		}
		catalog->push_back(c);
		token.clear();
		sstream.clear();
		clearCourseInfo(c);
	}
}

CourseInfo ImportCatalog::clearCourseInfo(CourseInfo &course)
{
	//clears info when called to a course
	course.Title = "";
	course.Code = "";
	course.type = "";
	course.Credits = 0;
	course.PreReqList.clear();
	course.CoReqList.clear();
	return course;
}
