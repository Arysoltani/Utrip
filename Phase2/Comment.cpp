#include "Comment.hpp"

using namespace std;

Comment::Comment(std::string input_user_name, string input_comment){user_name = input_user_name;comment = input_comment;}

void Comment::print()
{
    cout << user_name << ": " << comment << endl;
}
