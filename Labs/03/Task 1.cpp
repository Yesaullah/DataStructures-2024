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

    // INSERT NODE AT FRONT
    void AddFront(const int value)
    {
        Node *newnode = new Node(value);
        // if the list is empty
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

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
    // Insert node after a given value
    void AddAfer(const int value, const int temp_value)
    {
        if (head != nullptr)
        {
            Node *newnode = new Node(value);
            Node *current = head;
            while (current && current->data != temp_value)
            {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
        else
        {
            cout << "There is no existing node with your given value." << endl;
        }
    }
    // INSERT NODE BEFORE A GIVEN VALUE
    void AddBefore(const int value, const int temp_value)
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *newnode = new Node(value);

        if (head->data == temp_value)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        Node *current = head;
        Node *previous = nullptr;

        while (current && current->data != temp_value)
        {
            previous = current;
            current = current->next;
        }

        if (current)
        {
            newnode->next = current;
            previous->next = newnode;
        }
        else
        {
            cout << "There is no existing node with your given value." << endl;
        }
    }

    // DELETE NODE FROM HEAD
    void DeleteFromHead()
    {
        if (head != nullptr)
        {
            Node *current = head;
            head = current->next;
            delete current;
            current = NULL;
        }
        else
        {
            cout << "List is already empty." << endl;
        }
    }

    // DELETE LAST NODE
    void DeleteLast()
    {
        if (!head)
        {
            cout << "List is already empty." << endl;
            return;
        }
        // if the list contains only one node
        if (!head->next)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *current = head;
        while (current->next && current->next->next)
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    // DELETE NODE OF A PARTICULAR VALUE
    void DeleteNode(int value)
    {
        if (!head)
        {
            cout << "List is already empty." << endl;
            return;
        }
        // checking if the head stores the needed value
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        Node *previous = nullptr;

        // Traverse the list to find the node with the given value
        while (current && current->data != value)
        {
            previous = current;
            current = current->next;
        }

        // If the node with the value is not found
        if (!current)
        {
            cout << "Value not found in the list." << endl;
            return;
        }

        previous->next = current->next;
        delete current;
    }

    // COUNT NUMBER OF NODES
    void CountNodes()
    {
        Node *current = head;
        int count = 0;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        cout << "Number of nodes in the list: " << count << endl;
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
    list.AddFront(1);
    list.AddFront(2);
    list.AddFront(3);
    list.AddFront(4);
    list.AddFront(5);
    list.DisplayList();

    // ADDING A VALUE AFTER A SPECIFIC VALUE
    list.AddAfer(69, 3);
    list.DisplayList();

    // ADDING A VALUE BEFORE A SPCIFIC VALUE
    list.AddBefore(50, 3);
    list.DisplayList();

    // ADDING A NODE AT THE END
    list.AddEnd(23);
    list.DisplayList();

    // COUNTING THE NODES IN THE LIST
    list.CountNodes();

    // DELETING A NODE FROM THE END
    list.DeleteLast();
    list.DisplayList();

    // DELETING A NODE FROM THE FRONT
    list.DeleteFromHead();
    list.DisplayList();

    // DELETING A SPECIFIC NODE
    list.DeleteNode(3);
    list.DisplayList();

    return 0;
}