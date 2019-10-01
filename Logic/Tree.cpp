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
	head -> value = statement;
	int firstParen = statement.find('(');
	if (firstParen != std::string::npos){
		//Note to self: maybe we should count how many parentheses there are to check if the input is valid?
		std::string stat1 = "";
		std::string stat2 = "";
		if(firstParen == 0){
			int nextStart = 1;
			int nextEnd = 1;
			bool contin = true;
			while(contin){
				int nextParen = statement.find('(', nextStart);
				int nextClosed = statement.find(')', nextEnd)
				if(nextClosed = std::string::npos){
					//error
					System.out.println("Error: Incorrect inputs")
					break;
				}
				if(nextParen != std::string::npos && nextParen < nextClosed){
					nextStart = nextParen + 1;
					nextClosed = nextParen + 1;
				}
				else{
					contin = false;
				}
			}
			if(!contin){
				// just a check to make sure when there is an error it doesn't go into here
				stat1 = statement.substr(0, firstParen);
				stat2 = statement.substr(firstParen + 1, nextClosed);
				
			}
		}
		else{

		}
		
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
