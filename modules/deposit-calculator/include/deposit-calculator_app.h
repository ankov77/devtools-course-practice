// Copyright 2018 Kovshov Andrey

#ifndef MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_APP_H_
#define MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_APP_H_
#include <string>

class DepositCalculApp {
 public:
    DepositCalculApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int amount;
        float percentage;
        int duration;
        int type_capital;
    } Arguments;
};

#endif  // MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_APP_H_
