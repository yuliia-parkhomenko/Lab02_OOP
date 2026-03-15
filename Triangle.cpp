#include "Triangle.h"
#include <iostream>
#include <cmath>

using namespace std;
 
double crossProduct(const Point& A, const Point& B, const Point& C)
{
  return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
bool Triangle::isDegenerate() const
{
  return fabs(crossProduct(A, B, C)) < 1e-9;
}
bool Triangle::contains(const Point &P) const
{
    double d1 = crossProduct(A, B, P);
    double d2 = crossProduct(B, C, P);
    double d3 = crossProduct(C, A, P);

if ((d1 >= 0 && d2 >= 0 && d3 >= 0) ||
   (d1 <= 0 && d2 <= 0 && d3 <= 0))
   return true;
else
   return false;
}

void runProgram()
{
   Triangle t;
   
   cout << "Введіть координати трикутника:\n";
   
   cout << "A (x, y): ";
   cin >> t.A.x >> t.A.y;

   cout << "B (x, y): ";
   cin >> t.B.x >> t.B.y;

   cout << "C (x, y): ";
   cin >> t.C.x >> t.C.y;
if (t.isDegenerate())
{
   cout << "Трикутник вироджений (площа дорівнює 0)." << endl;
   return;
}
Point P;

while(true)
{
   cout <<"Введіть координати точки (x, y): ";
   cin >> P.x >> P.y;
  if(P.x ==  0 && P.y == 0)
   break;

   double d1 = crossProduct(t.A, t.B, P);
   double d2 = crossProduct(t.B, t.C, P);
   double d3 = crossProduct(t.C, t.A, P);

  if(fabs(d1) < 1e-9 || fabs(d2) < 1e-9 || fabs(d3) < 1e-9)
  {
   cout <<"Точка знаходиться на межі трикутника." << endl;
  }

  else if(t.contains(P))
    cout <<"Точка знаходиться всередині трикутника." << endl;

 else
 {
    cout <<"Точка знаходиться поза трикутником." << endl;
    }
  }
}