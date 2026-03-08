#include <iostream>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

int main() {
    int sides;
    std::cout << "Enter sides: ";
    std::cin >> sides;

    if (sides < 3) {
        std::cerr << "Shape needs 3+ sides" << std::endl;
        return 1;
    }

    const int width = 400;
    const int height = 400;
    const float cx = width / 2.0f;
    const float cy = height / 2.0f;
    const float r = 120.0f;

    sf::RenderWindow window(sf::VideoMode(width, height), "Convert Sides to Shape");
    window.clear(sf::Color::White);

    sf::VertexArray polygon(sf::LineStrip, sides + 1);

    for (int i = 0; i <= sides; ++i) {
        float angle = i * 2 * M_PI / sides;
        float x = cx + r * std::cos(angle);
        float y = cy + r * std::sin(angle);
        polygon[i].position = sf::Vector2f(x, y);
        polygon[i].color = sf::Color::Black;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(polygon);
        window.display();
    }

    return 0;
}
