/**
 * @file 06_optimum_location_of_point_to_minimize_total_distance
 * @author Ritesh Ranjan (https://sagittariusk2.github.io/)
 * @id sagittarius_k2
 * @brief brief description
 * @version 0.1 
 * @date 2022-01-13
 * @time 01:28
 * @link https://www.geeksforgeeks.org/optimum-location-point-minimize-total-distance/
 * @copyright Copyright (c) 2022
 */


#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point():x(0), y(0) {}
    Point(double x, double y):x(x), y(y) {}
};

struct Line {
    int a, b, c;
    Line(int a, int b, int c):a(a), b(b), c(c){}

    double getY(double x) {
        return (double)((double)(-(double)(a*x+c))/(double)b);
    }
};

double dist(Point p1, Point p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double total_dist(Point points[], int n, Point p1) {
    double ans = 0;
    for(int i=0; i<n; i++) {
        ans += dist(p1, points[i]);
    }
    return ans;
}

double findOptimumCost(Point points[], int n, Line l1) {
    double low_x = -1e6, high_x = 1e6;
    while(high_x-low_x>-1e-6) {
        double mid1_x = low_x + (high_x-low_x)/3;
        double mid2_x = low_x - (high_x-low_x)/3;

        double mid1_y = l1.getY(mid1_x);
        double mid2_y = l1.getY(mid2_x);
        Point mid1(mid1_x, mid1_y), mid2(mid2_x, mid2_y);

        double dist1 = total_dist(points, n, mid1);
        double dist2 = total_dist(points, n, mid2);

        if(dist1 < dist2) {
            high_x = mid2_x;
        } else {
            low_x = mid1_x;
        }
    }
    return total_dist(points, n, Point((low_x+high_x)/2.0, l1.getY((low_x+high_x)/2.0)));
}

signed main() {
    int a, b, c;
    cin >> a >> b >> c;
    Line l1(a, b, c);
    int n;
    cin >> n;
    Point points[n];
    for(int i=0; i<n; i++) {
        double x, y;
        cin >> x >> y;
        points[i] = Point(x, y);
    }

    cout << findOptimumCost(points, n, l1) << endl;
}