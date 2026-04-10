#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_ACCOUNTS = 100;

struct Account {
    int customerID;
    string firstName;
    string lastName;
    string address;
    double checking;
    double moneyMarket;
    double savings;
};

// Sort helper: compare by customer ID
bool compareByID(const Account &a, const Account &b) {
    return a.customerID < b.customerID;
}

// Display all accounts sorted by customer ID
void DisplayAccounts(Account arr[], int accts) {
    sort(arr, arr + accts, compareByID);
    cout << "\n--- All Accounts ---\n";
    cout << "ID     | Name                  | Address                          | Checking   | Money Mkt  | Savings\n";
    cout << string(110, '-') << "\n";
    for (int i = 0; i < accts; i++) {
        cout << arr[i].customerID << "\t| "
             << arr[i].firstName << " " << arr[i].lastName << "\t| "
             << arr[i].address << "\t| $"
             << arr[i].checking << "\t| $"
             << arr[i].moneyMarket << "\t| $"
             << arr[i].savings << "\n";
    }
}

// Display accounts with savings > 0, sorted by customer ID
void DisplaySavingsAccounts(Account arr[], int accts) {
    sort(arr, arr + accts, compareByID);
    cout << "\n--- Savings Accounts (balance > 0) ---\n";
    cout << "ID     | Name                  | Address                          | Savings\n";
    cout << string(80, '-') << "\n";
    for (int i = 0; i < accts; i++) {
        if (arr[i].savings > 0) {
            cout << arr[i].customerID << "\t| "
                 << arr[i].firstName << " " << arr[i].lastName << "\t| "
                 << arr[i].address << "\t| $"
                 << arr[i].savings << "\n";
        }
    }
}

// Display accounts with checking > 0, sorted by customer ID
void DisplayCheckingAccounts(Account arr[], int accts) {
    sort(arr, arr + accts, compareByID);
    cout << "\n--- Checking Accounts (balance > 0) ---\n";
    cout << "ID     | Name                  | Address                          | Checking\n";
    cout << string(80, '-') << "\n";
    for (int i = 0; i < accts; i++) {
        if (arr[i].checking > 0) {
            cout << arr[i].customerID << "\t| "
                 << arr[i].firstName << " " << arr[i].lastName << "\t| "
                 << arr[i].address << "\t| $"
                 << arr[i].checking << "\n";
        }
    }
}

// Display accounts with money market > 0, sorted by customer ID
void DisplayMoneyMktAccounts(Account arr[], int accts) {
    sort(arr, arr + accts, compareByID);
    cout << "\n--- Money Market Accounts (balance > 0) ---\n";
    cout << "ID     | Name                  | Address                          | Money Market\n";
    cout << string(80, '-') << "\n";
    for (int i = 0; i < accts; i++) {
        if (arr[i].moneyMarket > 0) {
            cout << arr[i].customerID << "\t| "
                 << arr[i].firstName << " " << arr[i].lastName << "\t| "
                 << arr[i].address << "\t| $"
                 << arr[i].moneyMarket << "\n";
        }
    }
}

// Calculate total of all balances across all accounts
double TotalBalanceAccounts(double arr[], int accts) {
    double total = 0.0;
    for (int i = 0; i < accts; i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int count = 0;

    // Read file
    ifstream inFile("accounts.txt");
    if (!inFile) {
        cout << "Error: Could not open accounts.txt\n";
        return 1;
    }

    // Read records until EOF; fields separated by ':'
    // Format: ID:First:Last:Address:Checking:MoneyMarket:Savings
    // Address can contain spaces (but no colons)
    string line;
    while (count < MAX_ACCOUNTS && getline(inFile, line)) {
        if (line.empty()) continue;

        // Parse by colon
        // Fields: [0]=ID [1]=First [2]=Last [3]=Address [4]=Checking [5]=MoneyMkt [6]=Savings
        string fields[7];
        int fieldIndex = 0;
        string token = "";
        for (int i = 0; i < (int)line.size() && fieldIndex < 7; i++) {
            if (line[i] == ':') {
                fields[fieldIndex++] = token;
                token = "";
            } else {
                token += line[i];
            }
        }
        fields[fieldIndex] = token; // last field

        accounts[count].customerID  = stoi(fields[0]);
        accounts[count].firstName   = fields[1];
        accounts[count].lastName    = fields[2];
        accounts[count].address     = fields[3];
        accounts[count].checking    = stod(fields[4]);
        accounts[count].moneyMarket = stod(fields[5]);
        accounts[count].savings     = stod(fields[6]);
        count++;
    }
    inFile.close();

    cout << "Loaded " << count << " account(s) from file.\n";

    // Menu loop
    int choice = 0;
    do {
        cout << "\n========== BANK ACCOUNT MENU ==========\n";
        cout << "1. Display All Accounts\n";
        cout << "2. Display Savings Accounts\n";
        cout << "3. Display Checking Accounts\n";
        cout << "4. Display Money Market Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: DisplayAccounts(accounts, count);      break;
            case 2: DisplaySavingsAccounts(accounts, count); break;
            case 3: DisplayCheckingAccounts(accounts, count); break;
            case 4: DisplayMoneyMktAccounts(accounts, count); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice, Try again.\n";
        }
    } while (choice != 5);

    // Build flat array of all balances for TotalBalanceAccounts
    double allBalances[MAX_ACCOUNTS * 3];
    int balanceCount = 0;
    for (int i = 0; i < count; i++) {
        allBalances[balanceCount++] = accounts[i].checking;
        allBalances[balanceCount++] = accounts[i].moneyMarket;
        allBalances[balanceCount++] = accounts[i].savings;
    }

    double total = TotalBalanceAccounts(allBalances, balanceCount);
    cout << "\nTotal balance of all accounts (checking + money market + savings): $"
         << total << "\n";

    return 0;
}