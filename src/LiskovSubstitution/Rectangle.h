//
// Created by echo_ on 2023-06-18.
//
#pragma once

class Rectangle{

public:
    Rectangle(const int width, const int height):
    m_Width(width), m_Height(height){}

    [[nodiscard]] int get_width() const {return m_Width;}
    virtual void set_width(const int width){
        this->m_Width = width;
    }
    [[nodiscard]] int get_height() const {return m_Height;}
    virtual void set_height(const int height){
        this->m_Height = height;
    }

    [[nodiscard]] int area() const {return m_Width*m_Height;}

protected:
    int m_Width, m_Height;
};


