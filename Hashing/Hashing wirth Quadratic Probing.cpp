#include <iostream>
#include <vector>
using namespace std;

class QuadraticProbingHashTable {
private:
    int tableSize;
    vector<int> table;
    vector<bool> isOccupied;

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    QuadraticProbingHashTable(int size) : tableSize(size), table(size, -1), isOccupied(size, false) {}

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (isOccupied[(index + i * i) % tableSize]) {
            i++;
        }
        table[(index + i * i) % tableSize] = key;
        isOccupied[(index + i * i) % tableSize] = true;
    }

    void remove(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (isOccupied[(index + i * i) % tableSize]) {
            if (table[(index + i * i) % tableSize] == key) {
                table[(index + i * i) % tableSize] = -1;
                isOccupied[(index + i * i) % tableSize] = false;
                return;
            }
            i++;
        }
        cout << "Key " << key << " not found.\n";
    }

    bool search(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (isOccupied[(index + i * i) % tableSize]) {
            if (table[(index + i * i) % tableSize] == key) return true;
            i++;
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
    QuadraticProbingHashTable ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);

    ht.display();

    cout << (ht.search(15) ? "Found\n" : "Not Found\n");
    ht.remove(15);
    ht.display();

    return 0;
}
