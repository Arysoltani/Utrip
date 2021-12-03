#include "CsvFile.hpp"

using namespace std;

CsvFile::CsvFile(string file_path)
    : csv_file_stream(file_path){}

vector<vector<string> > CsvFile::get_split_lines()
{
    read_useless_line();
    string new_line;
    vector< vector<string> >splited_lines;
    while(getline(csv_file_stream, new_line, DELIMITER))
    {
        splited_lines.push_back(split_line(new_line));
    }
    return splited_lines;
}

vector<string> CsvFile::split_line(string input_string)
{
    int begin = 0;
    vector<string>splited_line;
    while(begin < input_string.size())
    {
        int end = find_end_new_string(input_string, begin);
        splited_line.push_back(input_string.substr(begin, end - begin + 1));
        begin = end + 2;
    }
    return splited_line;
}

int CsvFile::find_end_new_string(string input_string, int begin)
{
    int end_string = input_string.find(SEMICOLON, begin);
    if(end_string == string::npos)
    {
        end_string = input_string.size();
    }
    end_string -= 1;
    return end_string;
}

void CsvFile::read_useless_line()
{
    string useless_line;
    getline(csv_file_stream, useless_line, DELIMITER);
}
