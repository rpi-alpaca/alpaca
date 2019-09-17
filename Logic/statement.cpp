#include "statement.h"
#include <string>
#include <vector>

Statement::Statement() {
	input_statement = "Variable_def";
	statement_type = 'v';
}
Statement::Statement(const std::string& input) {
	input_statement = input;
	if(input_statement.find("&&") >= 0){
		statement_type = '&';
	}
	else if(input_statement.find("||") >= 0){
		statement_type = '|';
	}
	else if(input_statement.find("~") >= 0){
		statement_type = '~';
	}
	else{
		statement_type = 'v';
	}
}
void Statement::interpretStatement() {

}

