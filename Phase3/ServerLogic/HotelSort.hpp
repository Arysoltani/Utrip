#ifndef HOTEL_SORT_HPP
#define HOTEL_SORT_HPP

#include "Hotels.hpp"
#include "Hotel.hpp"
#include<vector>
#include<algorithm>
#include<string>
#include "Rating.hpp"
#include "User.hpp"

#define CITY_PROPERTY "city"
#define NAME_PROPERTY "name"
#define ID_PROPERTY "id"
#define ASCENDING_TYPE "ascending"
#define STAR_RATING_PROPERTY "star_rating"
#define STANDARD_PRICE_PROPERTY "standard_room_price"
#define DELUXE_PRICE_PROPERTY "deluxe_room_price"
#define LUXURY_PRICE_PROPERTY "luxury_room_price"
#define PREMIUM_PRICE_PROPERTY "premium_room_price"
#define AVERAGE_PRICE_PROPERTY "average_room_price"
#define RATING_PRICE_PROPERTY "rating_personal"
#define ACTIVE_KEY_PRINT "active"
#define FALSE_KEY_PRINT "false"
#define TRUE_KEY_PRINT "true"
#define MIN_RATINGS_ESTIMATE 5
#define WARNING_NOT_ENOUGH_RATING "Insufficient Ratings"


class RatingSort
{
public:
    RatingSort();
    void reset(User* user_login);
    void make_on();
    std::vector<Hotel*> sort_by_rating(std::vector<Hotel*>hotels, bool ascending);
    static bool compare_by_rating(Hotel* hotel1, Hotel* hotel2, bool ascending, Rating weight_rating, User* input_user);
    bool is_rating_sort_on();
    void manual_weights_on(double location_rating, double cleanliness_rating, double staff_rating, double facilities_rating, double value_for_money_rating);
    void print_manual_weights();
    void manual_weights_off();
    void print_estimated_weights();
    bool can_sort();
private:
    User* user;
    Rating manual_weights;
    bool is_manual_weight_active;
    bool is_on;
};

class HotelSort
{
public:
    HotelSort();
    RatingSort* get_rating_sort();
    static bool compare_by_asscending(bool answer_for_ascending, bool ascending);
    static bool compare_by_id(Hotel* hotel1, Hotel* hotel2, bool ascending);
    static bool compare_by_city_name(Hotel* hotel1, Hotel* hotel2, bool ascending);
    static bool compare_by_standard_price(Hotel* hotel1, Hotel* hotel2, bool ascending);
    static bool compare_by_deluxe_price(Hotel* hotel1, Hotel* hotel2, bool ascending);
    static bool compare_by_luxury_price(Hotel* hotel1, Hotel* hotel2, bool ascending);
    static bool compare_by_premium_price(Hotel* hotel1, Hotel* hotel2, bool ascending);
    static bool compare_by_average_price(Hotel* hotel1, Hotel* hotel2, bool ascending);
    static bool compare_by_star_rating(Hotel* hotel1, Hotel* hotel2, bool ascending);

    static bool compare_by_name(Hotel* hotel1, Hotel* hotel2, bool ascending);

    Hotels sort_hotels(Hotels input_hotels);
    void set(std::string property, std::string order);
    static bool check_valid_property(std::string type);
    void reset(User* user_login);
    bool can_sort();

private:
    void set_order(std::string order);
    void set_property(std::string property);

    bool (*compare_sort_fucntion)(Hotel* hotel1, Hotel* hotel2, bool);
    bool is_ascending;
    RatingSort* rating_sort;
};

#endif
