#include "httplib.h"
#include <iostream>
#include <fstream>

int main() {
    httplib::Server server;

    // Загружаем JSON-файл при старте
    auto cards_json = []() {
        std::ifstream file("../data/cards.json");
        return std::string(std::istreambuf_iterator<char>(file), {});
    }();

    // Роут для получения карточек
    server.Get("/cards", [&](const httplib::Request& req, httplib::Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*"); // Для локального теста
        res.set_content(cards_json, "application/json");
    });

    // Роут для сохранения прогресса (POST-запрос)
    server.Post("/save", [](const httplib::Request& req, httplib::Response& res) {
        std::ofstream file("../data/progress.json");
        file << req.body;
        res.set_content("{\"status\": \"ok\"}", "application/json");
    });

    std::cout << "Сервер запущен на http://localhost:8080\n";
    server.listen("0.0.0.0", 8080);
}
