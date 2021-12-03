#include "PostCommandParser.hpp"

using namespace std;

PostCommandParser::PostCommandParser(HotelReservationInterface* input_hotel_reservation)
{
    hotel_reservation = input_hotel_reservation;
}

DeleteCommandParser::DeleteCommandParser(HotelReservationInterface* input_hotel_reservation)
{
    hotel_reservation = input_hotel_reservation;
}

void DeleteCommandParser::parse_command(string command)
{
    if(!hotel_reservation->is_user_login())
        throw PermissionDeniedError();
    string type = get_word(SECOND_TYPE, command);
    if(type == FILTER_COMMAND_KEY)
        parse_delete_filters(command);
    else if(type == RESERVE_COMMAND_KEY)
        parse_delete_reserves(command);
    else
        throw NotFoundError();
}

void PostCommandParser::parse_command(string command)
{
    string type = get_word(SECOND_TYPE, command);
    if(type != LOGIN_COMMAND_KEY && type != SIGN_UP_COMMAND_KEY && !hotel_reservation->is_user_login())
        throw PermissionDeniedError();
    if(type == LOGIN_COMMAND_KEY)
        parse_login_command(command);
    else if(type == SIGN_UP_COMMAND_KEY)
        parse_sign_up_command(command);
    else if(type == LOGOUT_COMMAND_KEY)
        parse_logout_command(command);
    else if(type == FILTER_COMMAND_KEY)
        parser_filter_command(command);
    else if(type == RESERVE_COMMAND_KEY)
        parse_reserve_command(command);
    else if(type == WALLET_COMMAND_KEY)
        parse_wallet_charge_command(command);
    else if(type == COMMENT_COMMAND_KEY)
        parse_comment_command(command);
    else if(type == RATING_COMMAND_KEY)
        parse_rating_command(command);
    else if(type == DEFAULT_PRICE_FILTER_KEY)
        parse_default_filter(command);
    else if(type == SORT_KEY)
        parse_sort_command(command);
    else if(type == MANUAL_WEIGHT_KEY)
        parse_manual_weight_command(command);
    else
        throw NotFoundError();
}

void PostCommandParser::parse_login_command(string command)
{
    string info_command = get_info_command(command);
    check_number_strings(LOGIN_NUMBER_STRINGS, info_command);
    string email = find_key_data<string>(EMAIL_KEY, info_command);
    string password = find_key_data<string>(PASSWORD_KEY, info_command);
    hotel_reservation->login_input_user(email, password);
}

void PostCommandParser::parse_sign_up_command(string command)
{
    string info_command = get_info_command(command);
    check_number_strings(SIGN_UP_NUMBER_STRINGS, info_command);
    string email = find_key_data<string>(EMAIL_KEY, info_command);
    string password = find_key_data<string>(PASSWORD_KEY, info_command);
    string user_name = find_key_data<string>(USER_NAME_KEY, info_command);
    hotel_reservation->signup_user(email, user_name, password);
}

void PostCommandParser::parse_logout_command(string command)
{
    hotel_reservation->logout_user();
}

void PostCommandParser::parser_filter_command(string command)
{
    string info_command = get_info_command(command);
    if(does_exist_key(CITY_KEY, info_command))
        parse_filter_by_city(info_command);
    else if(does_exist_key(MINIMUM_STAR_KEY, info_command))
        parse_filter_by_star(info_command);
    else if(does_exist_key(MINIMUM_PRICE_KEY, info_command))
        parse_filter_by_price(info_command);
    else if(does_exist_key(TYPE_ROOMS_KEY, info_command))
        parse_filter_by_reserves(info_command);
    else
        throw BadRequestError();
}

void PostCommandParser::parse_filter_by_city(string info_command)
{
    stringstream stream_info;
    stream_info << info_command;
    string key, city_name;
    stream_info >> key;
    getline(stream_info, city_name, '\n');
    city_name = delete_extra_spaces(city_name);
    if(city_name == EMPTY_STRING)
        throw BadRequestError();
    hotel_reservation->filter_hotels_by_city(city_name);
}

void PostCommandParser::parse_filter_by_star(string info_command)
{
    check_number_strings(STAR_FILTER_STRINGS, info_command);
    int min_star = find_key_data<int>(MINIMUM_STAR_KEY, info_command);
    int max_star = find_key_data<int>(MAXIMUM_STAR_KEY, info_command);
    hotel_reservation->filter_hotels_by_star(min_star, max_star);
}


void PostCommandParser::parse_filter_by_price(string info_command)
{
    check_number_strings(PRICE_FILTER_STRINGS, info_command);
    double min_price = find_key_data<double>(MINIMUM_PRICE_KEY, info_command);
    double max_price = find_key_data<double>(MAXIMUM_PRICE_KEY, info_command);
    hotel_reservation->filter_hotels_by_price(min_price, max_price);
}

void PostCommandParser::parse_reserve_command(string command)
{
    string info_command = get_info_command(command);
    check_number_strings(RESERVE_COMMAND_STRINGS, info_command);
    string hotel_id = find_key_data<string>(HOTEL_KEY, info_command);
    string type_rooms = find_key_data<string>(TYPE_ROOMS_KEY, info_command);
    int quantity = find_key_data<int>(QUANTITY_KEY, info_command);
    int check_in = find_key_data<int>(CHECK_IN_KEY, info_command);
    int check_out = find_key_data<int>(CHECK_OUT_KEY, info_command);
    hotel_reservation->reserve_rooms(hotel_id, type_rooms, quantity, check_in, check_out);
}

void PostCommandParser::parse_wallet_charge_command(string command)
{
    string info_command = get_info_command(command);
    check_number_strings(WALLET_CHARGE_STRINGS, info_command);
    double amount = find_key_data<double>(AMOUNT_KEY, info_command);
    hotel_reservation->charge_wallet_login_user(amount);
}

void PostCommandParser::parse_comment_command(string command)
{
    string info_command = get_info_command(command);
    check_number_strings(COMMENT_STRINGS, info_command);
    string hotel_id = find_key_data<string>(HOTEL_KEY, info_command);
    string comment = find_key_data<string>(COMMENT_KEY, info_command);
    hotel_reservation->add_comment(hotel_id, comment);
}

void PostCommandParser::parse_rating_command(string command)
{
    string info_command = get_info_command(command);
    check_number_strings(RATING_STRINGS, info_command);
    string hotel_id = find_key_data<string>(HOTEL_KEY, info_command);
    double location_rating = find_key_data<double>(LOCATION_RATING_KEY, info_command);
    double cleanliness_rating = find_key_data<double>(CLEANLINESS_RATING_KEY, info_command);
    double staff_rating = find_key_data<double>(STAFF_RATING_KEY, info_command);
    double facilities_rating = find_key_data<double>(FACILITIES_RATING_KEY, info_command);
    double value_for_money_rating = find_key_data<double>(VALUE_FOR_MONEY_RATING_KEY, info_command);
    double overall_rating = find_key_data<double>(OVERALL_RATING_KEY, info_command);
    hotel_reservation->add_new_rating(location_rating, cleanliness_rating, staff_rating, facilities_rating, value_for_money_rating, overall_rating, hotel_id);
}

void PostCommandParser::parse_filter_by_reserves(string info_command)
{
    string type = find_key_data<string>(TYPE_ROOMS_KEY, info_command);
    check_number_strings(RESERVE_FILTER_NUMBER_STRINGS, info_command);
    int quantity = find_key_data<int>(QUANTITY_KEY, info_command);
    int check_in = find_key_data<int>(CHECK_IN_KEY, info_command);
    int check_out = find_key_data<int>(CHECK_OUT_KEY, info_command);
    hotel_reservation->filter_hotels_by_rooms(type, quantity, check_in, check_out);
}

void DeleteCommandParser::parse_delete_filters(string command)
{
    hotel_reservation->delete_filters();
}

void DeleteCommandParser::parse_delete_reserves(string command)
{
    string info_command = get_info_command(command);
    int reserve_id = find_key_data<int>(ID_KEY, info_command);
    hotel_reservation->delete_reservation(reserve_id);
}

void PostCommandParser::parse_default_filter(string command)
{
    string info_command = get_info_command(command);
    check_number_strings(DEFUALT_FILTER_NUMBER_STRINGS, info_command);
    string active_state = find_key_data<string>(ACTIVE_KEY, info_command);
    hotel_reservation->change_default_price_filter(active_state);
}

void PostCommandParser::parse_sort_command(string command)
{
    string info_command = get_info_command(command);
    check_number_strings(SORT_NUMBER_STRINGS, info_command);
    string property = find_key_data<string>(PROPERTY_KEY, info_command);
    string order = find_key_data<string>(ORDER_KEY, info_command);
    if(!HotelSort::check_valid_property(property))
    {
        throw BadRequestError();
    }
    hotel_reservation->handle_sort_command(property, order);
}

void PostCommandParser::parse_manual_weight_command(string command)
{
    string info_command = get_info_command(command);
    string active = find_key_data<string>(ACTIVE_KEY, info_command);
    if(active == FALSE_DATA)
    {
        hotel_reservation->make_manual_weights_false();
        check_number_strings(MANUAL_RATING_FALSE_COMMAND, info_command);
        return;
    }
    else
        parse_true_command_manual(info_command);
}

void PostCommandParser::parse_true_command_manual(string info_command)
{
    check_number_strings(MANUAL_RATING_TRUE_COMMAND, info_command);
    double location_rating = DataBase::string_to_double(find_key_data<string>(LOCATION_RATING_KEY, info_command));
    double cleanliness_rating = DataBase::string_to_double(find_key_data<string>(CLEANLINESS_RATING_KEY, info_command));
    double staff_rating = DataBase::string_to_double(find_key_data<string>(STAFF_RATING_KEY, info_command));
    double facilities_rating = DataBase::string_to_double(find_key_data<string>(FACILITIES_RATING_KEY, info_command));
    double value_for_money_rating = DataBase::string_to_double(find_key_data<string>(VALUE_FOR_MONEY_RATING_KEY, info_command));
    hotel_reservation->make_manual_weights_true(location_rating, cleanliness_rating, staff_rating, facilities_rating, value_for_money_rating);
}
