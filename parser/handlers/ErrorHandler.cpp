//
// Created by Steli on 7/12/2023.
//

#include "ErrorHandler.h"

#include <iostream>
#include "../../utils/Utils.h"

// Error class member function definitions
std::string Error::getMessage() const { return message; }
int Error::getLineNumber() const { return lineNumber; }

// ErrorHandler class member function definitions
Error ErrorHandler::getLatestError() const { return errors.back(); }
std::vector<Error> ErrorHandler::getErrors() const { return errors; }
void ErrorHandler::addError(const Error&error) { errors.push_back(error); }

void ErrorHandler::printErrors() const {
    for (auto&error: errors) {
        std::cerr << RED_TEXT << "Error on line #" << error.getLineNumber() << ": " << error.getMessage() << "." << RESET_TEXT << std::endl;
    }
}


ErrorHandler& ErrorHandler::getInstance() {
    // guaranteed to be destroyed, instantiated on first use.
    static ErrorHandler instance;
    return instance;
}
