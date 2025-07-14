/*THIS PROGRAM IS AN IMPLEMENTATION OF THE STACK CONCEPT
IN DATA STRUCTURES.

THE PROGRAM IS BASED ON A CONTAINER YARD WHERE YOU CAN
STORE, REMOVE, AND CONSULT CONTAINERS, WHERE THE RULE IS TO ALWAYS
STORE ON TOP OF THE CONTAINER THAT IS ALREADY ON THE TOP OR REMOVE THE CONTAINER
THAT IS ON THE TOP.
BY KARTHIKEYA
  */
#include <iostream>
#include <stdlib.h>
#include "Container.h" // Make sure this file supports the operations used
using namespace std;

struct Container {
    unsigned code;
    unsigned size;
    float weight;
};

int main()
{
    system("color 3");
    // Define the size of the yard
    unsigned yardSize, section;
    cout << "ENTER THE SIZE OF THE YARD\nNUMBER OF SECTIONS: ";
    cin >> yardSize;

    // Creating an array of pointers to Pilha<Container>
    Pilha<Container> *yard[yardSize];

    // Initializing each stack (pile) in the yard with size = 5
    for (unsigned i = 0; i < yardSize; i++) {
        yard[i] = new Pilha<Container>(5);
    }

    Container c; // `c` is a variable of type Container
    int option;

    do {
        system("cls");
        cout << "****CONTAINER YARD****" << endl;
        cout << "1 - STORE CONTAINER." << endl;
        cout << "2 - REMOVE CONTAINER." << endl;
        cout << "3 - VIEW CONTAINER ON TOP." << endl;
        cout << "4 - DISPLAY YARD." << endl;
        cout << "9 - EXIT." << endl;
        cout << "SELECT: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "\nEnter the section: ";
            cin >> section;

            if (yard[section]->isFull()) {
                cout << "Section is full..." << endl;
                system("pause");
            } else {
                cout << "CONTAINER DATA." << endl;
                cout << "Enter container code: ";
                cin >> c.code;
                cout << "Enter size: ";
                cin >> c.size;
                cout << "Enter weight: ";
                cin >> c.weight;

                yard[section]->push(c);
                cout << "\nCONTAINER SUCCESSFULLY STORED." << endl;
                system("pause");
            }
            break;

        case 2:
            cout << "\nEnter the section: ";
            cin >> section;

            if (yard[section]->isEmpty()) {
                cout << "\nSECTION IS EMPTY!!!" << endl;
            } else {
                c = yard[section]->pop();
                cout << "CONTAINER DATA." << endl;
                cout << "Code: " << c.code << endl;
                cout << "Size: " << c.size << endl;
                cout << "Weight: " << c.weight << endl;
                cout << "The container was successfully removed.";
                system("pause");
            }
            break;

        case 3:
            cout << "Enter the section: ";
            cin >> section;

            if (yard[section]->isEmpty()) {
                cout << "\nSECTION IS EMPTY!!!" << endl;
            } else {
                c = yard[section]->peek();
                cout << "CONTAINER DATA." << endl;
                cout << "Code: " << c.code << endl;
                cout << "Size: " << c.size << endl;
                cout << "Weight: " << c.weight << endl;
                system("pause");
            }
            break;

        case 4:
            cout << "\nDisplaying the yard:" << endl;
            for (int s = 0; s < yardSize; s++) {
                if (yard[s]->isEmpty()) {
                    cout << s << " - SECTION EMPTY." << endl;
                } else {
                    for (int i = 0; i <= yard[s]->getTop(); i++) {
                        c = yard[s]->getValue(i);
                        cout << s << " - Section. Top element:\n\n";
                        cout << "CONTAINER DATA." << endl;
                        cout << "Code: " << c.code << endl;
                        cout << "Size: " << c.size << endl;
                        cout << "Weight: " << c.weight << "\n\n";
                    }
                }
            }
            system("pause");
            break;

        case 9:
            cout << "END" << endl;
            break;

        default:
            cout << "INVALID OPTION!!!\nTRY AGAIN!";
            system("pause");
        }

    } while (option != 9);

    return 0;
}


