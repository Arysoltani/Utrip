#include "../server/server.hpp"
#include "../ServerLogic/HotelReservationInterface.hpp"
#include "../ServerLogic/DataBase.hpp"
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include "UsersOnSite.hpp"
#include "handlers.hpp"

#define EMAIL_QUERY "email"
#define PASSWORD_QUERY "password"
#define PASSWORD_REPEAT_QUERY "password_repeat"
#define USER_NAME_QUERY "user_name"
#define FAIL_SIGN_UP_PATH "/signup/fail"
#define EMAIL_LOGIN_KEY "email"
#define PASSWORD_LOGIN_KEY "password"
#define LOGIN_FAIL_PAGE "/login/fail"


class SignupHandler : public RequestHandler
{
public:
    Response* callback(Request* request);
    SignupHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site);
private:
    Response* sign_up(std::string email, std::string password, std::string user_name);
    HotelReservationInterface* hotel_reservation;
    DataBase* all_datas;
    UsersOnSite* users_on_site;
};

class LoginHandler : public RequestHandler
{
public:
    Response* callback(Request* request);
    LoginHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site);
private:
    Response* login_user(std::string email, std::string password);
    HotelReservationInterface* hotel_reservation;
    DataBase* all_datas;
    UsersOnSite* users_on_site;
};

class LogoutHandler : public RequestHandler
{
public:
    Response* callback(Request* request);
    LogoutHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site);
private:
    HotelReservationInterface* hotel_reservation;
    DataBase* all_datas;
    UsersOnSite* users_on_site;
};
