#include "Display.h"

using namespace sf;

Display::Display(){
    window = new RenderWindow(VideoMode(640,320), "Tortilla");
    pixels = std::vector<std::vector<RectangleShape>>();
    for(int r = 0; r < 32; r++){
        pixels.push_back(std::vector<RectangleShape>());
        for(int c = 0; c < 64; c++){
            pixels[r].push_back(RectangleShape(Vector2f(10,10)));
            pixels[r][c].setPosition(Vector2f(c*10, r*10));
            pixels[r][c].setFillColor(Color(Color::Black));
            // if(c%2==0){
            //     pixels[r][c].setFillColor(Color(Color::Black));
            // } else {
            //     pixels[r][c].setFillColor(Color(Color::White));
            // }
        }
    }
}

void Display::clear(){
    window->clear();
}

void Display::paint(){
    for(int r = 0; r < pixels.size(); r++){
        for(int c = 0; c < pixels[r].size(); c++){
            window->draw(pixels[r][c]);
        }
    }
    window->display();
}

bool Display::isOpen(){
    return window->isOpen();
}

void Display::setPixels(int x, int y, int * pix, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 8; j++){
            if(pix[i+j] == 1){
                if(XOR_Color(Color(Color::White), pixels[i+x][j+y].getFillColor())){
                    pixels[i+x][j+y].setFillColor(Color::White);
                } else {
                    pixels[i+x][j+y].setFillColor(Color::Black);
                }
            }
        }
    }
}

bool Display::XOR_Color(sf::Color ca, sf::Color cb){
    if(ca.r == cb.r && ca.g == ca.g && ca.b == cb.b){
        return false;
    } else {
        return true;
    }
}

sf::RenderWindow * Display::getWindow(){
    return window;
}