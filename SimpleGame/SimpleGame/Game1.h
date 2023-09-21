#pragma once
#include "SimpleGame.h"

class Game1
{
private:
	//Window ������ ����
	//���� ����ϸ� â �ݾҴ� ������ ���ϰ� �ϱ� ���ؼ� ����Ʈ�� ����
	//���� ���𺸴� ��������� ��ü�� �޸� ��뿡 �� �����Ӵ�.
	RenderWindow* window1; 
	VideoMode vMode1;
	Event event1;

	void InitVariable();
	void InitWindow();

public:
	//Constructor class�� ����Ǹ� �ڵ����� ȣ��Ǵ� �Լ�
	Game1();
	//Destructor
	~Game1();

	//function
	const bool isOpenFunc();

	void eventPoll();
	void Update();
	void Render();
};

