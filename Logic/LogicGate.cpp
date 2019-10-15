//LogicGate.cpp

#include "LogicGate.h"
#include <iostream>

void LogicGate::asciiDraw(){
	std::cout << "This is a asciiDraw" << std::endl;
	std::unordered_map<char, bool>::const_iterator loopStates = initStatements.begin();

	for(; loopStates != initStatements.end(); loopStates++){
		std::cout << loopStates -> first << " ";
		if(loopStates -> second == true) std::cout << "true" << std::endl;
		else std::cout << "false" << std::endl;
	}
}

//Default of all statements is true;
bool LogicGate::addStatement(char addState){
	return initStatements.insert(std::make_pair(addState, true)).second;
}

//Changing a state too itself isn't much of a big problem so for now will ignore
bool LogicGate::changeOnOff(char stateName, bool newSwitch){
	std::unordered_map<char,bool>::iterator got = initStatements.find(stateName);
	if(got == initStatements.end()){
		std::cout << "Error Statement Does Not Exist" << std::endl;
		return false;	
	} 
	got -> second = newSwitch;
	return true;
}