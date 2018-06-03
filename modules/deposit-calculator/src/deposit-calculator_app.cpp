// Copyright 2018 Kovshov Andrey

#include "../include/deposit-calculator.h"
#include "../include/deposit-calculator_app.h"

#include <string>
#include <exception>
#include <sstream>
#include <fstream>

DepositCalculApp::DepositCalculApp() : message_("") {}

void DepositCalculApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a deposit calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <amount> <percentage> " +
        "<duration> <capitalization type>\n\n" +
        "Where all arguments are not negative," +
        " and the last one is 0 or 1 or 2 \n";
}

bool DepositCalculApp::validateNumberOfArguments
(int argc, const char** argv) {
     if (argc == 1) {
        help(argv[0]);
        return false;
     } else if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

int parseInt(const char* arg) {
    int value = std::stoi(std::string(arg));
    return value;
}

float parseFloat(const char* arg) {
    float value = std::stof(std::string(arg));
    return value;
}

std::string DepositCalculApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        Arguments args;
        args.amount = parseInt(argv[1]);
        args.percentage = parseFloat(argv[2]);
        args.duration = parseInt(argv[3]);
        args.type_capital = parseInt(argv[4]);
        Deposit dc(args.amount, args.percentage, args.duration,
            args.type_capital);
        std::ostringstream stream;
        stream << "Your profit: " << static_cast<int>(dc.getIncome());
        message_ = stream.str();
        return message_;
    }
    catch (std::exception& exc) {
        return std::string("Wrong format or value is out of range");
    }
}
