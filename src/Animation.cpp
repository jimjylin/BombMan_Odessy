#include "Animation.h"
Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}
Animation::~Animation()
{

}
void Animation::Update(int row , float deltaTime, bool faceLeft)
{
    currentImage.y = row;
    totalTime += deltaTime;
    float a = 0;
    if(row==2)
    a = 0.05f;
    else if(row==0)
    a = 0.3f;
    if(row==0&&currentImage.x!=2)
    {
        currentImage.x = 2;
    }
    if(totalTime >= switchTime+a)
    {
        totalTime -= (switchTime+a);
        currentImage.x+=2;

        if(currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
        }
    }


    uvRect.top = currentImage.y * uvRect.height;
    if(faceLeft)
    {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (currentImage.x+1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}
