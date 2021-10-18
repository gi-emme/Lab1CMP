#include <iostream>
#include <cmath>

using namespace std;

class Complex{
 public:
  //constructors
  Complex(){}
  
  Complex(double x, double y){
    x_ = x;
    y_ = y;
  }
  
  Complex(const Complex& z){
    x_ = z.x_;
    y_ = z.y_;
  }

  //setters:
  void setRealPart(const double x){ x_ = x; }
  void setImPart(const double y){ y_ = y; }

  //print the complex number:
  void print(){
    cout << "z = " << x_ << "+i(" << y_ << ")" << endl;
  }

  //real part
  double re(){
    return x_;
  }

  //imaginary part
  double im(){
    return y_;
  }

  //magnitude
  double mag(){
    return sqrt(x_*x_+y_*y_);
  }

  //inverse
  Complex inverse(){
    double x;
    double y;
    if(x_ == 0 && y_ == 0){
      cerr << "Null complex number. Cannot compute inverse. " 
	   << "Setting number to zero." << endl;
      return Complex(0,0);
    }else{
      if(x_ == 0){
	x = 0;
	y = -1./y_;
      }else{
	x = 1./(x_*x_ + y_*y_);
	y = -(y_/x_)*x;
      }
      return Complex(x,y);
    }
  }
  

  //phase
  double phase(){
    return atan(y_/x_);
  }

  //overloading of operations between complex objects
  //sum
  Complex operator+(const Complex& z) const {
    double x = x_ + z.x_;
    double y = y_ + z.y_;
    return Complex(x,y);
  }

  //difference
  Complex operator-(const Complex& z) const {
    double x = x_ - z.x_;
    double y = y_ - z.y_;
    return Complex(x,y);
  } 

  //product
  Complex operator*(const Complex& z) const {
    double x = x_*z.x_ - y_*z.y_;
    double y = x_*z.y_ + y_*z.x_;
    return Complex(x,y);
  }

  //division
  Complex operator/(Complex& z) const {
    //we first compute the inverse, than take the product with it
    Complex z_inv = z.inverse();
    double a = z_inv.re();
    double b = z_inv.im();

    double x = x_*a - y_*b;
    double y = x_*b + y_*a;

    return Complex(x,y); 
  }

  //reassignment
  const Complex& operator=(const Complex& z){
    x_ = z.x_;
    y_ = z.y_;
    return *this;
  }

  //operator +=
  const Complex& operator+=(const Complex& z){
    x_ += z.x_;
    y_ += z.y_;
    return *this;
  }

  //operator -=
   const Complex& operator-=(const Complex& z){
    x_ -= z.x_;
    y_ -= z.y_;
    return *this;
  }

  //operator *=
  const Complex& operator*=(const Complex& z){
    double a = x_;
    double b = y_;
    x_ = (a)*z.x_ - (b)*z.y_;
    y_ = (a)*z.y_ + (b)*z.x_;
    return *this;
  }
  
 private:
  double x_; //real part
  double y_; //imaginary part
};


//implementing operations between Complex objects and doubles as global functions
//product by a double
Complex operator*(const double& a, Complex& z){
  return Complex(a*z.re(),a*z.im());
}

//division by a double
Complex operator/(Complex& z, const double& a){
  return Complex(z.re()/a,z.im()/a);
}
  

int main(){
  
  cout << "ciao" << endl;
  
  Complex z1(0,1);
  Complex z2(1,0);

  
  z1.print();
  double r1 = z1.mag();
  cout << "magnitude of z:" << r1 << endl;
  double x1 = z1.re();
  double y1 = z1.im();
  cout << "real part of z1:" << x1 << endl;
  cout << "imaginary part of z1:" << y1 << endl;

  double phase1 = z1.phase();
  cout << "phase of z1:" << phase1 << " rad" << endl;

  Complex z3 = z1 + z2;
  z3.print();

  Complex z4 = z2 - z1;
  z4.print();
  
  Complex z5(1,1);
  Complex z6 = z5 * z1;
  z6.print();

  Complex z7 = z1.inverse();
  z7.print();

  Complex z8(0,0);
  Complex z9 = z8.inverse();
  z9.print();

  Complex z10 = z1.inverse();
  z10.print();

  Complex z11 = z1 * z10;
  z11.print();

  Complex z12 = z1 / z10;
  z12.print();

  double a = 5.44;
  Complex z13 = a*z1;
  z13.print();

  Complex z14 = z1/a;
  z14.print();

  z1 = z14;
  z1.print();

  z1 += Complex(1,0);
  z1.print();

  z1 -= z1;
  z1.print();

  Complex z15(0,1);
  z15 *= z15;
  z15.print();
  
  return 0;
}
