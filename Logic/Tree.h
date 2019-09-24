#include <string>

class StatementNode {
public:
	StatementNode() : left(NULL), right(NULL), value(NULL) {}

	StatementNode* left;
	StatementNode* right;
	std::string value
};

class StatementParser {
public: 
	StatementParser();
	StatementParser(StatementParser s1, StatementParser s2);
	StatementParser(std::string statement);

private:
	StatementNode* Head;

}