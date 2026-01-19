#include <iostream>
#include <string>
using namespace std;

/* ===== EXTERN GLOBALS ===== */
extern const int MOVIE_COUNT;
extern const int SEATS_PER_MOVIE;

extern string movies[];
extern string showTimes[];
extern int durations[];
extern int seats[][20];
extern int ticketPrice[];

/* ===== FUNCTION PROTOTYPES ===== */
void initializeSeats(int (*)[20]);
void showMovies(string*, string*, int*);
void showSeats(int (*)[20], int);

void bookSeat(int (*)[20], int, int);
void cancelSeat(int (*)[20], int, int);
void updateBooking(int (*)[20], int);

int countBookedSeats(int (*)[20], int);
void bookTicket();
int getTicketPrice(int *, int);
void showBill(string*, int*, int, int);

/* ===== MAIN ===== */
int main() {
    initializeSeats(seats);
    int choice;

    do {
        cout << "\n========== MOVIE TICKET SYSTEM ==========\n";
        cout << "1. Show Movies\n";
        cout << "2. Book Ticket\n";
        cout << "3. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showMovies(movies, showTimes, durations);
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cout << "Thank you for using the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
