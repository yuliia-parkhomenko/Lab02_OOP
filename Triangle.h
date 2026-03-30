#ifndef Triangle_h
#define Triangle_h

const double EPS = 1e-9;

struct Point {
   double x, y;
};

struct Triangle {
    Point A, B, C;

    int contains(const Point &P) const;        
    int containsHeron(const Point &P) const;
    bool isDegenerate() const;
};

double crossProduct(const Point& A, const Point& B, const Point& C);

double distance(const Point& p1, const Point& p2);
double heronArea(const Point& A, const Point& B, const Point& C);

void runProgram();

#endif