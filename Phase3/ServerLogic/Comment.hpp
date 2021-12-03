#ifndef COMMENT_HPP
#define COMMENT_HPP

#include<string>
#include<iostream>

class Comment
{
public:
    Comment(std::string input_user, std::string input_comment);
    void print();
private:
    std::string user_name;
    std::string comment;
};

#endif
