#ifndef HANDLERS_HPP
#define HANDLERS_HPP

#include "../server/server.hpp"
#include "../ServerLogic/HotelReservationInterface.hpp"
#include "../ServerLogic/DataBase.hpp"
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include "UsersOnSite.hpp"

#define CONTENT_TYPE "Content-Type"
#define HTML_TEXT "text/html"
#define HOME_PAGE "/home"
#define SECTION_TAG "<section>"
#define END_SECTION_TAG "</section>"
#define IMAGE_TAG_START "<img src = '";
#define STYLE_HOTEL_IMAGE_HOME "style = 'width:20%; height: 200px; padding:20px'></br></br\n"
#define END_LINE_TAG "</br>"
#define END_LINE_CHAR "\n"
#define LOGIN_PAGE "/login"
#define SIGNUP_PAGE "/signup"
#define DIV_TAG "<div>"
#define END_DIV_TAG "</div>"
#define H_ONE "<h1>"
#define END_H_ONE "</h1>"
#define END_TAG ">"
#define START_TAG "<"
#define END_BODY_TAG "</body>"
#define END_HTML_TAG "</html>"
#define TOOLBAR_PATH "toolbar_home_page.html"
#define H_FOUR "<h4>"
#define H_FOUR_END "</h4>"
#define H_THREE "<h3>"
#define H_THREE_END "</h3>"
#define LIST_ITEM_TAG "<li>"
#define LIST_ITEM_END_TAG "</li>"
#define LIST_TAG "<ul>"
#define END_LIST_TAG "</ul>"
#define P_START "<p>"
#define P_TAG_END "</p>"
#define TABLE_ROW_TAG "<tr>"
#define TABLE_ROW_TAG_END "</tr>"
#define TABLE_ITEM_TAG "<td>"
#define TABLE_ITEM_TAG_END "</td>"
#define FILTER_BOX_HTML "filter_home_page_form.html"
#define SECTION_HOTELS_HOME_PAGE "<section style = 'float:right; width:65%'>"
#define LIST_OF_HOTELS_NAME "<h1><i>List Of Hotels</i></h1>\n"
#define HOTEL_INFO_HTML_FILE "hotel_info_home_page.html"
#define MIN_STAR_NAME "min_star"
#define MAX_STAR_NAME "max_star"
#define CANT_ACCESS_PAGE "/cant-access"

std::string read_html_part(std::string path_folder);
std::string int_to_string(int input_number);
std::string double_to_string(double input_number);
std::string read_part_dynamic_html(std::vector<std::string> must_replaced, std::string path_folder);
double string_to_double(std::string input_string);


class HomePageHandler : public RequestHandler
{
public:
    Response* callback(Request* request);
    HomePageHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site);
private:
    HotelReservationInterface* hotel_reservation;
    bool check_can_sign_up(Request* request, Response* response);
    std::string html_part_one_hotel(Hotel* input_hotel);
    std::string make_html(std::vector<Hotel*> all_hotels);
    std::string add_filter_box();
    std::string add_image_one_hotel(std::string html_now, Hotel* input_hotel);
    Response* make_response_home_page(HotelReservationInterface* user_hotel_reservation, Request* request, Response* response);
    DataBase* all_datas;
    UsersOnSite* users_on_site;
};

class FilterFormHandler : public RequestHandler
{
public:
    FilterFormHandler(UsersOnSite* input_users_on_site);
    Response* callback(Request* request);
private:
    UsersOnSite* users_on_site;
};

#endif
