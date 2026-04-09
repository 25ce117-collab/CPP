#include<iostream>
#include<fstream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
    ifstream file("input.txt");

    if(!file)
    {
        cout<<"Error: File could not be opened.\n";
        return 1;
    }

    string line;
    int lineCount=0;
    int wordCount=0;
    int charCount=0;

    while(getline(file,line))
    {
        lineCount++;

        bool inWord=false;

        for(int i=0; i < line.length(); i++)
        {
            charCount++;

            if(isalnum(line[i]))
            {
                if(!inWord)
                {
                    wordCount++;
                    inWord=true;
                }
            }
            else
            {
                inWord=false;
            }
        }

        charCount++;
    }

    file.close();

    cout<<"Lines:"<<lineCount<<endl;
    cout<<"Words:"<<wordCount<<endl;
    cout<<"Characters(including spaces and newlines):"<<charCount<<endl;

    return 0;
}
