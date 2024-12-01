#include <iostream>
#include <vector>
#include <algorithm> // For std::fill
using namespace std;

class Member {
    int id;

public:
    Member(int id) : id(id) {}

    int getId() const {
        return id;
    }

    friend class Hash;
};

class Hash {
public:
    int bucket;
    vector<Member*> table;

    // Constructor
    Hash(int b) {
        bucket = b;
        table.resize(bucket, nullptr); // Initialize all slots with nullptr
    }

    // Hash Function
    int HashFunction(int id) {
        return id % bucket;
    }

    // Insert key into hash table
    void insert(Member* m) {
        int index = HashFunction(m->getId());
        int original = index;
        while (table[index] != nullptr) {
            index = (index + 1) % bucket;
            if (index == original) {
                cout << "Full Table\n";
                return;
            }
        }
        table[index] = m;
    }

    // Delete key from hash table
    bool deleteItem(int key) {
        int index = HashFunction(key);
        int original = index;
        while (table[index] != nullptr) {
            if (table[index]->getId() == key) {
                table[index] = nullptr; // Mark slot as empty
                cout << "Key " << key << " deleted.\n";
                return true;
            }
            index = (index + 1) % bucket;
            if (index == original) break;
        }
        cout << "Key " << key << " not found.\n";
        return false;
    }

    // Search key in hash table
    bool Search(int key) {
        int index = HashFunction(key);
        int original = index;
        while (table[index] != nullptr) {
            if (table[index]->getId() == key) {
                cout << "Key " << key << " found.\n";
                return true;
            }
            index = (index + 1) % bucket;
            if (index == original) break;
        }
        cout << "Key " << key << " not found.\n";
        return false;
    }

    // Display hash table
    void display() {
        for (int i = 0; i < bucket; i++) {
            cout << "Bucket " << i << ": ";
            if (table[i] != nullptr) {
                cout << table[i]->getId() << " ";
            } else {
                cout << "nullptr ";
            }
            cout << endl;
        }
    }
};

int main() {
    Hash h(7); // Create a hash table with 7 buckets

    // Insert member IDs 10 to 60
    for (int i = 10; i <= 60; i += 10) {
        Member* m = new Member(i);
        h.insert(m);
    }

    // Display the hash table after insertion
    cout << "Hash table after insertion:\n";
    h.display();

    // Search for member IDs 30, 50, 70
    h.Search(30);
    h.Search(50);
    h.Search(70); // Should show "not found"

    // Delete member IDs 20 and 40
    h.deleteItem(20);
    h.deleteItem(40);

    // Display the hash table after deletion
    cout << "Hash table after deletion:\n";
    h.display();

    // Insert additional member IDs 70 and 80 to show reuse of slots
    Member* m70 = new Member(70);
    Member* m80 = new Member(80);
    h.insert(m70);
    h.insert(m80);

    // Display the hash table after inserting new member IDs
    cout << "Hash table after inserting 70 and 80:\n";
    h.display();

    return 0;
}
