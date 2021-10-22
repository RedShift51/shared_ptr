#include <iostream>
#include <string>
#include "shared_ptr.h"

int main()
{
    std::cout << "Custom shared_ptr class" << std::endl;
    
    for (int i = 0; i < 1e12; i++)
    {
        //std::string* s = new std::string("SHARED PTR");
        shared_ptr<std::string> shared(new std::string("SHARED PTR"));
        shared_ptr<std::string> shared1 = shared;
        shared_ptr<std::string> shared2(shared);
        //std::cout << i << std::endl;
    }

    return 0;
}
