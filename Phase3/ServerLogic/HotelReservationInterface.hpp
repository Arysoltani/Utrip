#ifndef HOTEL_RESERVATION_HPP
#define HOTEL_RESERVATION_HPP

#include "DataBase.hpp"
#include "HotelReservationInterface.hpp"
#include<vector>
#include<string>
#include "CsvFile.hpp"
#include "Filter.hpp"
#include "User.hpp"
#include "HotelSort.hpp"

#define DELIMITER '\n'
#define SUCESSFUL_COMMAND "OK"
#define WARNING_DEFAULT_PRICE_FILTER "* Results have been filtered by the default price filter."
#define TRUE_INFO "true"
#define FALSE_INFO "false"
#define MIN_RESERVES 10

enum PageState{LoginState,LogoutState};

class HotelReservationInterface
{
public:
    HotelReservationInterface(DataBase* input_all_datas);
    void print_summary_hotels();
    void print_hotel_full_info(std::string id);
    void filter_hotels_by_price(double min_price, double max_price);
    void filter_hotels_by_star(int min_star, int max_star);
    void filter_hotels_by_city(std::string city_name);
    void filter_hotels_by_rooms(std::string type_rooms, int quantity, int check_in, int check_out);
    void signup_user(std::string email, std::string user_name, std::string password);
    void charge_wallet_login_user(double amount);
    void reserve_rooms(std::string hotel_id, std::string type_rooms, int quantity, int check_in_day, int check_out_day);
    void print_reservations();
    void delete_filters();
    void delete_reservation(int id);
    void print_wallet_last_history(int count);
    void add_comment(std::string id_hotel, std::string new_comment);
    void print_comments_hotel(std::string id_hotel);
    void add_new_rating(double location, double cleaniness, double staff, double facilities, double value_for_money, double overall_rating, std::string id_hotel);
    void print_ratings(std::string id_hotel);
    void login_input_user(std::string email, std::string password);
    ~HotelReservationInterface();
    void check_hotel_have_enough_room(Hotel* wanted_hotel,int quantity,std::string type_rooms,int check_in_day,int check_out_day);
    void logout_user();
    bool is_user_login();
    bool has_filter_default();
    void change_default_price_filter(std::string type_change);
    void handle_sort_command(std::string property, std::string order);
    void make_manual_weights_true(double location_rating, double cleanliness_rating,double staff_rating,double facilities_rating,double value_for_money_rating);
    void print_manual_weights();
    void make_manual_weights_false();
    Hotels get_filter_hotels();
    void print_estimated_weights();
    double get_money_login_user();
private:
    bool is_valid_range_star(int min_star, int max_star);
    bool is_valid_range_price(double min_price, double max_price);
    void add_filter(Filter* new_filter);
    void delete_all_filters();
    void check_user_have_enough_money(Hotel* input_hotel, int quantity, std::string type_rooms, int check_in, int check_out);
    Hotels sort_hotels(Hotels input_hotels);
    bool has_filter(FilterType filter_type);
    DataBase* all_datas;
    User* login_user;
    std::vector<Filter*>filters;
    PageState page_state;
    bool default_price_filter;
    HotelSort* hotel_sort;
};

#endif
