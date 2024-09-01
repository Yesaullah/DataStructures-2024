#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    string **seats = new string *[rows];
    vector<int> seats_per_row;
    int temp;

    for (int i = 0; i < rows; i++) {
        cout << "Enter the number of seats in row " << i + 1 << ": ";
        cin >> temp;
        seats_per_row.push_back(temp);
        seats[i] = new string[temp];
    }

    // Taking inputs for attendees names
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < seats_per_row[i]; j++) {
            cout << "Enter the name of attendee " << j + 1 << " in row " << i + 1 << ": ";
            cin >> seats[i][j];
        }
    }

    // Displaying the array with improved formatting
    cout << "\nAttendees seating arrangement:\n";
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < seats_per_row[i]; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < rows; i++) {
        delete[] seats[i];
    }
    delete[] seats;

    return 0;
}
