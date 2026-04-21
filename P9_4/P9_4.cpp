#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, vector<string>> directory;
    int choice;
    do
    {
        cout << "Directory Management System" << endl;
        cout << "1. Add Folder" << endl;
        cout << "2. Add File to Folder" << endl;
        cout << "3. Display Directory Contents" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string folderName;
            cout << "Enter folder name: ";
            cin >> folderName;
            directory[folderName] = vector<string>();
            cout << "Folder created: " << folderName << endl;
        }
        break;
        case 2:
        {
            string folderName, fileName;
            cout << "Enter folder name: ";
            cin >> folderName;
            cout << "Enter file name: ";
            cin >> fileName;
            auto it = directory.find(folderName);
            if (it == directory.end())
            {
                cout << "Error: Folder '" << folderName << "' does not exist. Create the folder first." << endl;
            }
            else
            {
                it->second.push_back(fileName);
                cout << "File added: " << fileName << " to folder " << folderName << endl;
            }
        }
        break;
        case 3:
        {
            cout << "Directory Contents:" << endl;
            for (const auto& pair : directory)
            {
                cout << "Folder: " << pair.first << endl;
                cout << "Files: ";
                for (const auto& file : pair.second)
                {
                    cout << file << " ";
                }
                cout << endl;
            }
        }
        break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    while (choice != 4);

    return 0;
}
