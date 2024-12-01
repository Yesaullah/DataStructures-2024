#include <iostream>
#include <vector>
using namespace std;

class LinearProbingHashTable {
private:
    int tableSize;
    vector<int> table;
    vector<bool> isOccupied;

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    LinearProbingHashTable(int size) : tableSize(size), table(size, -1), isOccupied(size, false) {}

    void insert(int key) {
        int index = hashFunction(key);
        while (isOccupied[index]) {
            index = (index + 1) % tableSize;
        }
        table[index] = key;
        isOccupied[index] = true;
    }

    void remove(int key) {
        int index = hashFunction(key);
        while (isOccupied[index]) {
            if (table[index] == key) {
                table[index] = -1;
                isOccupied[index] = false;
                return;
            }
            index = (index + 1) % tableSize;
        }
        cout << "Key " << key << " not found.\n";
    }

    bool search(int key) {
        int index = hashFunction(key);
        while (isOccupied[index]) {
            if (table[index] == key) return true;
            index = (index + 1) % tableSize;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Index " << i << ": " << (isOccupied[i] ? to_string(table[i]) : "NULL") << endl;
        }
    }
};

int main() {
    LinearProbingHashTable ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);

    ht.display();

    cout << (ht.search(15) ? "Found\n" : "Not Found\n");
    ht.remove(15);
    ht.display();

    return 0;
}
