
#include "statementevaluator.h"

/*
bool StatementEvaluator::evaluateStatement(const StatementParser& s, const std::unordered_map<std::string, bool>& variableValues) const{
	bool isTrue = evaluateBranch(s.head);
	return isTrue;
}

bool StatementEvaluator::evaluateBranch(const StatementNode& p, const std::unordered_map<std::string, bool>& variableValues) const{
	//Node is not an operation (variable)
	if(p -> opType == 'v'){
		return variableValues[p -> value];
	}
	else if(p -> opType == '~'){
		return !evaluateBranch(p -> left);
	}
	else{
		std::function<bool(bool,bool)> operation = functionMap[p -> opType];
		return operation(evaluateBranch(p -> left, p-> right));
	}
}

bool StatementEvaluator::printTruthTable(const StatementParser& s, const std::unordered_map<std::string, bool>& variableValues) const{
	
}
*/