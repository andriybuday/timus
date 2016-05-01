#include <iostream> 
#include <cmath> 

using namespace std; 

#define eps 0.000001 

struct Point{ 

        long double x; 
        long double y; 

        Point():x(0.0), y(0.0){} 
        Point(long double xx, long double yy){x = xx; y = yy;} 
        Point(const Point &p): x(p.x), y(p.y){} 

        Point operator +(const Point &p)const{ return Point(x + p.x, y + p.y);} 
        bool operator ==(const Point &p)const{ return (fabs(x - p.x) < eps) && (fabs(y - p.y) < eps);} 
        Point operator =(const Point &p) 
        { 
                if(*this == p)return *this; 
                x = p.x, y = p.y; 
                return *this; 
        } 

        long double dist(const Point &p)const{ 
                return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); 
        } 

        friend std::istream& operator >>(std::istream & in, Point &p) 
        { 
                in >> p.x >> p.y; 
                return in; 
        } 
}; 

inline double triangle_S(Point& pa, Point& pb, Point& pc) 
{ 
        double a = pa.dist(pb); 
        double b = pb.dist(pc); 
        double c = pc.dist(pa); 
        double p = (a + b + c) / 2.0; 

        return sqrt(p * (p - a) * (p - b) * (p - c)); 
} 
inline long double min_dist_to_line(Point& A, Point& B, Point& C) 
{ 

        Point S; 
        S.x = A.x + 0.1 * (B.x - A.x); 
        S.y = A.y + 0.1 * (B.y - A.y); 
        long double res = 0.0; 
        long double a = C.dist(A); 
        long double b = C.dist(B); 
        long double d = A.dist(B); 
        long double s = C.dist(S); 

        double s1, s2; 
        s1 = ( a * a - b * b + d * d); 
        s2 = (-a * a + b * b + d * d); 

// if((s < a) && (s < b)) 
        if ((s1 > 0) && (s2 > 0)) 
        {
                res = sqrt(a * a - ((a * a - b * b + d * d) / (2.0 * d)) * 
                                   ((a * a - b * b + d * d) / (2.0 * d))); 
/*
                        res = sqrt(a + b + d) / d * sqrt(-a + b + d) * sqrt(a - b + d) * sqrt(a + b - d); 
                        res /= 2.0; 
						*/

        } else 
                res = (a > b) ? b : a; 

        return res; 
} 
         
Point a[103]; 

int main() 
{ 
        int n, i; 
        Point Center, Dolly; 
        cin >> Center; 
        cin >> n; 
        for (i = 1; i <= n; i++) 
        { 
                cin >> a[i]; 
        } 
        a[n + 1] = a[1]; 

 Dolly.x = (a[1].x + a[2].x + a[3].x) / 3.0; 
        Dolly.y = (a[1].y + a[2].y + a[3].y) / 3.0; 

        //Dolly = a[1]; 

        double S_of_target = 0.0; 
        for (int i = 1; i <= n; i++) 
        { 
                S_of_target += triangle_S(Dolly, a[i], a[i + 1]); 
        } 

        double S_of_target_from_Center = 0.0; 
        for (int i = 1; i <= n; i++) 
        { 
                S_of_target_from_Center += triangle_S(Center, a[i], a[i + 1]); 
        } 
 if ((S_of_target_from_Center - S_of_target) < eps && (S_of_target_from_Center - S_of_target) > -eps) 
     //   if (fabs(S_of_target_from_Center - S_of_target) < eps) 
        { 
                printf("0.000\n"); 
                return 0; 
        } 

        long double min = 1e+30; 
        for(i = 1; i <= n; i++) 
        { 
                double d_t_l = min_dist_to_line(a[i], a[i + 1], Center); 
                if(min > d_t_l) 
                { 
                        min = d_t_l; 
                } 
        } 

        printf("%.3lf\n", 2.0 * min); 

        return 0; 
}