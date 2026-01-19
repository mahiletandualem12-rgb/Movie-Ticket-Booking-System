#include <iostream>
#include "menu.h"
#include "movies.h"
#include "booking.h"
#include "price.h"
using namespace std;

int main() {
    showMenu();
     showMovies();
     bookTicket();

cout<< "price:" <<calculatePrice()<<endl;
    return 0;
}
