
#include "statement.h"
#include "statementevaluator.h"

// CONSTRUCTOR		-	Initializes functionMap with characters mapped to the corresponding functions.
StatementEvaluator::StatementEvaluator(){
	functionMap['|'] = [](bool p, bool q){return p || q;};
	functionMap['&'] = [](bool p, bool q){return p && q;};
	functionMap['~'] = [](bool p){return !p;};
}


bool StatementEvaluator::evaluateStatement(const Statement& s, const std::vector<int> variableTruthValues) const{
	
}


void StatementEvaluator::printTruthTree(const Statement& s) const{

}
