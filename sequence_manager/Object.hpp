// Object.hpp
#pragma once
#include <string>
#include <iostream>

class Object
{
public:
    Object(std::string name) : name_(name) {}

    virtual ~Object()
    {
        std::cout << "[Destructor] Object: " << name_ << std::endl;
    }

    virtual void display() const
    {
        std::cout << "Object: " << name_ << std::endl;
    }

protected:
    std::string name_;
};
