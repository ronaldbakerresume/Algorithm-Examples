### `README.md` for Convex Hull (Graham's Scan)

---

# **Convex Hull Using Graham's Scan**

This project implements the **Convex Hull** algorithm using **Graham's Scan** in C++. A **Convex Hull** is the smallest convex boundary that encloses a set of points in a 2D plane. It is widely used in computational geometry for shape analysis and pattern recognition.

---

## **Problem Description**

Given a set of \(n\) points in a 2D plane, the task is to find the points that form the convex hull. These points form the vertices of the smallest polygon that contains all the given points.

### **Example Input**
```plaintext
Points: [(0, 3), (2, 2), (1, 1), (2, 1), (3, 0), (0, 0), (3, 3)]
```

### **Expected Output**
```plaintext
Convex Hull Points:
(0, 0)
(3, 0)
(3, 3)
(0, 3)
```

---

## **How It Works**

### **Steps**

1. **Find the Bottom-Most Point:**
   - Choose the point with the lowest \(y\)-coordinate. If there is a tie, choose the point with the lowest \(x\)-coordinate. This point will act as the reference point \(p_0\).

2. **Sort Points by Polar Angle:**
   - Sort all the points based on the polar angle they make with \(p_0\). If two points have the same polar angle, keep the closer one.

3. **Build the Convex Hull Using a Stack:**
   - Start with the first three points. For each subsequent point:
     - Check the orientation of the triplet formed by the last two points on the stack and the current point.
     - If it forms a clockwise turn, remove the second-to-last point (it's not part of the convex hull).
     - Add the current point to the stack.

4. **Output the Hull Points:**
   - The points remaining in the stack form the vertices of the convex hull in counterclockwise order.

---

## **Code Details**

### **Key Components**

1. **Orientation Function:**
   - Determines the orientation of three points:
     - \(0\): Collinear  
     - \(1\): Clockwise  
     - \(2\): Counterclockwise

2. **Sorting Function:**
   - Sorts points relative to the reference point \(p_0\) based on polar angle and distance.

3. **Convex Hull Function:**
   - Uses the Graham's Scan algorithm to find the convex hull.

4. **Main Function:**
   - Initializes the points and calls the `convexHull` function.

---

### **Code Walkthrough**

#### **Orientation Function**
```cpp
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}
```
Determines the relative orientation of three points.

#### **Sorting Points**
```cpp
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0) {
        return (p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y) <
               (p2.x - p0.x) * (p2.x - p0.x) + (p2.y - p0.y) * (p2.y - p0.y);
    }
    return o == 2;
}
```
Sorts points based on their polar angle relative to \(p_0\). Points with the same angle are sorted by distance.

#### **Convex Hull Construction**
```cpp
void convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        cout << "Convex hull not possible\n";
        return;
    }

    int minY = points[0].y, minIdx = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < minY) || (points[i].y == minY && points[i].x < points[minIdx].x)) {
            minY = points[i].y;
            minIdx = i;
        }
    }
    swap(points[0], points[minIdx]);
    p0 = points[0];

    sort(points.begin() + 1, points.end(), compare);

    vector<Point> hull = {points[0], points[1], points[2]};
    for (int i = 3; i < n; i++) {
        while (hull.size() > 1 &&
               orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    cout << "Convex Hull Points:\n";
    for (const auto& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
}
```
Constructs the convex hull by iteratively adding and removing points based on their orientation.

#### **Main Function**
```cpp
int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    convexHull(points);
    return 0;
}
```
Initializes the input points and calls the `convexHull` function.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `convex_hull.cpp`.
2. Compile the code:
   ```bash
   g++ convex_hull.cpp -o convex_hull
   ```
3. Run the program:
   ```bash
   ./convex_hull
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded points:
```plaintext
[(0, 3), (2, 2), (1, 1), (2, 1), (3, 0), (0, 0), (3, 3)]
```

### **Output**
The convex hull points:
```plaintext
Convex Hull Points:
(0, 0)
(3, 0)
(3, 3)
(0, 3)
```

---

## **Complexity**

### **Time Complexity**
- **Sorting:** \(O(n \log n)\)
- **Hull Construction:** \(O(n)\)  
**Total:** \(O(n \log n)\)

### **Space Complexity**
- \(O(n)\): Additional space for the `hull` stack.

---

## **Applications**

1. **Computer Graphics:**
   - Detecting the boundary of a set of points.

2. **Geographical Mapping:**
   - Constructing boundaries for geographical regions.

3. **Pattern Recognition:**
   - Identifying shapes in datasets.

4. **Robotics:**
   - Path planning and obstacle avoidance.

---

## **Customization**

- Modify the `points` array in the `main()` function to test different datasets.
- Extend the algorithm to handle collinear points explicitly in the convex hull.

---

This implementation provides a robust and efficient solution for computing the convex hull of a set of points using the Graham's Scan algorithm.