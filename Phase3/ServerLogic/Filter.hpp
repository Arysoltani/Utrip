#ifndef FILTER_HPP
#define FILTER_HPP

#include "Hotels.hpp"
#include "User.hpp"

#define MIN_LIMIT_RESERVES 10

enum FilterType{CityFilterType, PriceFilterType, RoomFilterType, StarFilterType, DefaultPriceFilterType};

class Filter
{
public:
    virtual Hotels filter(Hotels input_hotels) = 0;
    virtual FilterType get_type() = 0;
private:
};



class PriceFilter : public Filter
{
public:
    PriceFilter(int input_min_price, int input_max_price);
    virtual Hotels filter(Hotels input_hotels) override;
    virtual FilterType get_type();
private:
    int min_price, max_price;
};

class StarFilter : public Filter
{
public:
    StarFilter(int input_min_star, int input_max_star);
    virtual Hotels filter(Hotels input_hotels) override;
    virtual FilterType get_type();
private:
    int min_star;
    int max_star;
};

class CityFilter : public Filter
{
public:
    CityFilter(std::string input_city_name);
    virtual Hotels filter(Hotels input_hotels) override;
    virtual FilterType get_type();
private:
    std::string city_name;
};

class RoomFilter : public Filter
{
public:
    RoomFilter(std::string input_type_rooms, int input_quantity, int input_check_in, int input_check_out);
    virtual Hotels filter(Hotels input_hotels);
    virtual FilterType get_type();
private:
    std::string type_rooms;
    int check_in;
    int check_out;
    int quantity;
};

class DefaultPriceFilter : public Filter
{
public:
    DefaultPriceFilter(User* input_login_user);
    virtual Hotels filter(Hotels input_hotels);
    virtual FilterType get_type();
private:
    User* login_user;
};

#endif
