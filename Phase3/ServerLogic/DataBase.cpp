#include "DataBase.hpp"

using namespace std;

void DataBase::read_hotels(string file_path)
{
    CsvFile csv_file(file_path);
    vector<vector<string> >splited_lines = csv_file.get_split_lines();
    for(int i = 0; i < splited_lines.size(); i++)
    {
        add_hotel(splited_lines[i]);
    }
}

void DataBase::read_ratings(string file_path)
{
    CsvFile csv_file(file_path);
    vector<vector<string> >splited_lines = csv_file.get_split_lines();
    for(int i = 0; i < splited_lines.size(); i++)
        add_rating(splited_lines[i]);
}

void DataBase::add_hotel(vector<string> splited_hotel_data)
{
    HotelDatas datas = initialize_hotel_datas(splited_hotel_data);
    Hotel* new_hotel = new Hotel(datas);
    hotels.add_hotel(new_hotel);
}

void DataBase::add_rating(vector<string> splited_rating_data)
{
    string unique_id = splited_rating_data[INPUT_RATING_HOTEL_ID];
    Hotel* input_hotel = find_hotel(unique_id);
    double input_location = string_to_double(splited_rating_data[INPUT_LOCATION_RATING]);
    double input_cleanliness = string_to_double(splited_rating_data[INPUT_CLEANLINESS_RATING]);
    double input_staff = string_to_double(splited_rating_data[INPUT_STAFF_RATING]);
    double input_facilities = string_to_double(splited_rating_data[INPUT_FACILITIES_RATING]);
    double input_value_for_money = string_to_double(splited_rating_data[INPUT_VALUE_FOR_MONEY]);
    double input_overall_rating = string_to_double(splited_rating_data[INPUT_OVERALL_RATING]);
    input_hotel->add_new_rating(input_location, input_cleanliness, input_staff, input_facilities, input_value_for_money, input_overall_rating);
}

string DataBase::split_by_space(vector<string> splited_datas)
{
    string answer;
    for(int i = 0; i < splited_datas.size(); i++)
    {
        for(int j = 0; j < splited_datas[i].size(); j++)
            answer.push_back(splited_datas[i][j]);
        answer.push_back(' ');
    }
    return answer;
}

HotelDatas DataBase::initialize_hotel_datas(vector<string> splited_hotel_data)
{
    HotelDatas datas;
     // cout << splited_hotel_data.size() <<"b" << endl;
    datas = initialize_datas_hotel_place(splited_hotel_data, datas);
    datas = initialize_hotel_info_datas(splited_hotel_data, datas);
    datas = intialize_datas_hotel_rooms_number(splited_hotel_data, datas);
    datas = intialize_datas_hotel_rooms_price(splited_hotel_data, datas);
    return datas;
}
HotelDatas DataBase::initialize_hotel_info_datas(vector<string> splited_hotel_data, HotelDatas datas)
{
    datas.unique_id = splited_hotel_data[INPUT_NUMBER_UNIQUE_ID],datas.property_name = splited_hotel_data[INPUT_NUMBER_PROPERTY_NAME];
    datas.hotel_rating = stoi(splited_hotel_data[INPUT_NUMBER_HOTEL_RATING]),datas.hotel_overview = splited_hotel_data[INPUT_NUMBER_OVERVIEW_ID];
    datas.property_amenities = splited_hotel_data[INPUT_NUMBER_AMENITIES],datas.city_name = splited_hotel_data[INPUT_NUMBER_CITY_NAME];
    datas.image_url = splited_hotel_data[INPUT_NUMBER_IMAGE_URL];
    return datas;
}

HotelDatas DataBase::initialize_datas_hotel_place(vector<string> splited_hotel_data, HotelDatas datas)
{
    datas.latitude = string_to_double(splited_hotel_data[INPUT_NUMBER_LATITUDE]);
    datas.longitude = string_to_double(splited_hotel_data[INPUT_NUMBER_LONGITUDE]);
    return datas;
}

HotelDatas DataBase::intialize_datas_hotel_rooms_number(vector<string> splited_hotel_data, HotelDatas datas)
{
    datas.standard_number_rooms = stoi(splited_hotel_data[INPUT_NUMBER_STANDARD_NUM]);
    datas.deluxe_number_rooms = stoi(splited_hotel_data[INPUT_NUMBER_DELUXE_NUM]);
    datas.luxury_number_rooms = stoi(splited_hotel_data[INPUT_NUMBER_LUXURY_NUM]);
    datas.premium_number_rooms = stoi(splited_hotel_data[INPUT_NUMBER_PREMIUM_NUM]);
    return datas;
}

HotelDatas DataBase::intialize_datas_hotel_rooms_price(vector<string> splited_hotel_data, HotelDatas datas)
{
    datas.standard_price = stoi(splited_hotel_data[INPUT_NUMBER_STANDARD_PRICE]);
    datas.deluxe_price = stoi(splited_hotel_data[INPUT_NUMBER_DELUXE_PRICE]);
    datas.luxury_price = stoi(splited_hotel_data[INPUT_NUMBER_LUXURY_PRICE]);
    datas.premium_price = stoi(splited_hotel_data[INPUT_NUMBER_PREMIUM_PRICE]);
    return datas;
}

double DataBase::string_to_double(string input_string)
{
    stringstream stream_double_input;
    stream_double_input << input_string;
    double answer;
    stream_double_input >> answer;
    return answer;
}

Hotels DataBase::get_hotels()
{
    return hotels;
}

Hotel* DataBase::find_hotel(string id)
{
    return hotels.find_hotel(id);
}

DataBase::~DataBase()
{
    for(int i = 0; i < users.size(); i++){
        delete users[i];
    }
    hotels.delete_all_hotels();
}

bool DataBase::does_email_exist(string input_email)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i]->get_email() == input_email)
            return true;
    }
    return false;
}

bool DataBase::does_user_name_exist(string input_user_name)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i]->get_user_name() == input_user_name)
            return true;
    }
    return false;
}


void DataBase::add_user(string email, string user_name, string password)
{
    if(does_user_name_exist(user_name) || does_email_exist(email))
        throw BadRequestError();
    User* new_user = new User(email, user_name, password);
    users.push_back(new_user);
}

User* DataBase::find_user(string email, string password)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i]->get_email() == email && users[i]->get_hash_password() == User::get_hash(password))
        {
            return users[i];
        }
    }
    throw BadRequestError();
}
