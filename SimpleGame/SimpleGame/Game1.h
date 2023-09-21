#pragma once
#include "SimpleGame.h"

class Game1
{
private:
	//Window 포인터 선언
	//쉽게 얘기하면 창 닫았다 열었다 편하게 하기 위해서 포인트로 선언
	//정적 선언보다 동적선언된 객체가 메모리 사용에 더 자유롭다.
	RenderWindow* window1; 
	VideoMode vMode1;
	Event event1;

	void InitVariable();
	void InitWindow();

public:
	//Constructor class가 선언되면 자동으로 호출되는 함수
	Game1();
	//Destructor
	~Game1();

	//function
	const bool isOpenFunc();

	void eventPoll();
	void Update();
	void Render();
};

