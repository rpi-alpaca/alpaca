#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <string>

class StatementNode {
public:
	StatementNode() : left(nullptr), right(nullptr) {}

	StatementNode* left;
	StatementNode* right;
	std::string value;
	char connector;
	bool negation = false;
	char opType;
};

class StatementParser {
public: 
	StatementParser();
	StatementParser(const StatementParser& s);

	//Combine two statements with a connector
	StatementParser(const StatementParser& s1, const StatementParser& s2);
	StatementParser(const std::string& statement);

	void changeHeadValue(const std::string& statement);
	
	void print() const;
	void printNode(StatementNode* s) const;
	void printTree() const;
	void printTreeHelper(StatementNode* s, int depth) const;

private:
	StatementNode* copy_statement(StatementNode* old_node);
	void parseStatement(StatementNode* n, const std::string& statement);
	StatementNode* head;
	friend class StatementEvaluator;
};

#endif