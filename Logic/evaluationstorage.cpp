
#include "statementevaluator.cpp"

//This checks whether the statement is being stored in storage
bool EvaluationStorage::containsStatement(const Statement& s) const{
	return false;
}


bool EvaluationStorage::containsEvaluation(const Statement& s, const std::vector<bool>& truthValues) const{
	return false;
}


int evaluateStatement(const Statement& s, const std::vector<bool>& truthValues) const{
	return false;
}