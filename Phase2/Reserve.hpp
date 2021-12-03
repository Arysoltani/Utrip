#ifndef RESERVE_HPP
#define RESERVE_HPP

#include<vector>
#include<string>
#include "Hotel.hpp"
#include "Room.hpp"
#include<iomanip>

#define ID_KEY "id"
#define COST_KEY "cost"
#define ROOM_KEY "room"
#define NUMBER_ROOM_KEY "quantity"
#define CHECK_IN_KEY "check_in"
#define CHECK_OUT_KEY "check_out"
#define HOTEL_KEY "hotel"

class Reserve
{
public:
    Reserve(Hotel* input_reserved_hotel, std::vector<Room*> input_reserved_rooms, int input_check_in, int input_check_out, std::string input_room_type, int input_id);
    void print_info();
    int get_id();
    void print_rooms_names();
    int get_number_rooms();
    int get_cost();
    int get_rooms_cost_one_day();
    void cancel_reserved_rooms();
    double get_square_sum(double average);
private:
    Hotel* reserved_hotel;
    std::vector<Room*>reserved_rooms;
    int id;
    int check_in_day;
    int check_out_day;
    std::string room_type;
    int cost;
    void calculate_cost();
};

#endif
