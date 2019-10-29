//LogicGate.cpp

#include "LogicGate.h"


void LogicGate::asciiDraw(){
	std::cout << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "This is a asciiDraw" << std::endl;
	std::cout << std::endl;
	if(initStatements.size() == 0) std::cout << "No Statements!" << std::endl;
	std::unordered_map<char, bool>::const_iterator loopStates = initStatements.begin();

	for(; loopStates != initStatements.end(); loopStates++){
		std::cout << loopStates -> first << " ";
		if(loopStates -> second == true) std::cout << "true" << std::endl;
		else std::cout << "false" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;
}

//Default of all statements is true;
bool LogicGate::addStatement(char addState){
	return initStatements.insert(std::make_pair(addState, true)).second;
}

bool LogicGate::removeStatement(char removeState){
	return initStatements.erase(removeState);
}

//Changing a state too itself isn't much of a big problem so for now will ignore
bool LogicGate::changeOnOff(char stateName, bool newSwitch){
	std::unordered_map<char,bool>::iterator got = initStatements.find(stateName);
	if(containsState(stateName)){
		std::cout << "Error Statement Does Not Exist" << std::endl;
		return false;	
	} 
	got -> second = newSwitch;
	return true;
}

void LogicGate::clearStates(){
	initStatements.clear();
}
//For now wil
bool LogicGate::containsState(char checkState){
	std::unordered_map<char, bool>::const_iterator got = initStatements.find(checkState);
	
	if(got == initStatements.end()){
		return true;	
	} 

	return true;
}

bool LogicGate::addOperator(char stateOne, char stateTwo, char opAdd){
	return false;
}