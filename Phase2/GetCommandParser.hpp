#ifndef GET_COMMAND_PARSER_HPP
#define GET_COMMAND_PARSER_HPP

#include "HotelReservationInterface.hpp"
#include "CommandParser.hpp"
#include<string>
#include "Exceptions.hpp"

#define SECOND_TYPE 2
#define ID_KEY "id"
#define HOTEL_COMMAND_KEY "hotels"
#define RESERVE_GET_COMMAND_KEY "reserves"
#define COUNT_KEY "count"
#define WALLET_GET_COMMAND_KEY "wallet"
#define HOTEL_GET_ID "hotel"
#define COMMENT_GET_COMMAND_KEY "comments"
#define RATING_GET_COMMAND_KEY "ratings"
#define WALLET_GET_STRINGS 2
#define RATING_GET_STRINGS 2
#define COMMENT_GET_STRINGS 2
#define HOTEL_ID_STRINGS 2
#define EMPTY_STRING_GET ""
#define MANUAL_GET_COMMAND_KEY "manual_weights"
#define ESTIMATED_GET_KEY "estimated_weights"

class GetCommandParser : public CommandParser
{
public:
    GetCommandParser(HotelReservationInterface* input_hotel_reservation);
    void parse_command(std::string command);
private:
    HotelReservationInterface* hotel_reservation;
    void parse_hotel_command(std::string command);
    void parse_reserve_command(std::string command);
    void parse_wallet_history_command(std::string command);
    void parse_comment_command(std::string command);
    void parse_rating_command(std::string command);
    void parse_command_manual_weights();
    void parse_command_estimated_weights();
};

#endif
