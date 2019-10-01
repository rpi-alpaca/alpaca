#include "Tree.h"

StatementParser::StatementParser(){
	head = new StatementNode;
}

StatementParser::StatementParser(const StatementParser& s) {
	head = new StatementNode;
	head = copy_statement(s.head);
}

StatementParser::StatementParser(const StatementParser& s1, const StatementParser& s2) {
	head = new StatementNode;
	head->connector = '&';
	head->left = copy_statement(s1.head);
	head->right = copy_statement(s2.head);
}

StatementParser::StatementParser(const std::string& statement){
	//this->head = nullptr;
	//split it up
	head = new StatementNode;
	head -> value = statement;
	if (statement.find('(') >= 0){
		//Note to self: maybe we should count how many parentheses there are to check if the input is valid?
		std::string stat1 = "";
		std::string stat2 = "";
		
	}
	else{
		if (statement.find('&') >= 0){
			head -> opType = '&';
		}
		else if(statement.find('|') >= 0){
			head -> opType = '|';
		}
		else if(statement.find('@') >= 0){
			head -> opType = '@';
		}
		else{
			head -> opType = 'v';
			if(statement.find('~') >= 0){
				head -> negation = true;
			}
			else{
				head -> negation = false;
			}
		}
	}
	
}

void StatementParser::changeHeadValue(const std::string& statement) {
	head->value = statement;
}

//Copy helper function for copying nodes
StatementNode* StatementParser::copy_statement(StatementNode* old_node) {
	if (old_node == nullptr)
		return nullptr;
	StatementNode* new_node = new StatementNode;
	new_node->value = old_node->value;
	new_node->left = copy_statement(old_node->left);
	new_node->right = copy_statement(old_node->right);
	return new_node;
}