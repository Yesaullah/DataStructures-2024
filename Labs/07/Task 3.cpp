#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
    Student* next;
    Student(string n, int s) : name(n), score(s), next(NULL) {}
};

class StudentList {
public:
    Student* head;
    StudentList() : head(NULL) {}

    void addStudent(const string& name, int score) {
        Student* newStudent = new Student(name, score);
        newStudent->next = head;
        head = newStudent;
    }

    void display() const {
        for (Student* temp = head; temp; temp = temp->next)
            cout << temp->name << " - " << temp->score << endl;
    }

    void radixSort() {
        for (int exp = 1, maxScore = getMaxScore(); maxScore / exp > 0; exp *= 10)
            bucketSort(exp);
    }

private:
    int getMaxScore() const {
        int maxScore = 0;
        for (Student* temp = head; temp; temp = temp->next)
            maxScore = max(maxScore, temp->score);
        return maxScore;
    }

    void bucketSort(int exp) {
        Student* buckets[10] = {NULL}, *bucketTails[10] = {NULL};

        for (Student* temp = head; temp;) {
            int idx = (temp->score / exp) % 10;
            Student* next = temp->next;
            if (!buckets[idx])
                buckets[idx] = bucketTails[idx] = temp;
            else
                bucketTails[idx] = bucketTails[idx]->next = temp;
            temp->next = NULL;
            temp = next;
        }

        head = NULL;
        Student* tail = NULL;
        for (int i = 0; i < 10; ++i) {
            if (!buckets[i]) continue;
            if (!head) head = buckets[i];
            else tail->next = buckets[i];
            tail = bucketTails[i];
        }
    }
};

int main() {
    StudentList list;
    list.addStudent("Emaan", 85);
    list.addStudent("Zoni", 90);
    list.addStudent("Dani", 72);
    list.addStudent("Tanu", 100);
    list.addStudent("Yesa", 65);
    list.addStudent("Murtaza", 55);
    list.addStudent("Muneeb", 78);

    cout << "Before Sorting:\n";
    list.display();

    list.radixSort();

    cout << "\nAfter Sorting:\n";
    list.display();
    return 0;
}
