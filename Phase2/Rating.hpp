#ifndef RATING_HPP
#define RATING_HPP

#include<string>
#include<iomanip>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<ctime>

#define EPSILON (double)1/(double)1000
#define LOCATION_KEY "location"
#define STAFF_KEY "staff"
#define CLEANLINESS_KEY "cleanliness"
#define FACILITIES_KEY "facilities"
#define VALUE_FOR_MONEY_KEY "value for money"
#define OVERALL_KEY "overall rating"
#define LOCATION_ID 0
#define STAFF_ID 2
#define CLEANLINESS_ID 1
#define FACILITIES_ID 3
#define VALUE_FOR_MONEY_ID 4
#define OVERALL_ID 5
#define NUMBER_ITEMS 6
#define MIN_RATING 1
#define MAX_RATING 5
#define SEED_RANDOM 1000



class Rating
{
public:
    Rating(double location, double cleanliness, double staff, double facilities, double value_for_money, double overall_rating, std::string unique_id_input);
    void print();
    void print_items();
    void add_rating(Rating new_rating);
    double get_index(int index);
    Rating get_ratings_divided(double divison);
    static Rating get_zero_rating();
    static Rating get_random_rating();
    double calculate_epsilon_change(Rating weight_ratings, int index);
    void add_value_index(int index, double value);
    static double get_random_between(int min_random, int max_random);
    double calculate_fake_overall_rating(Rating weight_ratings);
    void make_valid();
    std::string get_hotel_id();
    bool is_valid_item_rating();
    double get_overall_rating();
private:
    std::vector<double>rating_items;
    std::string unique_id;
    void fill_vector_zero();
    double calculate_diffrence_overall_ratings(Rating weight_ratings);
};

#endif
