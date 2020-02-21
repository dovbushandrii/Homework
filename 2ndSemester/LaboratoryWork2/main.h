#include <iostream>
#include "QueueImplementations/ArrayQueue.h"
#include "QueueImplementations/VectorQueue.h"
#include "QueueImplementations/LinkedQueue.h"
#include "ConsoleWork/demo.h"
#include "ConsoleWork/interactive.h"

using namespace std;

int main_Lab_2_2() {
    Interactive interactive;
    string standard = "\u001B[38m";
    while (true) {
        cout << standard;
        cout << "Enter operating, witch you want to use:" << endl;
        cout << "1 - interactive;" << endl;
        cout << "2 - demo;" << endl;
        cout << "3 - benchmark." << endl;
        cout << "Your choice: ";

        int choiceValue;
        cin >> choiceValue;
        switch (choiceValue) {
            case 1:
                interactive.run();
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                cout << "Incorrect option selected!" << endl;
        }
    }
}
