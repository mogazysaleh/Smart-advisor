#pragma once
#include <iostream>
#include <string>
#include "Actions/Action.h"
#include "DEFs.h"
#include "GUI/GUI.h"
//Class responsible for doubling
class ActionDouble :
	public Action
{
public:
	ActionDouble(Registrar*);
	bool virtual Execute();
	virtual ~ActionDouble();
	
};
