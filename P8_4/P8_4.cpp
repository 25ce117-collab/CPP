#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

bool processLine(const string& line, int lineNumber)
{
    istringstream iss(line);
    double num, sum = 0;
    int count = 0;
    string token;
    while (iss >> token)
    {
        istringstream numStream(token);
        if (!(numStream >> num) || !(numStream.eof()))
        {
            cout << "Line " << lineNumber << " is invalid (non-numeric data: '" << token << "'). Skipping.\n";
            return false;
        }
        sum += num;
        ++count;
    }
    if (count == 0)
    {
        cout << "Line " << lineNumber << " is empty or contains no numbers. Skipping.\n";
        return false;
    }
    cout << "Line " << lineNumber << " sum: " << sum << endl;
    return true;
}

int main()
{
    string filepath;
    ifstream infile;
    while (true)
    {
        cout << "Enter file path (or type 'exit' to quit): ";
        getline(cin, filepath);
        if (filepath == "exit")
        {
            cout << "Exiting.\n";
            return 0;
        }
        infile.open(filepath);
        if (!infile)
        {
            cout << "Could not open file. Please try again.\n";
            infile.clear();
        }
        else
        {
            break;
        }
    }

    string line;
    int lineNumber = 1;
    while (getline(infile, line))
    {
        processLine(line, lineNumber);
        ++lineNumber;
    }
    infile.close();
    return 0;
}
