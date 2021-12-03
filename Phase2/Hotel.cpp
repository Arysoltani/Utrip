#include "Hotel.hpp"

using namespace std;


Hotel::Hotel(HotelDatas datas)
    : standard_rooms(datas.standard_price, datas.standard_number_rooms, RoomType::Standard),
    deluxe_rooms(datas.deluxe_price, datas.deluxe_number_rooms, RoomType::Deluxe),
    luxury_rooms(datas.luxury_price, datas.luxury_number_rooms, RoomType::Luxury),
    premium_rooms(datas.premium_price, datas.premium_number_rooms, RoomType::Premium)
{
    unique_id = datas.unique_id;
    property_name = datas.property_name;
    hotel_rating = datas.hotel_rating;
    hotel_overview = datas.hotel_overview;
    property_amenities = datas.property_amenities;
    city_name = datas.city_name;
    latitude = datas.latitude;
    longitude = datas.longitude;
    image_url = datas.image_url;
    // initialize_rooms(datas);
}
/*
void Hotel::initialize_rooms(HotelDatas datas)
{
    initialize_rooms_by_type(&standard_rooms, datas.standard_price, datas.standard_number_rooms, RoomType::Standard);
    initialize_rooms_by_type(&deluxe_rooms, datas.deluxe_price, datas.deluxe_number_rooms, RoomType::Deluxe);
    initialize_rooms_by_type(&luxury_rooms, datas.luxury_price, datas.luxury_number_rooms, RoomType::Luxury);
    initialize_rooms_by_type(&premium_rooms, datas.premium_price, datas.premium_number_rooms, RoomType::Premium);
}

void Hotel::initialize_rooms_by_type(Rooms* rooms, int price, int number_rooms, RoomType rooms_types)
{
    int next_id = 1;
    for(int i = 0; i < number_rooms; i++)
    {
        Room* new_room = new Room(price, rooms_types, next_id);
        rooms->add_room(new_room);
        next_id++;
    }
}
*/
void Hotel::print_all_info()
{
    cout << unique_id << endl;
    cout << property_name << endl;
    cout << STAR_KEY_PRINT << ": " << hotel_rating << endl;
    cout << OVERVIEW_KEY_PRINT << ": " << hotel_overview << endl;
    cout << AMENITIES_KEY_PRINT << ": " << property_amenities << endl;
    cout << CITY_KEY_PRINT << ": " << city_name << endl;
    cout << LATITUDE_KEY_PRINT << ": " << fixed << setprecision(2) << latitude << endl;
    cout << LONGITUDE_KEY_PRINT << ": " << fixed << setprecision(2) << longitude << endl;
    print_hotel_rooms_info();
}

void Hotel::print_hotel_rooms_info()
{
    cout << ROOM_NUMBER_KEY_PRINT << ": " << standard_rooms.get_number_rooms() << " " << deluxe_rooms.get_number_rooms() << " ";
    cout << luxury_rooms.get_number_rooms() <<" " << premium_rooms.get_number_rooms() << endl;
    cout << ROOM_PRICE_KEY_PRINT << ": " << standard_rooms.get_price() << " " << deluxe_rooms.get_price() << " " ;
    cout << luxury_rooms.get_price() << " " << premium_rooms.get_price() << endl;
}
bool Hotel::is_equal_id(string input_id)
{
    //cout << input_id << " " << unique_id << endl;
    if(input_id == unique_id)
        return true;
    return false;
}

int Hotel::get_number_non_zero_price()
{
    int answer = (standard_rooms.get_price() != 0) ;
    answer += (deluxe_rooms.get_price() != 0);
    answer += (luxury_rooms.get_price() != 0);
    answer += (premium_rooms.get_price() != 0);
    return answer;
}

double Hotel::get_price()
{
    int number_non_zero_price = get_number_non_zero_price();
    double sum_price = standard_rooms.get_price() + deluxe_rooms.get_price() + luxury_rooms.get_price() + premium_rooms.get_price();
    if(number_non_zero_price == 0)
        return 0;
    double answer = (sum_price / (double)number_non_zero_price);
    return answer;
}

double Hotel::get_average_rooms_price()
{
    double sum_price = 0;
    int number_rooms = 0;
    sum_price = (double)standard_rooms.get_sum_price() + (double)premium_rooms.get_sum_price() + (double)luxury_rooms.get_sum_price() + (double)deluxe_rooms.get_sum_price();
    number_rooms = standard_rooms.get_number_rooms() + premium_rooms.get_number_rooms() + luxury_rooms.get_number_rooms() + deluxe_rooms.get_number_rooms();
    double answer = (double)(sum_price / (double)number_rooms);
    return answer;
}

int Hotel::get_star(){return hotel_rating;}

void Hotel::print_summary()
{
    cout << unique_id << " " << property_name << " " << hotel_rating << " " << city_name << " " << get_number_all_rooms() << " " << fixed << setprecision(2) << get_price() << " " << endl;
}

int Hotel::get_number_all_rooms()
{
    int number_rooms = standard_rooms.get_number_rooms() + luxury_rooms.get_number_rooms() + deluxe_rooms.get_number_rooms() + premium_rooms.get_number_rooms();
    return number_rooms;
}

string Hotel::get_city_name(){return city_name;}

string Hotel::get_id(){return unique_id;}

vector<Room*> Hotel::reserve_rooms(string type_rooms, int quantity, int check_in_day,int check_out_day)
{
    if(type_rooms == STANDARD_TYPE)
        return standard_rooms.reserve_rooms(quantity, check_in_day, check_out_day);
    if(type_rooms == DELUXE_TYPE)
        return deluxe_rooms.reserve_rooms(quantity, check_in_day, check_out_day);
    if(type_rooms == LUXURY_TYPE)
        return luxury_rooms.reserve_rooms(quantity, check_in_day, check_out_day);
    if(type_rooms == PREMIUM_TYPE)
        return premium_rooms.reserve_rooms(quantity, check_in_day, check_out_day);
}

void Hotel::add_comment(Comment new_comment)
{
    comments.push_back(new_comment);
}

void Hotel::print_comments()
{
    if(comments.size() == 0)
        return;
    for(int i = (int)comments.size() -1 ; i >= 0; i--)
        comments[i].print();
}

bool Hotel::does_hotel_have_rooms(string type_rooms, int quantity, int check_in, int check_out)
{
    int number_free_rooms;
    if(type_rooms == STANDARD_TYPE)
        number_free_rooms = standard_rooms.get_number_rooms_free(check_in, check_out);
    if(type_rooms == DELUXE_TYPE)
        number_free_rooms = deluxe_rooms.get_number_rooms_free(check_in, check_out);
    if(type_rooms == LUXURY_TYPE)
        number_free_rooms = luxury_rooms.get_number_rooms_free(check_in, check_out);
    if(type_rooms == PREMIUM_TYPE)
        number_free_rooms = premium_rooms.get_number_rooms_free(check_in, check_out);
    if(number_free_rooms >= quantity)
        return true;
    return false;
}

void Hotel::add_new_rating(double location, double cleaniness, double staff, double facilities, double value_for_money, double overall_rating)
{
    hotel_ratings.add_new_rating(location, cleaniness, staff, facilities, value_for_money, overall_rating, unique_id);
}

void Hotel::print_ratings()
{
    hotel_ratings.print();
}

int Hotel::get_cost(string type_rooms, int quantity)
{
    if(type_rooms == STANDARD_TYPE)
        return (standard_rooms.get_price() * quantity);
    if(type_rooms == DELUXE_TYPE)
        return (deluxe_rooms.get_price() * quantity);
    if(type_rooms == LUXURY_TYPE)
        return (luxury_rooms.get_price() * quantity);
    if(type_rooms == PREMIUM_TYPE)
        return (premium_rooms.get_price() * quantity);
}

bool Hotel::is_in_range_deviation(double deviation, double average)
{
    double diffrence = get_price() - average;
    if(diffrence < 0)
        diffrence *= (double)-1;
    if(diffrence <= (double)2 * deviation)
        return true;
    return false;
}

string Hotel::get_name(){return property_name;}

int Hotel::get_standard_price(){return standard_rooms.get_price();}
int Hotel::get_deluxe_price(){return deluxe_rooms.get_price();}
int Hotel::get_luxury_price(){return luxury_rooms.get_price();}
int Hotel::get_premium_price(){return premium_rooms.get_price();}

double Hotel::get_overall_rating_by_weights(Rating weight_rating)
{
    Rating rating_hotel = hotel_ratings.get_average();
    double answer = rating_hotel.calculate_fake_overall_rating(weight_rating);
    return answer;
}
