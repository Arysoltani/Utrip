#ifndef HOTELS_HPP
#define HOTELS_HPP

#include "Hotel.hpp"
#include<vector>
#include "Exceptions.hpp"
#include<algorithm>

#define EMPTY_HOTELS "Empty"

class Hotels
{
public:
    void add_hotel(Hotel* new_hotel);
    void print_summary_hotels();
    int get_size();
    Hotels get_hotels_with_price_range(int min_price, int max_price);
    Hotels get_hotels_star_range(int min_star, int max_star);
    Hotels get_hotels_with_city_name(std::string city_name);
    Hotel* find_hotel(std::string unique_id);
    void delete_all_hotels();
    Hotels get_hotels_have_rooms(std::string type_rooms, int quantity, int check_in_day, int check_out_day);
    Hotels get_hotels_may_user_interest(double deviation, double average_price);
    std::vector<Hotel*> get_hotels();
private:
    std::vector<Hotel*>hotels;
    int get_number_rooms_non_zero();
    static bool compare_hotels_by_id(Hotel* hotel1, Hotel* hotel2);
};

#endif
