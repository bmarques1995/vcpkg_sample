#include <crow/common.h>
#include <iostream>
#include <spdlog/spdlog.h>
#include <crow.h>

int main(int argc, char** argv)
{
    std::cout << "Hello Cmake\n";
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    
    crow::SimpleApp app;
    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)
    ([]{
        crow::json::wvalue x({{"message", "Hello, World!"}});
        x["message2"] = "Hello, World.. Again!";
        return x;
    });
    return 0;
}