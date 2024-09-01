#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    // As there are 4 departments
    int rows = 4;

    // Courses in each department
    int courses[] = {3, 4, 2, 1};

    float **gpa = new float *[4];

    // initializing the column sizes in the gpa jagged array
    for (int i = 0; i < rows; i++)
    {
        gpa[i] = new float[courses[i]];
    }

    // These GPA values will be used for random courses
    float randomGPAvalues[] = {4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0};

    srand(time(0));

    // Initializing the GPA array with random GPA values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < courses[i]; j++)
        {
            int index = rand() % 7;
            gpa[i][j] = randomGPAvalues[index];
        }
    }

    // Displaying the GPA Jagged array
    for (int i = 0; i < rows; i++)
    {
        cout << "Department " << i + 1 << ": " << endl;
        for (int j = 0; j < courses[i]; j++)
        {
            cout << " Course " << j + 1 << " GPA: " << gpa[i][j] << endl;
        }
    }

    // Deallocating the occupied memory by the jagged array
    for (int i = 0; i < rows; i++)
    {
        delete[] gpa[i];
    }
    delete[] gpa;
}