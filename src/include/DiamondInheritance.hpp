//
// Created by echo_ on 2023-08-29.
//

#pragma once


class DiamondInheritance {
public:
    static void DisplayDiamondInheritanceResult();
};

class Pet{
public:
    Pet(): m_IsAlive{true}{};

    virtual void BeingAlive() const;

protected:
    bool m_IsAlive;
};

class Cat: virtual public Pet{
public:
    Cat(): m_Name{"Kitty"}{};
    void BeingAlive() const override;
private:
    const char* m_Name;
};

class Dog: virtual public Pet{
public:
    Dog(): m_Breed{"German Shepherd"}{};
    void BeingAlive() const override;
private:
    const char* m_Breed;
};

class Fox: public Cat, public Dog{
public:
    Fox():m_Status{"Not natural"}{};
    void BeingAlive() const override;

private:
    const char* m_Status;
};