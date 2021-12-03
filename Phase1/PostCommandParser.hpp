#ifndef POST_COMMAND_PARSER
#define POST_COMMAND_PARSER

#include "HotelReservationInterface.hpp"
#include "CommandParser.hpp"
#include "Exceptions.hpp"
#include "HotelSort.hpp"
#include "DataBase.hpp"

#define SECOND_TYPE 2
#define EMAIL_KEY "email"
#define PASSWORD_KEY "password"
#define LOGIN_COMMAND_KEY "login"
#define USER_NAME_KEY "username"
#define SIGN_UP_COMMAND_KEY "signup"
#define LOGOUT_COMMAND_KEY "logout"
#define FILTER_COMMAND_KEY "filters"
#define CITY_KEY "city"
#define MINIMUM_STAR_KEY "min_star"
#define MAXIMUM_STAR_KEY "max_star"
#define MINIMUM_PRICE_KEY "min_price"
#define MAXIMUM_PRICE_KEY "max_price"
#define RESERVE_COMMAND_KEY "reserves"
#define HOTEL_KEY "hotel"
#define TYPE_ROOMS_KEY "type"
#define QUANTITY_KEY "quantity"
#define CHECK_IN_KEY "check_in"
#define CHECK_OUT_KEY "check_out"
#define WALLET_COMMAND_KEY "wallet"
#define AMOUNT_KEY "amount"
#define COMMENT_KEY "comment"
#define COMMENT_COMMAND_KEY "comments"
#define RATING_COMMAND_KEY "ratings"
#define LOCATION_RATING_KEY "location"
#define CLEANLINESS_RATING_KEY "cleanliness"
#define STAFF_RATING_KEY "staff"
#define FACILITIES_RATING_KEY "facilities"
#define VALUE_FOR_MONEY_RATING_KEY "value_for_money"
#define OVERALL_RATING_KEY "overall_rating"
#define ID_KEY "id"
#define LOGIN_NUMBER_STRINGS 4
#define SIGN_UP_NUMBER_STRINGS 6
#define STAR_FILTER_STRINGS 4
#define PRICE_FILTER_STRINGS 4
#define COMMENT_STRINGS 4
#define RATING_STRINGS 14
#define WALLET_CHARGE_STRINGS 2
#define RESERVE_FILTER_NUMBER_STRINGS 8
#define RESERVE_COMMAND_STRINGS 10
#define EMPTY_STRING ""
#define ACTIVE_KEY "active"
#define DEFAULT_PRICE_FILTER_KEY "default_price_filter"
#define ORDER_KEY "order"
#define PROPERTY_KEY "property"
#define SORT_KEY "sort"
#define SORT_NUMBER_STRINGS 4
#define DEFUALT_FILTER_NUMBER_STRINGS 2
#define MANUAL_RATING_TRUE_COMMAND 12
#define MANUAL_RATING_FALSE_COMMAND 2
#define FALSE_DATA "false"
#define MANUAL_WEIGHT_KEY "manual_weights"

class PostCommandParser : public CommandParser
{
public:
    PostCommandParser(HotelReservationInterface* input_hotel_reservation);
    void parse_command(std::string command);
private:
    HotelReservationInterface* hotel_reservation;
    void parse_login_command(std::string command);
    void parse_sign_up_command(std::string command);
    void parse_logout_command(std::string command);
    void parser_filter_command(std::string command);
    void parse_filter_by_city(std::string info_command);
    void parse_filter_by_star(std::string info_command);
    void parse_filter_by_price(std::string info_command);
    void parse_reserve_command(std::string command);
    void parse_wallet_charge_command(std::string command);
    void parse_comment_command(std::string command);
    void parse_rating_command(std::string command);
    void parse_filter_by_reserves(std::string info_command);
    void parse_default_filter(std::string command);
    void parse_sort_command(std::string command);
    void parse_true_command_manual(std::string info_command);
    void parse_manual_weight_command(std::string command);
};

class DeleteCommandParser : public CommandParser
{
public:
    DeleteCommandParser(HotelReservationInterface* input_hotel_reservation);
    void parse_command(std::string command);
private:
    HotelReservationInterface* hotel_reservation;
    void parse_delete_filters(std::string command);
    void parse_delete_reserves(std::string command);
};

#endif
