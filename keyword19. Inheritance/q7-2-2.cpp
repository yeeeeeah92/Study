#include <iostream>
#include <cstring>
using namespace std;

class Book
{
    private : 
        char* title;
        char* isbn;
        int price;
    public : 
        Book(const char* btitle, const char* bisbn, int bprice) : price(bprice)
        {
            title = new char[strlen(btitle) + 1];
            isbn = new char[strlen(bisbn) + 1];
            strcpy(title, btitle);
            strcpy(isbn, bisbn);
        }
        void ShowBookInfo()
        {
            cout << "title : " << title << endl;
            cout << "isbn : " << isbn << endl;
            cout << "price : " << price << endl;
        }
        ~Book()
        {
            delete[] title;
            delete[] isbn;
        }
};

class EBook : public Book
{
    private : 
        char* DRMKey;
    public : 
        EBook(const char* btitle, const char* bisbn, int bprice, const char* drm) : Book(btitle, bisbn, bprice)
        {
            DRMKey = new char[strlen(drm) + 1];
            strcpy(DRMKey, drm);
        }
        void ShowEBookInfo()
        {
            ShowBookInfo();
            cout << "DRMKey : " << DRMKey << endl;
        }
        ~EBook()
        {
            delete[] DRMKey;
        }
};

int main()
{
    Book book("good C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}