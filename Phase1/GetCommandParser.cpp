#include "GetCommandParser.hpp"

using namespace std;

GetCommandParser::GetCommandParser(HotelReservationInterface* input_hotel_reservation)
{
    hotel_reservation = input_hotel_reservation;
}

void GetCommandParser::parse_command(string command)
{
    if(!hotel_reservation->is_user_login())
        throw PermissionDeniedError();
    string type = get_word(SECOND_TYPE, command);
    if(type == HOTEL_COMMAND_KEY)
        parse_hotel_command(command);
    else if(type == RESERVE_GET_COMMAND_KEY)
        parse_reserve_command(command);
    else if(type == WALLET_GET_COMMAND_KEY)
        parse_wallet_history_command(command);
    else if(type == COMMENT_GET_COMMAND_KEY)
        parse_comment_command(command);
    else if(type == RATING_GET_COMMAND_KEY)
        parse_rating_command(command);
    else if(type == MANUAL_GET_COMMAND_KEY)
        parse_command_manual_weights();
    else if(type == ESTIMATED_GET_KEY)
        parse_command_estimated_weights();
    else
        throw NotFoundError();
}

void GetCommandParser::parse_hotel_command(string command)
{
    string info_command = get_info_command(command);
    if(does_exist_key(ID_KEY, info_command))
    {
        check_number_strings(HOTEL_ID_STRINGS, info_command);
        string id = find_key_data<string>(ID_KEY, info_command);
        hotel_reservation->print_hotel_full_info(id);
    }
    else
    {
        if(info_command != EMPTY_STRING_GET)
            throw BadRequestError();
        hotel_reservation->print_summary_hotels();
    }
}

void GetCommandParser::parse_reserve_command(string command)
{
    hotel_reservation->print_reservations();
}

void GetCommandParser::parse_wallet_history_command(string command)
{
    string info_command = get_info_command(command);
    check_number_strings(WALLET_GET_STRINGS, info_command);
    int count = find_key_data<int>(COUNT_KEY, info_command);
    hotel_reservation->print_wallet_last_history(count);
}

void GetCommandParser::parse_comment_command(string command)
{
    string info_command = get_info_command(command);
    check_number_strings(COMMENT_GET_STRINGS, info_command);
    string hotel_id = find_key_data<string>(HOTEL_GET_ID, info_command);
    hotel_reservation->print_comments_hotel(hotel_id);
}

void GetCommandParser::parse_rating_command(string command)
{
    string info_command = get_info_command(command);
    check_number_strings(RATING_GET_STRINGS, info_command);
    string hotel_id = find_key_data<string>(HOTEL_GET_ID, info_command);
    hotel_reservation->print_ratings(hotel_id);
}

void GetCommandParser::parse_command_manual_weights()
{
    hotel_reservation->print_manual_weights();
}

void GetCommandParser::parse_command_estimated_weights()
{
    hotel_reservation->print_estimated_weights();
}
