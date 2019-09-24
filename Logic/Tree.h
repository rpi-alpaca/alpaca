#include <string>

class StatementNode {
public:
	StatementNode() : left(NULL), right(NULL), value(NULL) {}

	StatementNode* left;
	StatementNode* right;
	std::string value;
	bool negation;
	char opType;
};

class StatementParser {
public: 
	StatementParser();

	//Combine two statements with a connector
	StatementParser(const StatementParser& s1, const StatementParser& s2);
	StatementParser(const std::string& statement);

private:
	StatementNode* Head;

}