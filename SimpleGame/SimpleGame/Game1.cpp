#include "Game1.h"

void Game1::InitVariable()
{
	//int a = 0;
	this->window1 = nullptr; // 포인터 초기화 시 사용
}

void Game1::InitWindow()
{
	this->vMode1.width = 1024;
	this->vMode1.height = 768;

	this->window1 = new RenderWindow(this->vMode1, "Simple Game made by SY", Style::Titlebar | Style::Close);

}

Game1::Game1()
{
	this->InitVariable();
	this->InitWindow();
}

Game1::~Game1()
{
}

const bool Game1::isOpenFunc()
{	
	return this->window1->isOpen();
}

void Game1::eventPoll()
{
    while (this->window1->pollEvent(event1)) {
        switch (event1.type) {
        case Event::Closed:
            this->window1->close();
            break;
        case Event::KeyPressed:
            if (event1.key.code == Keyboard::Escape) {
                this->window1->close();
            }
        }
    }
}

void Game1::Update()
{
}

void Game1::Render()
{
}
