# Youtube Refernce
https://www.youtube.com/watch?v=BySDfVNljG8&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up

# SFML ���̺귯�� ��ġ
- unreal engine�� ����(��� �̺�Ʈ ��)

## ������Ʈ �ٿ�ε�
https://www.sfml-dev.org/
- c++ 17 : 2022 32bit

## ���� ����
```
- SimpleGame/External ����
- SimpleGame/External/include ����
- SimpleGame/External/lib ����
- SFML -> SimpleGame : include, lib ���� ���� �ٿ��ֱ�
- dll������ġ SimpleGame(C:\Users\user\CPP_PJ\SimpleGameRepo\SimpleGame\SimpleGame)
```

# VS 2022 ȯ�漳��
- Solution Explorer > Drop Down Menu > Properties
- ��� ���� ����
	- ����(C) Configuration : ��� ���� All Configuration 
	- �÷���(C) Platform : Win32
	- 
- ���͸� �߰��ϴ� ��
	- Solution Explorer > Drop Down Menu > Properties > C/C++ > General(�Ϲ�) > Additional include directories
	- SFML���� �����ؿ� ����/������ �ִ� ��ġ�� ����
	- C:\Users\user\CPP_PJ\SimpleGameRepo\SimpleGame\\External\include ��
	- $(SolutionDir)\External\include �� ���� ����
	- $(SolutionDir) : ��������
- ���̺귯�� �߰��ϴ� ��
	- C:\Users\user\CPP_PJ\SimpleGameRepo\SimpleGame\External\lib
	- $(SolutionDir)\External\lib

- ��Ŀ ����
	- Linker > General > Additional Library Directories
	- SFML���� �����ؿ� ����/������ �ִ� ��ġ�� ����
	```
	- ��� Configuration : Release ī�װ��� ����
	- Linker > Input
	- Configuration : Release
	- sfml-system.lib
	- sfml-graphics.lib
	- sfml-window.lib
	- sfml-audio.lib
	- sfml-network.lib
	
	- ��� Configuration : Debug ī�װ��� ����
	- Linker > Input
	- sfml-system-d.lib
	- sfml-graphics-d.lib
	- sfml-window-d.lib
	- sfml-audio-d.lib
	- sfml-network-d.lib
	```
- Visual Studio ����
- ����� ������ ���� ���� Debug : x64���� x86���� ����

# Event �ڡڡ�

## �̺�Ʈ ����
- ���
- ��Ȳ�� ��ȭ
- Interface�� �����ؼ� ����� ��Ȳ�� ��ȭ
- Ű����, ���콺�� ����� ��Ȳ�� ��ȭ
	- Ű���� �̺�Ʈ : ����Ű ��
	- ���콺 �̺�Ʈ ; ���콺 Ŭ��(Push/Release), mouse over, �� ��ũ��, ����Ŭ��
	- ��ġ ��ũ�� :  ��ġ, ��������, ��ġ
- �ε�


## �̺�Ʈ �ڵ鸵(Event Handling)
- Event Delegate �븮��..? ��������ִ�
- Event Listening �̺�Ʈ �߻� ���θ� ��������� ������

## SimpleGame ������Ʈ�� ������ Game Ŭ����
- ������ ���������� ��Ʈ���ϴ� Ŭ����
- 