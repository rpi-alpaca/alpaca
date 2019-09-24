#include "Tree.h"

StatementParser::StatementParser(){
	head = nullptr;
}

StatementParser::StatementParser(const StatementParser& s1, const StatementParser& s2) {
	head = new StatementNode();
	
}

StatementParser::StatementParser(const std::string& statement){
	//this->head = nullptr;
	//split it up
	head = new StatementNode();
	if (statement.find('(') >= 0){

	}
	else{
		if (statement.find('&') >= 0){

		}
		else if(statement.find('|') >= 0){

		}
		else if(statement.find('@') >= 0){

		}
		else{
			if(statement.find('~') >= 0){
				head.negation = true;
			}
			else{
				head.negation = false;
			}
			head.
			head.value = statement;
		}
	}
	
}
