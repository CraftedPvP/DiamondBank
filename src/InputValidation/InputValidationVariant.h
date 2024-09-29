#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <vector>
#include <string>
#include <variant>
#include <functional>
#include <iostream>
using std::cout;
using std::endl;

class IValidation {
public:
    // add rules in this function
    virtual void Initialize() = 0;
    virtual bool IsValid(std::variant<int,float, std::string> input) const = 0;
    virtual std::string GetErrorMessage() = 0;
};

// Validation for int type
class InputValidationInt : public IValidation {
public:
    void AddRule(std::function<bool(int)> rule) {
        validations.push_back(rule);
    }

    bool IsValid(std::variant<int, float, std::string> input) const override {
        if (!std::holds_alternative<int>(input))
            return false; // Wrong type

        int value = std::get<int>(input);
        for (const auto& validation : validations) {
            if (!validation(value)) return false;
        }
        return true;
    }

private:
    std::vector<std::function<bool(int)>> validations;
};

// Validation for string type
class InputValidationString : public IValidation {
public:
    void AddRule(std::function<bool(const std::string&)> rule) {
        validations.push_back(rule);
    }

    bool IsValid(std::variant<int, float, std::string> input) const override {
        if (!std::holds_alternative<std::string>(input))
            return false; // Wrong type

        std::string value = std::get<std::string>(input);
        for (const auto& validation : validations) {
            if (!validation(value)) return false;
        }
        return true;
    }

private:
    std::vector<std::function<bool(const std::string&)>> validations;
};

// Validation for float type
class InputValidationFloat : public IValidation {
public:
    void AddRule(std::function<bool(float)> rule) {
        validations.push_back(rule);
    }

    bool IsValid(std::variant<int, float, std::string> input) const override {
        // cout << endl << "boogsh"<< endl;
        if (!std::holds_alternative<float>(input))
            return false; // Wrong type

        float value = std::get<float>(input);
        for (const auto& validation : validations) {
            if (!validation(value)) return false;
        }
        return true;
    }

private:
    std::vector<std::function<bool(float)>> validations;
};
#endif