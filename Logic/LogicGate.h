//LogicGate.h

#ifndef LogicGate_h
#define LogicGate_h

#include <unordered_map>
#include <utility>
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






*/