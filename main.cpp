#include "CircularLinkedList.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create a circular linked list to store property names
    CircularLinkedList<string> monopolyBoard;

    // Append some Monopoly property names
    monopolyBoard.append("Go");
    monopolyBoard.append("Mediterranean Avenue");
    monopolyBoard.append("Community Chest");
    monopolyBoard.append("Baltic Avenue");
    monopolyBoard.append("Income Tax");

    // Show the current node (should be "Go")
    cout << "Current space: " << monopolyBoard.getCurrent() << endl;

    // Step to next and show
    monopolyBoard.step();
    cout << "Next space: " << monopolyBoard.getCurrent() << endl;

    // Step a few more times
    monopolyBoard.step();
    monopolyBoard.step();
    cout << "After 3 steps: " << monopolyBoard.getCurrent() << endl;

    // Loop all the way back around
    for (int i = 0; i < 37; i++) {
        monopolyBoard.step();
    }
    cout << "After 37 more steps: " << monopolyBoard.getCurrent() << endl;

    return 0;
}
