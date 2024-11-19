#include <iostream>
#include <climits>

using namespace std;

struct Item{
    int value;
    int priority;
};

Item queue[1000];
int size_queue = -1;

void enqueue(int value, int priority){
    size_queue++;
    queue[size_queue].value = value;
    queue[size_queue].priority = priority;
}

// FUNCTION TO FIND THE INDEX OF THE ELEMENT WITH THE LOWEST PRIORITY
int peek_ascending(){
    int lowestPriority = INT_MAX;
    int index = -1;

    for(int i = 0; i<=size_queue; i++){
        if(lowestPriority > queue[i].priority){
            lowestPriority = queue[i].priority;
            index = i;
        }
    }
    return index;
}

// FUNCTION TO FIND THE INDEX OF THE ELEMENT WITH THE HIGHEST PRIORITY
int peek_descending(){
    int highestPriority = INT_MIN;
    int index = -1;

    for(int i = 0; i<=size_queue; i++){
        if(highestPriority < queue[i].priority){
            highestPriority = queue[i].priority;
            index = i;
        }
    }
    return index;
}

void dequeue(bool ascending = true){
    // if the ascending is set to true then peek_ascending() is called and index of the element with the lowest priority is returned, else the index of the element with the highest priority is returned.
    int index = ascending ? peek_ascending():peek_descending();

    for(int i = index; i<size_queue; i++){
        queue[i] = queue[i+1];
    }
    size_queue--;
}

int main() {
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(12, 3);
    enqueue(7, 1);

    // Ascending Priority Queue
    cout << "Ascending Order Priority Queue:" << endl;
    while (size_queue >= 0) {
        cout << "Dequeued value: " << queue[peek_ascending()].value << endl;
        dequeue(true);  // Passing true for ascending order
    }

    // Resetting queue for demonstration
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(12, 3);
    enqueue(7, 1);

    // Descending Priority Queue
    cout << "\nDescending Order Priority Queue:" << endl;
    while (size_queue >= 0) {
        cout << "Dequeued value: " << queue[peek_descending()].value << endl;
        dequeue(false);  // Passing false for descending order
    }

    return 0;
}