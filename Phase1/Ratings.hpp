#ifndef RATINGS_HPP
#define RATINGS_HPP

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include "Rating.hpp"

#define NO_RATING "No Rating"

class Ratings
{
public:
    void add_new_rating(double location, double cleaniness, double staff, double facilities, double value_for_money, double overall_rating, std::string rated_user);
    void print();
    Rating get_average();
private:
    std::vector<Rating>ratings;
    Rating calculate_sum_rating();
    void add_rating(Rating new_rating);
};

#endif
