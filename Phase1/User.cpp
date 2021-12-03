#include "User.hpp"

using namespace std;

User::User(string input_email, string input_user_name, string password)
    :estimate_ratings(0,0,0,0,0,0,"")
{
    user_name = input_user_name;
    email = input_email;
    hash_password = get_hash(password);
    amount_money = 0;
    wallet_history.push_back(amount_money);
    next_id = 1;
    has_estimate_ratings = false;
}

void User::print_for_check()
{
    cout <<"email:" << email << " user_name:"  << user_name << " hash_password:" << hash_password << endl;
    for(int i = 0; i < wallet_history.size(); i++)
    {
        cout << wallet_history[i] << endl;
    }
}

void User::increase_wallet_amount(double amount_change)
{
    if(amount_change <= 0)
        throw BadRequestError();
    amount_money += amount_change;
    wallet_history.push_back(llround(amount_money));
}
void User::change_wallet_amount(double amount_change)
{
    amount_money += amount_change;
    wallet_history.push_back(llround(amount_money));
}

void User::add_reserve(Reserve new_reserve)
{
    reserves.push_back(new_reserve);
    change_wallet_amount(-1 * (new_reserve.get_cost()));
}

int User::get_next_reserve_id()
{
    return next_id++;
}

void User::print_reservations()
{
    for(int i = (int)reserves.size() - 1; i >= 0; i--)
    {
        reserves[i].print_info();
    }
}

void User::delete_reservation(int id)
{
    for(int i = 0; i < reserves.size(); i++)
    {
        if(reserves[i].get_id() == id)
        {
            delete_reserve_index(i);
            return;
        }
    }
    throw NotFoundError();
}

void User::delete_reserve_index(int index)
{
    int amount = reserves[index].get_cost();
    double return_amount = (double)amount / (double)2;
    change_wallet_amount(return_amount);
    reserves[index].cancel_reserved_rooms();
    for(int i = index + 1; i < reserves.size(); i++)
    {
        reserves[i - 1] = reserves[i];
    }
    reserves.pop_back();
}


void User::print_wallet_last_history(int count)
{
    int start = (int)wallet_history.size() - 1;
    int end;
    if(count <= wallet_history.size())
        end = (int)wallet_history.size() - count;
    else
        end = 0;
    for(int i = start; i >= end; i--){
        cout << (int)wallet_history[i] << endl;
    }
}

string User::get_user_name(){return user_name;}
string User::get_email(){return email;}
long int User::get_hash_password(){return hash_password;}

double User::get_wallet_amount(){return amount_money;}

long int User::get_hash(string input_string)
{
    long int hash_input = 0;
    for(int i = 0; i < input_string.size(); i++)
    {
        hash_input *= HASH_BASE;
        hash_input %= HASH_MOD;
        hash_input += (int)(input_string[i] + 1);
        hash_input %= HASH_MOD;
    }
    return hash_input;
}

int User::get_number_reserve_rooms()
{
    int number_reserve_rooms = 0;
    for(int i = 0; i < reserves.size(); i++)
    {
        number_reserve_rooms += reserves[i].get_number_rooms();
    }
    return number_reserve_rooms;
}

double User::calculate_reserves_average()
{
    double sum = 0;
    int number_rooms = get_number_reserve_rooms();
    for(int i = 0; i < reserves.size(); i++)
    {
        sum += reserves[i].get_rooms_cost_one_day();
    }
    double average = (double)(sum / (double)number_rooms);
    return average;
}

double User::calculate_reserves_deviation()
{
    double average = calculate_reserves_average();
    double sum_square = 0;
    for(int i = 0; i < reserves.size(); i++)
    {
        sum_square += reserves[i].get_square_sum(average);
    }
    int number_rooms = get_number_reserve_rooms();
    double square_answer = (double)(sum_square / (double)(number_rooms - 1));
    double answer = sqrt(square_answer);
    return answer;
}

int User::get_number_reserves()
{
    return reserves.size();
}

void User::add_new_rating(double location, double cleanliness, double staff, double facilities, double value_for_money, double overall_rating, string input_hotel_id)
{
    Rating new_rating(location, cleanliness, staff, facilities, value_for_money, overall_rating, input_hotel_id);
    auto iterator_rate = find_if(user_ratings.begin(), user_ratings.end(), [input_hotel_id](Rating input_rating){return input_hotel_id == input_rating.get_hotel_id();});
    if(iterator_rate == user_ratings.end())
        user_ratings.push_back(new_rating);
    else
        (*iterator_rate) = new_rating;
    has_estimate_ratings = false;
}

Rating User::get_estimate_ratings()
{
    if(has_estimate_ratings)
        return estimate_ratings;
    estimate_ratings = calculate_estimate_rating();
    return estimate_ratings;
}

double User::calculate_diffrence_index(Rating weight_ratings, int index)
{
    double sum_diffrence = 0;
    for(int i = 0;  i < user_ratings.size(); i++)
    {
        double diffrence = user_ratings[i].calculate_epsilon_change(weight_ratings, index);
        sum_diffrence += diffrence;
    }
    return (double)-1 * sum_diffrence;
}

int User::get_number_ratings(){return user_ratings.size();}

Rating User::better_estimate_rating(Rating estimate_rating)
{
    Rating diffrence_rating = Rating::get_zero_rating();
    for(int i = 0; i < NUMBER_ITEMS - 1; i++)
    {
        diffrence_rating.add_value_index(i, calculate_diffrence_index(estimate_rating, i));
    }
    estimate_rating.add_rating(diffrence_rating);
    return estimate_rating;
}

Rating User::calculate_estimate_rating()
{
    Rating estimate_rating = Rating::get_random_rating();
    for(int i = 1; i <= TIMES_ESTIMATE; i++)
    {
        estimate_rating = better_estimate_rating(estimate_rating);
        estimate_rating.make_valid();
    }
    return estimate_rating;
}

double User::get_overall_rating(Hotel* hotel_input, Rating weight_rating)
{
    auto iterator_rate = find_if(user_ratings.begin(), user_ratings.end(), [hotel_input](Rating input_rating){return (hotel_input->get_id() == input_rating.get_hotel_id());});
    if(iterator_rate == user_ratings.end())
    {
        return hotel_input->get_overall_rating_by_weights(weight_rating);
    }
    else
    {
        return (*iterator_rate).get_overall_rating();
    }
}
