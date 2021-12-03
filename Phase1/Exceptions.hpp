#ifndef EXEPTION_HPP
#define EXEPTION_HPP

#include<exception>

#define NOT_FOUND_ERROR "Not Found\n"
#define PERMISSION_DENIED_ERROR "Permission Denied\n"
#define BAD_REQUEST_ERROR "Bad Request\n"
#define NOT_ENOUGH_CREDIT_ERROR "Not Enough Credit\n"
#define NOT_ENOUGH_ROOM_ERROR "Not Enough Room\n"

class NotFoundError : public std::exception
{
public:
    virtual const char* what() const throw();
private:
};

class PermissionDeniedError : public std::exception
{
public:
    virtual const char* what() const throw();
private:
};

class BadRequestError : public std::exception
{
public:
    virtual const char* what() const throw();
private:
};

class NotEnoughCreditError : public std::exception
{
public:
    virtual const char* what() const throw();
private:
};

class NotEnoughRoomError : public std::exception
{
public:
    virtual const char* what() const throw();
private:
};

#endif
