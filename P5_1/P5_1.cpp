#include<iostream>
#include<string>
#include<cctype>

using namespace std;

void toLowerCase(string &str)
{
    for(int i=0; i<str.length(); i++)
    {
        str[i]=tolower(str[i]);
    }
}

int main()
{
    string paragraph;

    cout<<"Enter a paragraph:\n";
    getline(cin, paragraph);

    const int MAX_WORDS=1000;
    string words[MAX_WORDS];
    int freq[MAX_WORDS]= {0};

    int wordCount=0;

    string temp="";

    for(int i=0; i<=paragraph.length(); i++)
    {
        if(isalnum(paragraph[i]))
        {
            temp+=paragraph[i];
        }
        else
        {
            if(temp.length()>0)
            {
                toLowerCase(temp);
                bool found=false;
                for(int j=0; j<wordCount; j++)
                {
                    if(words[j]==temp)
                    {
                        freq[j]++;
                        found=true;
                        break;
                    }
                }

                if(!found && wordCount<MAX_WORDS)
                {
                    words[wordCount]=temp;
                    freq[wordCount]=1;
                    wordCount++;
                }
                temp="";
            }
        }
    }

    cout<<"\nWord Frequencies:\n";
    for(int i=0; i<wordCount; i++)
    {
        cout<<words[i]<<" : "<<freq[i]<<endl;
    }
    return 0;
}
