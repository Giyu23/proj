#ifndef THEATER_H_INCLUDED
#define THEATER_H_INCLUDED

#include <iostream>

/****************************
   CODED BY DANIEL SANTANA
*****************************/

using namespace std;

struct Theater {

    unsigned Rows;
    unsigned Columns;
    unsigned Sales;
    bool* Seats;

    Theater() {
    }

    Theater(int rows, int columns) {
        Rows = rows;
        Columns = columns;
        Seats = new bool[Rows * Columns];
        Sales = 0;
        // Initialize the matrix
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Columns; j++) {
                Seats[i * Columns + j] = false;
            }
        }
    }

    /* Check seat availability */
    bool IsAvailable(int row, int column) {
        if (row < Rows && column < Columns &&
            Seats[row * Columns + column] == false)
            return true;
        return false;
    }

    /* Mark a seat as sold */
    void ReserveSeat(int row, int column) {
        Seats[row * Columns + column] = true;
        Sales += 1;
    }

    /* Refund seat */
    void Refund(int row, int column) {
        Seats[row * Columns + column] = false;
        Sales -= 1;
    }
};

#endif // THEATER_H_INCLUDED

