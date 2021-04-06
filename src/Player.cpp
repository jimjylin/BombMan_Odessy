#include "Player.h"
const float Gravity = 981.0f;
const float JumpHeight = 200.0f;
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, int id, sf::Sound Jump):
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    this->id = id;
    this->Jump = Jump;
    this->texture = texture;
    row = 0;
    faceLeft = true;
    if(id==1)
    {
        body.setPosition(400.0f, 100.0f);
        faceLeft = false;
    }

    else if(id==2)
    {
        body.setPosition(1200.0f, 100.0f);
        faceLeft = true;
        body.setFillColor(sf::Color::Red);
    }

    else if(id==3)
    {
        body.setPosition(400.0f, 400.0f);
        faceLeft = false;
        body.setFillColor(sf::Color::Blue);
    }

    else if(id==4)
    {
        body.setPosition(1200.0f, 400.0f);
        faceLeft = true;
        body.setFillColor(sf::Color::Yellow);
    }


    body.setTexture(texture);
    body.setSize(sf::Vector2f(50,100));
    //bodyRect.width = 50.0f;
    //bodyRect.height = 100.0f;
    body.setOrigin(body.getSize()/2.0f);
    Life = 1;
    isLive = true;


}
Player::~Player()
{

}
void Player::Update(float deltaTime, bool isthr)
{
    int a = 1;
    velocity.x *= 0.0f;

    if(id==1)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        a=3;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            velocity.x-=speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            velocity.x+=speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
        {
            canJump = false;
            velocity.y = -sqrt(2.0f*Gravity*jumpHeight);
            Jump.play();
        }
    }
    else if(id==2)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            velocity.x-=speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            velocity.x+=speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)
        {
            canJump = false;
            velocity.y = -sqrt(2.0f*Gravity*jumpHeight);
            Jump.play();
        }

    }
    else if(id==3)
    {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            velocity.x-=speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
            velocity.x+=speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::T) && canJump)
        {
            canJump = false;
            velocity.y = -sqrt(2.0f*Gravity*jumpHeight);
            Jump.play();
        }
    }
    else if(id==4)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
            velocity.x-=speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            velocity.x+=speed;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && canJump)
        {
            canJump = false;
            velocity.y = -sqrt(2.0f*Gravity*jumpHeight);
            Jump.play();
        }
    }
    if(body.getPosition().y>1100.0f)
    {
        isLive = false;
    }
    velocity.y+=981.0f*deltaTime;

    if(isthr)
    {
        row = 0;
    }
    else if(velocity.x==0.0f)
    {
        row = 2;
    }
    else
    {
        row = 1;
        if(velocity.x>0.0f)
            faceLeft = false;
        else
            faceLeft = true;
    }
    if(isLive)
    {
        animation.Update(row, deltaTime, faceLeft);
        body.setTextureRect(animation.uvRect);
        body.move(deltaTime*velocity);
    }
    else
    {

        //body.setTextureRect(bodyRect);
    }

}
void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}
void Player::OnCollision(sf::Vector2f direction)
{
    if(direction.x<0.0f)
    {
        velocity.x = 0.0f;
    }
    else if(direction.x>0.0f)
    {
        velocity.x = 0.0f;
    }
    if(direction.y<0.0f)
    {
        velocity.y = 0.0f;
        canJump = true;
    }
    else if(direction.y>0.0f)
    {
        velocity.y = 0.0f;

    }
}
void Player::Damage()
{
    Life--;
    if(Life<=0)
    {
        isLive = false;
    }
}
void Player::Revive()
{
    isLive = true;
    if(id==1)
        body.setPosition(400.0f, 100.0f);
    else if(id==2)
        body.setPosition(1200.0f, 100.0f);
    else if(id==3)
        body.setPosition(400.0f, 300.0f);
    else if(id==4)
        body.setPosition(1200.0f, 300.0f);
    body.setTexture(texture);
    velocity.y = 0.0f;
}
