#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <windows.h>
using namespace std;

class Bill {
private:
    string item;
    int rate, quantity;

public:
    Bill() : item(""), rate(0), quantity(0) {}

    void setItem(string item) {
        this->item = item;
    }

    void setRate(int rate) {
        this->rate = rate;
    }

    void setQuant(int quant) {
        this->quantity = quant;
    }

    string getitem() {
        return item;
    }

    int getrate() {
        return rate;
    }

    int getquant() {
        return quantity;
    }

    void addItem() {
        bool close = false;
        while (!close) {
            int choice;
            cout << "1. Add Item" << endl;
            cout << "2. Close" << endl;
            cout << "Enter Choice: ";
            cin >> choice;

            if (choice == 1) {
                system("cls");
                string itemName;
                int rate, quant;
                cout << "Enter Item Name: ";
                cin >> itemName;
                cout << "Enter Rate of Item: ";
                cin >> rate;
                cout << "Enter Quantity of Item: ";
                cin >> quant;

                ofstream out("project.txt", ios::app);
                if (!out) {
                    cout << "Error: Cannot open file!" << endl;
                } else {
                    out << itemName << "," << rate << "," << quant << endl;
                }
                out.close();

                cout << "Item added successfully!" << endl;
                Sleep(2000);
                system("cls");
            } else if (choice == 2) {
                close = true;
                cout << "Returning to main menu..." << endl;
                Sleep(2000);
                system("cls");
            } else {
                cout << "Invalid choice. Try again." << endl;
                Sleep(2000);
            }
        }
    }
};

void printBill() {
    system("cls");
    int total = 0;
    bool close = false;

    while (!close) {
        int choice;
        cout << "1. Add Item to Bill" << endl;
        cout << "2. Close Session" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            int quant;
            cout << "Enter Item Name: ";
            cin >> item;
            cout << "Enter Quantity: ";
            cin >> quant;

            ifstream inFile("project.txt");
            ofstream tempFile("temp.txt");
            string line;
            bool found = false;

            system("cls");
            cout << left << setw(15) << "Item"
                 << setw(10) << "Rate"
                 << setw(10) << "Qty"
                 << setw(10) << "Amount" << endl;
            cout << string(45, '-') << endl;

            while (getline(inFile, line)) {
                stringstream ss(line);
                string itemName;
                int itemRate, itemQty;

                getline(ss, itemName, ',');
                ss >> itemRate;
                ss.ignore(); // skip comma
                ss >> itemQty;

                if (item == itemName) {
                    found = true;
                    if (quant <= itemQty) {
                        int amount = itemRate * quant;
                        int newQty = itemQty - quant;
                        total += amount;

                        cout << left << setw(15) << itemName
                             << setw(10) << itemRate
                             << setw(10) << quant
                             << setw(10) << amount << endl;

                        // Update quantity in temp file
                        if (newQty > 0)
                            tempFile << itemName << "," << itemRate << "," << newQty << endl;
                    } else {
                        cout << "Sorry, not enough quantity available!" << endl;
                        tempFile << itemName << "," << itemRate << "," << itemQty << endl;
                    }
                } else {
                    tempFile << itemName << "," << itemRate << "," << itemQty << endl;
                }
            }

            if (!found) {
                cout << "Item not found!" << endl;
            }

            inFile.close();
            tempFile.close();

            remove("project.txt");
            rename("temp.txt", "project.txt");

            Sleep(3000);
            system("cls");
        } else if (choice == 2) {
            close = true;
            cout << "\nCalculating total bill..." << endl;
            Sleep(2000);
        } else {
            cout << "Invalid choice. Try again." << endl;
            Sleep(2000);
            system("cls");
        }
    }

    cout << "\n\n";
    cout << "Total Bill Amount: " << total << endl;
    cout << "Thank you for shopping!" << endl;
    Sleep(4000);
    system("cls");
}

int main() {
    Bill b;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "WELCOME TO SUPER MARKET BILLING SYSTEM" << endl;
        cout << "***************************************" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Print Bill" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> val;

        if (val == 1) {
            system("cls");
            b.addItem();
        } else if (val == 2) {
            printBill();
        } else if (val == 3) {
            exit = true;
            cout << "Exiting the system... Goodbye!" << endl;
            Sleep(2000);
        } else {
            cout << "Invalid choice. Try again." << endl;
            Sleep(2000);
        }
    }

    return 0;
}
