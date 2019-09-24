// this is the main file for the logic team


/*
	This is a program that will take in a logical statement and do various functions


	
*/


#include <iostream>
#include "statement.h"
#include "statementevaluator.h"
#include "Tree.h"

int main(int argc, char* argv[]) {
	StatementParser state1;
	StatementParser state2;
	state1.changeHeadValue("The sky is blue");
	state2.changeHeadValue("Hali's shirt is blue");
	StatementParser combined(state1, state2);


	std::cout<< "Testing" <<std::endl;

	//Testing Cases

	return 0;
}
