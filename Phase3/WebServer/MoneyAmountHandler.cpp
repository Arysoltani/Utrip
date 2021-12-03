#include "MoneyAmountHandler.hpp"

using namespace std;


MoneyAmountHandler::MoneyAmountHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site)
{
    all_datas = input_datas;
    hotel_reservation = input_hotel_reservation;
    users_on_site = input_users_on_site;
}

Response* MoneyAmountHandler::callback(Request* request)
{
    Response* response = new Response();
    HotelReservationInterface* user_hotel_reservation;
    response->setHeader(CONTENT_TYPE, HTML_TEXT);
    if(!users_on_site->has_session_id(request->getSessionId()))
        return Response::redirect(CANT_ACCESS_PAGE);
    user_hotel_reservation = users_on_site->get_hotel_reservation(request);
    string html_hotels;
    html_hotels += read_html_part(TOOLBAR_PATH);
    html_hotels +=  add_page_body(user_hotel_reservation);
    response->setBody(html_hotels);
    return response;
}

string MoneyAmountHandler::add_page_body(HotelReservationInterface* user_hotel_reservation)
{
    string answer;
    vector<string>must_replaced;
    double amount_money = user_hotel_reservation->get_money_login_user();
    must_replaced.push_back(double_to_string(amount_money));
    answer += read_part_dynamic_html(must_replaced, AMOUNT_MONEY_PAGE_HTML);
    return answer;
}

FormChargeHandler::FormChargeHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site)
{
    all_datas = input_datas;
    hotel_reservation = input_hotel_reservation;
    users_on_site = input_users_on_site;
}

Response* FormChargeHandler::callback(Request* request)
{
    HotelReservationInterface* user_hotel_reservation;
    if(!users_on_site->has_session_id(request->getSessionId()))
        return Response::redirect(CANT_ACCESS_PAGE);
    user_hotel_reservation = users_on_site->get_hotel_reservation(request);
    string amount_str = request->getBodyParam(CHARGE_AMOUNT_QUERY);
    double amount_money = string_to_double(amount_str);
    user_hotel_reservation->charge_wallet_login_user(amount_money);
    return Response::redirect(AMOUNT_CHARGE_PATH);
}
