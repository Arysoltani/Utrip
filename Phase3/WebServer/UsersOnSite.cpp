#include "UsersOnSite.hpp"

using namespace std;

UsersOnSite::~UsersOnSite()
{
    for(int i = 0; i < users_on_site.size(); i++)
        delete users_on_site[i].first;
}

HotelReservationInterface* UsersOnSite::get_user(string session)
{
    for(int i = 0; i < users_on_site.size(); i++)
    {
        if(users_on_site[i].second == session)
            return users_on_site[i].first;
    }
}


void UsersOnSite::add_user(string session, HotelReservationInterface* hotel_reservation)
{
    users_on_site.push_back(make_pair(hotel_reservation, session));
}

void UsersOnSite::delete_user(string session)
{
    for(int i = 0; i < users_on_site.size(); i++)
    {
        if(users_on_site[i].second == session)
        {
            delete_user_index(i);
        }
    }
}


void UsersOnSite::delete_user_index(int index)
{
    delete users_on_site[index].first;
    for(int i = index + 1; i < users_on_site.size(); i++)
    {
        users_on_site [i - 1] = users_on_site[i];
    }
    users_on_site.pop_back();
}

HotelReservationInterface* UsersOnSite::get_hotel_reservation(Request* request)
{
    string session_id = request->getSessionId();
    return get_user(session_id);
}

bool UsersOnSite::has_session_id(string session_id)
{
    for(int i = 0; i < users_on_site.size(); i++)
    {
        if(users_on_site[i].second == session_id)
            return true;
    }
    return false;
}
