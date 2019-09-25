#include <iostream>
#include "../include/defines.h"
#include "../include/CSV_RW.hpp"

int main() {
    CSV_RW file = CSV_RW("output.csv");
    file.writeValue(10);
}