
#include "statement.h"
#include "statementevaluator.h"


bool StatementEvaluator::evaluateStatement(StatementParser& s, std::vector<std::pair<std::string, bool> >& variableTruthValues) const{
	std::unordered_map<std::string, bool> variableValues;
	for(int i = 0; i < variableTruthValues.size(); i++){
		variableValues[variableTruthValues[i].first] = variableTruthValues[i].second;
	}

	bool isTrue = evaluateBranch(s.head, variableValues);
	return isTrue;
}


void StatementEvaluator::printTruthTable(const StatementParser& s, const std::vector<std::string> variableNames) const{
	std::vector<std::pair<std::string, bool> > variableTruthValues;
	for(int i = 0; i < variableNames.size(); i++){
		variableTruthValues.push_back(std::make_pair(variableNames[i], true));
	}

	recurseDownArray(s, variableTruthValues, 0);
}


bool StatementEvaluator::evaluateBranch(StatementNode* p, std::unordered_map<std::string, bool>& variableValues) const{
	//Node is not an operation (variable)
	/*if(p -> opType == 'v'){
		return variableValues[p -> value];
	}
	else if(p -> opType == '~'){
		return !evaluateBranch(p -> left, variableValues);
	}
	else{
		std::function<bool(bool,bool)> operation = functionMap.find(p -> opType) -> second;
		return operation(evaluateBranch(p -> left, variableValues), evaluateBranch(p-> right, variableValues));
	}*/
	return true;
}


void StatementEvaluator::recurseDownArray(const StatementParser& s, std::vector<std::pair<std::string, bool> >& variableTruthValues, int index) const{
	if(index == variableTruthValues.size()){

	}
	else{
		recurseDownArray(s, variableTruthValues, index + 1);
		variableTruthValues[index].second = false;
		recurseDownArray(s, variableTruthValues, index + 1);
		variableTruthValues[index].second = true;
	}
}
