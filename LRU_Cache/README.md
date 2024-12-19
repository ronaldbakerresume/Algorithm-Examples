### `README.md` for LRU Cache Implementation

---

# **LRU Cache**

This project implements a **Least Recently Used (LRU) Cache** in C++. An LRU Cache is a data structure that keeps track of the most recently used items, evicting the least recently used item when its capacity is exceeded.

---

## **Problem Description**

Given:
- A fixed-capacity cache.
- Two operations:
  1. **`get(key)`**: Retrieve the value associated with a key. Return \(-1\) if the key is not present.
  2. **`put(key, value)`**: Insert or update the value associated with a key. Evict the least recently used item if the cache is at capacity.

Goal:
- Design a data structure to perform both operations in \(O(1)\) time.

### **Example Input/Output**

```plaintext
Cache Capacity: 2
Operations:
put(1, 1)
put(2, 2)
get(1) -> 1
put(3, 3) -> Evicts key 2
get(2) -> -1
```

---

## **How It Works**

### **Algorithm**

1. **Data Structures:**
   - **Doubly Linked List:** Maintains the order of keys, with the most recently used key at the front.
   - **Hash Map:** Maps keys to their values and positions in the linked list for \(O(1)\) access.

2. **Operations:**
   - **`get(key)`**:
     - If the key exists in the cache:
       - Move the key to the front of the list (mark it as most recently used).
       - Return the associated value.
     - Otherwise, return \(-1\).
   - **`put(key, value)`**:
     - If the key already exists:
       - Update the value and move the key to the front of the list.
     - If the key does not exist:
       - Add the key to the front of the list.
       - If the cache is at capacity, evict the least recently used key (the key at the back of the list).

---

## **Code Details**

### **Key Components**

1. **`LRUCache` Class:**
   - Maintains the cache using a linked list and a hash map:
     ```cpp
     class LRUCache {
     private:
         int capacity;
         list<int> keys;
         unordered_map<int, pair<int, list<int>::iterator>> cache;

     public:
         LRUCache(int cap) : capacity(cap) {}
     };
     ```

2. **`get(key)` Method:**
   - Retrieves the value for a key and updates its usage:
     ```cpp
     int get(int key) {
         if (cache.find(key) == cache.end()) return -1;

         keys.erase(cache[key].second);
         keys.push_front(key);
         cache[key].second = keys.begin();

         return cache[key].first;
     }
     ```

3. **`put(key, value)` Method:**
   - Adds a new key-value pair or updates an existing one:
     ```cpp
     void put(int key, int value) {
         if (cache.find(key) != cache.end()) {
             keys.erase(cache[key].second);
         } else if (keys.size() == capacity) {
             int leastUsed = keys.back();
             keys.pop_back();
             cache.erase(leastUsed);
         }

         keys.push_front(key);
         cache[key] = {value, keys.begin()};
     }
     ```

4. **Main Function:**
   - Demonstrates the functionality of the LRU Cache:
     ```cpp
     int main() {
         LRUCache lru(2);
         lru.put(1, 1);
         lru.put(2, 2);
         cout << "Get 1: " << lru.get(1) << endl; // Output: 1
         lru.put(3, 3); // Removes key 2
         cout << "Get 2: " << lru.get(2) << endl; // Output: -1
         return 0;
     }
     ```

---

## **How to Run**

### **Requirements**
- A C++ compiler (e.g., `g++`)

### **Steps**
1. Copy the code into a file named `lru_cache.cpp`.
2. Compile the code:
   ```bash
   g++ lru_cache.cpp -o lru_cache
   ```
3. Run the program:
   ```bash
   ./lru_cache
   ```

---

## **Input/Output**

### **Input**
The program uses the following operations:
```plaintext
put(1, 1)
put(2, 2)
get(1)
put(3, 3)
get(2)
```

### **Output**
```plaintext
Get 1: 1
Get 2: -1
```

---

## **Complexity**

### **Time Complexity**
- **`get` and `put` Operations:** \(O(1)\), due to the combination of a hash map and linked list.

### **Space Complexity**
- \(O(C)\), where \(C\) is the cache capacity.

---

## **Applications**

1. **Caching Systems:**
   - Efficiently manage frequently accessed data in systems like databases, web servers, and file systems.
2. **Memory Management:**
   - Evict least-used data to make room for new data.
3. **Operating Systems:**
   - Manage page replacement in virtual memory.

---

## **Customization**

- Modify the cache capacity by changing the argument to the `LRUCache` constructor in the `main()` function.
- Extend the implementation to track access frequencies or to evict based on custom criteria.

---

## **Advantages**

1. Provides efficient \(O(1)\) time complexity for both `get` and `put` operations.
2. Balances speed and space usage effectively.

---

## **Limitations**

1. Additional space is required for the linked list and hash map.
2. Not suitable for large-scale data where memory is highly constrained.

---

This implementation provides a practical and efficient solution for managing limited storage in applications requiring quick access to frequently used data.