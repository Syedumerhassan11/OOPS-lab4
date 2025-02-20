#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string partNum, string partDesc, int qty, double price) {
        partNumber = partNum;
        partDescription = partDesc;
        quantity = (qty > 0) ? qty : 0;
        pricePerItem = (price > 0) ? price : 0.0;
    }

    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }

    void displayInvoice() const {
        cout << "Part Number: " << partNumber << endl;
        cout << "Part Description: " << partDescription << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per Item: " << pricePerItem << endl;
        cout << "Total Invoice Amount: " << getInvoiceAmount() << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 5) {
        cerr << "Usage: " << argv[0] << " <part number> <part description> <quantity> <price per item>" << endl;
        return 1;
    }

    string partNumber = argv[1];
    string partDescription = argv[2];
    int quantity = atoi(argv[3]);
    double pricePerItem = atof(argv[4]);

    Invoice invoice(partNumber, partDescription, quantity, pricePerItem);
    invoice.displayInvoice();
    
    return 0;
}

