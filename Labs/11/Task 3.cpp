#include <iostream>
#include <vector>
#include <cmath>  // For sqrt()
#include <algorithm>  // For std::fill

using namespace std;

class Student {
    int id;

public:
    Student(int id) : id(id) { }

    int getId() const {
        return id;
    }

    friend class Hash;
};

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int NextPrime(int n) {
    n = n * 2;
    while (!isPrime(n)) {
        n++;
    }
    return n;
}

class Hash {
    vector<Student*> table;
    int bucket;
    float loadingFactor;
    int no;

public:
    Hash(int b) : bucket(b), table(bucket, nullptr), no(0), loadingFactor(0) { }

    int HashFunction(int id) {
        return id % bucket;
    }

    void updatesize() {
        loadingFactor = static_cast<float>((no) / bucket);
    }

    void reHashing() {
        int oldBucket = bucket;
        bucket = NextPrime(bucket);
        vector<Student*> table2(bucket, nullptr);

        for (int i = 0; i < oldBucket; i++) {
            if (table[i] != nullptr) {
                int index = HashFunction(table[i]->getId());
                while (table2[index] != nullptr) {
                    index = (index + 1) % bucket;  // Linear probing
                }
                table2[index] = table[i];
            }
        }

        table = move(table2);  // Move the new table into `table`
    cout<<"LoadingFactor had become greater than 0.75\n Rehashed New Bucket size : "<<bucket<<endl;
	}

    void insert(Student* s) {
        if (loadingFactor > 0.75) {
            reHashing();
        }
        int index = HashFunction(s->getId());
        while (table[index] != nullptr) {
            index = (index + 1) % bucket;  // Linear probing
        }
        table[index] = s;
        no++;
        updatesize();
    }

    bool deleteItem(int key) {
        int index = HashFunction(key);
        while (table[index] != nullptr) {
            if (table[index]->getId() == key) {
                table[index] = nullptr;
                cout << "Removed " << key << endl;
                no--;
                updatesize();
                return true;
            }
            index = (index + 1) % bucket;  // Linear probing
        }
        cout << "Not found\n";
        return false;
    }

    bool Search(int key) {
        int index = HashFunction(key);
        while (table[index] != nullptr) {
            if (table[index]->getId() == key) {
                cout << "Found " << key << endl;
                return true;
            }
            index = (index + 1) % bucket;  // Linear probing
        }
        cout << "Not found "<<key<<"\n";
        return false;
    }

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
int main(){
	Hash table(7);
	table.insert(new Student(12));
	table.insert(new Student(22));
	table.insert(new Student(32));
	table.insert(new Student(42));
	table.insert(new Student(52));
	table.insert(new Student(62));
	 table.display();
	 table.Search(22);
	 table.Search(42);
	 table.Search(72);
	 table.insert(new Student(72));
	 table.insert(new Student(82));
	 table.display();
}
