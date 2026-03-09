#include <iostream>
#include <limits>

using namespace std;

int getBit() {
    int bit;
    cin >> bit;
    while (cin.fail() || (bit != 0 && bit != 1)) {
        cout << "Invalid. Enter strictly 0 or 1: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> bit;
    }
    return bit;
}

void BasicGate() {
    cout << "1. AND Gate\n2. OR Gate\n3. NOT Gate\nSelect: ";
    int choice;
    cin >> choice;
    
    if (choice == 3) {
        cout << "Enter bit: ";
        int a = getBit();
        cout << ">>> NOT Result: " << (!a) << "\n";
    } else if (choice == 1 || choice == 2) {
        cout << "Enter first bit: ";
        int a = getBit();
        cout << "Enter second bit: ";
        int b = getBit();
        if (choice == 1) cout << ">>> AND Result: " << (a & b) << "\n";
        if (choice == 2) cout << ">>> OR Result: " << (a | b) << "\n";
    }
}

void UniversalGate() {
    cout << "1. NAND Gate\n2. NOR Gate\nSelect: ";
    int choice;
    cin >> choice;
    cout << "Enter first bit: ";
    int a = getBit();
    cout << "Enter second bit: ";
    int b = getBit();
    if (choice == 1) cout << ">>> NAND Result: " << !(a & b) << "\n";
    if (choice == 2) cout << ">>> NOR Result: " << !(a | b) << "\n";
}

void SpecialGate() {
    cout << "1. XOR Gate\n2. XNOR Gate\nSelect: ";
    int choice;
    cin >> choice;
    cout << "Enter first bit: ";
    int a = getBit();
    cout << "Enter second bit: ";
    int b = getBit();
    if (choice == 1) cout << ">>> XOR Result: " << (a ^ b) << "\n";
    if (choice == 2) cout << ">>> XNOR Result: " << !(a ^ b) << "\n";
}

int main() {
    cout << "Enter the type of gate you want to test:\n"
         << "1. Basic Gates\n"
         << "2. Universal Gates\n"
         << "3. Special Gates\n"
         << "Enter 1, 2, or 3: ";
    
    int gate;
    if (!(cin >> gate)) {
        cout << "Fatal: Non-integer input detected.\n";
        return 1;
    }

    if (gate == 1) BasicGate();
    else if (gate == 2) UniversalGate();
    else if (gate == 3) SpecialGate();
    else cout << "Invalid selection.\n";

    return 0;
}