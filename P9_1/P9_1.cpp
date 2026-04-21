#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector <int> v;
    cout << "Enter the number of elements in the first vector: ";
    int n;
    cin >> n;
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }
    vector <int> v_rev_it;
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        v_rev_it.push_back(*it);
    }
    reverse(v.begin(), v.end());
    cout << "The reversed vector using reverse iterators is: ";
    for(int value: v)
    {
        cout << value << " ";
    }
    cout << "The reversed vector using the reverse function is: ";
    for(int value: v)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
