#include <iostream>
#include <vector>
using namespace std;

//Library Management System (Basic)

class clsBook
{
private:
	string _ID;
	string _Title;
	string _Author;
	string _Gendre;
	int _PublictionYear;
	int _Pages;
	string _Language;
    bool _IsBorrow;
    bool _IsReturned;
public:
   
    // Constructor
    /*clsBook(string ID, string Title, string Author, string Gendre, int PublictionYear, int Pages, string Language) {
        _ID = ID;
        _Title = Title;
        _Author = Author;
        _Gendre = Gendre;
        _PublictionYear = PublictionYear;
        _Pages = Pages;
        _Language = Language;
        _BooksNumber++;
        vBooksList.push_back(*this);
    }*/

    clsBook()
    {
        cout << "\nEnter Book ID : "; cin >> _ID;
        cout << "\nEnter Book Title : "; cin >> _Title;
        cout << "\nEnter Book Author : "; cin >> _Author;
        cout << "\nEnter Book Gendre : "; cin >> _Gendre;
        cout << "\nEnter Book PublictionYear : "; cin >> _PublictionYear;
        cout << "\nEnter Book Pages : "; cin >> _Pages;
        cout << "\nEnter Book Language : "; cin >> _Language;
    }

    void SetID(string ID) { _ID = ID; }
    void SetTitle(string Title) { _Title = Title; }
    void SetAuthor(string Author) { _Author = Author; }
    void SetGendre(string Gendre) { _Gendre = Gendre; }
    void SetPublictionYear(int PublictionYear) { _PublictionYear = PublictionYear; }
    void SetPages(int Pages) { _Pages = Pages; }
    void SetLanguage(string Language) { _Language = Language; }
    void SetIsBorrow() { _IsBorrow = true; }
    void SetIsReturned() { _IsReturned = true; }

    // Getters
    string ID() { return _ID; }
    string Title() { return _Title; }
    string Author() { return _Author; }
    string Gendre() { return _Gendre; }
    int PublictionYear() { return _PublictionYear; }
    int Pages() { return _Pages; }
    string Language() { return _Language; }
    bool IsBorrow() { return _IsBorrow; }
    bool IsReturned() { return _IsReturned; }

    //Print Fonction.
    void Print() {
        cout << "Book Information:" << endl;
        cout << "----------------------" << endl;
        cout << "ID: " << _ID << endl;
        cout << "Title: " << _Title << endl;
        cout << "Author: " << _Author << endl;
        cout << "Gendre: " << _Gendre << endl;
        cout << "Publication Year: " << _PublictionYear << endl;
        cout << "Pages: " << _Pages << endl;
        cout << "Language: " << _Language << endl;
        cout << "IsBorrowed : " << _IsBorrow << endl;
        cout << "IsReturnded : " << _IsReturned << endl;
        cout << "----------------------" << endl;
    }
};

class clsLibrary
{
private:
    int _NumberOfBooks;
    bool _BookIsBorrow;
    bool _BookIsReturned;
    vector <clsBook> vBooksList;
public:
    void AddNewBook()
    {
        char Answer = 'y';
        while (toupper(Answer) == 'Y')
        {
            clsBook NewBook;
            vBooksList.push_back(NewBook);
            cout << "\nAdded Successfully .";
            cout << "\nDo You Want Add More Books ? "; cin >> Answer;
        }
    }
    void RemoveBook(string ID)
    {
        for (auto it = vBooksList.begin() ; it != vBooksList.end() ; it++)
        {
            if ((*it).ID() == ID)
            {
                vBooksList.erase(it);
                return;
            }
        }
        cout << "Book With ID " << ID << "not Founded ! ";
    }
    void BorrowBook(string ID)
    {
        for (clsBook& Book : vBooksList)
        {
            if (Book.ID() == ID)
            {
                if (!(Book.IsBorrow())) { Book.SetIsBorrow(); }
                else
                    cout << "\nBook Already Borrowed.";
            }
        }
            cout << "Book With ID " << ID << "not Founded ! ";
    }
    void ReturnBook(string ID)
    {
        for (clsBook& Book : vBooksList)
        {
            if (Book.ID() == ID)
            {
                if (Book.IsBorrow()) { Book.SetIsReturned(); }
                else
                    cout << "\nBook Not Borrowed.";
            }
        }
        cout << "Book With ID " << ID << "not Founded ! ";
    }
    void Print(string ID)
    {
        for (clsBook& Book : vBooksList)
        {
            if (Book.ID() == ID)
            {
                Book.Print();
            }
        }
        cout << "Book With ID " << ID << "not Founded ! ";
    }
    void printBooks() {
        cout << "ID | Title | Author | Date of Publication | Pages | Language | Genre" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        for (clsBook & Book : vBooksList) {
            cout << Book.ID() << " | " << Book.Title() << " | " << Book.Author()
                << " | " << Book.PublictionYear() << " | " << Book.Pages()
                << " | " << Book.Language() << " | " << Book.Gendre() << endl;
        }
    }
};

int main()
{
    clsLibrary Lib1;
    Lib1.AddNewBook();
    Lib1.printBooks();
    system("pause>0");
}