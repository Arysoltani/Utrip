#include "../server/server.hpp"
#include "../ServerLogic/HotelReservationInterface.hpp"
#include "../ServerLogic/DataBase.hpp"
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include "UsersOnSite.hpp"
#include "handlers.hpp"

#define PART_AMENITIES '|'
#define ID_QUERY_KEY "id"
#define SECTION_IMAGE_STYLE "<section style = 'float:left; width:40%;'>"
#define IMAGE_STYLE_HOTEL "<img  style = 'width:100% ;' src = '"
#define STYLE_DIV_HOTEL_INFO  "<div style = 'float:left ;width: 60%;'>"
#define LIST_AMENTIES_STYLE  "<ul style = 'list-style-type:circle; background-color:#F0F8F0; width:80%'>"
#define AMENTIES_NAME "Amenties : "
#define OVERVIEW_NAME "Overview : "
#define P_STYLE_OVERVIEW "<p style = 'background-color:#F0F8F0; padding:20px'>"
#define CITY_NAME "City : "
#define HOTEL_RATING_NAME "Hotel Rating : "
#define TABLE_PRICES_STYLE "<table style = 'background-color: #F0F8F0; padding: 20px; '>"
#define TABLE_HEADER_TYPE_PRICE "<th>Type Price</th>"
#define TABLE_HEADER_PRICE "<th>Price</th>"
#define STANDARD_PRICE_NAME "Standard Price"
#define DELUXE_PRICE_NAME "Deluxe Price"
#define LUXURY_PRICE_NAME "Luxury Price"
#define PREMIUM_PRICE_NAME "Premium Price"


class HotelPageHandler : public RequestHandler
{
public:
    Response* callback(Request* request);
    HotelPageHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site);
private:
    DataBase* all_datas;
    UsersOnSite* users_on_site;
    HotelReservationInterface* hotel_reservation;
    std::string write_parts_after_name(Hotel* needed_hotel);
    std::string write_part_info_hotel(Hotel* needed_hotel);
    std::vector<std::string> seperate_amenities(std::string amenitites);
    std::string write_part_amenities(Hotel* needed_hotel);
    std::string write_part_overview(Hotel* needed_hotel);
    std::string write_info(Hotel* needed_hotel);
    std::string write_prices(Hotel* needed_hotel);
    std::string add_header_price(std::string name, std::string value);
};
