#include "SimpleGame.h"
#include <iostream>

void SimpleWindow() {
	//create Window
	RenderWindow Window(VideoMode(1024, 768), "Simple Game of C++ class", Style::Titlebar | Style::Close);//classtype의 일종 ,객체 생성

	Event event1;

	//Window 창 유지
	while (Window.isOpen()) {//isOpen() : Window Open 여부 확인 => true 
		//Close 버튼을 클릭 Event 감지 => Window Close 
		while (Window.pollEvent(event1))//계속 Event(event1) 감지
		{
			//Event type 구분
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