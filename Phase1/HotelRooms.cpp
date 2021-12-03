#include "HotelRooms.hpp"

using namespace std;

HotelRooms::HotelRooms(int input_price, int input_number, RoomType input_rooms_type)
{
    int next_id = 1;
    for(int i = 0; i < input_number; i++)
    {
        Room new_room(input_price, input_rooms_type, next_id++);
        rooms.push_back(new_room);
    }
    rooms_type = input_rooms_type;
    price = input_price;
}

int HotelRooms::get_number_rooms(){return rooms.size();}
int HotelRooms::get_price(){return price;}

vector<Room*> HotelRooms::reserve_rooms(int quantity,int check_in_day,int check_out_day)
{
    vector<Room*> answer;
    if(get_number_rooms_free(check_in_day, check_out_day) < quantity)
        throw NotEnoughRoomError();
    for(int i  = 0; i < rooms.size(); i++)
    {
        if(rooms[i].is_free_in_day(check_in_day, check_out_day))
        {
            answer.push_back(&rooms[i]);
            rooms[i].reserve(check_in_day, check_out_day);
        }
        if(answer.size() == quantity)
            break;
    }
    return answer;
}

int HotelRooms::get_number_rooms_free(int check_in_day, int check_out_day)
{
    int answer = 0;
    for(int i = 0; i < rooms.size(); i++)
    {
        if(rooms[i].is_free_in_day(check_in_day, check_out_day))
            answer++;
    }
    return answer;
}

int HotelRooms::get_sum_price()
{
    return (int)rooms.size() * price;
}
