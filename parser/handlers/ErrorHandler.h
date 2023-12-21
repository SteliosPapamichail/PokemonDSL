//
// Created by Steli on 7/12/2023.
//

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H
#include <string>
#include <utility>
#include <vector>

class Error {
    std::string message;
    int lineNumber;

public:
    std::string getMessage() const;

    int getLineNumber() const;

    Error(std::string message, const int lineNumber) : message(std::move(message)), lineNumber(lineNumber) {
    }

    ~Error() = default;
};

class ErrorHandler final {
    std::vector<Error> errors;

    // prevent instantiation
    ErrorHandler() {
    }

public:
    Error getLatestError() const;

    std::vector<Error> getErrors() const;

    void printErrors() const;

    void addError(const Error&error);

    ~ErrorHandler() = default;

    static ErrorHandler& getInstance();

    ErrorHandler(ErrorHandler const&) = delete;

    void operator=(ErrorHandler const&) = delete;
};

#endif //ERRORHANDLER_H
