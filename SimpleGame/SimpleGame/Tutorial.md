# SFML 라이브러리 설치

## 웹사이트 다운로드
https://www.sfml-dev.org/
- c++ 17 : 2022 32bit

## 폴더 구조
```
- SimpleGame/External 생성
- SimpleGame/External/include 생성
- SimpleGame/External/lib 생성
- SFML -> SimpleGame : include, lib 파일 복사 붙여넣기
- dll파일위치 SimpleGame(C:\Users\user\CPP_PJ\SimpleGameRepo\SimpleGame\SimpleGame)
```

# VS 2022 환경설정
- Solution Explorer > Drop Down Menu > Properties
- 상단 공통 영역
	- 구성(C) Configuration : 모든 구성 All Configuration 
	- 플랫폼(C) Platform : Win32
	- 
- 디렉터리 추가하는 법
	- Solution Explorer > Drop Down Menu > Properties > C/C++ > General(일반) > Additional include directories
	- SFML에서 복사해온 파일/폴더가 있는 위치를 선택
	- C:\Users\user\CPP_PJ\SimpleGameRepo\SimpleGame\\External\include 를
	- $(SolutionDir)\External\include 로 변경 가능
	- $(SolutionDir) : 현재폴더
- 라이브러리 추가하는 법
	- C:\Users\user\CPP_PJ\SimpleGameRepo\SimpleGame\External\lib
	- $(SolutionDir)\External\lib

- 링커 설정
	- Linker > General > Additional Library Directories
	- SFML에서 복사해온 파일/폴더가 있는 위치를 선택
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