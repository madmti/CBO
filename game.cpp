#include <SFML/Graphics.hpp>
#include "./lib/console.cpp"
#include "./lib/math.cpp"

class Game {
private:
    sf::RenderWindow* window;
    Vector2 win_size;

    void _mainloop() {

        while (window->isOpen()) {
            sf::Event ev;

            while (window->pollEvent(ev)) {
                if (ev.type == sf::Event::Closed) _fin();
            };

            window->clear();
            window->display();
        };
    };

    void _setup() {
        printl("| --- INICIO --- |");
    };
    void _fin() {
        window->close();
        printl("| -- FINAL -- |");
    };

public:
    Game(Vector2 _win_size) {
        win_size = _win_size;
        window = new sf::RenderWindow(sf::VideoMode(_win_size.x, win_size.y), "CBO");
    };
    ~Game() { delete window; };

    void run() {
        _setup();
        _mainloop();
    };
};