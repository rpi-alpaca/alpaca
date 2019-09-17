
#ifndef __STATEMENT_EVALUATOR_H_
#define __STATEMENT_EVALUATOR_H_

class StatementEvaluator{
	public:
		bool evaluateStatement(const Statement& s, const std::vector<int> variableTruthValues);
		void printTruthTree(const Statement& s);

	private:

}

#endif