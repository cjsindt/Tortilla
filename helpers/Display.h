#include <SFML/Graphics.hpp>

using namespace sf;

class Display{
    public:
        Display();

        void Clear();

    private:
        RenderWindow* window;

};