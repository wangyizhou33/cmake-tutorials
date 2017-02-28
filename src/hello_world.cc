#include <iostream>
#include <Config.h>

#ifdef USE_UTILS
#include <mysqrt.h>
#endif

int main(int argc, char** argv)
{
    std::cout << "Version Major: " << VERSION_MAJOR << ", Version Minor: " << VERSION_MINOR << std::endl;

#ifdef USE_UTILS
    std::cout << "sqrt of 4.0 is " << mysqrt(4.0) << std::endl;
#endif

    return 0;

}
