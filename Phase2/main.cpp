#include "DataBase.hpp"
#include "HotelReservationInterface.hpp"
#include<vector>
#include<string>
#include<iostream>
#include "CommandHandlerInterface.hpp"

#define ARGV_ID_HOTEL_FOLDER 1
#define ARGV_ID_RATING_FOLDER 2

using namespace std;

int main(int argc, char* argv[])
{
    DataBase* datas = new DataBase();
    string hotel_file_path = argv[ARGV_ID_HOTEL_FOLDER];
    string rating_file_path = argv[ARGV_ID_RATING_FOLDER];
    datas->read_hotels(hotel_file_path);
    datas->read_ratings(rating_file_path);
    HotelReservationInterface* hotel_reservation = new HotelReservationInterface(datas);
    CommandHandlerInterface* command_handler = new CommandHandlerInterface(hotel_reservation);
    command_handler->run();
    delete datas;
    delete command_handler;
    delete hotel_reservation;
}
