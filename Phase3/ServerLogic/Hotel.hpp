#ifndef HOTEL_HPP
#define HOTEL_HPP

#include<string>
#include "HotelRooms.hpp"
#include "Room.hpp"
#include<iostream>
#include<iomanip>
#include "Comment.hpp"
#include "Ratings.hpp"

#define ID_UNIQUE_ID_DATA 0

#define STAR_KEY_PRINT "star"
#define CITY_KEY_PRINT "city"
#define LATITUDE_KEY_PRINT "latitude"
#define LONGITUDE_KEY_PRINT "longitude"
#define OVERVIEW_KEY_PRINT "overview"
#define AMENITIES_KEY_PRINT "amenities"
#define ROOM_NUMBER_KEY_PRINT "#rooms"
#define ROOM_PRICE_KEY_PRINT "price"
#define STANDARD_TYPE "standard"
#define DELUXE_TYPE "deluxe"
#define LUXURY_TYPE "luxury"
#define PREMIUM_TYPE "premium"

struct HotelDatas
{
    std::string unique_id;
    std::string property_name;
    int hotel_rating;
    std::string hotel_overview;
    std::string property_amenities;
    std::string city_name;
    double latitude;
    double longitude;
    std::string image_url;
    int standard_price;
    int deluxe_price;
    int luxury_price;
    int premium_price;
    int standard_number_rooms;
    int deluxe_number_rooms;
    int luxury_number_rooms;
    int premium_number_rooms;
};


class Hotel
{
public:
    Hotel(HotelDatas datas);
    void print_all_info();
    bool is_equal_id(std::string input_id);
    double get_price();
    int get_star();
    void print_summary();
    std::string get_city_name();
    std::string get_id();
    std::vector<Room*> reserve_rooms(std::string type_rooms, int quantity, int check_in_day, int check_out_day);
    void add_comment(Comment new_comment);
    void print_comments();
    bool does_hotel_have_rooms(std::string type_rooms, int quantity, int check_in, int check_out);
    void add_new_rating(double location, double cleaniness, double staff, double facilities, double value_for_money, double overall_rating);
    void print_ratings();
    int get_cost(std::string type_rooms, int quantity);
    bool is_in_range_deviation(double deviation, double average);
    std::string get_name();
    int get_price_room(std::string type);
    int get_standard_price();
    int get_premium_price();
    int get_deluxe_price();
    std::string get_url_image();
    int get_luxury_price();
    double get_overall_rating_by_weights(Rating weight_rating);
    std::string get_amenities();
    std::string get_overview();


private:
    int get_number_non_zero_price();
    int get_number_all_rooms();
    void print_hotel_rooms_info();
    double get_average_rooms_price();

    std::string unique_id;
    std::string property_name;
    int hotel_rating;
    std::string hotel_overview;
    std::string property_amenities;
    std::string city_name;
    double latitude;
    double longitude;
    std::string image_url;
    HotelRooms standard_rooms;
    HotelRooms deluxe_rooms;
    HotelRooms luxury_rooms;
    HotelRooms premium_rooms;
    std::vector<Comment>comments;
    Ratings hotel_ratings;
};


#endif
