#include <SFML/Graphics.hpp>
#include <optional>
#include "objects.h"
#include "Physics.h"
#include "Solver.h"
#include <vector>


int main()
{
    //basic sfml stuff
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "My Program");
    window.setFramerateLimit(60);

    //Creating and setting values for our objects
    GravitySource sun(500000.0, 960, 540);
    GravityParticle earth(1.0, 1260, 540, 0, -22);// eart mass doesnt matter for calculations so we just give 1 and scale K and sun mass accordingly 

    sf::CircleShape S;
    sf::CircleShape P;

    S.setRadius(30);
    S.setFillColor(sf::Color::Yellow);
    S.setOrigin({ 30,30 });
    S.setPosition({ static_cast<float>(sun.Position_X),static_cast<float>(sun.Position_Y) });

    P.setRadius(8);
    P.setFillColor(sf::Color::Blue);
    P.setOrigin({ 8,8 });
    P.setPosition({ static_cast<float>(earth.Position_X),static_cast<float>(earth.Position_Y)});

    //Handling Step size
    double t = 0;
    double h = 0.5;

   //handling Orbit visualization 
    std::vector<sf::Vertex> trail;




    //Displaying stuff
    while (window.isOpen())
    {
        //basic sfml stuff used to close the window when we press escape or press "x"
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }

        //The Physics
        State s = { earth.Position_X , earth.Position_Y , earth.Velocity_X , earth.Velocity_Y };

        s = RK4(equation, h, t, s, sun);
        //s = euler(equation, h, t, s, sun);

        //we visualize the orbit by basically creating a list of points where "earth" has been and connect those points(done in window.draw())
        sf::Vertex point;
        point.position = sf::Vector2f(static_cast<float>(earth.Position_X),static_cast<float>(earth.Position_Y));
        point.color = sf::Color::Cyan;
        trail.push_back(point);
        

        //update our "state" 
        earth.Position_X = s[0];
        earth.Position_Y = s[1];
        earth.Velocity_X = s[2];
        earth.Velocity_Y = s[3];

        t += h;
        //tie-up the updated state with whats on the display
        P.setPosition({ static_cast<float>(earth.Position_X),static_cast<float>(earth.Position_Y) });


        //Finally to draw on the screen
        window.clear();

        window.draw(trail.data(), trail.size(), sf::PrimitiveType::LineStrip);//sf::PrimitiveType::LineStrip does the "connecting dots mentioned earlier
        window.draw(S);
        window.draw(P);

        window.display();
    }
}


