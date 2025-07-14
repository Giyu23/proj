/* THIS PROGRAM SIMULATES A TICKET SALES SYSTEM FOR A THEATER
WHERE YOU CAN PURCHASE, REFUND, AND CHANGE SEATS.

DATA STRUCTURES

by Karthikeya
*/

#include <iostream>
#include <stdlib.h>
#include <locale.h>

#include "Theater.h" 

using namespace std;

int main(void) {
    Theater theater;
    bool running = true;
    int row = 10, col = 6, newRow, newCol;
    theater = Theater(row, col);
    setlocale(LC_ALL, "en_US.UTF-8"); 
    system("color 2");

    while (running) {
        cout << "\n\n  ";
        for (int k = 0; k < theater.Columns; k++) {
            if (k < 9)
                cout << "  " << (k + 1) << "  ";
            else
                cout << "  " << (k + 1) << "  ";
        }
        cout << "\n";
        for (int i = 0; i < theater.Rows; i++) {
            if (i < 9)
                cout << (i + 1) << " ";
            else
                cout << (i + 1);
            for (int j = 0; j < theater.Columns; j++) {
                if (theater.Seats[i * theater.Columns + j] == true) {
                    cout << " [X] ";
                } else {
                    cout << " [ ] ";
                }
            }
            cout << endl;
        }

        cout << "\n_________________________________\n";
        cout << "_WELCOME TO AMAZON THEATER________" << endl;
        cout << "_1) PURCHASE A SEAT.______________" << endl;
        cout << "_2) REFUND A SEAT.________________" << endl;
        cout << "_3) CHANGE A SEAT.________________" << endl;
        cout << "_0) TYPE 0 AND PRESS ENTER TO EXIT." << endl;
        cout << "\nOPTION: ";
        int option;
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter the row and column of the desired seat:" << endl;
            cout << "Row: ";
            cin >> row;
            row -= 1;
            cout << "Column: ";
            cin >> col;
            col -= 1;

            if (!theater.IsAvailable(row, col)) {
                system("cls");
                cout << "The seat is not available.";
            } else {
                theater.ReserveSeat(row, col);
                system("cls");
                cout << "Seat reserved! Enjoy the show!";
            }
            break;

        case 2:
            cout << "Enter the row and column you wish to refund: " << endl;
            cout << "Row: ";
            cin >> row;
            row -= 1;
            cout << "Column: ";
            cin >> col;
            col -= 1;

            if (theater.IsAvailable(row, col)) {
                system("cls");
                cout << "Seat is empty! You can purchase it!";
            } else {
                theater.Refund(row, col);
                system("cls");
                cout << "Refund completed successfully!";
            }
            break;

        case 3:
            cout << "Enter the row and column of your current seat:" << endl;
            cout << "Row: ";
            cin >> row;
            row -= 1;
            cout << "Column: ";
            cin >> col;
            col -= 1;
            cout << "Enter the row and column of the new desired seat:" << endl;
            cout << "Row: ";
            cin >> newRow;
            newRow -= 1;
            cout << "Column: ";
            cin >> newCol;
            newCol -= 1;

            if (!theater.IsAvailable(row, col) && theater.IsAvailable(newRow, newCol)) {
                theater.Refund(row, col);
                theater.ReserveSeat(newRow, newCol);
                system("cls");
                cout << "Seat changed successfully!";
            } else {
                cout << "Could not change the seat. Please try again.";
            }
            break;

        case 0:
            running = false;
            system("cls");
            cout << "You have exited the menu. Thank you for your preference!" << endl;
            break;

        default:
            system("cls");
            cout << "Invalid option, please try again!" << endl;
            break;
        }
    }

    return 0;
}

