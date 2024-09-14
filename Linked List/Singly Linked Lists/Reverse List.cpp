#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    public:
    Node(): data(0), next(nullptr){}
    Node(int value): data(value), next(nullptr){}

    friend class LinkedList;
};

class LinkedList{
    Node* head;
    public:
    LinkedList(): head(nullptr){}
    LinkedList(Node* n): head(n){}

    void Insert_at_end(int value)
    {
        Node *newnode = new Node(value);
        // checking if the list is empty
        if (head == nullptr)
        {
            head = newnode;
            return;
        }

        Node *current = head;
        // traversing to the end of the list
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = nullptr;
    }

    void Reverse_list(){
        if(head==nullptr){
            cout<<"The list is empty."<<endl;
            return;
        }
        Node* current = head; 
        Node* previous = nullptr; 
        Node* temp_next = nullptr; 
        // the loop will traverse till the end of the list
        while(current != nullptr){
            temp_next = current->next; 
            current->next = previous; 
            previous = current; 
            current = temp_next; 
        }
        /*
            SUPPOSE WE HAVE THE LIST: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
            Iteration 1:
                temp_next points to the second node
                next pointer of the first node points to null
                previous points to the first node now
                current points to the second node now
            Iteration 2:
                temp_next points to the third node
                next pointer of the second node points to the first node
                previous points to the second node now
                current points to the third node now
            Iteration 3:
                temp_next points to the fourth node now
                next pointer of the third node points to the second node
                previous points to the third node
                current points to the fourth node
            Iteration 4:
                temp_next points to the fifth node now
                next pointer of the fourth node points to the third node
                previous points to the fourth node
                current points to the fifth node
            Iteration 5:
                temp_next points to null now
                next pointer of the fifth node points to the fourth node
                previous points to the fifth node
                current points to null 

            PREVIOUS IS NOW AT THE END OF THE INITIAL LIST
            HENCE HEAD SHOULD NOW POINT TO PREVIOUS
        */
        head = previous;
    }

    void Display_list(){
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
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
    LinkedList my_list;

    my_list.Insert_at_end(1);
    my_list.Insert_at_end(2);
    my_list.Insert_at_end(3);
    my_list.Insert_at_end(4);
    my_list.Insert_at_end(5);

    my_list.Display_list();

    my_list.Reverse_list();

    my_list.Display_list();
    
    return 0;
}