//
// Created by echo_ on 2023-08-27.
//

#pragma once


class BitFieldMember {
public:
    static void DisplayStructPadding();
};

struct S{
    int i: 3 = 0;
    int j: 5 = 0;
    S() = default;
};

struct S1{
    int i: 24;
    int j: 24;
    S1():i{0}, j{0}{};
};
