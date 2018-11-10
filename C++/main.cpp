//
// Created by alfons on 18-11-8.
//
#include <iostream>

#include "config.h"
#include "DeleteRepeatElem.h"

int main() {
    fprintf(stdout, "Version -> %d.%d\n", PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR);

#ifdef USE_NO_REPEAT_LIB
    DelRepeatElems();
#endif

    std::cout << "helloworld" << std::endl;
    return 1;
}