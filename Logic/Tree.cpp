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
		std::cout << " ";
		std::cout << s->opType << " ";
		printNode(s->right);
		std::cout << ")";
	}
}

//Print the tree as its structure
void StatementParser::printTree() const {
	printTreeHelper(head, 0);
}

//Helper function for tree print
void StatementParser::printTreeHelper(StatementNode* s, int depth) const {
	if (!s)
		return;
	printTreeHelper(s->right, depth+1);
	std::cout << std::string(depth, '\t') << (s->negation ? '~' : ' ') << s->opType;
	if (s->opType == 'v')
		std::cout << ": " << (s->negation ? '~' : ' ') << s->value;
	std::cout << std::endl;
	printTreeHelper(s->left, depth+1);
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

	std::string subStatementL = "";
	//Evaluates the left
	for (i = 0; i < statement.size(); i++) {
		if (statement[i] == '(')
			parenCount++;
		else if (statement[i] == ')')
			parenCount--;
		//parenCount == zero suggests a fully closed statement
		if (parenCount == 0) {

			//subStatementL is the inner statement without parentheses
			subStatementL = statement.substr(1, i-1);
			break;
		}
	}

	//Statement is compound, find the opType
	n->opType = statement[i+2];

	//subStatementR is the inner statement without parentheses after the operation
	std::string subStatementR = statement.substr(i+5, statement.size()-(i+5)-1);

	//Give subStatementL to left node for parsing
	n->left = new StatementNode();

	//Create a node for the right statement
	n->right = new StatementNode();

	//Changes conditional A -> B to ~A | B
	if(n->opType == '>'){
		n->left->negation = !(n->left->negation);
		n->opType = '|';
	}
	if(n->opType == '='){
		std::string newLeft = "(" + subStatementL + ") & (" + subStatementR + ")";
		std::string newRight = "(~(" + subStatementL + ")) & (~(" + subStatementR + "))";
		n->opType = '|';
		subStatementL = newLeft;
		subStatementR = newRight;
	}

	parseStatement(n->left, subStatementL);
	parseStatement(n->right, subStatementR);
} 

// std::string conditional(std::string A, std::string B){
// 	return "(" + B + ") | (~(" + A + "))";
// }