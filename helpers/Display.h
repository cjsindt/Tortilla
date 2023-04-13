#include <SFML/Graphics.hpp>

using namespace sf;



class Display{
    public:
        Display();

        void clear();

        void paint();

        bool isOpen();

        void setPixels(int x, int y, int * pix, int n);

    private:
        RenderWindow* window;
        std::vector< std::vector<RectangleShape> > pixels;
        int * pixels_int;

        bool XOR_Color(sf::Color ca, sf::Color cb);

};