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

/* Sample Tests CrowCpp

#include <gtest/gtest.h>
#include "crow.h"

// Configurando o app Crow em uma função acessível para testes
crow::SimpleApp create_app() {
    crow::SimpleApp app;
    CROW_ROUTE(app, "/api/hello")([](){
        return crow::response(200, "Olá do Crow!");
    });
    return app;
}

// Testando a rota
TEST(CrowAppTest, RotaHello) {
    crow::SimpleApp app = create_app();

    // Cria uma requisição HTTP falsa simulando um GET para "/api/hello"
    crow::request req;
    req.url = "/api/hello";
    req.method = crow::HTTPMethod::GET;

    // Cria um objeto de resposta vazio
    crow::response res;

    // Processa a requisição internamente sem precisar rodar o servidor
    app.handle(req, res);

    // Verifica o código de status HTTP
    EXPECT_EQ(res.code, 200);

    // Verifica o corpo da resposta
    EXPECT_EQ(res.body, "Olá do Crow!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

*/
