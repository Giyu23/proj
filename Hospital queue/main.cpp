/*
THIS PROGRAM IS AN IMPLEMENTATION OF THE CONCEPT OF
QUEUE USING SEQUENTIAL ALLOCATION IN DATA STRUCTURES.

IMPLEMENTATION OF A MEDICAL POST QUEUE.
THE SERVICE IS INTENDED FOR PATIENTS OF THE GUARUJÁ HOSPITAL.
THE ORDER OF SERVICE IS BASED ON PATIENT ARRIVAL.
THE FIRST PERSON TO ENTER THE QUEUE IS THE FIRST TO LEAVE THE HOSPITAL.
note: "Karthivit" HOSPITAL" IS A FICTIONAL NAME.

by DANIEL SANTANA
*/

#include <iostream>
#include <stdlib.h>
#include "filaalocacaosequencial.h" // This header must define class Fila
using namespace std;

int main()
{
    system("color 3");
    unsigned size = 30; // QUEUE SIZE
    int option, ticket = 0;
    Fila<int> queue(size);
    cout << "\tKarthivit HOSPITAL\n\tWELCOME!!!\n\n";

    do {
        cout << "\n";
        cout << "1 - GENERATE TICKET FOR PATIENT." << endl;
        cout << "2 - CALL NEXT PATIENT FOR SERVICE." << endl;
        cout << "3 - SHOW FIRST TICKET IN QUEUE." << endl;
        cout << "4 - DISPLAY HOW MANY PATIENTS ARE WAITING." << endl;
        cout << "5 - EXIT." << endl;
        cin >> option;
        system("cls");

        switch(option) {
        case 1:
            // ADD ONE PATIENT TO THE QUEUE
            if(queue.isFull()) {
                cout << "THE QUEUE IS FULL!!!" << endl;
            } else {
                ticket++;
                queue.insertEnd(ticket);
                cout << "YOUR TICKET NUMBER IS: " << ticket << "\nPLEASE WAIT TO BE CALLED!";
            }
            break;

        case 2:
            // REMOVE ONE PATIENT FROM THE QUEUE
            if(queue.isEmpty()) {
                cout << "THE QUEUE IS EMPTY!!!" << endl;
            } else {
                cout << "PLEASE, PATIENT WITH TICKET: " << queue.front()
                     << "\nPROCEED IMMEDIATELY TO THE DOCTOR'S ROOM!" << endl;
                queue.removeFront();
            }
            break;

        case 3:
            if(queue.isEmpty()) {
                cout << "THE QUEUE IS EMPTY!!!" << endl;
            } else {
                cout << "THE NEXT PATIENT TO BE CALLED IS: " << queue.front() << endl;
            }
            break;

        case 4:
            if(queue.isEmpty()) {
                cout << "THE QUEUE IS EMPTY!!!" << endl;
            } else {
                cout << "PATIENTS WAITING: ";
                if(queue.getStart() <= queue.getEnd()) {
                    for(int i = queue.getStart(); i <= queue.getEnd(); i++) {
                        cout << queue.getValue(i) << " ";
                    }
                } else {
                    for(int i = queue.getStart(); i < queue.getSize(); i++) {
                        cout << queue.getValue(i) << " ";
                    }
                    for(int i = 0; i <= queue.getEnd(); i++) {
                        cout << queue.getValue(i) << " ";
                    }
                }
            }
            break;

        case 5:
            // EXIT
            cout << "THANK YOU FOR VISITING Karthivit HOSPITAL\nCOME BACK IF YOU NEED TO!" << endl;
            break;

        default:
            cout << "INVALID OPTION\nPLEASE TRY AGAIN!!!" << endl;
            break;
        }
    } while(option != 5);

    return 0;
}

