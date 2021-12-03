#include "Exceptions.hpp"

const char* NotFoundError::what() const throw()
{
    return NOT_FOUND_ERROR;
}

const char* PermissionDeniedError::what() const throw()
{
    return PERMISSION_DENIED_ERROR;
}

const char* BadRequestError::what() const throw()
{
    return BAD_REQUEST_ERROR;
}

const char* NotEnoughCreditError::what() const throw()
{
    return NOT_ENOUGH_CREDIT_ERROR;
}

const char* NotEnoughRoomError::what() const throw()
{
    return NOT_ENOUGH_ROOM_ERROR;
}
