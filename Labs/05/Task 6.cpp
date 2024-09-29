#include <iostream>
using namespace std;

void Recursive_Fibonacci_Generator(int n, int a = 0, int b = 1)
{
    if (n == 0)
    {
        return;
    }
    cout << a << " ";
    Recursive_Fibonacci_Generator(n - 1, b, a + b);
}

int main()
{
    int n;
    cout << "Enter the number of Fibonacci terms to generate: ";
    cin >> n;

    if (n <= 0)
    {
        return 0;
    }
    else
    {
        cout << "Fibonacci sequence for " << n << " terms:" << endl;
        Recursive_Fibonacci_Generator(n);
    }

    return 0;
}
