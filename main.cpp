#include <iostream>
#include <string>
using namespace std;

// Constants
const int MOVIE_COUNT = 5;
const int SEATS_PER_MOVIE = 20;

// Movie data
string movies[MOVIE_COUNT] = {
    "The Fault in Our Stars",
    "5 Feet Apart",
    "Divergent",
    "Insurgent",
    "Allegiant"
};

string showTimes[MOVIE_COUNT] = {
    "6:00 AM",
    "9:00 AM",
    "1:30 PM",
    "4:00 PM",
    "6:00 PM"
};

int durations[MOVIE_COUNT] = {140, 128, 150, 167, 120};
int ticketPrice[MOVIE_COUNT] = {200, 180, 220, 210, 190};

// Seat data (1 = available, 0 = booked)
int seats[MOVIE_COUNT][SEATS_PER_MOVIE];

// Function declarations
void initializeSeats(int (*)[SEATS_PER_MOVIE]);
void showMovies(string*, string*, int*);
void showSeats(int (*)[SEATS_PER_MOVIE], int);
void bookSeat(int (*)[SEATS_PER_MOVIE], int, int);
void cancelSeat(int (*)[SEATS_PER_MOVIE], int, int);
void updateBooking(int (*)[SEATS_PER_MOVIE], int);
int countBookedSeats(int (*)[SEATS_PER_MOVIE], int);
void showBill(string*, int*, int, int);
void bookTicket();

// Initialize all seats
void initializeSeats(int (*seatPtr)[SEATS_PER_MOVIE]) {
    for (int i = 0; i < MOVIE_COUNT; i++)
        for (int j = 0; j < SEATS_PER_MOVIE; j++)
            seatPtr[i][j] = 1;
}

// Display available movies
void showMovies(string *moviePtr, string *timePtr, int *durationPtr) {
    cout << "\n=========== AVAILABLE MOVIES ===========\n";
    for (int i = 0; i < MOVIE_COUNT; i++) {
        cout << i + 1 << ". " << moviePtr[i] << endl;
        cout << "   Time     : " << timePtr[i] << endl;
        cout << "   Duration : " << durationPtr[i] << " minutes\n";
        cout << "   Price    : " << ticketPrice[i] << " Birr\n\n";
    }
}

// Show seat status
void showSeats(int (*seatPtr)[SEATS_PER_MOVIE], int movieIndex) {
    cout << "\nAvailable seats: ";
    int available = 0;
    for (int i = 0; i < SEATS_PER_MOVIE; i++) {
        if (seatPtr[movieIndex][i] == 1) {
            cout << i + 1 << " ";
            available++;
        }
    }
    cout << "\nAvailable seat count: " << available << endl;
}

// Book seat
void bookSeat(int (*seatPtr)[SEATS_PER_MOVIE], int movieIndex, int seatIndex) {
    seatPtr[movieIndex][seatIndex] = 0;
}

// Cancel seat
void cancelSeat(int (*seatPtr)[SEATS_PER_MOVIE], int movieIndex, int seatIndex) {
    seatPtr[movieIndex][seatIndex] = 1;
}

// Update booking
void updateBooking(int (*seatPtr)[SEATS_PER_MOVIE], int movieIndex) {
    int cancelCount, seatNo;
    cout << "\nHow many seats do you want to cancel? ";
    cin >> cancelCount;

    for (int i = 0; i < cancelCount; i++) {
        cout << "Enter seat number to cancel: ";
        cin >> seatNo;
        int idx = seatNo - 1;

        if (idx >= 0 && idx < SEATS_PER_MOVIE && seatPtr[movieIndex][idx] == 0) {
            cancelSeat(seatPtr, movieIndex, idx);
            cout << "Seat cancelled.\n";
        } else {
            cout << "Invalid seat. Try again.\n";
            i--;
        }
    }

    int newCount;
    cout << "\nHow many new seats to book? ";
    cin >> newCount;

    for (int i = 0; i < newCount; i++) {
        cout << "Enter seat number: ";
        cin >> seatNo;
        int idx = seatNo - 1;

        if (idx >= 0 && idx < SEATS_PER_MOVIE && seatPtr[movieIndex][idx] == 1) {
            bookSeat(seatPtr, movieIndex, idx);
            cout << "Seat booked.\n";
        } else {
            cout << "Seat unavailable. Try again.\n";
            i--;
        }
    }
}

// Count booked seats
int countBookedSeats(int (*seatPtr)[SEATS_PER_MOVIE], int movieIndex) {
    int count = 0;
    for (int i = 0; i < SEATS_PER_MOVIE; i++)
        if (seatPtr[movieIndex][i] == 0)
            count++;
    return count;
}

// Show bill
void showBill(string *moviePtr, int *pricePtr, int movieIndex, int seatCount) {
    cout << "\n=========== BILL SUMMARY ===========\n";
    cout << "Movie Name       : " << moviePtr[movieIndex] << endl;
    cout << "Tickets Booked   : " << seatCount << endl;
    cout << "Price per Ticket : " << pricePtr[movieIndex] << " Birr\n";
    cout << "----------------------------------\n";
    cout << "Total Amount     : " << pricePtr[movieIndex] * seatCount << " Birr\n";
    cout << "==================================\n";
}

// Book ticket process
void bookTicket() {
    int movieChoice, seatCount, seatNo;

    showMovies(movies, showTimes, durations);
    cout << "Choose a movie (1-5): ";
    cin >> movieChoice;
    movieChoice--;

    if (movieChoice < 0 || movieChoice >= MOVIE_COUNT) {
        cout << "Invalid choice.\n";
        return;
    }

    showSeats(seats, movieChoice);

    cout << "\nHow many seats do you want to book? ";
    cin >> seatCount;

    for (int i = 0; i < seatCount; i++) {
        cout << "Enter seat number: ";
        cin >> seatNo;
        int idx = seatNo - 1;

        if (idx >= 0 && idx < SEATS_PER_MOVIE && seats[movieChoice][idx] == 1) {
            bookSeat(seats, movieChoice, idx);
            cout << "Seat booked.\n";
        } else {
            cout << "Seat unavailable. Try again.\n";
            i--;
        }
    }

    char choice;
    cout << "\nDo you want to update your booking? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
        updateBooking(seats, movieChoice);

    int finalCount = countBookedSeats(seats, movieChoice);
    showBill(movies, ticketPrice, movieChoice, finalCount);
}


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
                cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
