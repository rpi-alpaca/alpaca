//LogicGate.cpp

#include "LogicGate.h"
#include <iostream>

void LogicGate::asciiDraw(){
	std::cout << "This is a asciiDraw" << std::endl;
}

//Default of all statements is true;
bool LogicGate::addStatement(char addState){
	return initStatements.insert(std::make_pair(addState, true)).second;
}

//Changing a state too itself isn't much of a big problem so for now will ignore
bool LogicGate::changeOnOff(char stateName, bool newSwitch){
	std::unordered_map<char,bool>::iterator got = initStatements.find(stateName);
	if(got == initStatements.end()) return false;
	got -> second = newSwitch;
	return true;
}