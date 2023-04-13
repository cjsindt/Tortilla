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

void Display::setPixels(int x, int y, int * pix){

}