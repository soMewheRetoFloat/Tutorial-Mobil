#pragma once
#include "operation.h"
#include "node.h"

//双目运算符子类
class Oplus : public OperationNodeTwo {
public:
    Oplus(string name, Node *lhs, Node *rhs): OperationNodeTwo(name, lhs, rhs) {};
    virtual void UpdateValue() override;
};

class Osubt : public OperationNodeTwo {
public:
    Osubt(string name, Node *lhs, Node *rhs): OperationNodeTwo(name, lhs, rhs) {};
    virtual void UpdateValue() override;
};

