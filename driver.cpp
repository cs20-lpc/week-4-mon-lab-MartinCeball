#include <iostream>
#include <string>
#include "LinkedList.hpp" // Make sure this includes your completed implementation

using namespace std;

int main() {
    cout << "===== SCENARIO 1: TESTING WITH INTEGERS =====" << endl;

    // --- Test: Creation of an empty list ---
    cout << "\n--> Test: Creating an empty list.\n";
    LinkedList<int> intList;
    cout << "Initial List: " << intList;
    cout << "Is empty? " << (intList.isEmpty() ? "Yes" : "No") << endl;
    cout << "Length: " << intList.getLength() << endl;

    // --- Test: Appending elements ---
    cout << "\n--> Test: Appending 10, 20, 30.\n";
    intList.append(10);
    intList.append(20);
    intList.append(30);
    cout << "List after appending: " << intList;
    cout << "Length: " << intList.getLength() << endl;

    // --- Test: Getting elements at valid positions ---
    cout << "\n--> Test: Getting elements at first (0), middle (1), and last (2) positions.\n";
    cout << "Element at position 0: " << intList.getElement(0) << endl;
    cout << "Element at position 1: " << intList.getElement(1) << endl;
    cout << "Element at position 2: " << intList.getElement(2) << endl;

    // --- Test: Replacing elements at valid positions ---
    cout << "\n--> Test: Replacing element at position 1 with 99.\n";
    intList.replace(1, 99);
    cout << "List after replacement: " << intList;

    // --- Test: Exception handling for out-of-bounds access ---
    cout << "\n--> Test: Triggering exceptions for invalid positions.\n";
    try {
        cout << "Trying to get element at position -1... ";
        intList.getElement(-1);
    } catch (const string& e) {
        cout << "Caught exception: " << e << endl;
    }
    try {
        cout << "Trying to replace element at position 3 (out of bounds)... ";
        intList.replace(3, 100);
    } catch (const string& e) {
        cout << "Caught exception: " << e << endl;
    }

    // --- Test: Clearing the list ---
    cout << "\n--> Test: Clearing the list.\n";
    intList.clear();
    cout << "List after clear: " << intList;
    cout << "Is empty? " << (intList.isEmpty() ? "Yes" : "No") << endl;
    cout << "Length: " << intList.getLength() << endl;

    // --- Test: Appending to a cleared list ---
    cout << "\n--> Test: Appending to a list after it has been cleared.\n";
    intList.append(55);
    cout << "List after appending again: " << intList;
    cout << "Length: " << intList.getLength() << endl;

    cout << "\n\n===== SCENARIO 2: TESTING WITH STRINGS =====" << endl;
    
    // --- Test: Creation and appending with strings ---
    cout << "\n--> Test: Creating and appending to a list of strings.\n";
    LinkedList<string> stringList;
    stringList.append("Hello");
    stringList.append("World");
    stringList.append("!");
    cout << "String List: " << stringList;
    cout << "Length: " << stringList.getLength() << endl;

    // --- Test: Replacing a string element ---
    cout << "\n--> Test: Replacing an element in the string list.\n";
    stringList.replace(0, "Greetings");
    cout << "String List after replace: " << stringList;

    cout << "\n\n===== SCENARIO 3: TESTING WITH DOUBLES =====" << endl;

    // --- Test: Creation and appending with doubles ---
    cout << "\n--> Test: Creating and appending to a list of doubles.\n";
    LinkedList<double> doubleList;
    doubleList.append(3.14);
    doubleList.append(1.618);
    cout << "Double List: " << doubleList;
    cout << "Element at position 1: " << doubleList.getElement(1) << endl;


    cout << "\n\nAll tests completed." << endl;

    return 0;
}
