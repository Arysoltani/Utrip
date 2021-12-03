#ifndef MONEY_HPP
#define MONEY_HPP

#include "../server/server.hpp"
#include "../ServerLogic/HotelReservationInterface.hpp"
#include "../ServerLogic/DataBase.hpp"
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include "UsersOnSite.hpp"
#include "handlers.hpp"

#define LOGIN_PAGE_PATH "/login"
#define AMOUNT_MONEY_PAGE_HTML "amount_money_page.html"
#define CHARGE_AMOUNT_QUERY "charge_amount"
#define AMOUNT_CHARGE_PATH "/amount-charge"

class MoneyAmountHandler : public RequestHandler
{
public:
    Response* callback(Request* request);
    MoneyAmountHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site);
private:
    std::string add_page_body(HotelReservationInterface* user_hotel_reservation);
    DataBase* all_datas;
    UsersOnSite* users_on_site;
    HotelReservationInterface* hotel_reservation;
};

class FormChargeHandler : public RequestHandler
{
public:
    Response* callback(Request* request);
    FormChargeHandler(HotelReservationInterface* input_hotel_reservation, DataBase* input_datas, UsersOnSite* input_users_on_site);
private:
    DataBase* all_datas;
    UsersOnSite* users_on_site;
    HotelReservationInterface* hotel_reservation;
};

#endif
