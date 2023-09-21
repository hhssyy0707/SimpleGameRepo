# SFML ���̺귯�� ��ġ

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
	- Linker > Input
	- Configuration : Release
	- sfml-system.lib
	- sfml-graphics.lib
	- sfml-window.lib
	- sfml-audio.lib
	- sfml-network.lib
	
	- Linker > Input
	- Configuration : Debug
	- sfml-system-d.lib
	- sfml-graphics-d.lib
	- sfml-window-d.lib
	- sfml-audio-d.lib
	- sfml-network-d.lib
	```

# 