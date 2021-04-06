#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collider.h"
#include "Animation.h"
class Player
{
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, int id, sf::Sound Jump);
    ~Player();
    sf::Vector2f GetPosition() {return body.getPosition();}
    Collider GetCollider() {return Collider(body);}
    void Update(float deltaTime, bool isthr);
    void Draw(sf::RenderWindow& window);
    void OnCollision(sf::Vector2f direction);
    bool GetIsLeft() {return faceLeft;}
    void Damage();
    bool CheckisLive() {return isLive;}
    void setColor() {body.setFillColor(sf::Color::Red);}
    sf::Vector2f GetVelocity() {return velocity;}
    sf::Sound Jump;
    void Revive();

private:
    bool isLive;
    int Life;
    sf::RectangleShape body;
    Animation animation;
    int row;
    float speed;
    bool faceLeft;
    int id;
    float jumpHeight;
    sf::Vector2f velocity;
    bool canJump;
    sf::Texture* texture;
    //sf::IntRect bodyRect;

};

#endif // PLAYER_H
