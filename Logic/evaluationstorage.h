
#ifndef _EVALUATION_STORAGE_H_
#define _EVALUATION_STORAGE_H_

#include "statementevaluator.h"

//The EvaluationStorage class stores Statements with evaluations that have already 
//been computed for fast access/to avoid frequent computation.

class EvaluationStorage{
public:
	bool containsStatement(const StatementParser& s) const;
	bool containsEvaluation(const StatementParser& s, const std::vector<bool>& truthValues) const;
	int evaluateStatement(const StatementParser& s, const std::vector<bool>& truthValues) const;
	void addStatement(const StatementParser& s);
	void addEvaluation(const StatementParser& s, const std::vector<bool>& truthValues);

private:
	std::unordered_map<int, bool> storedStatements;
};

#endif