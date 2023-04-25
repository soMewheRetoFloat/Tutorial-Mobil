#include "try_subtraction.h"

SubtractionNode::SubtractionNode(string name, Node* input1, Node* input2) : OperationNodeTwo(name, input1, input2) {}

void SubtractionNode::UpdateValue() {
    value_ = input1->value() - input2->value();
}
