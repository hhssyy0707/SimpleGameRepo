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
    //window1 = new RenderWindow(VideoMode(1024, 768), "Simple Game of C++ class", Style::Titlebar | Style::Close);

}

void Game1::InitWindowPointer()
{
    this->window1 = nullptr; // 포인터 초기화 시 사용
}

void Game1::DelWindow()
{
    delete this->window1;
}

Game1::Game1()
{
	this->InitVariable();
	this->InitWindow();
}

Game1::~Game1()
{
    this->DelWindow();
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

const bool Game1::Running() const
{
    return this->window1->isOpen(); //동적생성한 객체가 갖고있는 변수나 함수는 ->로
}

void Game1::EventHandler()
{

}

void Game1::Update()
{

}

void Game1::Render()
{
}
