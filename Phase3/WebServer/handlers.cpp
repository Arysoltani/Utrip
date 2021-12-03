#include "handlers.hpp"

using namespace std;

int string_to_int(string input_string)
{
    stringstream stream_string;
    stream_string << input_string;
    int answer;
    stream_string >> answer;
    return answer;
}

double string_to_double(string input_string)
{
    stringstream stream_string;
    stream_string << input_string;
    double answer;
    stream_string >> answer;
    return answer;
}

string double_to_string(double input_number)
{
    stringstream stream_string;
    stream_string << input_number;
    string answer;
    stream_string >> answer;
    return answer;
}

string read_html_part(string path_folder)
{
    ifstream file_in(path_folder);
    string answer;
    while(!file_in.eof())
    {
        char new_char;
        file_in.get(new_char);
        answer += new_char;
    }
    return answer;
}

string int_to_string(int input_number)
{
    stringstream stream_string;
    stream_string << input_number;
    string answer;
    stream_string >> answer;
    return answer;
}

string read_part_dynamic_html(vector<string> must_replaced, string path_folder)
{
    int pnt = 0;
    string answer;
    ifstream file_in(path_folder);
    while(!file_in.eof())
    {
        char new_char;
        file_in.get(new_char);
        if(new_char == '^')
            answer += must_replaced[pnt++];
        else
            answer += new_char;
    }
    return answer;
}

Response* HomePageHandler::callback(Request* request)
{
    Response* response = new Response();
    HotelReservationInterface* user_hotel_reservation;
    if(!users_on_site->has_session_id(request->getSessionId()))
        return Response::redirect(CANT_ACCESS_PAGE);
    user_hotel_reservation = users_on_site->get_hotel_reservation(request);
    return make_response_home_page(user_hotel_reservation, request, response);
}

Response* HomePageHandler::make_response_home_page(HotelReservationInterface* user_hotel_reservation, Request* request, Response* response)
{
    response->setHeader(CONTENT_TYPE, HTML_TEXT);
    Hotels all_hotels_container = user_hotel_reservation->get_filter_hotels();
    vector<Hotel*>all_hotels = all_hotels_container.get_hotels();
    string html_home_page = make_html(all_hotels);
    response->setBody(html_home_page);
    return response;
}


string HomePageHandler::make_html(vector<Hotel*> all_hotels)
{
    string html_hotels;
    html_hotels += read_html_part(TOOLBAR_PATH);
    html_hotels += SECTION_TAG;
    html_hotels += read_html_part(FILTER_BOX_HTML);
    html_hotels += SECTION_HOTELS_HOME_PAGE;
    html_hotels += LIST_OF_HOTELS_NAME;
    for(int i = 0; i < all_hotels.size(); i++)
    {
        html_hotels += html_part_one_hotel(all_hotels[i]);
    }
    html_hotels += END_SECTION_TAG;
    html_hotels += END_SECTION_TAG;
    html_hotels += END_BODY_TAG;
    html_hotels += END_HTML_TAG;
    return html_hotels;
}

HomePageHandler::HomePageHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site)
{
    all_datas = input_datas;
    hotel_reservation = input_hotel_reservation;
    users_on_site = input_users_on_site;
}

string HomePageHandler::html_part_one_hotel(Hotel* input_hotel)
{
    vector<string>must_replaced;
    must_replaced.push_back(input_hotel->get_id());
    must_replaced.push_back(input_hotel->get_name());
    must_replaced.push_back(input_hotel->get_city_name());
    must_replaced.push_back(int_to_string(input_hotel->get_star()));
    string answer = read_part_dynamic_html(must_replaced, HOTEL_INFO_HTML_FILE);
    answer = add_image_one_hotel(answer, input_hotel);
    return answer;
}

string HomePageHandler::add_image_one_hotel(string html_now, Hotel* input_hotel)
{
    html_now += SECTION_TAG;
    html_now += IMAGE_TAG_START;
    html_now += input_hotel->get_url_image();
    html_now += "'";
    html_now += STYLE_HOTEL_IMAGE_HOME;
    html_now += END_SECTION_TAG;
    html_now += SECTION_TAG;
    html_now += END_LINE_TAG;
    html_now += END_LINE_TAG;
    html_now += END_LINE_CHAR;
    return html_now;
}

FilterFormHandler::FilterFormHandler(UsersOnSite* input_users_on_site)
{
    users_on_site = input_users_on_site;
}

Response* FilterFormHandler::callback(Request* request)
{
    if(!users_on_site->has_session_id(request->getSessionId()))
        return Response::redirect(CANT_ACCESS_PAGE);
    int min_star = string_to_int(request->getBodyParam(MIN_STAR_NAME));
    int max_star = string_to_int(request->getBodyParam(MAX_STAR_NAME));
    HotelReservationInterface* user_hotel_reservation = users_on_site->get_hotel_reservation(request);
    user_hotel_reservation->filter_hotels_by_star(min_star, max_star);
    return Response::redirect(HOME_PAGE);
}
