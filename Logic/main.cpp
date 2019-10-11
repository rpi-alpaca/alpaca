// this is the main file for the logic team


/*
	This is a program that will take in a logical statement and do various functions
	
*/


#include <iostream>
#include "Tree.h"


void statementEvaluatorTest();

int main(int argc, char* argv[]) {
	StatementParser state1;
	StatementParser state2;
	state1.changeHeadValue("The sky is blue");
	state2.changeHeadValue("Hali's shirt is blue");
	StatementParser combined(state1, state2);

	state1.print();
	std::cout << std::endl;
	state2.print();
	std::cout << std::endl;
	combined.print();
	std::cout << std::endl;


	std::cout<< "Testing" <<std::endl;

	statementEvaluatorTest();

	//Testing Cases

	return 0;
}


void statementEvaluatorTest(){
	std::cout << "RUNNING STATEMENTEVALUATORTEST\n\n";

	StatementParser state1;
	StatementParser state2;
	state1.changeHeadValue("The sky is blue");
	state2.changeHeadValue("Hali's shirt is blue");
	StatementParser combined(state1, state2);

	std::vector<std::string> variables;
	variables.push_back("The sky is blue");
	variables.push_back("Hali's shirt is blue");

	//Testing printTruthTable and evaluateStatement
	StatementEvaluator eval;
	eval.printTruthTable(combined, variables);
}
