#ifndef Triangle_h
#define Triangle_h

struct Point {
   double x, y;
};

struct Triangle {
    Point A, B, C;

    bool contains(const Point &P) const;
    bool containsHeron(const Point &P) const; 
    bool isDegenerate() const;
};

double crossProduct(const Point& A, const Point& B, const Point& C);

double distance(const Point& p1, const Point& p2);
double triangleArea(const Point& A, const Point& B, const Point& C);

void runProgram();

#endif