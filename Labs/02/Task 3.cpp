#include <iostream>
#include <vector>

using namespace std;

void FriendChecker(const bool Array[5][5], int A, int B){
    // Initializing two vector to keep record of friends
    vector<int> mutualfriends;
    // A temp variable to determine if any common friend was found
    bool commonfriend = false;
    // Checking if the indices are out of bounds
    if (A < 0 || A > 4 || B < 0 || B > 4){
        cout << "Invalid input. Please enter a number between 0 and 4." << endl;
        return;
    }
    // checking for friends of person A
    for(int i = 0; i<5; i++){
        if(Array[A][i] == true & Array[B][i] == true){
            commonfriend = true;
            mutualfriends.push_back(i);
        }
    }
    if(commonfriend == false){
        cout<<"No mutual friends of Person A and person B."<<endl;
    }
    else {
        cout << "Mutual friends of Person A and person B are: ";
        for(int index: mutualfriends){
            cout<<"| "<<index<<" |";
        }
    }
}

int main(){
    bool Array[5][5] = {
        {false, true, false, true, true},
        {true, false, true, false, true},
        {false, true, false, false, false},
        {true, false, false, false, true},
        {true, true, false, true, false}
    };

    cout<<"Friendship Array: "<<endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout<<Array[i][j]<<" ";
        }
        cout<<endl;
    }
    int A, B;
    cout<<"Enter Person A number: ";
    cin>>A;
    cout<<"Enter Person B Number: ";
    cin>>B;

    FriendChecker(Array, A, B);
}