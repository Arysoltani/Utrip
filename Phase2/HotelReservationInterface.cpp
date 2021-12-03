#include "HotelReservationInterface.hpp"

using namespace std;

HotelReservationInterface::HotelReservationInterface(DataBase* input_all_datas)
{
    all_datas = input_all_datas;
    login_user = NULL;
    page_state = LogoutState;
    default_price_filter = true;
    hotel_sort = new HotelSort();
}

Hotels HotelReservationInterface::sort_hotels(Hotels input_hotels)
{
    Hotels sorted_hotels = hotel_sort->sort_hotels(input_hotels);
    return sorted_hotels;
}

void HotelReservationInterface::print_summary_hotels()
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    if(!hotel_sort->can_sort())
    {
        cout << WARNING_NOT_ENOUGH_RATING << endl;
        return;
    }
    Hotels filter_hotels = get_filter_hotels();
    if(!has_filter(FilterType::PriceFilterType) && default_price_filter == true && login_user->get_number_reserves() >= MIN_RESERVES)
    {
        cout << WARNING_DEFAULT_PRICE_FILTER << endl;
        DefaultPriceFilter* default_filter = new DefaultPriceFilter(login_user);
        filter_hotels = default_filter->filter(filter_hotels);
        delete default_filter;
    }
    filter_hotels = sort_hotels(filter_hotels);
    filter_hotels.print_summary_hotels();
}

bool HotelReservationInterface::has_filter(FilterType filter_type)
{
    for(int i = 0; i < filters.size(); i++)
    {
        if(filters[i]->get_type() == filter_type)
            return true;
    }
    return false;
}

void HotelReservationInterface::print_hotel_full_info(string id)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    Hotel* wanted_hotel = all_datas->find_hotel(id);
    wanted_hotel->print_all_info();
}

bool HotelReservationInterface::is_valid_range_price(double min_price, double max_price)
{
    if(min_price < 0 || max_price < 0)
        return false;
    if(min_price > max_price)
        return false;
    return true;
}

void HotelReservationInterface::filter_hotels_by_price(double min_price, double max_price)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    if(!is_valid_range_price(min_price, max_price))
        throw BadRequestError();
    Filter* price_filter = new PriceFilter(min_price, max_price);
    add_filter(price_filter);
    cout << SUCESSFUL_COMMAND << endl;
}

bool HotelReservationInterface::is_valid_range_star(int min_star, int max_star)
{
    if(min_star > max_star)
        return false;
    if(min_star < 1 || min_star > 5)
        return false;
    if(max_star < 1 || max_star > 5)
        return false;
    return true;
}
void HotelReservationInterface::filter_hotels_by_star(int min_star, int max_star)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    if(!is_valid_range_star(min_star, max_star))
        throw BadRequestError();
    Filter* star_filter = new StarFilter(min_star, max_star);
    add_filter(star_filter);
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::filter_hotels_by_city(string city_name)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    Filter* city_filter = new CityFilter(city_name);
    add_filter(city_filter);
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::signup_user(string email, string user_name, string password)
{
    if(page_state != LogoutState)
        throw PermissionDeniedError();
    all_datas->add_user(email, user_name, password);
    login_input_user(email, password);
}

void HotelReservationInterface::charge_wallet_login_user(double amount)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    login_user->increase_wallet_amount(amount);
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::delete_filters()
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    delete_all_filters();
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::check_user_have_enough_money(Hotel* input_hotel, int quantity, string type_rooms, int check_in, int check_out)
{
    int total_cost = input_hotel->get_cost(type_rooms, quantity) * (check_out - check_in + 1);
    if(total_cost > login_user->get_wallet_amount())
        throw NotEnoughCreditError();
}

void HotelReservationInterface::check_hotel_have_enough_room(Hotel* wanted_hotel,int quantity,string type_rooms,int check_in_day,int check_out_day)
{
    if(!wanted_hotel->does_hotel_have_rooms(type_rooms, quantity, check_in_day, check_out_day))
        throw NotEnoughRoomError();
}
void HotelReservationInterface::reserve_rooms(std::string hotel_id, string type_rooms, int quantity, int check_in_day, int check_out_day)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    Hotel* wanted_hotel = all_datas->find_hotel(hotel_id);
    check_hotel_have_enough_room(wanted_hotel, quantity, type_rooms, check_in_day, check_out_day);
    check_user_have_enough_money(wanted_hotel, quantity, type_rooms, check_in_day, check_out_day);
    vector<Room*> reserved_rooms = wanted_hotel->reserve_rooms(type_rooms, quantity, check_in_day, check_out_day);
    int next_reserve_id = login_user->get_next_reserve_id();
    Reserve new_reserve(wanted_hotel, reserved_rooms, check_in_day, check_out_day, type_rooms, next_reserve_id);
    new_reserve.print_rooms_names();
    login_user->add_reserve(new_reserve);
}

void HotelReservationInterface::print_reservations()
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    login_user->print_reservations();
}

void HotelReservationInterface::delete_reservation(int id)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    login_user->delete_reservation(id);
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::print_wallet_last_history(int count)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    login_user->print_wallet_last_history(count);
}

void HotelReservationInterface::add_comment(string id_hotel, string new_comment)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    Hotel* wanted_hotel = all_datas->find_hotel(id_hotel);
    Comment new_coment(login_user->get_user_name(), new_comment);
    wanted_hotel->add_comment(new_coment);
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::print_comments_hotel(string id_hotel)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    Hotel* wanted_hotel = all_datas->find_hotel(id_hotel);
    wanted_hotel->print_comments();
}

void HotelReservationInterface::filter_hotels_by_rooms(string type_rooms, int quantity, int check_in, int check_out)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    Filter* room_filter = new RoomFilter(type_rooms, quantity, check_in, check_out);
    add_filter(room_filter);
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::add_new_rating(double location, double cleaniness, double staff, double facilities, double value_for_money, double overall_rating, string id_hotel)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    Hotel* wanted_hotel = all_datas->find_hotel(id_hotel);
    wanted_hotel->add_new_rating(location, cleaniness, staff, facilities, value_for_money, overall_rating);
    login_user->add_new_rating(location, cleaniness, staff, facilities, value_for_money, overall_rating, wanted_hotel->get_id());
    //Rating weight_ratings = login_user->get_estimate_ratings();
    //weight_ratings.print();
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::print_ratings(string id_hotel)
{
    if(page_state != LoginState)
         throw PermissionDeniedError();
    Hotel* wanted_hotel = all_datas->find_hotel(id_hotel);
    wanted_hotel->print_ratings();
}

HotelReservationInterface::~HotelReservationInterface()
{
    delete_all_filters();
    delete hotel_sort;
}

void HotelReservationInterface::login_input_user(string email, string password)
{
    if(page_state != LogoutState)
        throw PermissionDeniedError();
    login_user = all_datas->find_user(email, password);
    page_state = LoginState;
    default_price_filter = true;
    hotel_sort->reset(login_user);
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::logout_user()
{
    if(page_state != LoginState)
        throw PermissionDeniedError();
    delete_all_filters();
    page_state = LogoutState;
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::delete_all_filters()
{
    for(int i = 0; i < filters.size(); i++)
        delete filters[i];
    filters.clear();
}

void HotelReservationInterface::add_filter(Filter* new_filter)
{
    for(int i = 0; i < filters.size(); i++)
    {
        if(filters[i]->get_type() == new_filter->get_type())
        {
            delete filters[i];
            filters[i] = new_filter;
            return;
        }
    }
    filters.push_back(new_filter);
}

Hotels HotelReservationInterface::get_filter_hotels()
{
    Hotels all_hotels = all_datas->get_hotels();
    Hotels filter_hotels = all_hotels;
    for(int i = 0; i < filters.size(); i++)
        filter_hotels = filters[i]->filter(filter_hotels);
    return filter_hotels;
}

bool HotelReservationInterface::is_user_login()
{
    if(page_state == LoginState)
        return true;
    return false;
}

void HotelReservationInterface::change_default_price_filter(string type_change)
{
    if(page_state != LoginState)
        throw PermissionDeniedError();
    if(type_change == TRUE_INFO)
        default_price_filter = true;
    else if(type_change == FALSE_INFO)
        default_price_filter = false;
    else
        throw BadRequestError();
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::handle_sort_command(string property, string order)
{
    if(page_state != LoginState)
        throw PermissionDeniedError();
    hotel_sort->set(property, order);
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::make_manual_weights_true(double location_rating, double cleanliness_rating,double staff_rating,double facilities_rating,double value_for_money_rating)
{
    if(page_state != LoginState)
        throw PermissionDeniedError();
    RatingSort* rating_sort = hotel_sort->get_rating_sort();
    rating_sort->manual_weights_on(location_rating, cleanliness_rating, staff_rating, facilities_rating, value_for_money_rating);
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::print_manual_weights()
{
    if(page_state != LoginState)
        throw PermissionDeniedError();
    RatingSort* rating_sort = hotel_sort->get_rating_sort();
    rating_sort->print_manual_weights();
}

void HotelReservationInterface::make_manual_weights_false()
{
    if(page_state != LoginState)
        throw PermissionDeniedError();
    RatingSort* rating_sort = hotel_sort->get_rating_sort();
    rating_sort->manual_weights_off();
    cout << SUCESSFUL_COMMAND << endl;
}

void HotelReservationInterface::print_estimated_weights()
{
    if(page_state != LoginState)
        throw PermissionDeniedError();
    RatingSort* rating_sort = hotel_sort->get_rating_sort();
    rating_sort->print_estimated_weights();
}
