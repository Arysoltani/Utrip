#include "Rating.hpp"

using namespace std;

void Rating::print()
{
    cout << LOCATION_KEY << ": " << fixed << setprecision(2) << rating_items[LOCATION_ID] << endl;
    cout << CLEANLINESS_KEY << ": " << fixed << setprecision(2) << rating_items[CLEANLINESS_ID] << endl;
    cout << STAFF_KEY << ": " << fixed << setprecision(2) << rating_items[STAFF_ID] << endl;
    cout << FACILITIES_KEY << ": " << fixed << setprecision(2) << rating_items[FACILITIES_ID] << endl;
    cout << VALUE_FOR_MONEY_KEY << ": " << fixed << setprecision(2) << rating_items[VALUE_FOR_MONEY_ID] << endl;
    cout << OVERALL_KEY << ": " << fixed << setprecision(2) << rating_items[OVERALL_ID] << endl;
}

Rating Rating::get_zero_rating()
{
    return Rating(0, 0, 0, 0, 0, 0, "");
}

Rating::Rating(double location, double cleanliness, double staff, double facilities, double value_for_money, double overall_rating, string unique_id_input)
{
    fill_vector_zero();
    rating_items[LOCATION_ID] = location;
    rating_items[STAFF_ID] = staff;
    rating_items[CLEANLINESS_ID] = cleanliness;
    rating_items[FACILITIES_ID] = facilities;
    rating_items[VALUE_FOR_MONEY_ID] = value_for_money;
    rating_items[OVERALL_ID] = overall_rating;
    unique_id = unique_id_input;
}

void Rating::fill_vector_zero()
{
    for(int i = 0; i < NUMBER_ITEMS; i++)
        rating_items.push_back(0);
}

void Rating::add_rating(Rating new_rating)
{
    for(int i = 0; i < NUMBER_ITEMS; i++)
        rating_items[i] += new_rating.get_index(i);
}

double Rating::get_index(int index)
{
    // cout << "index :" << index << endl;
    return rating_items[index];
}

Rating Rating::get_ratings_divided(double divison)
{
    Rating answer = Rating(rating_items[0] / divison, rating_items[1] / divison, rating_items[2] / divison, rating_items[3] / divison, rating_items[4] / divison, rating_items[5] / divison, "");
    return answer;
}


double Rating::calculate_fake_overall_rating(Rating weight_ratings)
{
    double sum_weights = 0;
    double sum_multiplies_weights = 0;
    for(int i = 0; i < NUMBER_ITEMS - 1; i++)
    {
        sum_multiplies_weights += weight_ratings.get_index(i) * rating_items[i];
        sum_weights += weight_ratings.get_index(i);
    }
    double answer = sum_multiplies_weights / sum_weights;
    return answer;
}

double Rating::calculate_diffrence_overall_ratings(Rating weight_ratings)
{
    double fake_overall_rating = calculate_fake_overall_rating(weight_ratings);
    double diffrence = fake_overall_rating - rating_items[OVERALL_ID];
    diffrence *= diffrence;
    return diffrence;
}

void Rating::add_value_index(int index, double value)
{
    rating_items[index] += value;
}

double Rating::calculate_epsilon_change(Rating weight_ratings, int index)
{
    Rating new_rating = weight_ratings;
    new_rating.add_value_index(index,EPSILON);
    double diffrence = calculate_diffrence_overall_ratings(new_rating) - calculate_diffrence_overall_ratings(weight_ratings);
    diffrence /= EPSILON;
    return diffrence;
}

double Rating::get_random_between(int min_random, int max_random)
{
    int random = (rand() % max_random) + min_random;
    return (double)random;
}

Rating Rating::get_random_rating()
{
    vector<double>random_numbers;
    srand(SEED_RANDOM);
    for(int i = 0; i < NUMBER_ITEMS - 1; i++)
    {
        random_numbers.push_back(get_random_between(MIN_RATING, MAX_RATING - MIN_RATING));
    }
    Rating new_rating = Rating(random_numbers[0], random_numbers[1], random_numbers[2], random_numbers[3], random_numbers[4], 0, "");
    return new_rating;
}

void Rating::make_valid()
{
    for(int i = 0; i < NUMBER_ITEMS - 1; i++)
    {
        if(rating_items[i] < MIN_RATING)
            rating_items[i] = MIN_RATING;
        if(rating_items[i] > MAX_RATING)
            rating_items[i] = MAX_RATING;
    }
}

double Rating::get_overall_rating(){return rating_items[OVERALL_ID];}

string Rating::get_hotel_id(){return unique_id;}

void Rating::print_items()
{
    cout << LOCATION_KEY << " " << fixed << setprecision(2) << rating_items[LOCATION_ID] << " ";
    cout << CLEANLINESS_KEY << " " << fixed << setprecision(2) << rating_items[CLEANLINESS_ID] << " ";
    cout << STAFF_KEY << " " << fixed << setprecision(2) << rating_items[STAFF_ID] << " ";
    cout << FACILITIES_KEY << " " << fixed << setprecision(2) << rating_items[FACILITIES_ID] << " ";
    cout << VALUE_FOR_MONEY_KEY << " " << fixed << setprecision(2) << rating_items[VALUE_FOR_MONEY_ID] << " " << endl;
}

bool Rating::is_valid_item_rating()
{
    for(int i = 0; i < NUMBER_ITEMS - 1; i++)
    {
        if(rating_items[i] < MIN_RATING || rating_items[i] > MAX_RATING)
            return false;
    }
    return true;
}
