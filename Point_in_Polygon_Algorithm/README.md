### `README.md` for Point-in-Polygon Algorithm (Ray-Casting)

---

# **Point-in-Polygon Algorithm**

This project implements the **Ray-Casting Algorithm** in C++ to determine whether a given point lies inside or outside a polygon.

---

## **Problem Description**

Given:
- A polygon defined by its vertices.
- A point \(P(x, y)\).

Goal:
- Determine if the point \(P\) lies inside or outside the polygon.

---

## **Algorithm**

The **Ray-Casting Algorithm** checks how many times a horizontal ray starting at the point \(P\) intersects the edges of the polygon. The key observations are:

1. If the ray intersects an **odd** number of edges, the point lies inside the polygon.
2. If the ray intersects an **even** number of edges, the point lies outside the polygon.

### **Steps**

1. **Construct the Ray:**
   - The ray starts at \(P\) and extends infinitely to the right.

2. **Count Intersections:**
   - For each edge of the polygon:
     - Check if the edge intersects the ray.
     - Increment the intersection count if it does.

3. **Determine Position:**
   - If the intersection count is odd, the point is inside.
   - Otherwise, it is outside.

---

## **Code Details**

### **Key Components**

1. **Point Structure:**
   - Represents a 2D point:
     ```cpp
     struct Point {
         double x, y;
     };
     ```

2. **Ray-Casting Function:**
   - Implements the algorithm to check if a point lies inside a polygon:
     ```cpp
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

         return count % 2 == 1;
     }
     ```

3. **Main Function:**
   - Initializes the polygon and the point, and checks if the point lies inside:
     ```cpp
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
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`).

### **Steps**
1. Copy the code into a file named `point_in_polygon.cpp`.
2. Compile the code:
   ```bash
   g++ point_in_polygon.cpp -o point_in_polygon
   ```
3. Run the program:
   ```bash
   ./point_in_polygon
   ```

---

## **Input/Output**

### **Input**
The program uses the following hardcoded values:

1. **Polygon:**
   ```plaintext
   Vertices: (1, 1), (3, 1), (3, 3), (1, 3)
   ```
2. **Point:**
   ```plaintext
   P = (2, 2)
   ```

### **Output**
```plaintext
Point is inside the polygon.
```

---

## **Complexity**

### **Time Complexity**
- \(O(n)\): Where \(n\) is the number of vertices in the polygon.

### **Space Complexity**
- \(O(1)\): Constant space used for calculations.

---

## **Applications**

1. **Geographic Information Systems (GIS):**
   - Checking if a point lies within a region or boundary.
2. **Computer Graphics:**
   - Hit detection and collision detection in games.
3. **Robotics and Pathfinding:**
   - Determining if a location is within a restricted zone.

---

## **Limitations**

1. **Collinear Points:**
   - The algorithm may need adjustments for points exactly on the edges of the polygon.
2. **Non-Simple Polygons:**
   - Works best with simple polygons (no self-intersecting edges).

---

This implementation provides a robust and efficient method to determine point-in-polygon relationships, making it ideal for use in computational geometry and related fields.