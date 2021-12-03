#include "HotelSort.hpp"

using namespace std;

HotelSort::HotelSort()
{
    is_ascending = true;
    compare_sort_fucntion = &compare_by_id;
    rating_sort = new RatingSort();
}

RatingSort::RatingSort()
: manual_weights(0, 0, 0, 0, 0, 0, "")
{
    is_manual_weight_active = false;
    is_on = false;
}

bool HotelSort::compare_by_id(Hotel* hotel1, Hotel* hotel2, bool ascending)
{
    return compare_by_asscending(hotel1->get_id() < hotel2->get_id(), ascending);
}

bool HotelSort::compare_by_city_name(Hotel* hotel1, Hotel* hotel2, bool ascending)
{
    if(hotel1->get_city_name() == hotel2->get_city_name())
        return hotel1->get_id() < hotel2->get_id();
    return compare_by_asscending(hotel1->get_city_name() < hotel2->get_city_name(), ascending);
}

bool HotelSort::compare_by_name(Hotel* hotel1, Hotel* hotel2, bool ascending)
{
    if(hotel1->get_name() == hotel2->get_name())
        return hotel1->get_id() < hotel2->get_id();
    return compare_by_asscending(hotel1->get_name() < hotel2->get_name(), ascending);
}

bool HotelSort::compare_by_star_rating(Hotel* hotel1, Hotel* hotel2, bool ascending)
{
    if(hotel1->get_star() == hotel2->get_star())
        return hotel1->get_id() < hotel2->get_id();
    return compare_by_asscending(hotel1->get_star() < hotel2->get_star(), ascending);
}


bool HotelSort::compare_by_standard_price(Hotel* hotel1, Hotel* hotel2, bool ascending)
{
    if(hotel1->get_standard_price() == hotel2->get_standard_price())
        return hotel1->get_id() < hotel2->get_id();
    return compare_by_asscending(hotel1->get_standard_price() < hotel2->get_standard_price(), ascending);
}

bool HotelSort::compare_by_deluxe_price(Hotel* hotel1, Hotel* hotel2, bool ascending)
{
    if(hotel1->get_deluxe_price() == hotel2->get_deluxe_price())
        return hotel1->get_id() < hotel2->get_id();
    return compare_by_asscending(hotel1->get_deluxe_price() < hotel2->get_deluxe_price(), ascending);
}

bool HotelSort::compare_by_luxury_price(Hotel* hotel1, Hotel* hotel2, bool ascending)
{
    if(hotel1->get_luxury_price() == hotel2->get_luxury_price())
        return hotel1->get_id() < hotel2->get_id();
    return compare_by_asscending(hotel1->get_luxury_price() < hotel2->get_luxury_price(), ascending);
}

bool HotelSort::compare_by_premium_price(Hotel* hotel1, Hotel* hotel2, bool ascending)
{
    if(hotel1->get_premium_price() == hotel2->get_premium_price())
        return hotel1->get_id() < hotel2->get_id();
    return compare_by_asscending(hotel1->get_premium_price() < hotel2->get_premium_price(), ascending);
}

bool HotelSort::compare_by_average_price(Hotel* hotel1, Hotel* hotel2, bool ascending)
{
    if(hotel1->get_price() == hotel2->get_price())
        return hotel1->get_id() < hotel2->get_id();
    return compare_by_asscending(hotel1->get_price() < hotel2->get_price(), ascending);
}

bool RatingSort::compare_by_rating(Hotel* hotel1, Hotel* hotel2, bool ascending, Rating weight_rating, User* input_user)
{
    double overall_rating1 = input_user->get_overall_rating(hotel1, weight_rating);
    double overall_rating2 = input_user->get_overall_rating(hotel2, weight_rating);
    if(overall_rating1 == overall_rating2)
        return hotel1->get_id() < hotel2->get_id();
    return HotelSort::compare_by_asscending(overall_rating1 < overall_rating2, ascending);
}

void HotelSort::reset(User* user_login)
{
    is_ascending = true;
    compare_sort_fucntion = &compare_by_id;
    rating_sort->reset(user_login);
}

bool HotelSort::compare_by_asscending(bool answer_for_ascending, bool ascending)
{
    if(ascending == true)
        return answer_for_ascending;
    return !(answer_for_ascending);
}

bool HotelSort::check_valid_property(string type)
{
    if(type == CITY_PROPERTY || type == NAME_PROPERTY || type == ID_PROPERTY || type == STAR_RATING_PROPERTY)
        return true;
    if(type == STANDARD_PRICE_PROPERTY || type == LUXURY_PRICE_PROPERTY || type == DELUXE_PRICE_PROPERTY || type == PREMIUM_PRICE_PROPERTY || type==AVERAGE_PRICE_PROPERTY || type==RATING_PRICE_PROPERTY)
        return true;
    return false;
}

Hotels HotelSort::sort_hotels(Hotels input_hotels)
{
    vector<Hotel*> hotels = input_hotels.get_hotels();
    bool (*compare_fucntion)(Hotel* hotel1, Hotel* hotel2, bool ascending) = compare_sort_fucntion;
    bool ascending = is_ascending;
    if(!rating_sort->is_rating_sort_on())
        sort(hotels.begin(), hotels.end(), [&compare_fucntion, &ascending](Hotel* hotel1, Hotel* hotel2){return (*compare_fucntion)(hotel1, hotel2, ascending);});
    else
        hotels = rating_sort->sort_by_rating(hotels, ascending);
    Hotels answer;
    for(int i = 0; i < hotels.size(); i++)
        answer.add_hotel(hotels[i]);
    return answer;
}

void HotelSort::set(string property, string order)
{
    set_order(order);
    set_property(property);
}

void HotelSort::set_order(string order)
{
    if(order == ASCENDING_TYPE)
        is_ascending = true;
    else
        is_ascending = false;
}

void HotelSort::set_property(string property)
{
    if(property == CITY_PROPERTY)
        compare_sort_fucntion = &compare_by_city_name;
    if(property == ID_PROPERTY)
        compare_sort_fucntion = &compare_by_id;
    if(property == NAME_PROPERTY)
        compare_sort_fucntion = &compare_by_name;
    if(property == STAR_RATING_PROPERTY)
        compare_sort_fucntion = &compare_by_star_rating;
    if(property == STANDARD_PRICE_PROPERTY)
        compare_sort_fucntion = &compare_by_standard_price;
    if(property == DELUXE_PRICE_PROPERTY)
        compare_sort_fucntion = &compare_by_deluxe_price;
    if(property == LUXURY_PRICE_PROPERTY)
        compare_sort_fucntion = &compare_by_luxury_price;
    if(property == PREMIUM_PRICE_PROPERTY)
        compare_sort_fucntion = &compare_by_premium_price;
    if(property == AVERAGE_PRICE_PROPERTY)
        compare_sort_fucntion = &compare_by_average_price;
    if(property == RATING_PRICE_PROPERTY)
        rating_sort->make_on();
}

void RatingSort::reset(User* user_login)
{
    user = user_login;
    is_manual_weight_active = false;
    is_on = false;
}

void RatingSort::make_on()
{
    is_on = true;
}

vector<Hotel*> RatingSort::sort_by_rating(vector<Hotel*>hotels, bool ascending)
{
    Rating weight_rating = manual_weights;
    if(!is_manual_weight_active)
        weight_rating = user->get_estimate_ratings();
    User* copy_user = user;
    sort(hotels.begin(),hotels.end(), [weight_rating, ascending, copy_user](Hotel* hotel1, Hotel* hotel2){return compare_by_rating(hotel1, hotel2, ascending, weight_rating, copy_user);});
    return hotels;
}

bool RatingSort::is_rating_sort_on()
{
    return is_on;
}

RatingSort* HotelSort::get_rating_sort(){return rating_sort;}

void RatingSort::manual_weights_on(double location_rating, double cleanliness_rating, double staff_rating, double facilities_rating, double value_for_money_rating)
{
    manual_weights = Rating(location_rating, cleanliness_rating, staff_rating, facilities_rating, value_for_money_rating, 0, "");
    if(!manual_weights.is_valid_item_rating())
        throw BadRequestError();
    is_manual_weight_active = true;
}

void RatingSort::print_manual_weights()
{
    cout << ACTIVE_KEY_PRINT << " ";
    if(!is_manual_weight_active)
    {
        cout << FALSE_KEY_PRINT << endl;
        return;
    }
    cout << TRUE_KEY_PRINT << " ";
    manual_weights.print_items();
}

void RatingSort::manual_weights_off()
{
    is_manual_weight_active = false;
}

void RatingSort::print_estimated_weights()
{
    if(user->get_number_ratings() >= MIN_RATINGS_ESTIMATE)
    {
        Rating weights = user->get_estimate_ratings();
        weights.print_items();
    }
    else
    {
        cout << WARNING_NOT_ENOUGH_RATING << endl;
    }
}

bool RatingSort::can_sort()
{
    if(!is_manual_weight_active && user->get_number_ratings() < MIN_RATINGS_ESTIMATE)
        return false;
    return true;
}

bool HotelSort::can_sort()
{
    if(rating_sort->is_rating_sort_on())
        return rating_sort->can_sort();
    return true;
}
