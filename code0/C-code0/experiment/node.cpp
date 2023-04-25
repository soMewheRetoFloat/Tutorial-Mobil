#include "node.h"
#include "operx.h"

Node::~Node() = default;

void PlaceholderNode::set_val(float val) {
    this -> value_ = val;
}

void PlaceholderNode::calc() {}