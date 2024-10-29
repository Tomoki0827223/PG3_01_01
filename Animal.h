#pragma once
#include <iostream>


class Animal {

public:

    virtual void makeSound() const = 0;

    virtual ~Animal() = default;

};

class Dog : public Animal {

public:

    void makeSound() const override;

};


class Cat : public Animal {

public:

    void makeSound() const override;

};