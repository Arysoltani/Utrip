#include "Filter.hpp"

using namespace std;



PriceFilter::PriceFilter(int input_min_price, int input_max_price)
{
    min_price = input_min_price;
    max_price = input_max_price;
}


StarFilter::StarFilter(int input_min_star, int input_max_star)
{
    min_star = input_min_star;
    max_star = input_max_star;
}

CityFilter::CityFilter(string input_city_name)
{
    city_name = input_city_name;
}

Hotels PriceFilter::filter(Hotels input_hotels)
{
    Hotels output_hotel = input_hotels.get_hotels_with_price_range(min_price, max_price);
    return output_hotel;
}

Hotels StarFilter::filter(Hotels input_hotels)
{
    Hotels output_hotels = input_hotels.get_hotels_star_range(min_star, max_star);
    return output_hotels;
}

Hotels CityFilter::filter(Hotels input_hotels)
{
    Hotels output_hotels = input_hotels.get_hotels_with_city_name(city_name);
    return output_hotels;
}


RoomFilter::RoomFilter(string input_type_rooms, int input_quantity, int input_check_in, int input_check_out)
{
    type_rooms = input_type_rooms;
    quantity = input_quantity;
    check_in = input_check_in;
    check_out = input_check_out;
}

Hotels RoomFilter::filter(Hotels input_hotels)
{
    Hotels output_hotels = input_hotels.get_hotels_have_rooms(type_rooms, quantity, check_in, check_out);
    return output_hotels;
}

FilterType RoomFilter::get_type(){return RoomFilterType;}
FilterType StarFilter::get_type(){return StarFilterType;}
FilterType PriceFilter::get_type(){return PriceFilterType;}
FilterType CityFilter::get_type(){return CityFilterType;}
FilterType DefaultPriceFilter::get_type(){return DefaultPriceFilterType;}


Hotels DefaultPriceFilter::filter(Hotels input_hotels)
{
    double deviation = login_user->calculate_reserves_deviation();
    double average_price_reserves = login_user->calculate_reserves_average();
    Hotels output_hotels = input_hotels;
    if(login_user->get_number_reserves() < MIN_LIMIT_RESERVES)
        return output_hotels;
    output_hotels = input_hotels.get_hotels_may_user_interest(deviation, average_price_reserves);
    return output_hotels;
}

DefaultPriceFilter::DefaultPriceFilter(User* input_login_user)
{
    login_user = input_login_user;
}
