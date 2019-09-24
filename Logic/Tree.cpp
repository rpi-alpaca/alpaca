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
	
}
