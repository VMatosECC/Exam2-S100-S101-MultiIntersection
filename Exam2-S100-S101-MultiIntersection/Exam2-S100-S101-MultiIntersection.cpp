// Exam2-S100-S101-MultiIntersection.cpp 
/*
Multi-Intersection
Assume v1, v2, and v3 are vectors holding integer values (vector<int>).
As an example, consider the following sample.
    vector<int> v1 { 44, 22, 33, 44 };
    vector<int> v2 { 22, 33, 77, 55, 88 };
    vector<int> v3 { 22, 66, 55 };

You are asked to write the functions
-----------------------------------------------------------------------------------------
void multiIntersection(vector<int> v1, vector<int> v2, vector<int> v3,
                       vector<int>& v4);

The function returns inside the vector v4 those values which are
common to at least two of the three given vectors v1, v2, and v3.

***************************************************************************************  */

#include <iostream>
#include <vector>
using namespace std;

//Prototypes ----------------------------------------------------------------------------------------

void multiIntersection(vector<int> v1, vector<int> v2, vector<int> v3, vector<int>& v4);

void showVector(vector<int> v, string caption = "");
int  countOccurrence(int item, vector<int> v);

//-----------------------------------------------------------------------------------------------------
int main()
{
    //define test vectors
    vector<int> v1{ 44, 22, 33, 44 };
    vector<int> v2{ 22, 33, 77, 55, 88 };
    vector<int> v3{ 22, 66, 55 };
    
    //solution vector 
    vector<int> v4;

    showVector(v1, "Vector v1");
    showVector(v2, "Vector v2");
    showVector(v3, "Vector v3");

    multiIntersection(v1, v2, v3, v4);
    showVector(v4, "Vector v4 (Multi Intersection)");

}

// User-defined methods ------------------------------------------------------------------------
int countOccurrence(int item, vector<int> v)
{
    //tell how many time item occurs in vector v
    int counter = 0;
    for (int num : v) if (num == item) counter++;
    return counter;
}

//----------------------------------------------------------------------------------------------
void showVector(vector<int> v, string caption)
{
    //display given caption followed by the vector's data items
    cout << endl << caption << endl;
    for (int item : v) cout << item << ", ";
    cout << endl;
}

//-------------------------------------------------------------------------------------------------------

void multiIntersection(vector<int> v1, vector<int> v2, vector<int> v3, vector<int>& v4)
{
    //make sure solution vector is empty
    v4.clear();         

    //test v1 items against those of v2 and v3
    for (int i = 0; i < v1.size(); i++)
    {
        int item = v1[i];
        if ((countOccurrence(item, v2) > 0 || countOccurrence(item, v3) > 0)
            && (countOccurrence(item, v4) == 0))
        {
            v4.push_back(item);
        }

    }

    //test v2 items against those of v3 (we already compared v1 and v3)
    for (int i = 0; i < v2.size(); i++)
    {
        int item = v2[i];
        if ((countOccurrence(item, v3) > 0) && (countOccurrence(item, v4) == 0))
        {
            v4.push_back(item);
        }
    }
}



