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
	this->window1 = nullptr; // ������ �ʱ�ȭ �� ���
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
    this->window1 = nullptr; // ������ �ʱ�ȭ �� ���
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
    //vector ������ -> ����� ũ�⸦ ���� ������
    //scalar ������ -> ũ�⸸ ���� ������

    this->RctEnemy.setSize(Vector2f(30.0f,30.0f));
    this->RctEnemy.setFillColor(Color::Magenta);
    this->RctEnemy.setPosition(30.0f, 30.0f);
}

void Game1::SpawnEnemy()
{
    RctEnemy.setPosition(
        static_cast<float>(rand() % this->vMode1.width)  // ������ �� % ����â ���α��� ( ���α��� ���� ���� ��ġ�ؾ���)
        ,0.0f);
    //�迭�� �ϳ��� �־��ֱ�
    this->RctRndmEnemies.push_back(this->RctEnemy);
}

void Game1::SetSpawnValue()
{//�����ϰ� enemy�� ������ �� �ֵ��� ��ġ �ʿ�
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
    return this->window1->isOpen(); //���������� ��ü�� �����ִ� ������ �Լ��� ->��
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
    //�� �����쿡 ǥ�õǴ� �ִ� ���� ����
    if (this->RctRndmEnemies.size() < this->EnemyMaxNum) {
        //���� �����Ǵ� �ð� ����
        if (this->EnemySpawnTime >= this->EnemySpawnTimeMax) {
            this->EnemySpawnTime = 0.0f;
            this->SpawnEnemy();
        }
        else {
            this->EnemySpawnTime += 1.0f;
        }
    }

    //this->RctEnemy.move(1.0f,3.0f); -> �� ������ �� �غô� �ڵ�
    //offset ������ǥ������ �Ÿ�. ��, ���ǵ带 �ǹ�

    //���� ���� �� �����Ǵ� ��� ������
    for (int i = 0; i < this->RctRndmEnemies.size(); i++) {
        this->RctRndmEnemies[i].move(0.0f, 3.0f);
    }

    //���� ������ �ٱ����� �����(y��ǥ�� window�� �Ѿ��) ����
    for (int i = 0; i < this->RctRndmEnemies.size(); i++) {
        if (this->RctRndmEnemies[i].getPosition().y >= this->window1->getSize().y) {
            this->RctRndmEnemies.erase(this->RctRndmEnemies.begin() + i);
        }
    }

}


void Game1::UpdatePlayer() {
    float movespeed = 5.0f;
    //Ű���� �Է��� else if ������ �밢���� �̵��� ���� �־���Ѵ�
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
        if (this->player1.getGlobalBounds().intersects(this->RctRndmEnemies[i].getGlobalBounds())) {//��� ���� ũ�� ����������������� �Լ�
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
    //this->window1->draw(this->RctEnemy); -> �� ������ �� �غô� �ڵ�
    
    // 1. enemy
    for (int i = 0; i < this->RctRndmEnemies.size(); i++) {

        this->window1->draw(this->RctRndmEnemies[i]);
    }
    // 2. player
    this->window1->draw(this->player1);

    //display();
    this->window1->display();

}
