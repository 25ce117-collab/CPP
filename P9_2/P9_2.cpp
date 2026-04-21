#include <iostream>
#include <map>
using namespace std;

int main()
{
    string input;
    map<string, int> wordCount;
    cout << "Enter a string: ";
    getline(cin, input);
    string word;
    for (char c : input)
    {
        if (c == ' ' || c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':')
        {
            if (!word.empty())
            {
                wordCount[word]++;
                word.clear();
            }
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
    {
        wordCount[word]++;
    }
    cout << "Word count:" << endl;
    for (const auto& pair : wordCount)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
