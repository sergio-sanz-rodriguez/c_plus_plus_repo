#include <iostream>
#include <string>
#include <functional>

class BaseClass
{
    public:
    void triggerProcess() const
    {
        process();
    }

    protected:
    // if you do not want a subclass to use the overloaded process method, then the modificator "final" shall be added. With final you can not overload process() anymore
    virtual void process() const final {
    //virtual void process() const {    
        std::cout << "Base: " << a << "\n";
    }

    int a = 5;
   
};

class SubClass : public BaseClass
{
    protected:
    // As is, it calls to the process method of the base class. Indicate in the overwritting methods an "override"
    void process() const override {
        std::cout << "SubClass: " << a << "\n";
    }

};

int main() {

}