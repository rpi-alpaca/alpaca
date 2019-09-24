
#ifndef __STATEMENT_EVALUATOR_H_
#define __STATEMENT_EVALUATOR_H_

#include "Tree.h"
#include <functional>
#include <unordered_map>
#include <vector>

class StatementEvaluator{
	public:
		bool evaluateStatement(const StatementParser& s, const std::vector<int> variableTruthValues);
		void printTruthTree(const StatementParser& s) const;

	private:
		//Mapping of operation characters to the corresponding functions.
		//std::unordered_map<char, std::function<bool (bool, bool)> > functionMap();

		bool evaluateBranch(const StatementNode& p) const;
};

#endif