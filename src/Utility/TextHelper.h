#ifndef TEXTHELPER_H
#define TEXTHELPER_H

#include <iomanip> // to limit decimal places
#include <sstream> // to store float value
#include <string>

class TextHelper{
    public:
    /**
     * Returns a string that limits the decimal value by 2 places
     */
    static std::string FixedFloat(float amount){
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << amount;
        return stream.str();
    }
};

#endif