#include <iostream>
using namespace std;

string accNums[5] = {"4810055992", "4962006345", "4753008741", "3345256348", "4954083265"};
string cusNames[5] = {"Tom Lara", "Simon David", "Ben Stacy", "John Mark", "Cooper Jake"};
string nics[5] = {"965622411V", "931122456V", "927391333V", "961343267V", "967591530V"};
string accTypes[5] = {"Saving", "Current", "Fixed", "Current", "Saving"};
double balance[5] = {153000.00, 25000.00, 85000.00, 62000.00, 178000.00};

void displayMenu();
void displayAccount();
void searchAccount();
void depositAmount();
void withdrawAmount();

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    char isContinue = 'y';
    do {
        cout << "\n-----  Bank of Northern  -----\n";
        cout << "01. Customer Details\n";
        cout << "02. Search Account Details\n";
        cout << "03. Deposit\n";
        cout << "04. Withdrawal\n";
        cout << "05. Interest (Coming Soon)\n";

        int op;
        cout << "Enter the number of the operation you want: ";
        cin >> op;

        switch (op) {
            case 1:
                displayAccount();
                break;
            case 2:
                searchAccount();
                break;
            case 3:
                depositAmount();
                break;
            case 4:
                withdrawAmount();
                break;
            case 5:
                cout << "Interest calculation is not implemented yet.\n";
                break;
            default:
                cout << "Wrong input! Please try again.\n";
        }

        cout << "\nWould you like to use this app once more? (y/n): ";
        cin >> isContinue;

    } while (isContinue == 'y' || isContinue == 'Y');
}

void displayAccount() {
    cout << "\nAccount Number\tCustomer Name\tNIC\t\tBalance\n";
    for (int i = 0; i < 5; i++) {
        cout << accNums[i] << "\t" << cusNames[i] << "\t" << nics[i] << "\t" << balance[i] << endl;
    }
}

void searchAccount() {
    string userEnteredNIC;
    cout << "Enter NIC Number: ";
    cin >> userEnteredNIC;

    for (int i = 0; i < 5; i++) {
        if (nics[i] == userEnteredNIC) {
            cout << "\nAccount Number\tCustomer Name\tNIC\t\tBalance\n";
            cout << accNums[i] << "\t" << cusNames[i] << "\t" << nics[i] << "\t" << balance[i] << endl;
            return;
        }
    }
    cout << "Sorry, we don't have any account with this NIC Number.\n";
}

void depositAmount() {
    string userEnteredAccNum;
    cout << "Enter Account Number: ";
    cin >> userEnteredAccNum;

    for (int i = 0; i < 5; i++) {
        if (accNums[i] == userEnteredAccNum) {
            double depositAmount;
            cout << "Enter the amount you want to deposit: ";
            cin >> depositAmount;

            balance[i] += depositAmount;

            cout << "\nDeposit Successful!\n";
            cout << "Account Number\tCustomer Name\tNIC\t\tBalance\n";
            cout << accNums[i] << "\t" << cusNames[i] << "\t" << nics[i] << "\t" << balance[i] << endl;
            return;
        }
    }
    cout << "Sorry, we don't have any account with this Account Number.\n";
}

void withdrawAmount() {
    string userEnteredAccNum;
    cout << "Enter Account Number: ";
    cin >> userEnteredAccNum;

    for (int i = 0; i < 5; i++) {
        if (accNums[i] == userEnteredAccNum) {
            double withdrawalAmount;
            cout << "Enter the amount you want to withdraw: ";
            cin >> withdrawalAmount;

            if (withdrawalAmount > balance[i]) {
                cout << "Insufficient balance to withdraw.\n";
                return;
            }
            if ((balance[i] - withdrawalAmount) < 10000) {
                cout << "Minimum balance of 10,000 must be maintained.\n";
                return;
            }

            balance[i] -= withdrawalAmount;

            cout << "\nWithdrawal Successful!\n";
            cout << "Account Number\tCustomer Name\tNIC\t\tBalance\n";
            cout << accNums[i] << "\t" << cusNames[i] << "\t" << nics[i] << "\t" << balance[i] << endl;
            return;
        }
    }
    cout << "Sorry, we don't have any account with this Account Number.\n";
}
