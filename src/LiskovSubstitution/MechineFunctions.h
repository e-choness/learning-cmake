//
// Created by echo_ on 2023-06-18.
//
#pragma once
#include <vector>
#include <string>
#include <iostream>

struct Document{
public:
    Document(const std::string& filename, const std::string& content): m_FileName(filename), m_Content(content){}
    const std::string& m_FileName;
    const std::string& m_Content;
};

struct IPrinter{
    virtual void print(std::vector<Document*> docs) const = 0 ;
};

struct IScanner{
    virtual void scan(std::vector<Document*> docs)const= 0;
};

struct IMachine :IPrinter, IScanner{
    void print(std::vector<Document*> docs) const override{
        for(auto& d: docs){
            std::cout << "Printing " << d->m_FileName << ": " << d->m_Content << std::endl;
        }
    }

    void scan(std::vector<Document*> docs) const override{
        for(auto& d:docs){
            std::cout << "Scanning " << d->m_FileName << ": " << d->m_Content << std::endl;
        }
    }
};
