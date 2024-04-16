bin/tron : src/test.cpp
	g++ -o bin/tron src/main.cpp -Iinclude -lftxui-screen -lftxui-dom -lftxui-component