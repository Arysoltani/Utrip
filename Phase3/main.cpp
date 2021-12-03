#include<iostream>
#include "ServerLogic/DataBase.hpp"
#include "ServerLogic/HotelReservationInterface.hpp"
#include<vector>
#include<string>
#include "server/server.hpp"
#include "WebServer/handlers.hpp"
#include "WebServer/UsersOnSite.hpp"
#include "WebServer/HotelPageHandler.hpp"
#include "WebServer/SignupHandler.hpp"
#include "WebServer/MoneyAmountHandler.hpp"

#define LOGIN_FAIL_HTML "login_fail.html"
#define CANT_ACCESS_HTML "error_cant_access.html"
#define ARGV_ID_HOTEL_FOLDER 1
#define ARGV_ID_RATING_FOLDER 2
#define SIGNUP_PATH "/signup"
#define SUCCESSFULL_LOGIN "/login/succesfull_page"
#define HOME_PATH "/home"
#define HOTEL_PAGE "/home/hotelpage"
#define SIGNUP_FAIL "/signup/fail"
#define FILTER_FORM_PATH "/home/filter_form"
#define LOGOUT_FORM_PATH "/logout-form"
#define CHARGE_AMOUNT_FORM "/charge-form"
#define SIGNUP_PAGE_HTML "signup_page.html"
#define SUCCESSFULL_PAGE_HTML "succesfull_page.html"
#define FAIL_SIGNUP_HTML "fail_signup.html"
#define LOGIN_PAGE_HTML "login_page.html"

using namespace std;

void run_server(HotelReservationInterface* hotel_reservation, DataBase* datas, UsersOnSite* users_on_site)
{
    Server server(8080);
    server.get(SIGNUP_PATH,new ShowPage(SIGNUP_PAGE_HTML));
    server.get(SUCCESSFULL_LOGIN, new ShowPage(SUCCESSFULL_PAGE_HTML));
    server.get(HOME_PATH, new HomePageHandler(hotel_reservation, datas, users_on_site));
    server.get(HOTEL_PAGE, new HotelPageHandler(hotel_reservation, datas, users_on_site));
    server.get(SIGNUP_FAIL, new ShowPage(FAIL_SIGNUP_HTML));
    server.get(CANT_ACCESS_PAGE, new ShowPage(CANT_ACCESS_HTML));
    server.get(LOGIN_FAIL_PAGE, new ShowPage(LOGIN_FAIL_HTML));
    server.post(SIGNUP_PATH, new SignupHandler(hotel_reservation, datas, users_on_site));
    server.post(FILTER_FORM_PATH, new FilterFormHandler(users_on_site));
    server.get(LOGIN_PAGE_PATH, new ShowPage(LOGIN_PAGE_HTML));
    server.get(LOGOUT_FORM_PATH, new LogoutHandler(hotel_reservation, datas, users_on_site));
    server.post(LOGIN_PAGE_PATH, new LoginHandler(hotel_reservation, datas, users_on_site));
    server.get(AMOUNT_CHARGE_PATH, new MoneyAmountHandler(hotel_reservation, datas, users_on_site));
    server.post(CHARGE_AMOUNT_FORM, new FormChargeHandler(hotel_reservation, datas, users_on_site));
    server.run();
}

int main(int argc, char* argv[])
{
    DataBase* datas = new DataBase();
    string hotel_file_path = argv[ARGV_ID_HOTEL_FOLDER];
    string rating_file_path = argv[ARGV_ID_RATING_FOLDER];
    UsersOnSite* users_on_site = new UsersOnSite();
    datas->read_hotels(hotel_file_path);
    datas->read_ratings(rating_file_path);
    HotelReservationInterface* hotel_reservation = new HotelReservationInterface(datas);
    run_server(hotel_reservation, datas, users_on_site);
    delete users_on_site;
    delete datas;
    delete hotel_reservation;
}
