#include "node.h"
#include "operation.h"

Node::~Node() = default;

void PlaceholderNode::set_val(float val) {
    value_ = val;
}

void PlaceholderNode::calc() {}

OperationNodeTwo::~OperationNodeTwo() = default;

void OperationNodeTwo::calc() {
    input1->calc();
    input2->calc();
    UpdateValue();
}
