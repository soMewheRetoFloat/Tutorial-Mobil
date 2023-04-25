#include "compare.h"
#include "abstract_compare.h"

bool AbstractCompare<int>::compare(int a, int b) {
    return a < b;
}

AbstractCompare<int>* get_compare_int(int type){
    if (type == 1) {
        
    }
    else if (type == 2) {

    }
}

AbstractCompare<Point>* get_compare_point(int type) {

}