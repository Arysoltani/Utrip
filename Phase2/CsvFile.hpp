#ifndef CSV_FILE_HPP
#define CSV_FILE_HPP

#define DELIMITER '\n'
#define SEMICOLON ','

#include<string>
#include<vector>
#include<iostream>
#include<fstream>

class CsvFile
{
public:
    CsvFile(std::string file_path);
    std::vector<std::vector<std::string> > get_split_lines();
private:
    int find_end_new_string(std::string input_string, int begin);
    std::vector<std::string> split_line(std::string input_string);
    void read_useless_line();
    std::ifstream csv_file_stream;
};

#endif
