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
	if (s->negation) 
		std::cout << '~';
	if (s->opType == 'v') 
		std::cout << s->value;
	else {
		std::cout << '(';
		printNode(s->left);
		std::cout << ") ";
		std::cout << s->opType << " (";
		printNode(s->right);
		std::cout << ")";
	}
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
// Assumes statement is of format ((A) & (B)) & (~C)
void StatementParser::parseStatement(StatementNode* n, const std::string& statement){
	int parenCount = 0;
	unsigned int i;

	//If there is a negation character, negate the current head node and recurse
	if (statement[0] == '~') {
		n->negation = !(n->negation);
		//If there's no parenthesis after, statement is basic
		if (statement[1] != '(') {
			n->value = statement.substr(1, statement.size()-1);
			n->opType = 'v';
			return;
		}
		//Otherwise, statement is compound
		//Recurse with outer parentheses removed
		parseStatement(n, statement.substr(2, statement.size()-3));
		return;
	}

	//If there's no parenthesis at the start, statement is basic
	if (statement[0] != '(') {
		n->value = statement;
		n->opType = 'v';
		return;
	}

	//Evaluates the left
	for (i = 0; i < statement.size(); i++) {
		if (statement[i] == '(')
			parenCount++;
		else if (statement[i] == ')')
			parenCount--;
		//parenCount == zero suggests a fully closed statement
		if (parenCount == 0) {

			//subStatementL is the inner statement without parentheses
			std::string subStatementL = statement.substr(1, i-1);

			//Give subStatementL to left node for parsing
			n->left = new StatementNode();
			parseStatement(n->left, subStatementL);
			break;
		}
	}
	//Statement is compound, find the opType
	n->opType = statement[i+2];

	//Create a node for the right statement
	std::string subStatementR = statement.substr(i+5, statement.size()-(i+5)-1);
	n->right = new StatementNode();
	parseStatement(n->right, subStatementR);
} 