#include "inc/tvec.hpp"
#include "inc/tcontrol.hpp"
#include <iostream>

int main(int argc, char **argv) { 
    
    tmath::vec<float,4> x(0,1,2,3);
    tmath::vec<float,4> y(0,1,2,3);
    auto z = x + y/2;
    std::cout << tmath::sin(z) << std::endl;
}