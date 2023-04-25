#include "graph.h"
#include "try_addition.h"
#include "try_subtraction.h"

Graph::Graph(int num_node) {
    nodes_.initialize(num_node);
}

void Graph::InsertPlaceholder(const string &node_name) {
    PlaceholderNode* new_node = new PlaceholderNode(node_name);
    nodes_.insert(node_name, new_node);
}

void Graph::InsertConstant(const string &node_name, float value) {
    ConstantNode* new_node = new ConstantNode(node_name, value);
    nodes_.insert(node_name, new_node);
}

void Graph::InsertOperation(const string &node_name, const string &operation_type,
                            const string &input1, const string &input2) {
    Node* in1 = nodes_[input1];
    Node* in2 = nodes_[input2];
    OperationNodeTwo* new_node;

    if (operation_type == "+") {
        new_node = new AdditionNode(node_name, in1, in2);
    } else if (operation_type == "-") {
        new_node = new SubtractionNode(node_name, in1, in2);
    }

    nodes_.insert(node_name, new_node);
}

void Graph::Eval(const string &node_name, const int &argument_num,
                 const string* argument_name_list_, const float* argument_value_list_) {
    for (int i = 0; i < argument_num; ++i) {
        PlaceholderNode* ph_node = dynamic_cast<PlaceholderNode*>(nodes_[argument_name_list_[i]]);
        ph_node->set_val(argument_value_list_[i]);
    }

    nodes_[node_name] -> calc();
    float result = nodes_[node_name] -> value();
    std::cout << std::fixed << std::setprecision(2) << result << std::endl;
}

Graph::~Graph() = default;
