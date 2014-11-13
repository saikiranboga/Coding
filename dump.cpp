#include<iostream>
using namespace std;

class animal
{
public:
  void /*nonvirtual*/ move() {
    cout << "animal move" << endl;
  }
  virtual void eat() {
    cout << "animal eat\n";
  }
};

// The class "animal" may possess a declaration for eat() if desired.
class fish : public animal
{
public:
  void move(){
    cout << "fish move\n";
  }
  
  // The non virtual function move() is inherited but cannot be overridden
  void eat() {
    cout << "fish eat\n";
  }  
};


// The class "animal" may possess a declaration for eat() if desired.
class fish2 : public animal
{
public:
};

int main(){
  fish *f = new fish();
  //  f->move();
  //  f->eat();

  animal *f2 = new animal();
  f2->move();
  f2->eat();
  return 0;
}
