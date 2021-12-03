#include "Room.hpp"

using namespace std;

Room::Room(int input_price, RoomType input_room_type, int input_id)
{
    price = input_price;
    room_type = input_room_type;
    id_in_hotel = input_id;
    for(int i = 0; i <= NUMBER_DAYS; i++)
    {
        reservation_state_days.push_back(NotReserved);
    }
}

void Room::unreserve(int start_day, int end_day)
{
    for(int i = start_day ; i <= end_day; i++)
    {
        reservation_state_days[i] = NotReserved;
    }
}

void Room::print_short_name()
{
    string answer;
    switch(room_type)
    {
        case Standard:
            cout << 's';
            break;
        case Deluxe:
            cout << 'd';
            break;
        case Luxury:
            cout << 'l';
            break;
        case Premium:
            cout << 'p';
            break;
    }
    cout << id_in_hotel;
}

void Room::reserve(int check_in_day, int check_out_day)
{
    for(int i = check_in_day ; i <= check_out_day; i++)
    {
        reservation_state_days[i] = Reserved;
    }
}

bool Room::is_free_in_day(int start_day, int end_day)
{
    for(int i = start_day ; i <= end_day; i++)
    {
        if(reservation_state_days[i] == Reserved)
            return false;
    }
    return true;
}

double Room::get_price(){return price;}
