#include "operation.h"
#include "node.h"
#include "operx.h"

void Oplus::UpdateValue() {
        value_ = input1 -> value() + input2 -> value();
}

void Osubt::UpdateValue() {
        value_ = input1 -> value() - input2 -> value();
}