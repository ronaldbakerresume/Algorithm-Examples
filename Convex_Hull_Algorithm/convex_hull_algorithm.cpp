#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

Point p0;

// To find orientation of ordered triplet (p, q, r).
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// To sort points relative to p0
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0) {
        return (p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y) <
               (p2.x - p0.x) * (p2.x - p0.x) + (p2.y - p0.y) * (p2.y - p0.y);
    }
    return o == 2;
}

// Print convex hull using Graham's scan
void convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        cout << "Convex hull not possible\n";
        return;
    }

    // Find the bottom-most point
    int minY = points[0].y, minIdx = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < minY) || (points[i].y == minY && points[i].x < points[minIdx].x)) {
            minY = points[i].y;
            minIdx = i;
        }
    }
    swap(points[0], points[minIdx]);
    p0 = points[0];

    // Sort remaining points based on orientation relative to p0
    sort(points.begin() + 1, points.end(), compare);

    // Use a stack to find the hull points
    vector<Point> hull = {points[0], points[1], points[2]};
    for (int i = 3; i < n; i++) {
        while (hull.size() > 1 &&
               orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    // Print the convex hull
    cout << "Convex Hull Points:\n";
    for (const auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    convexHull(points);
    return 0;
}

