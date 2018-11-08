//
// Created by alfons on 18-11-8.
//
#include <iostream>
#include <array>
#include <algorithm>

#include "DeleteRepeatElem.h"

void DelRepeatElems() {
    std::array<int, 15> elemArr{1, 2, 3, 4, 5, 6, 7, 342, 432, 43, 2, 34, 5, 6, 2};
    std::sort(elemArr.begin(), elemArr.end());

    int L = 0, R = 0;
    for (; R < elemArr.size(); ++R) {
        if (elemArr[L] != elemArr[R]) {
            std::cout << elemArr[L] << " number is " << R - L << std::endl;
            L = R;
        }
    }
    std::cout << elemArr[L] << " number is " << R - L << std::endl;
}