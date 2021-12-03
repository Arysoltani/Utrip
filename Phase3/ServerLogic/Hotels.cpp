#include "Hotels.hpp"

using namespace std;

void Hotels::add_hotel(Hotel* new_hotel)
{
    hotels.push_back(new_hotel);
}

bool Hotels::compare_hotels_by_id(Hotel* hotel1, Hotel* hotel2)
{
    if(hotel1->get_id() < hotel2->get_id())
        return true;
    return false;
}

void Hotels::print_summary_hotels()
{
    if(hotels.size() == 0)
    {
        cout << EMPTY_HOTELS << endl;
        return;
    }
    for(int i = 0; i < hotels.size(); i++)
        hotels[i]->print_summary();
}

int Hotels::get_size()
{
    return hotels.size();
}

Hotel* Hotels::find_hotel(string unique_id)
{
    //cout << "***********" <<  " " << hotels.size() << endl;
    for(int i = 0; i < hotels.size(); i++)
    {
        if(hotels[i]->is_equal_id(unique_id))
            return hotels[i];
    }
    throw NotFoundError();
}

Hotels Hotels::get_hotels_with_price_range(int min_price, int max_price)
{
    Hotels answer;
    for(int i = 0; i < hotels.size(); i++)
    {
        double price = hotels[i]->get_price();
        if((price >= (double)min_price) && (price <= (double)max_price)){
            answer.add_hotel(hotels[i]);
        }
    }
    return answer;
}

Hotels Hotels::get_hotels_star_range(int min_star, int max_star)
{
    Hotels answer;
    for(int i = 0; i < hotels.size(); i++)
    {
        int star_hotel = hotels[i]->get_star();
        if(star_hotel >= min_star && star_hotel <= max_star)
            answer.add_hotel(hotels[i]);
    }
    return answer;
}

Hotels Hotels::get_hotels_with_city_name(string city_name)
{
    Hotels answer;
    for(int i = 0; i < hotels.size(); i++)
    {
        string hotel_city_name = hotels[i]->get_city_name();
        if(hotel_city_name == city_name)
            answer.add_hotel(hotels[i]);
    }
    return answer;
}

void Hotels::delete_all_hotels()
{
    for(int i = 0; i < hotels.size(); i++){
        delete hotels[i];
    }
}

Hotels Hotels::get_hotels_have_rooms(string type_rooms, int quantity, int check_in_day, int check_out_day)
{
    Hotels answer;
    for(int i = 0; i < hotels.size(); i++)
    {
        if(hotels[i]->does_hotel_have_rooms(type_rooms, quantity, check_in_day, check_out_day))
            answer.add_hotel(hotels[i]);
    }
    return answer;
}

Hotels Hotels::get_hotels_may_user_interest(double deviation, double average_price)
{
    Hotels answer;
    for(int i = 0; i < hotels.size(); i++)
    {
        if(hotels[i]->is_in_range_deviation(deviation, average_price))
            answer.add_hotel(hotels[i]);
    }
    return answer;
}

vector<Hotel*> Hotels::get_hotels(){return hotels;}
