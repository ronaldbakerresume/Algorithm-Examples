#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y;
};

// Check if a point is inside a polygon using ray-casting algorithm
bool isPointInPolygon(vector<Point>& polygon, Point p) {
    int n = polygon.size();
    if (n < 3) return false; // A polygon must have at least 3 sides

    Point extreme = {1e9, p.y}; // Create a ray to the right
    int count = 0, i = 0;

    do {
        int next = (i + 1) % n;

        // Check if the ray intersects with the edge of the polygon
        if ((p.y >= min(polygon[i].y, polygon[next].y) &&
             p.y <= max(polygon[i].y, polygon[next].y)) &&
            ((p.y - polygon[i].y) * (polygon[next].x - polygon[i].x) <=
             (p.x - polygon[i].x) * (polygon[next].y - polygon[i].y))) {
            count++;
        }

        i = next;
    } while (i != 0);

    // Odd count of intersections means the point is inside
    return count % 2 == 1;
}

int main() {
    vector<Point> polygon = {{1, 1}, {3, 1}, {3, 3}, {1, 3}};
    Point p = {2, 2};

    if (isPointInPolygon(polygon, p)) {
        cout << "Point is inside the polygon.\n";
    } else {
        cout << "Point is outside the polygon.\n";
    }
    return 0;
}

