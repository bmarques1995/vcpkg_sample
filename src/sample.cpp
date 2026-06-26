#include <iostream>
#include <spdlog/spdlog.h>

int main(int argc, char** argv)
{
    std::cout << "Hello Cmake\n";
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    return 0;
}