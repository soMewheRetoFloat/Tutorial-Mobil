#include "try_addition.h"

AdditionNode::AdditionNode(string name, Node* input1, Node* input2) : OperationNodeTwo(name, input1, input2) {}

void AdditionNode::UpdateValue() {
    value_ = input1->value() + input2->value();
}
