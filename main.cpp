#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */
#include "Player.h"
#include "Collider.h"
#include "Animation.h"
#include "Bomb.h"
#include "Platform.h"
#include "Map.h"
using namespace std;
const double path = 1;
static const float VIEW_HEIGHT = 512.0f;
const int BombSpeed = 300;
const float Gravity = 981.0f;
const float JumpHeight = 200.0f;



int main()
{
    //sf::View view(sf::Vector2f(0.0f,0.0f), sf::Vector2f(512.0f, 512.0f));
    int playernum = 0;
    cin >> playernum;
    while(playernum<2||playernum>4)
    {
        cout << "87" << endl;
        cin >> playernum;
    }
    int Map = 1;
    int win = 0;
    srand( time(NULL) );
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Bomb Man Odyssey");

    sf::Texture test;
    sf::Texture BombImage;
    sf::Texture ExplosionImage;
    sf::Texture DeathImage;
    sf::Texture BackGround;
    sf::Sprite BackGroundImage;
    sf::Texture GAMEOVER;
    sf::Sprite GAMEOVERImage;
    sf::Texture GAMEOVERL;
    sf::Sprite GAMEOVERLImage;

    sf::SoundBuffer JumpBf;
    sf::Sound Jump;
    if(!JumpBf.loadFromFile("Jump.ogg"))
        std::cout << 0;
    Jump.setBuffer(JumpBf);

    sf::SoundBuffer ThrowBf;
    sf::Sound Throw;
    Jump.setVolume(30);
    if(!ThrowBf.loadFromFile("Throw.ogg"))
        std::cout << 0;
    Throw.setBuffer(ThrowBf);

    sf::SoundBuffer ExplosionBf;
    sf::Sound Explosion;
    if(!ExplosionBf.loadFromFile("Explosion.ogg"))
        std::cout << 0;
    Explosion.setBuffer(ExplosionBf);



    if(!BackGround.loadFromFile("BackGround.png"))
        std::cout << 0;
    if(!GAMEOVER.loadFromFile("GAMEOVER.png"))
        std::cout << 0;
    if(!GAMEOVERL.loadFromFile("GAMEOVERL.png"))
        std::cout << 0;
    BackGroundImage.setTexture(BackGround);
    GAMEOVERImage.setTexture(GAMEOVER);
    GAMEOVERLImage.setTexture(GAMEOVERL);
    BackGroundImage.setScale((16.0f/25.6f), (10.0f/19.2f));
    GAMEOVERImage.setScale((16.0f/25.6f), (10.0f/19.2f));
    GAMEOVERLImage.setScale((16.0f/25.6f), (10.0f/19.2f));



    test.loadFromFile("qq2.png");
    BombImage.loadFromFile("BombImage.png");
    ExplosionImage.loadFromFile("Explosion.png");
    DeathImage.loadFromFile("death.png");

    vector <Player> players;
    for(int i = 0;i<playernum;i++)
    {
        Player temp(&test, sf::Vector2u(8,3), 0.15f, 300.0f,JumpHeight, i+1, Jump);
        players.push_back(temp);
    }

    vector<vector<Bomb> > Bombs;
    for(int i = 0;i<playernum;i++)
    {
        vector<Bomb> temp;
        Bombs.push_back(temp);
    }
    bool thr[4] = {false};
    float thrTime[4] = {0.0f};

    float deathTime = 0.0f;
    vector<vector<Platform> > maps;
    for(int i = 0;i<3;i++)
    {
        vector<Platform> temp;
        Initialize(temp,i);
        maps.push_back(temp);
    }
    std::vector<Platform> map1;
    Initialize(map1,0);

    std::vector<Platform> map2;
    Initialize(map2,1);

    std::vector<Platform> map3;
    Initialize(map3,2);






    bool isPlaying = false;
    float deltaTime = 0.0f;
    sf::Clock clock;
    double totalT = 0;
    float cd[4] = {0.0f};
    while(window.isOpen())
    {
        isPlaying = true;
        deltaTime = clock.restart().asSeconds();
        for(int i = 0;i<playernum;i++)
        {
            cd[i]+=deltaTime;
        }


        if(deltaTime>1.0f/20.0f)
            deltaTime = 1.0f/20.0f;



        sf::Event evnt;
        while(window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                //ResizeView(window, view);
                break;
            case sf::Event::TextEntered:
                if(evnt.text.unicode=='a')
                    //std::cout << "weeeeeeee";
                break;
            case sf::Event::KeyPressed:

                break;

            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && cd[0]>0.75f )
        {
            if(!players[0].CheckisLive())
                break;
            cd[0] = 0;
            Bomb temp(players[0].GetPosition(), &BombImage, players[0].GetIsLeft(), players[0].GetVelocity());
            Bombs[0].push_back(temp);
            Throw.play();
            thr[0] = true;

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && cd[1]>0.75f )
        {
            if(!players[1].CheckisLive())
                break;
            cd[1] = 0;
            Bomb temp(players[1].GetPosition(), &BombImage, players[1].GetIsLeft(), players[1].GetVelocity());
            Bombs[1].push_back(temp);
            Throw.play();
            thr[1] = true;
        }
        if(playernum>=3 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M) && cd[2]>0.75f )
        {
            if(!players[2].CheckisLive())
                break;
            cd[2] = 0;
            Bomb temp(players[2].GetPosition(), &BombImage, players[2].GetIsLeft(), players[2].GetVelocity());
            Bombs[2].push_back(temp);
            Throw.play();
            thr[2] = true;
        }
        if(playernum>=4 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Slash) && cd[3]>0.75f )
        {
            cout <<"here";
            if(!players[3].CheckisLive())
                break;
            cd[3] = 0;
            Bomb temp(players[3].GetPosition(), &BombImage, players[3].GetIsLeft(), players[3].GetVelocity());
            Bombs[3].push_back(temp);
            Throw.play();
            thr[3] = true;
        }
        for(int i = 0;i<playernum;i++)
        {
            if(thr[i])
            {
                thrTime[i]+=deltaTime;
            }
            if(thrTime[i]>0.40f)
            {
                thr[i] = false;
                thrTime[i] = 0.0f;
            }
        }

        for(int i = 0;i<playernum;i++)
        {
            players[i].Update(deltaTime, thr[i]);
        }

        vector <Collider> Colliders;
        for(int i = 0;i<playernum;i++)
        {
            Collider temp(players[i].GetCollider());
            Colliders.push_back(temp);
        }
        sf::Vector2f directions[4];

        for(int i = 0;i<playernum;i++)
        {
            for(int j = 0;j<maps[Map-1].size();j++)
            {
                if(maps[Map-1][j].GetCollider().CheckCollision(Colliders[i], directions[i], 1.0f))
                {
                    players[i].OnCollision(directions[i]);
                }
            }
        }




        //view.setCenter(player.GetPosition());
        window.clear();
        //window.setView(view);
        window.draw(BackGroundImage);

        for(int i = 0;i<maps[Map-1].size();i++)
        {
            for(int k = 0;k<playernum;k++)
            {
                for(int j = 0;j<Bombs[k].size();j++)
                {
                    Collider temp(Bombs[k][j].GetCollider());
                    if(maps[Map-1][i].GetCollider().CheckCollision(temp, directions[k], 1.0f)&&!Bombs[k][j].checkExploded())
                    {
                        Explosion.play();
                        for(int l = 0;l<playernum;l++)
                        {
                            if(l==k)
                                continue;
                            if(Bombs[k][j].Explode(&ExplosionImage, players[l].GetPosition()))
                                players[l].Damage();
                        }

                    }

                    if(Bombs[k][j].checkExploded())
                    {
                        Bombs[k][j].passTime+=deltaTime;
                        if(Bombs[k][j].passTime>1.0f)
                        Bombs[k].erase(Bombs[k].begin()+j);
                    }
                }
            }
        }
        for(int i = 0;i<playernum;i++)
        {
            for(int j = 0;j<Bombs[i].size();j++)
            {
                Bombs[i][j].Update(deltaTime);
            }
        }
        int stillAlive = 0;
        int survivor = 0;
        for(int i = 0;i<playernum;i++)
        {
            if(players[i].CheckisLive())
            {
                stillAlive++;
                survivor = i;
            }

        }


        if(stillAlive>1||deathTime<=1.0f)
        {
            for(int i = 0;i<maps[Map-1].size();i++)
            {
                maps[Map-1][i].Draw(window);
            }

            for(int i = 0;i<playernum;i++)
            {
                for(int j = 0;j<Bombs[i].size();j++)
                {
                    Bombs[i][j].Draw(window);
                }
            }

            for(int i = 0;i<playernum;i++)
            {
                if(players[i].CheckisLive())
                players[i].Draw(window);
                else
                {
                    sf::RectangleShape temp;
                    temp.setPosition(sf::Vector2f(players[i].GetPosition().x, players[i].GetPosition().y+15.0f));
                    temp.setSize(sf::Vector2f(50.0f, 70.0f));
                    temp.setOrigin(sf::Vector2f(25.0f, 35.0f));
                    temp.setTexture(&DeathImage);

                    if(i==1)
                        temp.setFillColor(sf::Color::Red);
                    else if(i==2)
                        temp.setFillColor(sf::Color::Blue);
                    else if(i==3)
                        temp.setFillColor(sf::Color::Yellow);

                    window.draw(temp);
                }
            }
        }
        if(stillAlive<2)
        {
            win = survivor+1;
        }

        for(int i = 0;i<playernum;i++)
        {
            if(win==i+1)
            {
                deathTime+=deltaTime;
                if(deathTime>=1.0f)
                {
                    window.draw(GAMEOVERLImage);
                    isPlaying = false;
                }
            }
        }


        /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)&&(!isPlaying))
        {
            win = 0;
            isPlaying = true;
            deathTime = 0;
            for(int i = 0;i<playernum;i++)
            {
                players[i].Revive();
                Bombs[i].clear();
            }
            Map = 1;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)&&(!isPlaying))
        {
            win = 0;
            isPlaying = true;
            deathTime = 0;
            for(int i = 0;i<playernum;i++)
            {
                players[i].Revive();
                Bombs[i].clear();
            }
            Map = 2;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)&&(!isPlaying))
        {
            win = 0;
            isPlaying = true;
            deathTime = 0;
            for(int i = 0;i<playernum;i++)
            {
                players[i].Revive();
                Bombs[i].clear();
            }
            Map = 3;
        }*/
        if((!isPlaying) && deathTime>=2.0f)
        {
            win = 0;
            isPlaying = true;
            deathTime = 0;
            for(int i = 0;i<playernum;i++)
            {
                players[i].Revive();
                Bombs[i].clear();
            }
            Map = rand()%3+1;
        }
        window.display();
    }
    return 0;
}
