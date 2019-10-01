//LogicGate.h

#include <vector>
#include <utility>

class LogicGate{
public:
	void asciiDraw();

private:
	std::vector<std::pair<char, bool>> initStatements;
};