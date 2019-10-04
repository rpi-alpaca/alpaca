
#include "statement.h"
#include "statementevaluator.h"

/* evaluateStatement
 * Requires: s is a valid StatementParser and is created correctly
 *			 variableTruthValues contains a vector of pairs where the first value is variable name and second is boolean 
 * Returns: A boolean indicating whether the statement is true given the provided variable boolean values
 */
bool StatementEvaluator::evaluateStatement(const StatementParser& s, const std::vector<std::pair<std::string, bool> >& variableTruthValues) const{
	//Creates a hash table from variable names to boolean value
	std::unordered_map<std::string, bool> variableValues;
	for(int i = 0; i < variableTruthValues.size(); i++){
		variableValues[variableTruthValues[i].first] = variableTruthValues[i].second;
	}

	bool isTrue = evaluateBranch(s.head, variableValues);
	return isTrue;
}


/* printTruthTable
 * Requires: s is a valid StatementParser and is created correctly, variableNames is a vector containing all of the variable names in s
 * Effects: Prints a truth table
 * Returns: Nothing
 */
void StatementEvaluator::printTruthTable(const StatementParser& s, const std::vector<std::string> variableNames) const{
	std::vector<std::pair<std::string, bool> > variableTruthValues;
	for(int i = 0; i < variableNames.size(); i++){
		variableTruthValues.push_back(std::make_pair(variableNames[i], true));
	}

	recurseDownArray(s, variableTruthValues, 0);
}


//PRIVATE: Helper function for evaluateStatement
bool StatementEvaluator::evaluateBranch(StatementNode* p, const std::unordered_map<std::string, bool>& variableValues) const{
	//Node is not an operation (variable)
	if(p -> opType == 'v'){
		return variableValues.find(p -> value) -> second;
	}
	else if(p -> opType == '~'){
		return !evaluateBranch(p -> left, variableValues);
	}
	else{
		std::function<bool(bool,bool)> operation = functionMap.find(p -> opType) -> second;
		return operation(evaluateBranch(p -> left, variableValues), evaluateBranch(p-> right, variableValues));
	}
	return true;
}


//PRIVATE: Helper function for printTruthTable
void StatementEvaluator::recurseDownArray(const StatementParser& s, std::vector<std::pair<std::string, bool> >& variableTruthValues, int index) const{
	if(index == variableTruthValues.size()){
		for(int i = 0; i < variableTruthValues.size(); i++){
			std::cout << std::setw(3) << variableTruthValues[index].second << " ";
		}
		std::cout << std::boolalpha << evaluateStatement(s, variableTruthValues) << "\n";
	}
	else{
		recurseDownArray(s, variableTruthValues, index + 1);
		variableTruthValues[index].second = false;
		recurseDownArray(s, variableTruthValues, index + 1);
		variableTruthValues[index].second = true;
	}
}
