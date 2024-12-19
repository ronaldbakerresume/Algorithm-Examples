### `README.md` for Consistent Hashing Implementation

---

# **Consistent Hashing**

This project implements **Consistent Hashing** in C++. Consistent Hashing is a technique commonly used in distributed systems to map keys to nodes in a distributed hash table (DHT). It minimizes the redistribution of keys when nodes are added or removed, making it ideal for scalable systems.

---

## **Problem Description**

In a distributed system, data (keys) must be distributed across multiple nodes. The challenge is to ensure minimal disruption when nodes are dynamically added or removed. Consistent Hashing solves this by mapping both nodes and keys to a fixed circular hash space, ensuring efficient distribution.

---

## **How It Works**

1. **Circular Hash Space:**
   - The hash space is represented as a circle, ranging from \(0\) to \(N-1\) (where \(N\) is the total number of hash slots).

2. **Node Mapping:**
   - Each node is hashed to a position on the circle using a hash function.

3. **Key Mapping:**
   - Each key is also hashed to a position on the circle. The key is assigned to the next node in the clockwise direction.

4. **Node Addition/Removal:**
   - When a node is added, only the keys in the hash range belonging to the new node are redistributed.
   - When a node is removed, its keys are redistributed to the next node clockwise.

---

## **Code Details**

### **Key Components**

1. **Hash Function:**
   - Converts strings (nodes or keys) into integer hash values within the range of the hash space.

2. **Circular Map:**
   - Maintains the mapping of hashed node values to their respective nodes.

3. **Core Methods:**
   - `addNode`: Adds a node to the hash ring.
   - `removeNode`: Removes a node from the hash ring.
   - `getNode`: Finds the node responsible for a given key.

---

### **Code Walkthrough**

#### **Hash Function**
```cpp
int hash(const string& key) {
    int hashValue = 0;
    for (char ch : key) {
        hashValue = (hashValue * 31 + ch) % totalSlots;
    }
    return hashValue;
}
```
- Computes a simple hash for strings using modular arithmetic.
- Maps strings to integers within the range `[0, totalSlots-1]`.

#### **Add Node**
```cpp
void addNode(const string& node) {
    int hashedKey = hash(node);
    circle[hashedKey] = node;
    cout << "Node " << node << " added at position " << hashedKey << endl;
}
```
- Hashes the node and adds it to the circular map.

#### **Remove Node**
```cpp
void removeNode(const string& node) {
    int hashedKey = hash(node);
    circle.erase(hashedKey);
    cout << "Node " << node << " removed.\n";
}
```
- Removes the node from the circular map based on its hash value.

#### **Get Node**
```cpp
string getNode(const string& key) {
    int hashedKey = hash(key);
    auto it = circle.upper_bound(hashedKey);
    if (it == circle.end()) it = circle.begin();
    return it->second;
}
```
- Finds the first node clockwise from the hashed key position. If none exists, wraps around to the first node.

#### **Main Function**
```cpp
int main() {
    ConsistentHashing hashRing;
    hashRing.addNode("NodeA");
    hashRing.addNode("NodeB");
    hashRing.addNode("NodeC");

    cout << "Key 'Key1' maps to: " << hashRing.getNode("Key1") << endl;
    cout << "Key 'Key2' maps to: " << hashRing.getNode("Key2") << endl;

    hashRing.removeNode("NodeB");
    cout << "Key 'Key1' maps to: " << hashRing.getNode("Key1") << endl;

    return 0;
}
```
- Adds three nodes (`NodeA`, `NodeB`, `NodeC`) to the hash ring.
- Maps keys to nodes using `getNode`.
- Demonstrates node removal and its impact on key mapping.

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `consistent_hashing.cpp`.
2. Compile the code:
   ```bash
   g++ consistent_hashing.cpp -o consistent_hashing
   ```
3. Run the program:
   ```bash
   ./consistent_hashing
   ```

---

## **Input/Output**

### **Example Input**
Hardcoded nodes and keys:
```cpp
hashRing.addNode("NodeA");
hashRing.addNode("NodeB");
hashRing.addNode("NodeC");
cout << "Key 'Key1' maps to: " << hashRing.getNode("Key1") << endl;
cout << "Key 'Key2' maps to: " << hashRing.getNode("Key2") << endl;
hashRing.removeNode("NodeB");
cout << "Key 'Key1' maps to: " << hashRing.getNode("Key1") << endl;
```

### **Example Output**
```plaintext
Node NodeA added at position 65
Node NodeB added at position 66
Node NodeC added at position 67
Key 'Key1' maps to: NodeC
Key 'Key2' maps to: NodeC
Node NodeB removed.
Key 'Key1' maps to: NodeC
```

---

## **Complexity**

### **Time Complexity**
- **Add/Remove Node:** \(O(\log N)\) (logarithmic insertion/removal into the `map`).
- **Get Node for a Key:** \(O(\log N)\) (binary search using `map::upper_bound`).

### **Space Complexity**
- \(O(N)\) for the `map` storing nodes in the hash ring.

---

## **Applications**

1. **Distributed Databases:**
   - Assigning data to servers in a scalable and fault-tolerant way.

2. **Caching Systems:**
   - Balancing cache keys across multiple cache servers.

3. **Load Balancing:**
   - Dynamically assigning tasks to servers with minimal disruption.

4. **Cloud Systems:**
   - Ensuring consistent data distribution across virtual nodes.

---

## **Customization**

- Modify the `totalSlots` variable to change the size of the hash space.
- Add support for virtual nodes to improve load balancing.

---

This implementation demonstrates the power and simplicity of consistent hashing in managing distributed resources dynamically and efficiently.