
#include "statement.h"
#include "statementevaluator.h"
#include "Tree.h"

// CONSTRUCTOR		-	Initializes functionMap with characters mapped to the corresponding functions.
StatementEvaluator::StatementEvaluator(){
	//functionMap['|'] = [](bool p, bool q){return p || q;};
	//functionMap['&'] = [](bool p, bool q){return p && q;};
	//functionMap['~'] = [](bool p){return !p;};
}


bool StatementEvaluator::evaluateStatement(const StatementParser& s, const std::vector<int> variableTruthValues) const{
	
}


bool StatementEvaluator::evaluateBranch(const StatementNode& p){

}

void StatementEvaluator::printTruthTree(const Statement& s) const{

}
