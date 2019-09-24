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
	head.value = statement;
	if (statement.find('(') >= 0){
		std::string stat1 = "";
		std::string stat2 = "";
	}
	else{
		if (statement.find('&') >= 0){
			head.opType = '&';
		}
		else if(statement.find('|') >= 0){
			head.opType = '|';
		}
		else if(statement.find('@') >= 0){
			head.opType = '@';
		}
		else{
			head.opType = 'v';
			if(statement.find('~') >= 0){
				head.negation = true;
			}
			else{
				head.negation = false;
			}
		}
	}
	
}
