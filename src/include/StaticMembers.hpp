//
// Created by echo_ on 2023-08-21.
//

#pragma once

class Square{
public:
    explicit Square(int length): m_SideLength{length}{m_TotalCount++;}
    [[nodiscard]] int Area() const {return m_SideLength * m_SideLength;}
    static int GetTotalCount() {return m_TotalCount;}
private:
    static inline int m_TotalCount{0};
    int m_SideLength;
};

class StaticMembers {
public:
    static void DisplayResult();
};

