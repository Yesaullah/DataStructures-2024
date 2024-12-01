#include <iostream>
using namespace std;

// Node structure for Circular Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// CircularDoublyLinkedList class
class CircularDoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularDoublyLinkedList() : head(nullptr) {}

    // Function to insert a node at the end
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // Function to insert a node at the beginning
    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to delete a node with a given value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        do {
            if (temp->data == value) {
                if (temp == head && temp->next == head) {
                    delete temp;
                    head = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (temp == head) {
                        head = temp->next;
                    }
                    delete temp;
                }
                cout << "Node with value " << value << " deleted.\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Node with value " << value << " not found.\n";
    }

    // Function to search for a node with a given value
    bool search(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return false;
        }

        Node* temp = head;
        do {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        return false;
    }

    // Function to traverse the list and print all values
    void traverse() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Destructor to free memory
    ~CircularDoublyLinkedList() {
        if (head == nullptr) return;
        
        Node* temp = head;
        do {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        } while (temp != head);
    }
};

// Main function to test the Circular Doubly Linked List
int main() {
    CircularDoublyLinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertFront(5);

    cout << "List after insertions: ";
    list.traverse();

    cout << "Searching for 20 in the list: ";
    if (list.search(20)) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    list.deleteNode(20);
    cout << "List after deleting 20: ";
    list.traverse();

    list.deleteNode(5);
    cout << "List after deleting 5: ";
    list.traverse();

    return 0;
}
