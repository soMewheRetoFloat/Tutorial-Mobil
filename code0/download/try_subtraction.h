#pragma once
#include "operation.h"

class SubtractionNode : public OperationNodeTwo {
public:
    SubtractionNode(string name, Node* input1, Node* input2);
    void UpdateValue() override;
};
