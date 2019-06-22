#pragma once
class BooleanExpression {
public:
	virtual void Print() = 0;
	virtual bool Evaluate() = 0;
	virtual bool isTautology() = 0;
	virtual bool isContraDiction() = 0;
	virtual ~BooleanExpression() {}
	bool getType() const;
protected:
	bool isANumber; //Ако обектът е NUM, ще пазим тук 1, а ако обектът е Операция, ще пазим тук 0.
}; 
