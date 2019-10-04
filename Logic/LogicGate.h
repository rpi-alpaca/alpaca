//LogicGate.h

#ifndef LogicGate_h
#define LogicGate_h

#include <unordered_map>
#include <utility>
#include <string>

class LogicGate{
public:
	bool addStatement(char addState);
	void asciiDraw();

private:
	std::unordered_map<char, bool> initStatements;
};

#endif