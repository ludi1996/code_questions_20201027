#include <iostream>
#include <vector>
#include<cmath>
using namespace std;
struct Point{
    double x;
    double y;
};

struct Line {

    Point P1;
    Point P2;
};
struct Triangle{
    Point P1;
    Point P2;
    Point P3;
    vector<Point> P;

    Line L1;
    Line L2;
    Line L3;
    vector<Line> L;

    Triangle();
    Triangle(double _x1,double _y1, double _x2,double _y2,double _x3,double _y3){
        P1.x=_x1;
        P1.y=_y1;
        P2.x=_x2;
        P2.y=_y2;
        P3.x=_x3;
        P3.y=_y3;
        P={P1,P2,P3};
        L1 = {P1,P2};
        L2 = {P1,P3};
        L3 = {P2,P3};
        L={L1,L2,L3};

    };
};

bool IsLinesIntersection(const Line &l1, const Line &l2)
{

    if ((l1.P1.x > l1.P2.x ? l1.P1.x : l1.P2.x) < (l2.P1.x < l2.P2.x ? l2.P1.x : l2.P2.x) ||
        (l1.P1.y > l1.P2.y ? l1.P1.y : l1.P2.y) < (l2.P1.y < l2.P2.y ? l2.P1.y : l2.P2.y) ||
        (l2.P1.x > l2.P2.x ? l2.P1.x : l2.P2.x) < (l1.P1.x < l1.P2.x ? l1.P1.x : l1.P2.x) ||
        (l2.P1.y > l2.P2.y ? l2.P1.y : l2.P2.y) < (l1.P1.y < l1.P2.y ? l1.P1.y : l1.P2.y))
    {
        return false;
    }

    if ((((l1.P1.x - l2.P1.x)*(l2.P2.y - l2.P1.y) - (l1.P1.y - l2.P1.y)*(l2.P2.x - l2.P1.x))*
        ((l1.P2.x - l2.P1.x)*(l2.P2.y - l2.P1.y) - (l1.P2.y - l2.P1.y)*(l2.P2.x - l2.P1.x))) > 0 ||
        (((l2.P1.x - l1.P1.x)*(l1.P2.y - l1.P1.y) - (l2.P1.y - l1.P1.y)*(l1.P2.x - l1.P1.x))*
        ((l2.P2.x - l1.P1.x)*(l1.P2.y - l1.P1.y) - (l2.P2.y - l1.P1.y)*(l1.P2.x - l1.P1.x))) > 0)
    {
        return false;
    }
    return true;
}


double ComputeTriangleArea(const Triangle &t)
{
    double a=sqrt(pow((t.P1.x-t.P2.x),2)+pow((t.P1.y-t.P2.y),2));
    double b=sqrt(pow((t.P2.x-t.P3.x),2)+pow((t.P2.y-t.P3.y),2));
    double c=sqrt(pow((t.P1.x-t.P3.x),2)+pow((t.P1.y-t.P3.y),2));
    double p=(a+b+c)/2;
    double s=sqrt(p*(p-a)*(p-b)*(p-c));
    return s;
}

bool IsPointInTriangle(const Point &P,const Triangle &t){
    Triangle PAB(P.x,P.y,t.P1.x,t.P1.y,t.P2.x,t.P2.y);
    Triangle PAC(P.x,P.y,t.P1.x,t.P1.y,t.P3.x,t.P3.y);
    Triangle PBC(P.x,P.y,t.P2.x,t.P2.y,t.P3.x,t.P3.y);
    double area_ABC = ComputeTriangleArea(t);
    double area_PAB = ComputeTriangleArea(PAB);
    double area_PAC = ComputeTriangleArea(PAC);
    double area_PBC = ComputeTriangleArea(PBC);
    if(fabs(area_PAB + area_PBC + area_PAC - area_ABC) < 0.000001)
        return true;
    else return false;

}

bool IsATriangleInAnother(const Triangle &t1,const Triangle &t2){

    for(int i=0; i<3;i++){
        if(IsPointInTriangle(t1.P[i],t2))
            return true;
    }
    for(int i=0; i<3;i++){
        if(IsPointInTriangle(t2.P[i],t1))
            return true;
    }
    return false;
}

bool IsTrianglesIntersection(const Triangle &t1, const Triangle &t2){
    for(int i = 0; i<3;i++)
        for(int j = 0; i<3;i++)
        {
            if(IsLinesIntersection(t1.L[i], t2.L[j]))
                return true;
        }

    if (IsATriangleInAnother(t1,t2))
        return true;
    else
        return false;

}


int main() {
    double a,b,c,d,e,f;
    cout << "input triangle1:" << endl;
    cin >> a >> b >> c >> d >> e >> f ;
    Triangle triangle1 = {a,b,c,d,e,f};
    cout << "input triangle2:" << endl;
    cin >> a >> b >> c >> d >> e >> f ;
    Triangle triangle2 = {a,b,c,d,e,f};

    if(IsTrianglesIntersection(triangle1, triangle2))
        cout << "Intersect!" << endl;
    else
        cout << "Not Intersect!" << endl;

    return 0;
}
