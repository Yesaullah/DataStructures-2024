#include <iostream>
using namespace std;

int Factorial_tail(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*Factorial_tail(n-1);
    }
}

int Factorial_Nontail(int n){
    if(n>=1){
        return n*Factorial_Nontail(n-1);
    }
    else{
        return 1;
    }
}

int main() {
    int n;

    cout<<"Enter a number: ";
    cin>>n;

    cout << "Tail recursion result: " << Factorial_tail(n) << endl;
    cout << "Nontail recursion result: " << Factorial_Nontail(n) << endl;
}