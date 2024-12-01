#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    int tableSize;
    list<int> *table;

    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    HashTable(int size) {
        tableSize = size;
        table = new list<int>[tableSize];
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int element : table[index]) {
            if (element == key) return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Index " << i << ": ";
            for (int key : table[i]) {
                cout << key << " -> ";
            }
            cout << "NULL\n";
        }
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(8);

    ht.display();

    cout << (ht.search(15) ? "Found\n" : "Not Found\n");
    ht.remove(15);
    ht.display();

    return 0;
}
