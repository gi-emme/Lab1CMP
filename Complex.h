#include <iostream>

using namespace std;

class Complex{
 public:
  //constructors
  Complex(); 
  Complex(double x, double y);
  Complex(const Complex& z);

  //setters:
  void setRealPart(const double x);
  void setImPart(const double y);

  //print the complex number:
  void print();

  //real part
  double re();

  //imaginary part
  double im();

  //magnitude
  double mag();
  
  //phase
  double phase();

  //inverse
  Complex inverse();

  //overloading of operations between complex objects
  //sum
  Complex operator+(const Complex& z) const;

  //difference
  Complex operator-(const Complex& z) const;

  //product
  Complex operator*(const Complex& z) const;

  //division
  Complex operator/(Complex& z) const;

  //reassignment
  const Complex& operator=(const Complex& z);

  //operator +=
  const Complex& operator+=(const Complex& z);

  //operator -=
   const Complex& operator-=(const Complex& z);

  //operator *=
  const Complex& operator*=(const Complex& z);

  //operator /=
  const Complex& operator/=(Complex& z);

  
 private:
  double x_; //real part
  double y_; //imaginary part
};

//implementing operations between Complex objects and doubles as global functions
//product by a double
Complex operator*(const double& a, Complex& z);

//division by a double
Complex operator/(Complex& z, const double& a);