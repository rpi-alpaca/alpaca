
//The EvaluationStorage class stores Statements with evaluations that have already 
//been computed for fast access/to avoid frequent computation.
#include "statementevaluator.h"

#ifndef _EVALUATION_STORAGE_H_
#define _EVALUATION_STORAGE_H_

class EvaluationStorage{
public:
	bool containsStatement(const Statement& s) const;
	bool containsEvaluation(const Statement& s, const std::vector<bool>& truthValues) const;
	int evaluateStatement(const Statement& s, const std::vector<bool>& truthValues) const;
	void addStatement(const Statement& s);
	void addEvaluation(const Statement& s, const std::vector<bool>& truthValues);

private:
	std::unordered_map<int, bool> storedStatements;
}

#endif