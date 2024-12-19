### `README.md` for Activity Selection Algorithm

---

# **Activity Selection Algorithm**

This project demonstrates the **Activity Selection Problem** using a greedy algorithm in C++. The goal is to select the maximum number of activities that don't overlap, given their start and finish times.

---

## **Problem Description**

Given a set of activities with their start and finish times, the task is to select the maximum number of activities that can be performed by a single person, assuming that a person can work on only one activity at a time.

### **Example Input**
```plaintext
Activities: [(1, 3), (2, 5), (4, 6), (6, 7), (5, 9), (8, 9)]
```

### **Expected Output**
```plaintext
Selected Activities: [(1, 3), (4, 6), (6, 7), (8, 9)]
```

---

## **How It Works**

1. **Sorting Activities:** 
   - Activities are sorted by their finish times.
   - This ensures that the earliest finishing activities are considered first.

2. **Activity Selection:**
   - Iterate through the sorted activities.
   - If the current activity's start time is greater than or equal to the last selected activity's finish time, select it.

---

## **Code Overview**

### **Key Components**
1. **Struct Definition:**  
   The `Activity` struct holds the start and finish times of an activity.

2. **Comparison Function:**  
   `compareActivities` is a comparator function used to sort activities by their finish times.

3. **Main Logic:**  
   The `activitySelection` function performs the greedy selection of activities.

---

### **Code Walkthrough**

#### **Struct Definition**
```cpp
struct Activity {
    int start, finish;
};
```
This struct represents an activity with a start and finish time.

#### **Comparator Function**
```cpp
bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}
```
This function sorts activities in ascending order of their finish times.

#### **Activity Selection Function**
```cpp
void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compareActivities);

    cout << "Selected Activities:\n";
    int lastFinish = -1;
    for (const auto& activity : activities) {
        if (activity.start >= lastFinish) {
            cout << "(" << activity.start << ", " << activity.finish << ")\n";
            lastFinish = activity.finish;
        }
    }
}
```
This function:
- Sorts the activities by their finish times.
- Selects the maximum number of non-overlapping activities.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `activity_selection.cpp`.
2. Compile the code:
   ```bash
   g++ activity_selection.cpp -o activity_selection
   ```
3. Run the program:
   ```bash
   ./activity_selection
   ```

---

## **Input/Output**

### **Input**
The program accepts a hardcoded list of activities with their start and finish times:
```cpp
vector<Activity> activities = {{1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 9}, {8, 9}};
```

### **Output**
The program outputs the selected activities:
```plaintext
Selected Activities:
(1, 3)
(4, 6)
(6, 7)
(8, 9)
```

---

## **Complexity**

### **Time Complexity**
- **Sorting:** \(O(n \log n)\)
- **Activity Selection:** \(O(n)\)  
**Total:** \(O(n \log n)\)

### **Space Complexity**
- \(O(1)\) additional space (excluding input data).

---

## **Customization**

- Modify the `activities` vector in the `main` function to test with different sets of activities.
- Extend the algorithm to return the selected activities as a list instead of printing them.

---

## **Applications**

- Scheduling tasks in operating systems.
- Event planning.
- Maximizing resource utilization.

---

This implementation serves as a great example of a greedy algorithm solving an optimization problem efficiently.