
#ifndef __STATEMENT_EVALUATOR_H_
#define __STATEMENT_EVALUATOR_H_

#include <functional>
#include <unordered_map>

class StatementEvaluator{
	public:
		StatementEvaluator();
		bool evaluateStatement(const Statement& s, const std::vector<int> variableTruthValues) const;
		void printTruthTree(const Statement& s) const;

	private:
		//Mapping of operation characters to the corresponding functions.
		std::unordered_map<char, std::function<bool (bool, bool)> > functionMap();
}

#endif