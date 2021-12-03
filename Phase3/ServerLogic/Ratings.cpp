#include "Ratings.hpp"

using namespace std;

void Ratings::add_new_rating(double location, double cleanliness, double staff, double facilities, double value_for_money, double overall_rating, string id_hotel)
{
    Rating new_rating(location, cleanliness, staff, facilities, value_for_money, overall_rating, id_hotel);
    add_rating(new_rating);
}

void Ratings::print()
{
    if(ratings.size() == 0)
    {
        cout << NO_RATING << endl;
        return;
    }
    Rating sum_all_ratings = calculate_sum_rating();
    Rating average_ratings = sum_all_ratings.get_ratings_divided((double)ratings.size());
    average_ratings.print();
}

Rating Ratings::calculate_sum_rating()
{
    Rating sum_ratings = Rating::get_zero_rating();
    for(int i = 0; i < ratings.size(); i++)
    {
        sum_ratings.add_rating(ratings[i]);
    }
    return sum_ratings;
}

void Ratings::add_rating(Rating new_rating)
{
    ratings.push_back(new_rating);
}

Rating Ratings::get_average()
{
    return ratings[0];
}
