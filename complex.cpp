#include <iostream>
#include <cmath>
#include "Complex.h"

using namespace std;

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

  Complex z15(0.,1.);
  z15 *= z15;
  z15.print();

  Complex q(1,0);
  q /= q;
  q.print();
  
  return 0;
}