#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;
    string publisher;
    int stock;

public:
    Book(string t, string a, double p, string pub, int s) : title(t), author(a), price(p), publisher(pub), stock(s) {}

    bool isMatch(string t, string a) const {
        return (title == t && author == a);
    }

    void displayBookDetails() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock Available: " << stock << endl;
    }

    bool sellBook(int quantity) {
        if (quantity <= stock) {
            stock -= quantity;
            cout << "Total Cost: " << (price * quantity) << endl;
            return true;
        } else {
            cout << "Required copies not in stock." << endl;
            return false;
        }
    }
};

class BookStore {
private:
    vector<Book> inventory;

public:
    void addBook(Book book) {
        inventory.push_back(book);
    }

    void searchBook(string title, string author, int quantity) {
        for (auto &book : inventory) {
            if (book.isMatch(title, author)) {
                book.displayBookDetails();
                if (quantity > 0) {
                    book.sellBook(quantity);
                }
                return;
            }
        }
        cout << "Book not available." << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <title> <author> <quantity>" << endl;
        return 1;
    }

    string title = argv[1];
    string author = argv[2];
    int quantity = atoi(argv[3]);

    BookStore store;
    store.addBook(Book("C++ Primer", "Stanley B. Lippman", 50.0, "Pearson", 10));
    store.addBook(Book("Effective C++", "Scott Meyers", 45.0, "O'Reilly", 5));
    
    store.searchBook(title, author, quantity);
    
    return 0;
}

