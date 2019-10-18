//LogicTest.cpp

#include "LogicGate.h"

int main(){
	
	LogicGate newLogic;

	newLogic.asciiDraw();

	newLogic.addStatement('A');

	newLogic.asciiDraw();

	newLogic.changeOnOff('A', false);

	newLogic.changeOnOff('B', false);

	newLogic.asciiDraw();

	newLogic.addStatement('B');

	newLogic.asciiDraw();

	newLogic.removeStatement('B');

	newLogic.asciiDraw();

	newLogic.removeStatement('C');

	newLogic.asciiDraw();

	std::string rawAction;
	char newState;
	bool operSucc;
	std::string changeCurrState;
	bool stateChange;
	int operationDo;

	newLogic.clearStates();

	while(true){

		newLogic.asciiDraw();

		std::cout << "Type an operation to do" << std::endl;
		std::cout << "0: Break, 1: Add Statement 2: Remove Statement 3: ChangeState" << std::endl;
		std::cin >> rawAction;

		if(isdigit(rawAction[0]))operationDo = stoi(rawAction);
		else{
			std::cout << "Not a number operation" << std::endl;
			continue;
		}

		if(operationDo == -0) break;

		else if(operationDo == 1){
			std::cout << "Type a statement to add" << std::endl;
			std::cin >> newState;

			operSucc = newLogic.addStatement(newState);

			if(!operSucc) std::cout << "Sorry Couldn't Add!" << std::endl;

		}

		else if(operationDo == 2){
			std::cout << "Type a statement to remove" << std::endl;
			std::cin >> newState;

			operSucc = newLogic.removeStatement(newState);

			if(!operSucc) std::cout << "Sorry Couldn't Remove!" << std::endl;

		}

		else if(operationDo == 3){

			std::cout << "Type a statement to change" << std::endl;
			std::cin >> newState;
			std::cout << "Type state to change (true/false)" << std::endl;
			std::cin >> changeCurrState;

			if(changeCurrState == "true") stateChange = true;
			else if(changeCurrState == "false") stateChange = false;
			else {
				std::cout << "Sorry, not valid state change" << std::endl;
				continue;
			}

			//Function includes error message
			newLogic.changeOnOff(newState, stateChange);

		}

		else{
			std::cerr << "Not a viable action" << std::endl;
		}

		
	}

	return 0;
}