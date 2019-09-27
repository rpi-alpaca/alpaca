#include "Tree.h"

StatementParser::StatementParser(){
	head = nullptr;
}

StatementParser::StatementParser(StatementParser& s1, StatementParser& s2) {
	head = new StatementNode();
	head->left = s1.head;
	head->right = s2.head;
	head->connector = '&';
	delete(s1);
	delete(s2);
}

StatementParser::StatementParser(const std::string& statement){
	//this->head = nullptr;
	//split it up
	head = new StatementNode();
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