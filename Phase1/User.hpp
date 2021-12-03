#ifndef USER_HPP
#define USER_HPP

#include<string>
#include<vector>
#include<iostream>
#include<functional>
#include "Reserve.hpp"
#include<cmath>
#include "Exceptions.hpp"
#include "Rating.hpp"
#include<algorithm>

#define FIRST_CHARACTER 'a'
#define TIMES_ESTIMATE 1000


const int HASH_MOD = 1000*1000*1000 + 9;
const int HASH_BASE = 123;

class User
{
public:
    User(std::string input_email, std::string input_user_name, std::string password);
    void print_for_check();
    void change_wallet_amount(double amount_change);
    void add_reserve(Reserve new_reserve);
    int get_next_reserve_id();
    void print_reservations();
    void delete_reservation(int id);
    void print_wallet_last_history(int count);
    std::string get_user_name();
    void increase_wallet_amount(double amount_change);
    std::string get_email();
    long int get_hash_password();
    double get_wallet_amount();
    static long int get_hash(std::string input_string);
    double calculate_reserves_average();
    double calculate_reserves_deviation();
    int get_number_reserves();
    void add_new_rating(double location, double cleaniness, double staff, double facilities, double value_for_money, double overall_rating, std::string input_hotel_id);
    Rating get_estimate_ratings();
    double get_overall_rating(Hotel* hotel_input, Rating weight_rating);
    int get_number_ratings();
private:
    double calculate_diffrence_index(Rating weight_ratings, int index);
    Rating better_estimate_rating(Rating estimate_rating);
    Rating calculate_estimate_rating();
    int get_number_reserve_rooms();
    std::string email;
    std::string user_name;
    long int hash_password;
    std::vector<double> wallet_history;
    double amount_money;
    int next_id;
    std::vector<Reserve>reserves;
    void delete_reserve_index(int index);
    std::vector<Rating> user_ratings;
    Rating estimate_ratings;
    bool has_estimate_ratings;
};

#endif
