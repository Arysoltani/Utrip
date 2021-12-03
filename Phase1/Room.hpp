#ifndef ROOM_HPP
#define ROOM_HPP

#include<vector>
#include<iostream>

#define FIRST_DAY 1

const int NUMBER_DAYS = 30;

enum ReservationState{Reserved, NotReserved};
enum RoomType{Standard, Deluxe, Luxury, Premium};

class Room
{
public:
    Room(int input_price, RoomType input_room_type, int input_id);
    void unreserve(int start_day, int end_day);
    void print_short_name();
    void reserve(int check_in_day, int check_out_day);
    bool is_free_in_day(int start_day, int end_day);
    double get_price();
private:
    std::vector<ReservationState> reservation_state_days;
    RoomType room_type;
    int id_in_hotel;
    double price;
};


#endif
