#include <iostream>
#include <string>
using namespace std;

// External data
extern const int MOVIE_COUNT;
extern const int SEATS_PER_MOVIE;
extern string movies[];
extern string showTimes[];
extern int durations[];
extern int seats[][20];
extern int ticketPrice[];

// Functions

void initializeSeats(int (*)[20]);
void showMovies(string*, string*, int*);
void showSeats(int (*)[20], int);

void bookSeat(int (*)[20], int, int);
void updateBooking(int (*)[20], int);

void showBill(string*, int*, int, int);

// Helper

int countBookedSeats(int (*seatPtr)[20], int movieIndex) {
    int count = 0;
    for (int i = 0; i < 20; i++)
        if (seatPtr[movieIndex][i] == 0)
            count++;
    return count;
}

// Booking Flow

void bookTicket() {
    int movieChoice, seatCount, seatNo;

    showMovies(movies, showTimes, durations);

    cout << "Choose movie (1-5): ";
    cin >> movieChoice;
    movieChoice--;

    showSeats(seats, movieChoice);

    cout << "Seats to book: ";
    cin >> seatCount;

    for (int i = 0; i < seatCount; i++) {
        cout << "Seat number: ";
        cin >> seatNo;

        int idx = seatNo - 1;
        if (seats[movieChoice][idx] == 1) {
            bookSeat(seats, movieChoice, idx);
        } else {
            cout << "Already booked.\n";
            i--;
        }
    }

    char ch;
    cout << "Update booking? (y/n): ";
    cin >> ch;

    if (ch == 'y' || ch == 'Y')
        updateBooking(seats, movieChoice);

    int finalSeats = countBookedSeats(seats, movieChoice);
    showBill(movies, ticketPrice, movieChoice, finalSeats);
}

// Main

int main() {
    initializeSeats(seats);
    int choice;

    do {
        cout << "\n1. Show Movies\n2. Book Ticket\n3. Exit\n";
        cin >> choice;

        switch (choice){
    case 1:
        showMovies(movies, showTimes, durations);
        break;
    case 2:
        bookTicket();
        break;
    case 3:
        break;
    default:
        cout<<"Invalid number\n";
        break;

    }

    } while (choice != 3);

    cout << "Thank you!\n";
    return 0;
}
