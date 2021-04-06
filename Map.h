#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <vector>
#include "Platform.h"
using namespace std;
void Initialize(vector <Platform>& Map, int a)
{
    if(a==0)
    {
        Platform pf1(nullptr, sf::Vector2f(1600.0f, 25.0f), sf::Vector2f(800.0f, 1000.0f));
        Map.push_back(pf1);

        Platform pf2(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(100.0f, 150.0f));
        Map.push_back(pf2);

        Platform pf3(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(1500.0f, 150.0f));
        Map.push_back(pf3);

        Platform pf35(nullptr, sf::Vector2f(25.0f, 150.0f), sf::Vector2f(800.0f, 225.0f));
        Map.push_back(pf35);

        Platform pf4(nullptr, sf::Vector2f(1000.0f, 25.0f), sf::Vector2f(800.0f, 300.0f));
        Map.push_back(pf4);

        Platform pf5(nullptr, sf::Vector2f(300.0f, 25.0f), sf::Vector2f(150.0f, 450.0f));
        Map.push_back(pf5);

        Platform pf6(nullptr, sf::Vector2f(300.0f, 25.0f), sf::Vector2f(1450.0f, 450.0f));
        Map.push_back(pf6);

        Platform pf7(nullptr, sf::Vector2f(300.0f, 25.0f), sf::Vector2f(800.0f, 600.0f));
        Map.push_back(pf7);

        Platform pf8(nullptr, sf::Vector2f(25.0f, 125.0f), sf::Vector2f(650.0f, 550.0f));
        Map.push_back(pf8);

        Platform pf9(nullptr, sf::Vector2f(25.0f, 125.0f), sf::Vector2f(950.0f, 550.0f));
        Map.push_back(pf9);

        Platform pf10(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(300.0f, 600.0f));
        Map.push_back(pf10);

        Platform pf11(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(1300.0f, 600.0f));
        Map.push_back(pf11);

        Platform pf12(nullptr, sf::Vector2f(400.0f, 25.0f), sf::Vector2f(300.0f, 750.0f));
        Map.push_back(pf12);

        Platform pf13(nullptr, sf::Vector2f(400.0f, 25.0f), sf::Vector2f(1300.0f, 750.0f));
        Map.push_back(pf13);

        Platform pf14(nullptr, sf::Vector2f(1.0f, 1500.0f), sf::Vector2f(0.0f, 500.0f));
        Map.push_back(pf14);

        Platform pf15(nullptr, sf::Vector2f(1.0f, 1500.0f), sf::Vector2f(1600.0f, 500.0f));
        Map.push_back(pf15);

        Platform pf16(nullptr, sf::Vector2f(300.0f, 25.0f), sf::Vector2f(800.0f, 900.0f));
        Map.push_back(pf16);
    }
    else if(a==1)
    {
        Platform pf21(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(400.0f, 150.0f));
        Map.push_back(pf21);

        Platform pf22(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(1200.0f, 150.0f));
        Map.push_back(pf22);

        Platform pf23(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(400.0f, 300.0f));
        Map.push_back(pf23);

        Platform pf24(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(1200.0f, 300.0f));
        Map.push_back(pf24);

        Platform pf25(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(400.0f, 450.0f));
        Map.push_back(pf25);

        Platform pf26(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(1200.0f, 450.0f));
        Map.push_back(pf26);

        Platform pf27(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(400.0f, 600.0f));
        Map.push_back(pf27);

        Platform pf28(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(1200.0f, 600.0f));
        Map.push_back(pf28);

        Platform pf29(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(400.0f, 750.0f));
        Map.push_back(pf29);

        Platform pf210(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(1200.0f, 750.0f));
        Map.push_back(pf210);

        Platform pf211(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(400.0f, 900.0f));
        Map.push_back(pf211);

        Platform pf212(nullptr, sf::Vector2f(200.0f, 25.0f), sf::Vector2f(1200.0f, 900.0f));
        Map.push_back(pf212);

        Platform pf214(nullptr, sf::Vector2f(25.0f, 1500.0f), sf::Vector2f(300.0f, 500.0f));
        Map.push_back(pf214);

        Platform pf215(nullptr, sf::Vector2f(25.0f, 1500.0f), sf::Vector2f(1300.0f, 500.0f));
        Map.push_back(pf215);
    }
    else if(a==2)
    {
        Platform pf31(nullptr, sf::Vector2f(20.0f, 300.0f), sf::Vector2f(250.0f, 1000.0f));
        Map.push_back(pf31);

        Platform pf351(nullptr, sf::Vector2f(20.0f, 300.0f), sf::Vector2f(1350.0f, 1000.0f));
        Map.push_back(pf351);

        Platform pf32(nullptr, sf::Vector2f(250.0f, 25.0f), sf::Vector2f(800.0f, 200.0f));
        Map.push_back(pf32);

        Platform pf33(nullptr, sf::Vector2f(300.0f, 25.0f), sf::Vector2f(800.0f, 300.0f));
        Map.push_back(pf33);

        Platform pf34(nullptr, sf::Vector2f(350.0f, 25.0f), sf::Vector2f(800.0f, 400.0f));
        Map.push_back(pf34);

        Platform pf335(nullptr, sf::Vector2f(400.0f, 25.0f), sf::Vector2f(800.0f, 500.0f));
        Map.push_back(pf335);

        Platform pf36(nullptr, sf::Vector2f(450.0f, 25.0f), sf::Vector2f(800.0f, 600.0f));
        Map.push_back(pf36);

        Platform pf37(nullptr, sf::Vector2f(500.0f, 25.0f), sf::Vector2f(800.0f, 700.0f));
        Map.push_back(pf37);

        Platform pf38(nullptr, sf::Vector2f(550.0f, 25.0f), sf::Vector2f(800.0f, 800.0f));
        Map.push_back(pf38);

        Platform pf39(nullptr, sf::Vector2f(600.0f, 25.0f), sf::Vector2f(800.0f, 900.0f));
        Map.push_back(pf39);

        Platform pf310(nullptr, sf::Vector2f(1600.0f, 25.0f), sf::Vector2f(800.0f, 1000.0f));
        Map.push_back(pf310);

        Platform pf311(nullptr, sf::Vector2f(25.0f, 1000.0f), sf::Vector2f(800.0f, 600.0f));
        Map.push_back(pf311);

        Platform pf314(nullptr, sf::Vector2f(1.0f, 1500.0f), sf::Vector2f(0.0f, 500.0f));
        Map.push_back(pf314);

        Platform pf315(nullptr, sf::Vector2f(1.0f, 1500.0f), sf::Vector2f(1600.0f, 500.0f));
        Map.push_back(pf315);
    }
}


#endif // MAP_H_INCLUDED
