#include "SignupHandler.hpp"

using namespace std;


Response* SignupHandler::callback(Request* request)
{
    string password = request->getBodyParam(PASSWORD_QUERY);
    string user_name = request->getBodyParam(USER_NAME_QUERY);
    string password_repeat = request->getBodyParam(PASSWORD_REPEAT_QUERY);
    string email = request->getBodyParam(EMAIL_QUERY);
    if(password != password_repeat)
    {
         return Response::redirect(FAIL_SIGN_UP_PATH);
    }
    return sign_up(email, password, user_name);
}

Response* SignupHandler::sign_up(string email, string password, string user_name)
{
    Response* response = new Response();
    response->setHeader(CONTENT_TYPE, HTML_TEXT);
    HotelReservationInterface* new_hotel_reservation = new HotelReservationInterface(all_datas);
    try
    {
        new_hotel_reservation->signup_user(email, user_name, password);
        response = Response::redirect(HOME_PAGE);
        response->setSessionId(email);
        users_on_site->add_user(email, new_hotel_reservation);
        return response;
    }
    catch(exception& error)
    {
        delete new_hotel_reservation;
        response = Response::redirect(FAIL_SIGN_UP_PATH);
    }
    return response;
}

SignupHandler::SignupHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site)
{
    all_datas = input_datas;
    hotel_reservation = input_hotel_reservation;
    users_on_site = input_users_on_site;
}

LoginHandler::LoginHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site)
{
    all_datas = input_datas;
    hotel_reservation = input_hotel_reservation;
    users_on_site = input_users_on_site;
}

LogoutHandler::LogoutHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site)
{
    all_datas = input_datas;
    hotel_reservation = input_hotel_reservation;
    users_on_site = input_users_on_site;
}


Response* LoginHandler::callback(Request* request)
{
    Response* response = new Response();
    string email = request->getBodyParam(EMAIL_LOGIN_KEY);
    string password = request->getBodyParam(PASSWORD_LOGIN_KEY);
    response->setHeader(CONTENT_TYPE, HTML_TEXT);
    return login_user(email, password);
}

Response* LoginHandler::login_user(string email, string password)
{
    Response* response = new Response();
    HotelReservationInterface* new_hotel_reservation = new HotelReservationInterface(all_datas);
    try
    {
        new_hotel_reservation->login_input_user(email, password);
        response = Response::redirect(HOME_PAGE);
        response->setSessionId(email);
        users_on_site->add_user(email, new_hotel_reservation);
        return response;
    }
    catch(exception& error)
    {
        delete new_hotel_reservation;
        response = Response::redirect(LOGIN_FAIL_PAGE);
    }
    return response;
}

Response* LogoutHandler::callback(Request* request)
{
    string session_id = request->getSessionId();
    users_on_site->delete_user(session_id);
    return Response::redirect(LOGIN_PAGE);
}
