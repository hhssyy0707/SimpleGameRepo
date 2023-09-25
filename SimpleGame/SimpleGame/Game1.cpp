#include "Game1.h"

Game1::Game1()
{
    this->InitVariable();
    this->InitWindow();
    //this->InitWindowPointer();

    //Enemy
    this->InitRctEnemy();
    this->SetSpawnValue();

    //Player
    this->InitPlayer();
}

Game1::~Game1()
{
    this->DelWindow();
}

/* -> Running()
const bool Game1::isOpenFunc()
{
    return this->window1->isOpen();
}
*/

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

    this->window1->setFramerateLimit(60);
}

void Game1::InitWindowPointer()
{
    this->window1 = nullptr; // 포인터 초기화 시 사용
}

void Game1::DelWindow()
{
    delete this->window1;
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

void Game1::InitRctEnemy()
{
    //RectangleShape
    //vector 데이터 -> 방향과 크기를 가진 데이터
    //scalar 데이터 -> 크기만 가진 데이터

    this->RctEnemy.setSize(Vector2f(30.0f,30.0f));
    this->RctEnemy.setFillColor(Color::Magenta);
    this->RctEnemy.setPosition(30.0f, 30.0f);
}

void Game1::SpawnEnemy()
{
    RctEnemy.setPosition(
        static_cast<float>(rand() % this->vMode1.width)  // 랜덤한 값 % 게임창 가로길이 ( 가로길이 범위 내에 위치해야함)
        ,0.0f);
    //배열에 하나씩 넣어주기
    this->RctRndmEnemies.push_back(this->RctEnemy);
}

void Game1::SetSpawnValue()
{//랜덤하게 enemy가 떨어질 수 있도록 장치 필요
    this->EnemySpawnTime = 0.0f;
    this->EnemySpawnTimeMax = 20.0f;
    this->EnemyMaxNum = 15;
}

void Game1::InitPlayer()
{
    this->player1.setRadius(30.0f);
    this->player1.setFillColor(Color::Blue);
    this->player1.setPosition(
        this->window1->getSize().x / 2,
        this->window1->getSize().y / 2);
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
    //this->SpawnEnemy();
    this->UpdateEnemy();
    this->UpdatePlayer();
    this->UpdateCollision();
}

void Game1::UpdateEnemy()
{
    //한 윈도우에 표시되는 최대 개수 제한
    if (this->RctRndmEnemies.size() < this->EnemyMaxNum) {
        //적이 생성되는 시간 간격
        if (this->EnemySpawnTime >= this->EnemySpawnTimeMax) {
            this->EnemySpawnTime = 0.0f;
            this->SpawnEnemy();
        }
        else {
            this->EnemySpawnTime += 1.0f;
        }
    }

    //this->RctEnemy.move(1.0f,3.0f); -> 한 개였을 때 해봤던 코드
    //offset 다음좌표까지의 거리. 즉, 스피드를 의미

    //여러 개의 적 생성되는 즉시 움직임
    for (int i = 0; i < this->RctRndmEnemies.size(); i++) {
        this->RctRndmEnemies[i].move(0.0f, 3.0f);
    }

    //적이 윈도우 바깥으로 벗어나면(y좌표가 window를 넘어가면) 삭제
    for (int i = 0; i < this->RctRndmEnemies.size(); i++) {
        if (this->RctRndmEnemies[i].getPosition().y >= this->window1->getSize().y) {
            this->RctRndmEnemies.erase(this->RctRndmEnemies.begin() + i);
        }
    }

}


void Game1::UpdatePlayer() {
    float movespeed = 5.0f;
    //키보드 입력은 else if 사용안함 대각으로 이동할 수도 있어야한다
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        this->player1.move(movespeed*(-1), 0.0f);
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        this->player1.move(movespeed, 0.0f);
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        this->player1.move(0.0f, movespeed*(-1));
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        this->player1.move(0.0f, movespeed);
    }
}

void Game1::UpdateCollision() {
    for (int i = 0; i < RctRndmEnemies.size(); i++) {
        if (this->player1.getGlobalBounds().intersects(this->RctRndmEnemies[i].getGlobalBounds())) {//경계 영역 크기 가져오고싶을때쓰는 함수
            this->GameOver();
        }
    }
}
void Game1::GameOver() {
    this->window1->close();
}

void Game1::Render()
{
    //remove object
    this->window1->clear();

    //draw object
    //this->window1->draw(this->RctEnemy); -> 한 개였을 때 해봤던 코드
    
    // 1. enemy
    for (int i = 0; i < this->RctRndmEnemies.size(); i++) {

        this->window1->draw(this->RctRndmEnemies[i]);
    }
    // 2. player
    this->window1->draw(this->player1);

    //display();
    this->window1->display();

}
