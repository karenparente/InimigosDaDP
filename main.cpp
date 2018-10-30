#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
using namespace std;

int main ()
{
    RenderWindow win(VideoMode(512, 512), "SFML Tutorial", Style::Resize | Style::Close);
    RectangleShape player(Vector2f(100.0f,100.0f));

    while (win.isOpen())
    {
        Event evnt;
        while (win.pollEvent(evnt))
        {

            switch (evnt.type)
            {
                case Event::Closed:
                    win.close();
                    break;

                case Event::Resized:
                    cout << "New window width: " << evnt.size.width << "New window height: " << evnt.size.height << endl;
                    break;

                case Event::TextEntered:
                    if (evnt.text.unicode < 128)
                    {
                        cout << (char)evnt.text.unicode << endl;
                    }
                    break;
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            player.move(-0.1, 0.0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            player.move(0.0, -0.1);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            player.move(0.0, 0.1);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            player.move(0.1, 0.0);
        }

        win.draw(player);
        win.display();

    }
    return 0;
}
