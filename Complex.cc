#include <iostream>
#include <cmath>
#include "Complex.h"

using namespace std;

//constructors
  Complex::Complex(){}
  
  Complex::Complex(double x, double y){
    x_ = x;
    y_ = y;
  }
  
  Complex::Complex(const Complex& z){
    x_ = z.x_;
    y_ = z.y_;
  }

  //setters:
  void Complex::setRealPart(const double x){ x_ = x; }
  void Complex::setImPart(const double y){ y_ = y; }

  //print the complex number:
  void Complex::print(){
    cout << "z = " << x_ << "+i(" << y_ << ")" << endl;
  }

  //getters:
  //real part
  double Complex::re(){
    return x_;
  }

  //imaginary part
  double Complex::im(){
    return y_;
  }

  //magnitude
  double Complex::mag(){
    return sqrt(x_*x_+y_*y_);
  }

  //inverse
  Complex Complex::inverse(){
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
  double Complex::phase(){
    return atan(y_/x_);
  }

  //overloading of operations between complex objects
  //sum
  Complex Complex::operator+(const Complex& z) const {
    double x = x_ + z.x_;
    double y = y_ + z.y_;
    return Complex(x,y);
  }

  //difference
  Complex Complex::operator-(const Complex& z) const {
    double x = x_ - z.x_;
    double y = y_ - z.y_;
    return Complex(x,y);
  } 

  //product
  Complex Complex::operator*(const Complex& z) const {
    double x = x_*z.x_ - y_*z.y_;
    double y = x_*z.y_ + y_*z.x_;
    return Complex(x,y);
  }

  //division
  Complex Complex::operator/(Complex& z) const {
    //we first compute the inverse, than take the product with it
    Complex z_inv = z.inverse();
    double a = z_inv.re();
    double b = z_inv.im();

    double x = x_*a - y_*b;
    double y = x_*b + y_*a;

    return Complex(x,y); 
  }

  //reassignment
  const Complex& Complex::operator=(const Complex& z){
    x_ = z.x_;
    y_ = z.y_;
    return *this;
  }

  //operator +=
  const Complex& Complex::operator+=(const Complex& z){
    x_ += z.x_;
    y_ += z.y_;
    return *this;
  }

  //operator -=
   const Complex& Complex::operator-=(const Complex& z){
    x_ -= z.x_;
    y_ -= z.y_;
    return *this;
  }

  //operator *=
  const Complex& Complex::operator*=(const Complex& z){
    double a = x_;
    double b = y_;
    double c = z.x_;
    double d = z.y_;
    //cout << "in op *=" << endl;
    //cout << "z.x_ before: " << z.x_ << endl;
    x_ = a*c- b*d;
    y_ = a*d + b*c;
    //cout << "z.x_ after: " << z.x_ << endl;
    return *this;
  }

  //operator /=
  const Complex& Complex::operator/=(Complex& z){
    
    Complex z_inv = z.inverse(); 

    double a = x_;
    double b = y_;
    double c = z_inv.x_;
    double d = z_inv.y_;

    x_ = a*c- b*d;
    y_ = a*d + b*c;

    return *this;
  }

//product by a double
Complex operator*(const double& a, Complex& z){
  return Complex(a*z.re(),a*z.im());
}

//division by a double
Complex operator/(Complex& z, const double& a){
  return Complex(z.re()/a,z.im()/a);
}
  

  