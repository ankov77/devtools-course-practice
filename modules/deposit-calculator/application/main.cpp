// Copyright 2018 Kovshov Andrey

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/deposit-calculator_app.h"

int main(int argc, const char** argv) {
    DepositCalculApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
