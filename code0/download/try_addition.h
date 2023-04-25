#pragma once
#include "operation.h"

class AdditionNode : public OperationNodeTwo {
public:
    AdditionNode(string name, Node* input1, Node* input2);
    void UpdateValue() override;
};
