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

public:
	//Constructor class�� ����Ǹ� �ڵ����� ȣ��Ǵ� �Լ�
	Game1();
	//Destructor
	~Game1();

	//function
	const bool isOpenFunc();
	void InitVariable();
	void InitWindow();
	void InitWindowPointer();
	void DelWindow();
	void eventPoll();

	//Game Loop
	//�� const : ��ȯ���� �����������
	//�� const : �Ű�����, �Լ� ���� ���� ������� ����
	const bool Running() const;
	void EventHandler();
	void Update();
	void Render();
};

