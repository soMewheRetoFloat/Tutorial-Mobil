#include <iostream>
using namespace std;
class Animal {
 public:
    Animal() {};
    virtual void sing() {};
    virtual void swim() {};
    virtual ~Animal() {};
};

class Fish final: public Animal {
 public:
    Fish(): Animal() {};
    void sing() override { cout << "fish can't sing." << endl; };
    void swim() override { cout << "fish is swimming." << endl; };
    ~Fish() { cout << "fish has gone." << endl; };
};

class Bird final: public Animal {
 public:
    Bird(): Animal() {};
    void sing() override { cout << "bird is singing." << endl; };
    void swim() override { cout << "bird can't swim." << endl; };
    ~Bird() { cout << "bird has gone." << endl; };
};



void action(Animal* pAnimal) {
	pAnimal -> sing();
	pAnimal -> swim();
}
int main(){
    Animal *myBird = new Bird();
    Animal *myFish = new Fish();
    action(myBird);
    action(myFish);
    delete myBird;
    delete myFish;
    return 0;
}
