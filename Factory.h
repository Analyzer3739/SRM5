//
// Created by mds on 2024/8/6.
//
#include<bits/stdc++.h>
#ifndef FACTORY_H
#define FACTORY_H

class Strategy;

class Product
{
public:
    Product() :strategy_(nullptr) {}
    virtual void process();
    Strategy *&get();
protected:
    Strategy* strategy_;
};

class ProductA : public Product
{
public:
    void process()override;
};
class ProductB : public Product
{
public:
    void process()override;
};
class ProductC : public Product
{
public:
    void process()override;
};

class Strategy
{
public:
    virtual void process() = 0;
};

class Heating : public Strategy
{
public:
    void process() override;
};
class Cooling : public Strategy
{
public:
    void process() override;
};
class Mixing : public Strategy
{
public:
    void process() override;
};

class FactoryManager
{
public:
    static FactoryManager& getInstance()
    {
        static FactoryManager instance;
        return instance;
    }
    Product *createProduct (const std::string &pinlei);
    void assignStrategy (Strategy* &strategy_ , const std::string &gongyi);
private:
    FactoryManager(){};
};
#endif //FACTORY_H
