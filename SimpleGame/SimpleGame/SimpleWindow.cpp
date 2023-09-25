#include "SimpleGame.h"
#include <iostream>

void SimpleWindow() {
	//create Window
	RenderWindow Window(VideoMode(1024, 768), "Simple Game of C++ class", Style::Titlebar | Style::Close);//classtype�� ���� ,��ü ����

	Event event1;

	//Window â ����
	while (Window.isOpen()) {//isOpen() : Window Open ���� Ȯ�� => true 
		//Close ��ư�� Ŭ�� Event ���� => Window Close 
		while (Window.pollEvent(event1))//��� Event(event1) ����
		{
			//Event type ����
			switch (event1.type) {

			case Event::Closed:
				Window.close();
				break;
			case Event::KeyPressed:
				if (event1.key.code == Keyboard::Escape) {
					Window.close();
				}
			}
		}
	}
}