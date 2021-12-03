#ifndef USERS_ON_SITE
#define USERS_ON_SITE

#include "../ServerLogic/HotelReservationInterface.hpp"
#include<string>
#include<vector>
#include<iostream>
#include "../server/server.hpp"

class UsersOnSite
{
public:
    ~UsersOnSite();
    void add_user(std::string session, HotelReservationInterface* hotel_reservation);
    HotelReservationInterface* get_user(std::string session);
    void delete_user(std::string session);
    HotelReservationInterface* get_user(Request* request);
    HotelReservationInterface* get_hotel_reservation(Request* request);
    bool has_session_id(std::string session_id);
private:
    std::vector< std::pair< HotelReservationInterface*, std::string> > users_on_site;
    void delete_user_index(int index);
};

#endif
