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