#include "Triangle.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-9;

double crossProduct(const Point& A, const Point& B, const Point& C)
{
    return (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}

double distance(const Point& p1, const Point& p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double heronArea(const Point& A, const Point& B, const Point& C)
{
    double a = distance(A, B);
    double b = distance(B, C);
    double c = distance(C, A);
    double p = (a + b + c) / 2.0;
    return sqrt(max(0.0, p*(p-a)*(p-b)*(p-c)));
}

bool Triangle::isDegenerate() const
{
    return fabs(crossProduct(A, B, C)) < eps;
}

int Triangle::contains(const Point &P) const
{
    if ((fabs(P.x - A.x) < eps && fabs(P.y - A.y) < eps) ||
        (fabs(P.x - B.x) < eps && fabs(P.y - B.y) < eps) ||
        (fabs(P.x - C.x) < eps && fabs(P.y - C.y) < eps))
        return 1;

    double d1 = crossProduct(A, B, P);
    double d2 = crossProduct(B, C, P);
    double d3 = crossProduct(C, A, P);

    if ((d1 > -eps && d2 > -eps && d3 > -eps) || (d1 < eps && d2 < eps && d3 < eps))
    {
        if (fabs(d1) < eps || fabs(d2) < eps || fabs(d3) < eps)
            return 0;
        return 1;
    }

    return -1;
}

int Triangle::containsHeron(const Point &P) const
{
    if ((fabs(P.x - A.x) < eps && fabs(P.y - A.y) < eps) ||
        (fabs(P.x - B.x) < eps && fabs(P.y - B.y) < eps) ||
        (fabs(P.x - C.x) < eps && fabs(P.y - C.y) < eps))
        return 1;

    double S  = heronArea(A, B, C);
    double S1 = heronArea(A, B, P);
    double S2 = heronArea(B, C, P);
    double S3 = heronArea(C, A, P);

    if (fabs(S - (S1 + S2 + S3)) < eps)
        return 1;

    return -1;
}

void runProgram()
{
    Triangle t;

    cout << "Введіть координати трикутника:\n";
    cout << "A (x y): ";
    cin >> t.A.x >> t.A.y;
    cout << "B (x y): ";
    cin >> t.B.x >> t.B.y;
    cout << "C (x y): ";
    cin >> t.C.x >> t.C.y;

    bool deg = t.isDegenerate();
    if (deg)
        cout << "Трикутник вироджений!\n";

    int n;
    cout << "Скільки точок перевірити? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Point P;
        cout << "\nТочка " << i + 1 << " (x y): ";
        cin >> P.x >> P.y;

        if (deg)
        {
            double d = crossProduct(t.A, t.B, P);

            double minX = min(t.A.x, min(t.B.x, t.C.x));
            double maxX = max(t.A.x, max(t.B.x, t.C.x));
            double minY = min(t.A.y, min(t.B.y, t.C.y));
            double maxY = max(t.A.y, max(t.B.y, t.C.y));

            if (fabs(d) < eps &&
                P.x >= minX - eps && P.x <= maxX + eps &&
                P.y >= minY - eps && P.y <= maxY + eps)
            {
                cout << "Точка на межі (трикутник вироджений)\n";
            }
            else
            {
                cout << "Точка не належить трикутнику (трикутник вироджений)\n";
            }

            cout << "Метод Герона: не застосовується\n";
            continue;
        }

        int res = t.contains(P);

        if (res == 1)
            cout << "Векторний метод: всередині\n";
        else if (res == 0)
            cout << "Векторний метод: на межі\n";
        else
            cout << "Векторний метод: поза\n";

        if (t.containsHeron(P) == 1)
        {
            if (res == 0)
                cout << "Метод Герона: на межі\n";
            else
                cout << "Метод Герона: всередині\n";
        }
        else
        {
            cout << "Метод Герона: поза\n";
        }
    }
}