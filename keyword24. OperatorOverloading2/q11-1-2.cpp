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
        Book(const Book& ref) : price(ref.price)
        {
            title = new char[strlen(ref.title) + 1];
            isbn = new char[strlen(ref.isbn) + 1];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);
        }
        void ShowBookInfo()
        {
            cout << "title : " << title << endl;
            cout << "isbn : " << isbn << endl;
            cout << "price : " << price << endl;
        }
        Book& operator=(const Book& ref)
        {
            delete[] title;
            delete[] isbn;
            
            title = new char[strlen(ref.title) + 1];
            isbn = new char[strlen(ref.isbn) + 1];
            strcpy(title, ref.title);
            strcpy(isbn, ref.isbn);
            price = ref.price;
            return *this;
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
        EBook(const EBook& ref) : Book(ref)
        {
            DRMKey = new char[strlen(ref.DRMKey) + 1];
            strcpy(DRMKey, ref.DRMKey);
        }
        void ShowEBookInfo()
        {
            ShowBookInfo();
            cout << "DRMKey : " << DRMKey << endl;
        }
        
        EBook& operator=(const EBook& ref)
        {
            Book::operator=(ref);
            delete [] DRMKey;
            DRMKey = new char[strlen(ref.DRMKey) + 1];
            strcpy(DRMKey, ref.DRMKey);
            return *this;
        }

        ~EBook()
        {
            delete[] DRMKey;
        }
};

int main()
{
    EBook ebook1("good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    EBook ebook2 = ebook1;
    ebook2.ShowEBookInfo();
    cout << endl;
    EBook ebook3("dummy", "dummy", 0, "dummy");
    ebook3.ShowEBookInfo();
    ebook3 = ebook2;
    ebook3.ShowEBookInfo();
    return 0;
}