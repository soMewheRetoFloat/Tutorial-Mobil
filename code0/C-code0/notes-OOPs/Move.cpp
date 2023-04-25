#include <iostream>
#include "Move.h"
using namespace std;
auto Move::calc() -> decltype(x * y)  {
    return x * y;
}

Move::Move(double a = 0, double b = 0) {
    this -> x = a;
    this -> y = b;
}

void Move::display() {
    cout << this -> calc() << endl;
}

double Move::get_x() {
    return this -> x;
}

double Move::get_y() {
    return this -> y;
};

void Move::reset(double a = 0, double b = 0) {
    this -> x = a;
    this -> y = b;
}
    
