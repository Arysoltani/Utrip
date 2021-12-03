#include "CommandHandlerInterface.hpp"

using namespace std;

CommandHandlerInterface::CommandHandlerInterface(HotelReservationInterface* input_hotel_reservation)
{
    get_command_parser = new GetCommandParser(input_hotel_reservation);
    post_command_parser = new PostCommandParser(input_hotel_reservation);
    delete_command_parser = new DeleteCommandParser(input_hotel_reservation);
    hotel_reservation = input_hotel_reservation;
}

void CommandHandlerInterface::run()
{
    string new_command;
    while(getline(cin, new_command, DELIMITER))
    {
        try
        {
            parse_command(new_command);
        }catch(exception& error_command)
        {
            cout << error_command.what();
        }
    }
}

void CommandHandlerInterface::parse_command(string command)
{
    string first_word = get_first_word(command);
    if(first_word == GET_COMMAND_KEY)
        get_command_parser->parse_command(command);
    else if(first_word == POST_COMMAND_KEY)
        post_command_parser->parse_command(command);
    else if(first_word == DELETE_COMMAND_KEY)
        delete_command_parser->parse_command(command);
    else
    {
        if(!hotel_reservation->is_user_login())
            throw PermissionDeniedError();
        else
            throw BadRequestError();
    }
}

string CommandHandlerInterface::get_first_word(string command)
{
    string answer;
    stringstream stream_line;
    stream_line << command;
    stream_line >> answer;
    return answer;
}

CommandHandlerInterface::~CommandHandlerInterface()
{
    delete get_command_parser;
    delete post_command_parser;
    delete delete_command_parser;
}
