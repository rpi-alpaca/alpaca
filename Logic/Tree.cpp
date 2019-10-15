#include "Tree.h"

StatementParser::StatementParser(){
	head = new StatementNode;
	head->opType = 'v';
}

StatementParser::StatementParser(const StatementParser& s) {
	head = new StatementNode;
	head = copy_statement(s.head);
}

StatementParser::StatementParser(const StatementParser& s1, const StatementParser& s2) {
	head = new StatementNode;
	head->opType = '&';
	head->left = copy_statement(s1.head);
	head->right = copy_statement(s2.head);
}

StatementParser::StatementParser(const std::string& statement){
	//this->head = nullptr;
	//split it up
	head = new StatementNode();
	parseStatement(head, statement);
}

void StatementParser::changeHeadValue(const std::string& statement) {
	head->value = statement;
}

//Prints the tree in order
void StatementParser::print() const {
	printNode(head);
	std::cout << std::endl;
}

//Helper function for print
void StatementParser::printNode(StatementNode* s) const {
	if (s->left)
		printNode(s->left);
	if (s->opType == 'v')
		std::cout << s->value << " ";
	else
		std::cout << s->opType << " ";
	if (s->right)
		printNode(s->right);
}

//Copy helper function for copying nodes
StatementNode* StatementParser::copy_statement(StatementNode* old_node) {
	if (old_node == nullptr)
		return nullptr;
	StatementNode* new_node = new StatementNode;
	new_node->value = old_node->value;
	new_node->opType = old_node->opType;
	new_node->left = copy_statement(old_node->left);
	new_node->right = copy_statement(old_node->right);
	return new_node;
}

// Recursively parses a statment
// Assumes statement is of format (A) & (B)
void StatementParser::parseStatement(StatementNode* n, const std::string& statement){
	int parenCount = 0;
	unsigned int i;

	//If there's no parenthesis at the start, statement is basic
	if (statement[0] != '(') {
		n->value = statement;
		n->opType = 'v';
		return;
	}

	//Evaluates the left
	i = 0;
	bool neg = false;
	int start = 1;
	if(statement[0] == '~'){
		neg = true;
		i=2;
		start = 1;
	}
	for (; i < statement.size(); i++) {
		if (statement[i] == '(')
			parenCount++;
		else if (statement[i] == ')')
			parenCount--;
		//parenCount == zero suggests a fully closed statement
		if (parenCount == 0) {
			
			//subStatementL is the inner statement without parentheses
			std::string subStatementL = statement.substr(start, i-1);
			if(i == statement.size()-1){
				if(neg){
					n->negation = n->negation;
				}
				parseStatement(n, subStatementL);
			}
			else{
				//Give subStatementL to left node for parsing
				n->left = new StatementNode();
				n->left->negation = neg;
				parseStatement(n->left, subStatementL);
				//Statement is compound, find the opType
				n->opType = statement[i+2];
	
				//Create a node for the right statement
				n->right = new StatementNode();
				int rStart = i+5;
				neg = false;
				if(statement[i+3] == '~'){
					neg = true;
					rStart = i+6;
				}
				std::string subStatementR = statement.substr(rStart, statement.size()-(i+5)-1);
				parseStatement(n->right, subStatementR);
				break;
			}
		}
	}
}