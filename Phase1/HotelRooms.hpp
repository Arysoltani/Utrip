#ifndef ROOMS_HPP
#define ROOMS_HPP

#include<vector>
#include "Room.hpp"
#include "Exceptions.hpp"

class HotelRooms
{
public:
    HotelRooms(int input_price, int input_number, RoomType input_rooms_type);
    void add_room(Room* new_room);
    int get_number_rooms();
    int get_price();
    std::vector<Room*> reserve_rooms(int quantity,int check_in_day,int check_out_day);
    int get_number_rooms_free(int check_in_day, int check_out_day);
    int get_sum_price();
private:
    std::vector<Room>rooms;
    int price;
    RoomType rooms_type;
};

#endif
