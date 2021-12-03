#ifndef DATABASE_HPP
#define DATABASE_HPP

#define INPUT_NUMBER_UNIQUE_ID 0
#define INPUT_NUMBER_PROPERTY_NAME 1
#define INPUT_NUMBER_HOTEL_RATING 2
#define INPUT_NUMBER_OVERVIEW_ID 3
#define INPUT_NUMBER_AMENITIES 4
#define INPUT_NUMBER_CITY_NAME 5
#define INPUT_NUMBER_LATITUDE 6
#define INPUT_NUMBER_LONGITUDE 7
#define INPUT_NUMBER_IMAGE_URL 8
#define INPUT_NUMBER_STANDARD_NUM 9
#define INPUT_NUMBER_DELUXE_NUM 10
#define INPUT_NUMBER_LUXURY_NUM 11
#define INPUT_NUMBER_PREMIUM_NUM 12
#define INPUT_NUMBER_STANDARD_PRICE 13
#define INPUT_NUMBER_DELUXE_PRICE 14
#define INPUT_NUMBER_LUXURY_PRICE 15
#define INPUT_NUMBER_PREMIUM_PRICE 16
#define INPUT_RATING_HOTEL_ID 0
#define INPUT_LOCATION_RATING 1
#define INPUT_CLEANLINESS_RATING 2
#define INPUT_STAFF_RATING 3
#define INPUT_FACILITIES_RATING 4
#define INPUT_VALUE_FOR_MONEY 5
#define INPUT_OVERALL_RATING 6

#include "Hotels.hpp"
#include<vector>
#include<string>
#include "CsvFile.hpp"
#include<sstream>
#include "User.hpp"

class DataBase
{
public:
    ~DataBase();
    void add_user(User* new_user);
    void read_hotels(std::string hotel_file_path);
    Hotels get_hotels();
    void add_user(std::string email, std::string user_name, std::string password);
    Hotel* find_hotel(std::string id);
    User* find_user(std::string email, std::string password);
    void read_ratings(std::string file_path);
    static double string_to_double(std::string input_string);
private:
    Hotels hotels;
    std::vector<User*>users;

    void add_hotel(std::vector<std::string> splited_hotel_data);
    std::string split_by_space(std::vector<std::string> splited_datas);
    HotelDatas initialize_hotel_datas(std::vector<std::string>splited_hotel_data);
    HotelDatas intialize_datas_hotel_rooms_price(std::vector<std::string> splited_hotel_data, HotelDatas datas);
    HotelDatas intialize_datas_hotel_rooms_number(std::vector<std::string> splited_hotel_data, HotelDatas datas);
    HotelDatas initialize_datas_hotel_place(std::vector<std::string> splited_hotel_data, HotelDatas datas);
    HotelDatas initialize_hotel_info_datas(std::vector<std::string> splited_hotel_data, HotelDatas datas);
    bool does_email_exist(std::string input_email);
    bool does_user_name_exist(std::string input_user_name);
    void add_rating(std::vector<std::string> splited_rating_data);
};

#endif
