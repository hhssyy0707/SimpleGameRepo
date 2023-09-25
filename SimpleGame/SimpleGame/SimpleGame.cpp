#include "SimpleGame.h"
#include "Game1.h"
#include <iostream>
using namespace std;

int main()
{
    //Window창 생성, 크기, 타이틀 스타일 정의
    /*********************************************/
    /*********************************************
    RenderWindow FirstWindow(VideoMode(1024,768), "Simple Game made by SY", Style::Titlebar|Style::Close);
    Event event1;

    while (FirstWindow.isOpen()) {
        while (FirstWindow.pollEvent(event1)) {
            switch (event1.type) {
            case Event::Closed:
                FirstWindow.close();
                break;
            case Event::KeyPressed:
                if (event1.key.code == Keyboard::Escape) {
                    FirstWindow.close();
                }
            }
        }
        FirstWindow.clear(Color(155,150,150,255));
        //FirstWindow.clear(Color::Cyan);

        FirstWindow.display();

    }
    /*********************************************/
    /*********************************************

    Game1 simpleGame1;

    while (simpleGame1.isOpenFunc()) {
        simpleGame1.eventPoll();
        //FirstWindow.clear(Color::Cyan);
        //FirstWindow.display();
    }
    **********************************************/
    /*********************************************/

    //230925
    //윈도우창 띄우기

    //SimpleWindow();

    Game1 SimpleGame;

    //Game Loop
    while (SimpleGame.Running())
    {
        SimpleGame.EventHandler();
        SimpleGame.Update();
        SimpleGame.Render();

    }
    
}

