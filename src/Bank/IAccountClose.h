#ifndef ACCOUNTCLOSE_H
#define ACCOUNTCLOSE_H

#include <string>

/**
 * Interface for account termination or deletion
 */
class IAccountClose {
public:
    virtual bool Close() = 0;
};

#endif