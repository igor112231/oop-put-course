#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

class logarithmException :public std::runtime_error {
public:
    explicit logarithmException(const std::string& message):std::runtime_error(message){}
};



class Logarithm {
public:
    Logarithm(double base, double argument) {
        base_ = base;
        argument_ = argument;
    }

    double Calculate() const {
        return std::log(argument_) / std::log(base_);
    }

    void baseException()
    {
        if (base_ <= 0 )
        {
            throw logarithmException("base<=0");
        }
        if (base_ == 1)
        {
            throw logarithmException("base=1");
        }
    }
    void argumentException()
    {
        if (argument_ <= 0)
        {
            throw logarithmException("argument<=0");
        }
    }

private:
    double base_;
    double argument_;
};



int main()
{
    Logarithm loog(2, 0);
    try {
        loog.baseException();
        loog.argumentException();
    }
    catch (const logarithmException& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
    /*try {
        loog.argumentException();
    }
    catch (const Customexception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }*/
    std::cout<<loog.Calculate();
}
