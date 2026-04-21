#include <bits/stdc++.h>
using namespace std;

int main()
{
    list <int> l;
    cout << "Enter the number of elements in the list: ";
    int n;
    cin >> n;
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        l.push_back(element);
    }
    set <int> s(l.begin(), l.end());
    cout << "The elements of the set are: ";
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;
    return 0;
}
