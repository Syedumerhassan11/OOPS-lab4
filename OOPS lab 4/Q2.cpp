#include <iostream>
#include <cstdlib>
using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 0)
            balance = initialBalance;
        else {
            balance = 0;
            cerr << "Initial balance invalid. Setting balance to 0." << endl;
        }
    }

    void credit(double amount) {
        balance += amount;
    }

    void debit(double amount) {
        if (amount > balance) {
            cerr << "Debit amount exceeded account balance." << endl;
        } else {
            balance -= amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <initial balance> <credit amount> <debit amount>" << endl;
        return 1;
    }

    double initialBalance = atof(argv[1]);
    double creditAmount = atof(argv[2]);
    double debitAmount = atof(argv[3]);

    Account myAccount(initialBalance);
    cout << "Initial Balance: " << myAccount.getBalance() << endl;
    
    myAccount.credit(creditAmount);
    cout << "Balance after credit: " << myAccount.getBalance() << endl;
    
    myAccount.debit(debitAmount);
    cout << "Balance after debit: " << myAccount.getBalance() << endl;
    
    return 0;
}

