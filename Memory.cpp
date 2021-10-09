/*
    Memory.cpp

    An example of memory resource problems.

    Definitely not a guide to good programming practices.
*/

#include <iostream>
#include <memory>

std::unique_ptr<int> producer(int n) {

    std::unique_ptr<int> p; //WIP
    
    p.reset(new int(n));

    return p;
}

void consumer(std::unique_ptr<int> pn) {

    // ...

    //delete pn;
}

int main() {

    // @error memory leak
    {
        //int* p = new int(5);

        std::unique_ptr<int> p;
        
        //p = new int(5);
         p.reset(new int(5));
        
        

        std::cerr << "TRACE: " << __FILE__ << ":" << __LINE__ << '\n';
    }

    // @error memory leak
    {
        //int* p = producer(5);
        
        std::unique_ptr<int> p = producer(5);
        
        

        std::cerr << "TRACE: " << __FILE__ << ":" << __LINE__ << '\n';
    }

    // @error memory leak
    {
        //int* p = new int(5);
        
        std::unique_ptr<int> p;

        //p = new int(5); //WIP
         p.reset(new int(5));

        //delete p;
        
        

        std::cerr << "TRACE: " << __FILE__ << ":" << __LINE__ << '\n';
    }

    // @error missing initialization and use unallocated memory
    {
        //int* p;

        std::unique_ptr<int> p;
        
        //p = new int();
        p.reset(new int());
        
        *p = 5; //WIP
        
        
        
        std::cerr << "TRACE: " << __FILE__ << ":" << __LINE__ << '\n';
    }

    // @error double free
    {
        std::unique_ptr<int> p;

        //p = new int(5);
        
        p.reset(new int(5));

        //delete p;

        //delete p;
        
        

        std::cerr << "TRACE: " << __FILE__ << ":" << __LINE__ << '\n';
    }

    // @error double free
    {
        //int* p = new int(5);
        
        std::unique_ptr<int> p;
        
        //p = new int(5);
        p.reset(new int(5));

        consumer(p);

        //delete p;

        std::cerr << "TRACE: " << __FILE__ << ":" << __LINE__ << '\n';
    }

    return 0;
}
