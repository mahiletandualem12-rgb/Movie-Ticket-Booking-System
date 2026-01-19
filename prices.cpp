#include <iostream>
#include <string>
using namespace std;

const int MOVIE_COUNT = 5;

int ticketPrice[MOVIE_COUNT] = {200,180,220,210,190};

int getTicketPrice(int *pricePtr, int movieIndex) {
    return *(pricePtr + movieIndex);
}

void showBill(string *moviePtr, int *pricePtr,
              int movieIndex, int seatCount) {

    cout << "\n=========== BILL SUMMARY ===========\n";
    cout << "Movie Name       : " << *(moviePtr + movieIndex) << endl;
    cout << "Tickets Booked   : " << seatCount << endl;
    cout << "Price per Ticket : "
         << getTicketPrice(pricePtr, movieIndex) << " Birr\n";
    cout << "----------------------------------\n";
    cout << "Total Amount     : "
         << getTicketPrice(pricePtr, movieIndex) * seatCount
         << " Birr\n";
    cout << "==================================\n";
}