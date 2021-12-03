#include "HotelPageHandler.hpp"

using namespace std;

HotelPageHandler::HotelPageHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site)
{
    all_datas = input_datas;
    hotel_reservation = input_hotel_reservation;
    users_on_site = input_users_on_site;
}

Response* HotelPageHandler::callback(Request* request)
{
    Response* response = new Response();
    string html_answer;
    string session_id = request->getSessionId();
    if(!users_on_site->has_session_id(session_id))
        return Response::redirect(CANT_ACCESS_PAGE);
    response->setHeader(CONTENT_TYPE, HTML_TEXT);
    string id = request->getQueryParam(ID_QUERY_KEY);
    Hotel* needed_hotel = all_datas->find_hotel(id);
    html_answer += write_part_info_hotel(needed_hotel);
    response->setBody(html_answer);
    return response;
}

string HotelPageHandler::write_part_info_hotel(Hotel* needed_hotel)
{
    string html_answer;
    html_answer += read_html_part(TOOLBAR_PATH);
    html_answer += SECTION_TAG;
    html_answer += STYLE_DIV_HOTEL_INFO;
    string name = needed_hotel->get_name();
    html_answer += H_ONE;
    html_answer += name;
    html_answer += END_H_ONE;
    html_answer += write_parts_after_name(needed_hotel);
    return html_answer;
}

string HotelPageHandler::write_parts_after_name(Hotel* needed_hotel)
{
    string html_answer;
    html_answer += write_part_amenities(needed_hotel);
    html_answer += END_DIV_TAG;
    html_answer += SECTION_IMAGE_STYLE;
    html_answer += IMAGE_STYLE_HOTEL;
    html_answer += needed_hotel->get_url_image();
    html_answer += "'";
    html_answer += END_TAG;
    html_answer += END_LINE_TAG;
    html_answer += END_LINE_TAG;
    html_answer += write_info(needed_hotel);
    html_answer += write_part_overview(needed_hotel);
    html_answer += END_SECTION_TAG;
    html_answer += END_SECTION_TAG;
    html_answer += END_BODY_TAG;
    html_answer += END_HTML_TAG;
    return html_answer;
}

string HotelPageHandler::write_part_amenities(Hotel* needed_hotel)
{
    string answer;
    string amenities = needed_hotel->get_amenities();
    answer += H_FOUR;
    answer += AMENTIES_NAME;
    answer += H_FOUR_END;
    vector<string> seperated_amenities = seperate_amenities(amenities);
    answer += LIST_AMENTIES_STYLE;
    for(int i = 0; i < seperated_amenities.size(); i++)
    {
        answer += LIST_ITEM_TAG;
        answer+= seperated_amenities[i];
        answer += LIST_ITEM_END_TAG;
    }
    answer += END_LIST_TAG;
    return answer;
}

vector<string> HotelPageHandler::seperate_amenities(string amenities)
{
    vector<string>answer;
    string last_amenities;
    for(int i = 0; i < amenities.size(); i++)
    {
        if(amenities[i] == PART_AMENITIES)
        {
            answer.push_back(last_amenities);
            last_amenities = "";
        }
        else
            last_amenities += amenities[i];
    }
    answer.push_back(last_amenities);
    return answer;
}

string HotelPageHandler::write_part_overview(Hotel* needed_hotel)
{
    string answer;
    answer += H_FOUR;
    answer += OVERVIEW_NAME;
    answer += H_FOUR_END;
    answer += P_STYLE_OVERVIEW;
    answer += needed_hotel->get_overview();
    answer += P_TAG_END;
    return answer;
}

string HotelPageHandler::write_info(Hotel* needed_hotel)
{
    string answer;
    answer += H_FOUR;
    answer += CITY_NAME;
    answer += needed_hotel->get_city_name();
    answer += H_FOUR_END;
    answer += H_FOUR;
    answer += HOTEL_RATING_NAME;
    answer += int_to_string(needed_hotel->get_star());
    answer += H_FOUR_END;
    answer += write_prices(needed_hotel);
    return answer;
}

string HotelPageHandler::write_prices(Hotel* needed_hotel)
{
    string answer;
    string standard_price = int_to_string(needed_hotel->get_standard_price());
    string deluxe_price = int_to_string(needed_hotel->get_deluxe_price());
    string luxury_price = int_to_string(needed_hotel->get_luxury_price());
    string premium_price = int_to_string(needed_hotel->get_premium_price());
    answer += TABLE_PRICES_STYLE;
    answer += TABLE_ROW_TAG;
    answer += TABLE_HEADER_TYPE_PRICE;
    answer += TABLE_HEADER_PRICE;
    answer += TABLE_ROW_TAG_END;
    answer += add_header_price(STANDARD_PRICE_NAME, standard_price);
    answer += add_header_price(DELUXE_PRICE_NAME,deluxe_price);
    answer += add_header_price(LUXURY_PRICE_NAME, luxury_price);
    answer += add_header_price(PREMIUM_PRICE_NAME,premium_price);
    answer += END_DIV_TAG;
    return answer;
}

string HotelPageHandler::add_header_price(string name, string value)
{
    string answer;
    answer += TABLE_ROW_TAG;
    answer += TABLE_ITEM_TAG;
    answer += name;
    answer += TABLE_ITEM_TAG_END;
    answer += TABLE_ITEM_TAG;
    answer += value;
    answer += TABLE_ITEM_TAG_END;
    answer += TABLE_ROW_TAG_END;
    return answer;
}
