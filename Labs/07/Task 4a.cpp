#include <iostream>
using namespace std;

int getMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void countsort(int array[], int size, int pos) {
    int b[size];  
    int count[10] = {0};  

    for (int i = 0; i < size; i++) {
        int index = (array[i] / pos) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int index = (array[i] / pos) % 10;
        b[--count[index]] = array[i];
    }

    for (int i = 0; i < size; i++) {
        array[i] = b[i];
    }
}

// Radix sort
void radixsort(int array[], int size) {
    int max = getMax(array, size);  
    for (int pos = 1; max / pos > 0; pos *= 10) {
        countsort(array, size, pos);
    }
}

int main() {
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = 8;
    cout<<"Unsorted Arrray:: \n";
  for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    radixsort(array, size);
   cout<<"Sorted Arrray:: \n";
 
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
