# Youtube Refernce
https://www.youtube.com/watch?v=BySDfVNljG8&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up

# SFML 라이브러리 설치
- unreal engine의 역할(충들 이벤트 등)

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
	- 상단 Configuration : Release 카테고리로 설정
	- Linker > Input
	- Configuration : Release
	- sfml-system.lib
	- sfml-graphics.lib
	- sfml-window.lib
	- sfml-audio.lib
	- sfml-network.lib
	
	- 상단 Configuration : Debug 카테고리로 설정
	- Linker > Input
	- sfml-system-d.lib
	- sfml-graphics-d.lib
	- sfml-window-d.lib
	- sfml-audio-d.lib
	- sfml-network-d.lib
	```
- Visual Studio 설정
- 상단의 에디터 툴바 설정 Debug : x64에서 x86으로 변경

# Event ★★★

## 이벤트 종류
- 사건
- 상황의 변화
- Interface와 연관해서 생기는 상황의 변화
- 키보드, 마우스로 생기는 상황의 변화
	- 키보드 이벤트 : 방향키 등
	- 마우스 이벤트 ; 마우스 클릭(Push/Release), mouse over, 휠 스크롤, 더블클릭
	- 터치 스크린 :  터치, 스와이프, 핀치
- 로딩


## 이벤트 핸들링(Event Handling)
- Event Delegate 대리자..? 대신일해주다
- Event Listening 이벤트 발생 여부를 계속적으로 감지함

## SimpleGame 프로젝트에 구현한 Game 클래스
- 게임을 전반적으로 컨트롤하는 클래스
- 