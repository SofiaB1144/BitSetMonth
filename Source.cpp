#include <iostream>
#include <bitset>
#include <map>
#include <string>

using namespace std;

const int MONTHS = 12;
typedef bitset<MONTHS> Set;

map<string, int> monthIndex = {
    {"january", 0}, {"february", 1}, {"march", 2}, {"april", 3},
    {"may", 4}, {"june", 5}, {"july", 6}, {"august", 7},
    {"september", 8}, {"october", 9}, {"november", 10}, {"december", 11}
};

Set inputSet(const string& name) {
    Set s;
    string month;
    cout << "Enter months for set " << name << " (type 'end' to stop):\n";
    while (true) {
        cin >> month;
        if (month == "end") break;
        if (monthIndex.count(month)) {
            s.set(monthIndex[month]);
        }
        else {
            cout << "Unknown month: " << month << endl;
        }
    }
    return s;
}
void printMonthsInSet(const Set& s, const string& setName) {
    cout << setName << " months (bitset): " << s << "\n";  
    cout << setName << " months: ";
    bool first = true;
    for (int i = 0; i < MONTHS; ++i) {
        if (s.test(i)) {  
            if (!first) cout << ", ";
            for (auto& pair : monthIndex) {
                if (pair.second == i) {
                    cout << pair.first;  
                    break;
                }
            }
            first = false;
        }
    }
    cout << "\n";
}

void printMenu() {
    cout << "\n1. Union (A | B)\n";
    cout << "2. Intersection (A & B)\n";
    cout << "3. Symmetric Difference (A ^ B)\n";
    cout << "4. A \\ B\n";
    cout << "5. B \\ A\n";
    cout << "6. Check month in A\n";
    cout << "7. Check month in B\n";
    cout << "8. Exit\n";
    cout << "Your choice: ";
}

int main() {
    Set A = inputSet("A");
    Set B = inputSet("B");

    printMonthsInSet(A, "A");
    printMonthsInSet(B, "B");

    int choice;
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "A | B = " << (A | B) << endl;
            break;
        case 2:
            cout << "A & B = " << (A & B) << endl;
            break;
        case 3:
            cout << "A ^ B = " << (A ^ B) << endl;
            break;
        case 4:
            cout << "A \\ B = " << (A & ~B) << endl;
            break;
        case 5:
            cout << "B \\ A = " << (B & ~A) << endl;
            break;
        case 6: {
            string m;
            cout << "Enter month: ";
            cin >> m;
            cout << (monthIndex.count(m) && A.test(monthIndex[m]) ? "Yes\n" : "No\n");
            break;
        }
        case 7: {
            string m;
            cout << "Enter month: ";
            cin >> m;
            cout << (monthIndex.count(m) && B.test(monthIndex[m]) ? "Yes\n" : "No\n");
            break;
        }
        case 8:
            cout << "Bye!\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}