#ifndef COMMAND_PARSE_HPP
#define COMMAND_PARSE_HPP

#include "HotelReservationInterface.hpp"
#include<string>
#include<sstream>
#include<iostream>

#define END_COMMAND_TYPES '?'

class CommandParser
{
public:
protected:
    std::string get_info_command(std::string command);
    std::string get_word(int number,std::string input_string);
    template<typename InputType> static InputType find_key_data(std::string key, std::string command_info);
    bool does_exist_key(std::string key, std::string info_command);
    HotelReservationInterface* hotel_reservation;
    std::string delete_extra_spaces(std::string input_string);
    void check_number_strings(int number_must_be, std::string info_command);
};

template<typename InputType>
InputType CommandParser::find_key_data(std::string input_key, std::string command_info)
{
    std::stringstream stream_info;
    std::string temp_data;
    stream_info << command_info;
    while(!(stream_info.eof()))
    {
        std::string key;
        InputType data;
        stream_info >> key;
        if(key == input_key)
        {
            stream_info >> data;
            return data;
        }
        else
        {
            stream_info >> temp_data;
        }
    }
    throw BadRequestError();
}

#endif
