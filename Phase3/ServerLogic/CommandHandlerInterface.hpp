#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

#include<string>
#include "GetCommandParser.hpp"
#include "HotelReservationInterface.hpp"
#include "PostCommandParser.hpp"
#include<exception>
#include "Exceptions.hpp"

#define DELIMITER '\n'
#define GET_COMMAND_KEY "GET"
#define POST_COMMAND_KEY "POST"
#define DELETE_COMMAND_KEY "DELETE"

class CommandHandlerInterface
{
public:
    CommandHandlerInterface(HotelReservationInterface* hotel_reservation);
    ~CommandHandlerInterface();
    void run();
private:
    GetCommandParser* get_command_parser;
    PostCommandParser* post_command_parser;
    DeleteCommandParser* delete_command_parser;
    HotelReservationInterface* hotel_reservation;
    void parse_command(std::string command);
    std::string get_first_word(std::string command);
};

#endif
