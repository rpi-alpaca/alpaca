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

void StatementParser::parseStatement(StatementNode* n, std::string statement){
	int firstParen = statement.find('(');
	if (firstParen != -1){
		//Note to self: maybe we should count how many parentheses there are to check if the input is valid?
		std::string stat1 = "";
		std::string stat2 = "";
		int nextStart = 1;
		int nextEnd = 1;
		bool contin = true;
		int nextParen;
		int nextClosed;
		while(contin){
			nextParen = statement.find('(', nextStart);
			nextClosed = statement.find(')', nextEnd);
			if(nextClosed == -1){
				//error
				std::cerr << "Error: Incorrect inputs" << std::endl;
				break;
			}
			if(nextParen != -1 && nextParen < nextClosed){
				nextStart = nextParen + 1;
				nextClosed = nextParen + 1;
			}
			else{
				contin = false;
			}
		}
		if(!contin){
			// just a check to make sure when there is an error it doesn't go into here
			stat1 = statement.substr(0, nextClosed);
			int tmp = nextClosed;
			if(nextParen >= 0){
				while(tmp < nextParen){
					if(statement[tmp] == '&'){
						n->opType = '&';
						break;
					}
					else if(statement[tmp] == '|'){
						n->opType = '|';
						break;
					}
					else if(statement[tmp] == '@'){
						n->opType = '@';
						break;
					}
					tmp++;
				}
				stat2 = statement.substr(tmp + 1);
				n->right = new StatementNode();
				parseStatement(n->right, stat2);
			}
			n -> value = statement;
			n->left = new StatementNode();
			parseStatement(n->left, stat1);
		}
	}
	else{
		if (statement.find('&') >= 0){
			n -> opType = '&';
			n -> value = statement;
			n->left = new StatementNode();
			parseStatement(n->left, statement.substr(0, statement.find('&')));
			n->right = new StatementNode();
			parseStatement(n->right, statement.substr(statement.find('&') + 1));
		}
		else if(statement.find('|') >= 0){
			n -> opType = '|';
			n -> value = statement;
			n->left = new StatementNode();
			parseStatement(n->left, statement.substr(0, statement.find('|')));
			n->right = new StatementNode();
			parseStatement(n->right, statement.substr(statement.find('|') + 1));
		}
		else if(statement.find('@') >= 0){
			n -> opType = '@';
			n -> value = statement;
			n->left = new StatementNode();
			parseStatement(n->left, statement.substr(0, statement.find('@')));
			n->right = new StatementNode();
			parseStatement(n->right, statement.substr(statement.find('@') + 1));
		}
		else{
			n -> opType = 'v';
			if(statement.find('~') >= 0){
				n -> negation = true;
				n -> value = statement.substr(statement.find('~'));
			}
			else{
				n -> negation = false;
				n -> value = statement;
			}
		}
	}
}

// TODO: This doesn't work but maybe it will eventually
// void StatementParser::parseStatement(StatementNode* n, const std::string& statement){
// 	int parenCount = 0;
// 	unsigned int i;
// 	for (i = 0; i < statement.size(); i++) {
// 		if (statement[i] == '(')
// 			parenCount++;
// 		else if (statement[i] == ')')
// 			parenCount--;
// 		// parenCount == zero suggests a fully closed statement
// 		if (parenCount == 0) {
// 			//subStatement is the inner statement without parentheses
// 			std::string subStatement = statement.substr(1, i-1);
// 			n->left = new StatementNode();
// 			parseStatement(n->left, subStatement);
// 			break;
// 		}
// 	}
// 	//Didn't reach the end of the string, statement is compound
// 	if (i != statement.size()) {
// 		n->opType = statement[i+2];
// 		//Evaluate the right 
// 	}
// }