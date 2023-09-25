#pragma once
#include "SimpleGame.h"

class Game1
{
private:

	//Window ������ ����
	//���� ����ϸ� â �ݾҴ� ������ ���ϰ� �ϱ� ���ؼ� ����Ʈ�� ����
	//���� ���𺸴� ��������� ��ü�� �޸� ��뿡 �� �����Ӵ�.
	RenderWindow* window1; //��� �Լ����� ����ϰ������ Ŭ���� ������ ����
	VideoMode vMode1;
	Event event1;
	RectangleShape RctEnemy;
	vector<RectangleShape> RctRndmEnemies;
	//���� ������ Window ����
	void DelWindow();

	//Enemy
	//Spawn Value
	float EnemySpawnTime = 0;
	float EnemySpawnTimeMax = 10; //10�ʿ� �� ���� ����
	int EnemyMaxNum ;

	void InitRctEnemy();
	void SetSpawnValue();

	//player
	CircleShape player1;
	void InitPlayer();

	//ūƲ init draw

public:

	//Constructor class�� ����Ǹ� �ڵ����� ȣ��Ǵ� �Լ�
	Game1();
	//Destructor
	~Game1();

	//function
	//const bool isOpenFunc(); -> Running();
	void InitVariable();
	void InitWindow();
	void InitWindowPointer();
	void eventPoll();

	//Enemy
	void SpawnEnemy();

	//Game Loop
	//�� const : ��ȯ���� �����������
	//�� const : �Ű�����, �Լ� ���� ���� ������� ����
	const bool Running() const;
	void EventHandler();
	void Update();
	void UpdateEnemy();
	void UpdatePlayer();
	void UpdateCollision();
	void GameOver();
	void Render();
};

