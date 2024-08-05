#include "Factory.h"

Strategy *&Product::get()
{
    return strategy_;
}
void Product::process() {
    std::cout << "Product";
}
void ProductA::process() {
    std::cout << "A ";
    strategy_->process();
}
void ProductB::process() {
    std::cout << "B ";
    strategy_->process();
}
void ProductC::process() {
    std::cout << "C ";
    strategy_->process();
}

void Heating::process() {
    std::cout << "Heated!" << std::endl;
}
void Cooling::process() {
    std::cout << "Cooled!" << std::endl;
}
void Mixing::process() {
    std::cout << "Mixed!" << std::endl;
}

void FactoryManager::assignStrategy (Strategy* &strategy_ , const std::string &gongyi) {
    if(gongyi == "Heating")
        strategy_ = new Heating;
    else if (gongyi == "Cooling")
        strategy_ = new Cooling;
    else if (gongyi == "Mixing")
        strategy_ = new Mixing;
}

Product *FactoryManager::createProduct (const std::string &pinlei) {
    if(pinlei == "ProductA")
        return new ProductA;
    else if (pinlei == "ProductB")
        return new ProductB;
    else if (pinlei == "ProductC")
        return new ProductC;
}