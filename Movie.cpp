#include <iostream>
#include <string>
using namespace std;
const int MOVIE_COUNT =5;
const int SEATS_PER_MOVIE=20;
string movies[MOVIE_COUNT]={
"The Fault In Our Stars",
 "5 Feet Apart",
 "Divergent",
 "Insurgent",
 "Allegiant"};
 string showTimes[MOVIE_COUNT]=
 {"6:00 AM","9:00 AM","1:30 PM","4:00 PM","6:00 PM"};
 int durations[MOVIE_COUNT]={140,128,150,167,120};
 int seats[MOVIE_COUNT][SEATS_PER_MOVIE];
//sets all seats for all movies as available by filling the 2D seat array with 1s.
 void initializeSeats (int(*seatptr)[SEATS_PER_MOVIE]){
 for (int i=0; i< MOVIE_COUNT; i++)
    for(int j=0;j<SEATS_PER_MOVIE;j++)
        seatptr[i][j]=1;
 }
//display movie with show time and duration
 void showMovies(string *movieptr, string *timeptr,int *durationptr){
 cout<<"Available Movies:\n";
 for (int i=0;i<MOVIE_COUNT;i++){
    cout<<i+1<<" "<<*(movieptr + i)<<endl;
    cout<<"Time:"<<*(timeptr +i)<<" "<<"Duration:"<<*(durationptr + i)<<" minutes";

 }}
//show available and booked seats
 void showSeats (int (*seatptr)[SEATS_PER_MOVIE],int movieIndex){
 int available=0;
 cout<<"Booked Seats:";
 for(int i=0;i<SEATS_PER_MOVIE;i++){
    if (seatptr[movieIndex][i]==0)
        cout<<i+1<<" ";
    else
        available++;
 }
 cout<<"Available seats :"<<available<<endl;
 }
