#include <SFML/Graphics.hpp>

using namespace sf;



class Display{
    public:
        Display();

        void clear();

        void paint();

        bool isOpen();

    private:
        RenderWindow* window;
        std::vector< std::vector<RectangleShape> > pixels;

};