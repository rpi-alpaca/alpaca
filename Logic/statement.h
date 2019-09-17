//Header class for statement objects
#ifndef statement_h
#define statement_h

#include <string>

class Statement {
private:
	std::string input_statement;
	char statement_type;
	bool value;

	void interpretStatement();
public:
	Statement();
	Statement(const std::string& input);
};

#endif