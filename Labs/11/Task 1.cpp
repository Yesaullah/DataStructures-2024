//HASHINGG:
/*
a way to search keys
-> a key is stored in the same index 1 is stored at index 1:
so time taken is o(1)


DRAWBACKS:
space wasted
the size of array will be greater than the keys usuually

we have types of mapping:
one-one  fn :h(x)=x (ideal hashing) drawback:space consumption
one-many
many-one   fn: h(x)-x%10  drawback:collisions
many-many  

AVOIDING COLLISIONS:
Closed Hashing:
*open addressing:
 1. 

Open hashing:
*Chaining:

worst case searching and deletion is O(N)
loading factor=n/size
so avg suscc search= 1+loading factor/2
avg unsuccess search=  1 + loading factor


*/

#include <iostream>
#include <vector>
using namespace std;

class Book {
    int id;
    int author_id;
    int book_id;

public:
    Book(int id) : id(id) {
        author_id = id / 10; // Extract author_id
        book_id = id % 10;   // Extract book_id
    }

    friend class Hash;
};

class Hash {
public:
    int bucket;
    vector<vector<Book>> table;

    // Constructor
    Hash(int b) {
        bucket = b;
        table.resize(bucket);
    }

    // Hash Function
    int HashFunction(int id) {
        return id % bucket;
    }

    // Insert key into hash table
    void insert(Book b) {
        int index = HashFunction(b.author_id);
        table[index].push_back(b);
    }

    // Delete key from hash table
    void deleteItem(int key ) {
        int index = HashFunction(key);

        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i].id ==key ) {
                table[index].erase(table[index].begin() + i); // Erase by iterator
                cout << "Key " << key << " deleted.\n";
                return;
            }
        }
        cout << "Key " << key << " not found.\n";
    }

    // Search key in hash table
    void Search(int key ) {
        int index = HashFunction(key);

        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i].id == key) {
                cout << "Key " << key << " found.\n";
                return;
            }
        }
        cout << "Key " << key << " not found.\n";
    }

    // Display hash table
    void display() {
        for (int i = 0; i < bucket; i++) {
            cout << "Bucket " << i << ": ";
            for (int j = 0; j < table[i].size(); j++) {
                cout << table[i][j].id << " ";
            }
            cout << endl;
        }
    }
};


    int main() {
    Hash h(10); // Create a hash table with 10 buckets

    // Insert Book objects
    h.insert(Book(120));
    h.insert(Book(121));
    h.insert(Book(122));
    h.insert(Book(210));
    h.insert(Book(211));
    h.insert(Book(310));
    h.insert(Book(311));
    h.insert(Book(312));
    h.insert(Book(313));

    // Display hash table
    cout << "Hash table after insertion:\n";
    h.display();

    // Search for books by ID
    h.Search(121);
    h.Search(313);
    h.Search(999); // A book that doesn't exist

    // Delete books by ID
    h.deleteItem(121);
    h.deleteItem(313);

    // Display hash table after deletion
    cout << "Hash table after deletion:\n";
    h.display();

    return 0;
}
