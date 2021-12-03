#include "Reserve.hpp"

using namespace std;

Reserve::Reserve(Hotel* input_reserved_hotel, vector<Room*> input_reserved_rooms, int input_check_in, int input_check_out, string input_room_type, int input_id)
{
    reserved_hotel = input_reserved_hotel;
    reserved_rooms = input_reserved_rooms;
    check_in_day = input_check_in;
    check_out_day = input_check_out;
    room_type = input_room_type;
    calculate_cost();
    id = input_id;
}

void Reserve::calculate_cost()
{
    cost = 0;
    for(int i = 0; i < reserved_rooms.size(); i++)
    {
        cost += reserved_rooms[i]->get_price() * (check_out_day - check_in_day + 1);
    }
}

int Reserve::get_rooms_cost_one_day()
{
    double cost = 0;
    for(int i = 0; i < reserved_rooms.size(); i++)
    {
        cost += reserved_rooms[i]->get_price();
    }
    return cost;
}

void Reserve::print_info()
{
    cout << ID_KEY << ": " << id << " " << HOTEL_KEY << ": " << reserved_hotel->get_id() << " ";
    cout << ROOM_KEY << ": " << room_type << " " << NUMBER_ROOM_KEY << ": " << reserved_rooms.size() << " ";
    cout << COST_KEY << ": " << cost << " ";
    cout << CHECK_IN_KEY << " " << check_in_day << " " << CHECK_OUT_KEY << " " << check_out_day << endl;
}

int Reserve::get_id(){return id;}

void Reserve::print_rooms_names()
{
    for(int i = 0; i < reserved_rooms.size(); i++)
    {
        reserved_rooms[i]->print_short_name();
        // if(i != ((int)reserved_rooms.size() - 1))
            cout << " ";
    }
    cout << endl;
}

int Reserve::get_cost(){return cost;}

void Reserve::cancel_reserved_rooms()
{
    for(int i = 0; i < reserved_rooms.size(); i++)
    {
        reserved_rooms[i]->unreserve(check_in_day, check_out_day);
    }
}

int Reserve::get_number_rooms()
{
    return reserved_rooms.size();
}

double Reserve::get_square_sum(double average)
{
    double sum = 0;
    for(int i = 0; i < reserved_rooms.size(); i++)
    {
        double cost_room = (double)reserved_rooms[i]->get_price();
        sum += (average - cost_room) * (average - cost_room);
    }
    return sum;
}
