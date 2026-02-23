#include <iostream>
#include <string>

using namespace std;

class Library
{
    string book_name;
    int bookid;
    string author_name;
    int copies;
    public:
        int search_book(string);
        void set_data();
        void add_book();
        void issue_book();
        void return_book();
        void display_book();
    };

int Library::search_book(string bookname)
{
    return bookname==book_name;
}

void Library::set_data()
{
    char newline;
    cout << "Enter Book's Name" << endl;
    getline(cin >> newline,book_name);
    cout << "Enter Author's Name" << endl;
    getline(cin,author_name);
    cout << "Enter Book ID" << endl;
    cin >> bookid;
    cout << "Enter Number of copies" << endl;
    cin >> copies;
}

void Library::add_book()
{
    int no;
    cout << "Enter number of copies" << endl;
    cin >> no;
    copies += no;
}

void Library::issue_book()

{
    if(copies>0)
        copies--;
}

void Library::return_book()
{
    copies++;
}

void Library::display_book()
{
    cout << "Book's Name: " << book_name << endl;
    cout << "Book's Author: " << author_name << endl;
    cout << "Book's ID: " << bookid << endl;
    cout << "No of Book: " << copies << endl;

}
int main()
{
    int choice,t=0,i;
    char newline;
    string input_book;
    Library book[10];
    menu:
    cout << "Welcome to the Library!" << endl
         << "1. Set Book Data" << endl
         << "2. Add Book" << endl
         << "3. Issue Book" << endl
         << "4. Return Book" << endl
         << "5. Display Book" << endl
         << "6. Exit" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            book[t].set_data();
            t++;
            goto menu;
        case 2:
            cout << "Please enter your Book name" << endl;
            getline(cin >> newline,input_book);
            for(i=0;i<t;i++)
            {
                if(book[i].search_book(input_book)==1)
                {
                    book[i].add_book();
                    break;
                }
            }
            if(i==t)
                {
                    cout << "Book not found!" << endl;
                }
            goto menu;
        case 3:
            cout << "Please enter your Book Name" << endl;
            getline(cin >> newline,input_book);
            for(i=0;i<t;i++)
            {
                if(book[i].search_book(input_book)==1)
                {
                    book[i].issue_book();
                    break;
                }
            }
            if(i==t)
                {
                    cout << "Book not found!" << endl;
                }
            goto menu;
        case 4:
            cout << "Please enter your Book Name" << endl;
            getline(cin >> newline,input_book);
            for(i=0;i<t;i++)
            {
                if(book[i].search_book(input_book)==1)
                {
                    book[i].return_book();
                    break;
                }
            }
            if(i==t)
                {
                    cout << "Book not found!" << endl;
                }
            goto menu;
        case 5:
            cout << "Please enter your Book Name" << endl;
            getline(cin >> newline,input_book);
            for(i=0;i<t;i++)
            {
                if(book[i].search_book(input_book)==1)
                {
                    book[i].display_book();
                    break;
                }
            }
            if(i==t)
                {
                    cout << "Book not found!" << endl;
                }
            goto menu;
        case 6:
            break;
        default:
            cout << "Invalid Choice, Please try again!" << endl;
            goto menu;
    }

    cout << "Visit Again!" << endl;
}
