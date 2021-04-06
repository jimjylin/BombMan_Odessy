#include "Bomb.h"
#include <cmath>
const int BombSpeed = 300;
Bomb::Bomb(sf::Vector2f position, sf::Texture* BombImage, bool isLeft, sf::Vector2f InitialSpeed)
{
    body.setSize(sf::Vector2f(40.0f,40.0f));
    body.setOrigin(20.0, 20.0);
    body.setPosition(position);
    body.setTexture(BombImage);
    this->start = position;
    this->isLeft = isLeft;
    velocity.x = abs(InitialSpeed.x)+(BombSpeed*sqrt(3));
    velocity.y = -BombSpeed;
    Exploded = false;
    passTime = 0.0f;

}
Bomb::~Bomb()
{

}
void Bomb::Move(float dx, float dy)
{
}
void Bomb::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}
void Bomb::Update(float deltaTime)
{
    if(Exploded)
    {
        velocity.x = 0;
        velocity.y = 0;
    }
    else
    {
        int a = 1;
        if(isLeft)
        {
            velocity.x = -abs(velocity.x);

        }
        else
        {

        }

        velocity.y += deltaTime*981;
    }

    body.move(velocity*deltaTime);
}
bool Bomb::Explode(sf::Texture* ExplosionImage, sf::Vector2f playerPosition)
{
    Exploded = true;
    body.setSize(sf::Vector2f(80.0f, 80.0f));
    body.setTexture(ExplosionImage);

    sf::Vector2f otherHalfSize(50.0f, 50.0f);
    sf::Vector2f thisPosition = body.getPosition();
    sf::Vector2f thisHalfSize(40.0f, 40.0f);

    float deltaX = playerPosition.x - thisPosition.x;
    float deltaY = playerPosition.y - thisPosition.y;
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(intersectX<0.0f&&intersectY<0.0f)
        return true;

    else
        return false;
}
