#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node() : data(0), next(NULL) {}
    Node(const int d) : data(d), next(NULL) {}
    friend class LinkedList;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(NULL) {}
    LinkedList(Node *n) : head(n) {}

    // INSERT NODE AT THE END
    void AddEnd(const int value)
    {
        Node *newnode = new Node(value);
        // checking if the list was initially empty
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newnode;
            newnode->next = nullptr;
        }
    }

    // SEGREGATING EVEN AND ODD NUMBERS
    void Even_Odd_Segregator()
    {
        Node *current = head;
        Node *EvenHead = nullptr;
        Node *EvenEnd = nullptr;
        Node *OddHead = nullptr;
        Node *OddEnd = nullptr;

        if (!head)
        {
            cout << "The list is empty." << endl;
            return;
        }

        while (current != nullptr)
        {
            if (current->data % 2 == 0)
            { 
                // if the even list is initially empty
                if (EvenHead == nullptr)
                {
                    // both the head and end pointer for the even list points to that node
                    EvenHead = current;
                    EvenEnd = current;
                }
                else
                {
                    // the existing last node's next pointer is set to point towards the new node
                    EvenEnd->next = current;
                    // end pointer of the even list is set to point to the new node found
                    EvenEnd = current;
                }
            }
            else
            { 
                // if the odd list is initially empty
                if (OddHead == nullptr)
                {
                    OddHead = current;
                    OddEnd = current;
                }
                else
                {
                    // the existing last node's next pointer is set to point towards the new node
                    OddEnd->next = current;
                    // end pointer of the even list is set to point to the new node found
                    OddEnd = current;
                }
            }
            current = current->next;
        }

        // if no even numbers were found in the list, the head points to the head of the odd list
        if (EvenHead == nullptr)
        {
            head = OddHead;
        }
        else
        {
            EvenEnd->next = OddHead;
            head = EvenHead;
        }

        // if there exists any odd number in the list, the next pointer of the last odd node is set to point to null
        if (OddEnd != nullptr)
        {
            OddEnd->next = nullptr;
        }
        // if there doesnt exist any odd number in the list, the next pointer of the last node is set to point to null
        else if (EvenEnd != nullptr)
        {
            EvenEnd->next = nullptr;
        }
    }

    // DISPLAY FUNCTION
    void DisplayList()
    {
        if (!head)
        {
            cout << "The list is empty." << endl;
            return;
        }
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    LinkedList list;

    // ADDING MULTIPLE NODES
    list.AddEnd(1);
    list.AddEnd(2);
    list.AddEnd(3);
    list.AddEnd(4);
    list.AddEnd(5);
    list.AddEnd(6);
    list.AddEnd(7);
    list.AddEnd(8);

    cout << "Original List: " << endl;
    list.DisplayList();

    cout<<"Seggregated List: "<<endl;
    list.Even_Odd_Segregator();
    list.DisplayList();

    return 0;
}