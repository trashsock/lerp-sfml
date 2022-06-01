#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#define pi 3.14159265


const int windowx = 1000.f;
const int windowy = 1000.f;


struct Answer1 {
    float lerp(float u, float v, float t) 
    {
        return (1.0f - t) * u + t * v;
    }

    void run(sf::RenderWindow& w) {
            //for shape, colour and pos
        sf::CircleShape wow;
        float radius = 40.0f;
        wow.setRadius(radius);
        wow.setFillColor(sf::Color(0,204,204));
        wow.setOrigin(sf::Vector2f(radius, radius));
            //for direction and velocity
        sf::CircleShape wowz;
        float radius2 = 20.0f;
        wowz.setRadius(radius2);
        wowz.setFillColor(sf::Color(255, 51, 255));
        wowz.setOrigin(sf::Vector2f(radius2, radius2));

        sf::Clock clock;
        clock.restart();
        float t = 0.0f;
        float sign = 1.0f;

        w.setFramerateLimit(60);

        while (w.isOpen())
        {
            sf::Event event;
            while (w.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    w.close();

                if (event.type == sf::Event::KeyPressed) {
                    return;
                }

            }

            float dt = clock.restart().asSeconds();

            t += dt * sign;
            if (t > 1.0f) {
                sign = -sign;
                t = 1.0f;  
            }

            if (t < 0.0f) {
                sign = -sign;
                t = 0.0f; 
            }

            float pos1x = 100.0f;
            float pos1y = 200.0f;
            float size1 = 10.0;
            float colour1 = 0.0f;
            float vel1x = 50.f;
            float vel1y = 50.f;
            float accel1 = 0.1f;

            float pos2x = 500.0f;
            float pos2y = 400.0f;
            float size2 = 200.0f;
            float colour2 = 1.0f;
            float vel2x = 300.f;
            float vel2y = 300.f;
            float accel2 = 50.f;

            float posx = lerp(pos1x, pos2x, t);
            float posy = lerp(pos1y, pos2y, t);
            float size = lerp(size1, size2, t);
            float colour = lerp(colour1, colour2, t);
            float velx = lerp(vel1x, vel1y, t);
            float vely = lerp(vel2x, vel2y, t);
            float accel = lerp(accel1, accel2, t);

            w.clear();            
            posx += velx * dt;
            posy += vely * dt;
            float wowzposx = 500.f + (350.0f) * cos(-dt * accel);
            float wowzposy = 500.f + (350.0f) * sin(-dt * accel);
            wow.setPosition(posx, posy);
            wowz.setPosition(wowzposx, wowzposy);
            wow.setRadius(size);
            wow.setFillColor(sf::Color((255.0f * colour), 255, 153, 255));
            w.draw(wow);
            w.draw(wowz);
            w.display();
        }
    }
};


struct Answer2 {
    float lerp(float u, float v, float t)
    {
        return (1.0f - t) * u + t * v;
    }
    float sstep3(float t) {
        return t * t * (3.0 - 2.0f * t);
    }

    void run(sf::RenderWindow& w) {
            //for shape, size and pos
        sf::CircleShape wow1;
        float radius = 40.0f;
        wow1.setRadius(radius);
        wow1.setFillColor(sf::Color(255, 108, 172));
        wow1.setOrigin(sf::Vector2f(radius, radius));
        wow1.setPosition(200, 200);
            //for direction and velocity
        sf::CircleShape wowz1;
        float radius2 = 20.0f;
        wowz1.setRadius(radius2);
        wowz1.setFillColor(sf::Color(204, 0, 0));
        wowz1.setOrigin(sf::Vector2f(radius2, radius2));

        sf::Clock clock;
        clock.restart();
        float t = 0.0f;
        float sign = 1.0f;

        w.setFramerateLimit(60);

        while (w.isOpen())
        {
            sf::Event event;
            while (w.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    w.close();

                if (event.type == sf::Event::KeyPressed) {
                    return;
                }

            }

            float dt = clock.restart().asSeconds();

            t += dt * sign;
            if (t > 1.0f) {
                sign = -sign;
                t = 1.0f;
            }

            if (t < 0.0f) {
                sign = -sign;
                t = 0.0f;
            }

            float pos1x = 100.0f;
            float pos1y = 200.0f;
            float size1 = 10.0;
            float colour1 = 0.0f;
            float vel1x = 500.f;
            float vel1y = 500.f;
            float accel1 = 0.1f;

            float pos2x = 500.0f;
            float pos2y = 400.0f;
            float size2 = 200.0f;
            float colour2 = 1.0f;
            float vel2x = 1500.f;
            float vel2y = 1500.f;
            float accel2 = 50.f;

            float posx = lerp(pos1x, pos2x, sstep3(t));
            float posy = lerp(pos1y, pos2y, sstep3(t));
            float size = lerp(size1, size2, sstep3(t));
            float colour = lerp(colour1, colour2, sstep3(t));
            float velx = lerp(vel1x, vel1y, sstep3(t));
            float vely = lerp(vel2x, vel2y, sstep3(t));
            float accel = lerp(accel1, accel2, sstep3(t));

            w.clear();
            posx += velx * dt;
            posy += vely * dt;
            float wowzposx = 500.f + (350.0f) * cos(-dt * accel);
            float wowzposy = 500.f + (350.0f) * sin(-dt * accel);
            wow1.setPosition(posx, posy);
            wowz1.setPosition(wowzposx, wowzposy);
            wow1.setRadius(size);
            wow1.setFillColor(sf::Color((255.0f * colour), 255, 5, 255));
            w.draw(wow1);
            w.draw(wowz1);
            w.display();
        }
    }
};

struct Answer3 {
    // t = 0..1
    sf::Vector2f cubicBezier(sf::Vector2f p0, sf::Vector2f c0, sf::Vector2f c1, sf::Vector2f p1, float t) 
    {
        return (1.0f - t) * (1.0f - t) * (1.0f - t) * p0 +
            3.0f * (1.0f - t) * (1.0f - t) * t * c0 +
            3.0f * (1.0f - t) * t * t * c1 +
            t * t * t * p1;
    }
    // t = 0..1
    sf::Vector2f cubicBezierVel(sf::Vector2f p0, sf::Vector2f v0, sf::Vector2f p1, sf::Vector2f v1, float t) 
    {
        sf::Vector2f c0 = p0 + 1.0f / 3.0f * v0;
        sf::Vector2f c1 = p1 - 1.0f / 3.0f * v1;

        return cubicBezier(p0, c0, c1, p1, t);
    }


    void run(sf::RenderWindow& w) {

        sf::CircleShape planet1;
        float radius1 = 40.0f;
        planet1.setRadius(radius1);
        planet1.setFillColor(sf::Color(0, 102, 204));
        planet1.setOrigin(sf::Vector2f(radius1, radius1));
        planet1.setPosition(windowx / 2.f, windowy / 2.f);

        sf::CircleShape planet2;
        float radius2 = 50.0f;
        planet2.setRadius(radius2);
        planet2.setFillColor(sf::Color(255, 128, 0));
        planet2.setOrigin(sf::Vector2f(radius2, radius2));
        planet2.setPosition(windowx / 2.f, windowy / 2.f);

        sf::CircleShape moon;
        float radiusM = 30.0f;
        moon.setRadius(radiusM);
        moon.setFillColor(sf::Color(192, 192, 192));
        moon.setOrigin(sf::Vector2f(radiusM, radiusM));
        moon.setPosition(windowx / 2.f, windowy / 2.f);

        sf::Clock clock;
        clock.restart();
        float t = 0.0f;

        w.setFramerateLimit(60);

        while (w.isOpen())
        {
            sf::Event event;
            while (w.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    w.close();

                if (event.type == sf::Event::KeyPressed) {
                    return;
                }

            }

            float time = clock.restart().asSeconds();
            t += time;

            float planet1x = (windowx / 2.f) + (370.0f) * cos(t * 0.6 * pi);
            float planet1y = (windowy / 2.f) + (370.0f) * sin(t * 0.6 * pi);
            planet1.setPosition(planet1x, planet1y);

            //sf::Vector2f planet2x = cubicBezier(10.f, 1.f, 5.f, 20.f, time) + cubicBezierVel(10.f, 1.f, 5.f, 20.f, time) * t;
            
            w.clear();
            w.draw(planet1);
            w.draw(planet2);
            w.draw(moon);
            w.display();
        }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowx, windowy), "idk bro i give up");

    int answer = 1;

    Answer1 answer1;
    Answer2 answer2;
    Answer3 answer3;

    while (window.isOpen()) 
    {
        switch (answer) 
        {
            case 1: answer1.run(window); break;
            case 2: answer2.run(window); break;
            case 3: answer3.run(window); break;
        }

        answer += 1;
        if (answer > 3) answer = 1;
    }

    return 0;
}
