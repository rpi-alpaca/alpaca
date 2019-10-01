

#include "statement.h"
#include "statementevaluator.h"



bool StatementEvaluator::evaluateStatement(StatementParser& s, std::unordered_map<std::string, bool>& variableValues) const{
	bool isTrue = evaluateBranch(s.head, variableValues);
	return isTrue;
}


bool StatementEvaluator::evaluateBranch(StatementNode* p, std::unordered_map<std::string, bool>& variableValues) const{
	//Node is not an operation (variable)
	if(p -> opType == 'v'){
		return variableValues[p -> value];
	}
	else if(p -> opType == '~'){
		return !evaluateBranch(p -> left, variableValues);
	}
	else{
		std::function<bool(bool,bool)> operation = functionMap.find(p -> opType) -> second;
		return operation(evaluateBranch(p -> left, variableValues), evaluateBranch(p-> right, variableValues));
	}
}
/*
bool StatementEvaluator::printTruthTable(const StatementParser& s, const std::unordered_map<std::string, bool>& variableValues) const{
	
}*/
