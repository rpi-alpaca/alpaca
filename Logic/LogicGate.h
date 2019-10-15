//LogicGate.h

#ifndef LogicGate_h
#define LogicGate_h

#include <unordered_map>
#include <utility>
//Will string be needed?
#include <string>

class LogicGate{
public:
	bool addStatement(char addState);
	//Likely will not be doing much, more of prototype for GUI to use later
	void asciiDraw();
	bool changeOnOff(char stateName, bool newSwitch);

private:
	std::unordered_map<char, bool> initStatements;
};

#endif

/*

	Idea: Have Nodes and operation

	Operation orders can be changed -- likely via a tree?

	Give each operator a code number?
	
	


*/