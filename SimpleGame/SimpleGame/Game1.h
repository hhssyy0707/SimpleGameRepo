#pragma once
#include "SimpleGame.h"

class Game1
{
private:

	//Window 포인터 선언
	//쉽게 얘기하면 창 닫았다 열었다 편하게 하기 위해서 포인트로 선언
	//정적 선언보다 동적선언된 객체가 메모리 사용에 더 자유롭다.
	RenderWindow* window1; //모든 함수에서 사용하고싶을때 클래스 변수로 선언
	VideoMode vMode1;
	Event event1;
	RectangleShape RctEnemy;
	vector<RectangleShape> RctRndmEnemies;
	//동적 생성된 Window 삭제
	void DelWindow();

	//Enemy
	//Spawn Value
	float EnemySpawnTime = 0;
	float EnemySpawnTimeMax = 10; //10초에 한 번씩 스폰
	int EnemyMaxNum ;

	void InitRctEnemy();
	void SetSpawnValue();

	//player
	CircleShape player1;
	void InitPlayer();

	//큰틀 init draw

public:

	//Constructor class가 선언되면 자동으로 호출되는 함수
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
	//앞 const : 반환값이 변경되지않음
	//뒤 const : 매개변수, 함수 내부 값이 변경되지 않음
	const bool Running() const;
	void EventHandler();
	void Update();
	void UpdateEnemy();
	void UpdatePlayer();
	void UpdateCollision();
	void GameOver();
	void Render();
};

