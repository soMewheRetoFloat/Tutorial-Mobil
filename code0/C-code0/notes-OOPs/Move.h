#ifndef _MOVE_H_
#define _MOVE_H_

class Move {
 private:
    double x;
    double y;
    double calc(); // calculate x * y
 public:
    Move(double a, double b); // init x and y to a and b
    Move(double a) {
      x = a;
      y = 2 * a;
    };
    void display(); // display the result of calc()
    double get_x(); // return x
    double get_y(); // return y
    void reset(double a, double b);
				// reset x and y to a and b
    
   ~Move() {};// 
};

#endif