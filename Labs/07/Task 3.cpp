#include <iostream>

using namespace std;

class Node{
    string name;
    int score;
    Node* next;
    public:
    Node(){
        name = "";
        score = 0;
        next = nullptr;
    }
    Node(string name, int score){
        this->name = name;
        this->score = score;
        next = nullptr;
    }
    ~Node(){
        delete[] next;
    }
    friend class LinkedList;
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
    LinkedList(Node* n){
        head = n;
    }
    ~LinkedList(){
        delete[] head;
    }

    
};