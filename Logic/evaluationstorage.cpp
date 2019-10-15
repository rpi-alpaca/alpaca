
#include "evaluationstorage.h"

/* containsStatement
 * Requires: s is a valid StatementParser
 * Returns: A boolean indicating whether the statement is already being tracked
 */
bool EvaluationStorage::containsStatement(const StatementParser& s) const{
	return false;
}

/* containsEvaluation
 * Requires: s is a valid StatementParser
 * Returns: A boolean indicating whether the evaluation is already stored
 */
bool EvaluationStorage::containsEvaluation(const StatementParser& s, const std::vector<bool>& truthValues) const{
	return false;
}


/* evaluateStatement
 * Requires: s is a valid StatementParser
 * Returns: A int indicating whether the statement evaluates to true or false (-1 - not present)
 */
int EvaluationStorage::evaluateStatement(const StatementParser& s, const std::vector<bool>& truthValues) const{
	return false;
}


/* addStatement
 * Requires: s is a valid StatementParser
 * Returns: A int indicating whether the statement evaluates to true or false (-1 - not present)
 */
void EvaluationStorage::addStatement(const StatementParser& s){

}


void EvaluationStorage::addEvaluation(const StatementParser& s, const std::vector<bool>& truthValues){

}
