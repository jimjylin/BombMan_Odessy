#ifndef BOMB_H
#define BOMB_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collider.h"
class Bomb
{
public:
    Bomb(sf::Vector2f position, sf::Texture* BombImage, bool isLeft, sf::Vector2f InitialSpeed);
    ~Bomb();
    sf::Vector2f GetPosition() {return body.getPosition();}
    Collider GetCollider() {return Collider(body);}
    void Move(float dx, float dy);
    void Draw(sf::RenderWindow& window);
    void Update(float deltaTime);
    bool Explode(sf::Texture* ExplosionImaage, sf::Vector2f playerPosition);
    bool checkExploded() {return Exploded;}
    float passTime;


private:
    sf::Vector2f velocity;
    sf::RectangleShape body;
    sf::Vector2f start;
    bool isLeft;

    bool Exploded;

};

#endif // BOMB_H
