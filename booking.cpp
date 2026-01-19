#include <iostream>
using  namespace std;
const int SEATS_PER_MOVIE = 20;

/*Book a single seat for a selected movie
parameters: movieIndex - index of the movie 0 - based
            seatIndex - index of he seat to book 0 - based*/

void bookSeat(int(*seatPtr)[SEATS_PER_MOVIE], int movieIndex, int seatIndex){
    /*mark the seat as booked by setting its value to 0
    1 means available, 0 means booked*/

    seatPtr[movieIndex][seatIndex] = 0;
}

//cancel a single seat for the selected movie

void cancelSeat(int(*seatPtr)[SEATS_PER_MOVIE], int movieIndex, int seatIndex){
   // mark the seat as available by setting its value to 1
    seatPtr[movieIndex][seatIndex] = 1;
}

/*update the booking for the selected movie
allows the user to cancel already booked seats and book new seats after cancellation*/

void updateBooking(int(*seatPtr)[SEATS_PER_MOVIE], int movieIndex){
int cancelCount, seatNo;
    cout<<"How many seats to cancel? ";
    cin>>cancelCount;

   for(int i =0; i< cancelCount; i++){
    cout<<"seat number to cancel: ";
    cin>> seatNo;
    // convert to 0 based index for internal use
    int idx = seatNo - 1;
    if(idx >= 0 && idx < SEATS_PER_MOVIE && seatPtr[movieIndex][idx] == 0)
    {
        cancelSeat(seatPtr, movieIndex, idx);
        cout<<"seat cancelled.\n";
    }else{
        cout<<"Invalid or not booked.\n";
        i--;
    }
   }
   int newCount;
   cout<<"How many new seats to book? ";
   cin>>newCount;

   for(int i = 0; i< newCount; i++){
    cout<<"seat number: ";
    cin >> seatNo;
    // convert to 0 based index for internal use
    int idx = seatNo - 1;
    if(idx >= 0 && idx < SEATS_PER_MOVIE && seatPtr[movieIndex][idx] == 1) 
    {
        bookSeat(seatPtr, movieIndex, idx);
        cout<< "Seat booked.\n";
    }else{

        cout<< "Seat unavailable.\n";
        i--;
    }
   }
}