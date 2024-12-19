#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class ConsistentHashing {
    map<int, string> circle;
    int totalSlots = 100;

    int hash(const string& key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue = (hashValue * 31 + ch) % totalSlots;
        }
        return hashValue;
    }

public:
    void addNode(const string& node) {
        int hashedKey = hash(node);
        circle[hashedKey] = node;
        cout << "Node " << node << " added at position " << hashedKey << endl;
    }

    void removeNode(const string& node) {
        int hashedKey = hash(node);
        circle.erase(hashedKey);
        cout << "Node " << node << " removed.\n";
    }

    string getNode(const string& key) {
        int hashedKey = hash(key);
        auto it = circle.upper_bound(hashedKey);
        if (it == circle.end()) it = circle.begin();
        return it->second;
    }
};

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

