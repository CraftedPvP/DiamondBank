#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <vector>
#include <functional>

// simple one type template for input validation
template<typename T>
class InputValidation {
public:
    InputValidation(){ Initialize(); }
    virtual void Initialize() = 0;

    // Add a validation rule
    void AddRule(std::function<bool(const T&)> rule) {
        validators.push_back(rule);
    }

    // Run all validation rules on the input
    bool IsValid(const T& input) const {
        for (const auto& validator : validators) {
            if (!validator(input)) {
                return false; // Validation failed
            }
        }
        return true; // All validations passed
    }

private:
    std::vector<std::function<bool(const T&)>> validators;
};
#endif