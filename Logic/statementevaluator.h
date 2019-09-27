
#ifndef _STATEMENT_EVALUATOR_H_
#define _STATEMENT_EVALUATOR_H_

#include "Tree.h"
#include <functional>
#include <unordered_map>
#include <vector>

class StatementEvaluator{
	public:
		//bool evaluateStatement(const StatementParser& s, const std::vector<int>& variableTruthValues) const;

	private:
		//Mapping of operation characters to the corresponding functions.
		std::unordered_map<char, std::function<bool (bool, bool)> > functionMap();
		std::unordered_map<char, std::function<bool (bool, bool)> > functionMap = {
			{'|', [](bool p, bool q){return p || q;}},
			{'&', [](bool p, bool q){return p && q;}},
			{'@', [](bool p, bool q){return p xor q;}}
		};

		//bool evaluateBranch(const StatementNode& p, const std::vector<int>& variableTruthValues) const;
};

#endif