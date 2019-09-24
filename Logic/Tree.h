#include <string>

class StatementNode {
public:
	StatementNode() : left(NULL), right(NULL), value(NULL) {}

	StatementNode* left;
	StatementNode* right;
	std::string value;
	char connector;
	bool negation;
	char opType;
};

class StatementParser {
public: 
	StatementParser();

	//Combine two statements with a connector
	StatementParser(StatementParser& s1, StatementParser& s2);
	StatementParser(const std::string& statement);

	void changeHeadValue(const std::string& statement);
	

private:
	StatementNode* head;

};