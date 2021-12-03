#include "CommandParser.hpp"

using namespace std;

string CommandParser::get_word(int number,string input_string)
{
    stringstream stream_line;
    stream_line << input_string;
    string answer;
    for(int i = 0; i < number; i++)
    {
        stream_line >> answer;
    }
    return answer;
}

string CommandParser::get_info_command(string command)
{
    for(int i = 0; i < command.size(); i++)
    {
        if(command[i] == END_COMMAND_TYPES)
        {
            return command.substr(i+1, command.size() - i - 1);
        }
    }
    return "";
}

bool CommandParser::does_exist_key(string key, string info_command)
{
    stringstream stream_line;
    stream_line << info_command;
    while(!(stream_line.eof()))
    {
        string key_data,data;
        stream_line >> key_data >> data;
        if(key_data == key)
            return true;
    }
    return false;
}

string CommandParser::delete_extra_spaces(string input_string)
{
    while(input_string.back() == ' ')
        input_string.pop_back();
    string answer;
    bool flag_seen_non_space = false;
    for(int i = 0; i < input_string.size(); i++)
    {
        if(input_string[i] != ' ')
            flag_seen_non_space = true;
        if(flag_seen_non_space == true)
            answer.push_back(input_string[i]);
    }
    return answer;
}

void CommandParser::check_number_strings(int number_must_be, string info_command)
{
    int count = 0;
    stringstream stream_line;
    stream_line << info_command;
    while(!(stream_line.eof()))
    {
        string temp;
        stream_line >> temp;
        count++;
    }
    if(count < number_must_be)
        throw BadRequestError();
}
