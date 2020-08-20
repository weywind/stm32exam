// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
struct MenuItem
{
	const char* title;
	struct MenuItem* children;
	int childrenCount;
	void(*handler)();
};
void test() {
	cout << "hahaha\n";
}
struct MenuItem aaa[] = {
	{"aaa",0,0,test},
	{"bbb",0,0,test},
	{"ccc",0,0,test},
};
struct MenuItem bbb[] = {
	{"ddd",0,0,test},
	{"eee",0,0,test},
	{"fff",0,0,test},
};
struct MenuItem ccc[] = {
	{"ggg",0,0,test},
	{"hhh",0,0,test},
	{"iii",0,0,test},
};
struct MenuItem home[] = {
	{"jjj",aaa,3,0},
	{"kkk",bbb,3,0},
	{"mmm",ccc,3,0},
};

int steps = 0;
int op[] = { 0,0,0,0,0,0,0,0,0 };
MenuItem* currentMenu;
int currentIndex;
int currentCount;

enum Operation
{
	GO = 1,
	BACK = 2,
	UP = 3,
	DOWN = 4
};
void showMenu() {
	for (int i = 0; i < currentCount; i++)
	{
		if (i == currentIndex) {
			cout << ">";
		}
		else {
			cout << " ";
		}
		cout << currentMenu[i].title<<endl;
	}
	cout << endl;

}
void go() {
	if (currentMenu[currentIndex].childrenCount == 0) {
		if (currentMenu[currentIndex].handler) {
			return currentMenu[currentIndex].handler();
		}
		else
		{
			return;
		}
	}
	op[steps] = GO;
	steps++;
	currentCount = currentMenu[currentIndex].childrenCount;
	currentMenu = currentMenu[currentIndex].children;
	currentIndex = 0;
	showMenu();
}

void back() {
	int last = 0;
	for (int i = 0; i < steps; i++)
	{
		if (op[i] == GO) {
			last = i;
		}
	}
	currentIndex = 0;
	MenuItem* temp = home;
	for (int i = 0; i < last; i++)
	{
		switch (op[i])
		{
		case GO:
			temp = temp[currentIndex].children;
			currentCount = temp[currentIndex].childrenCount;
		case UP:
			currentIndex = (currentCount + currentIndex - 1) % currentCount;
		case DOWN:
			currentIndex = (currentCount + currentIndex + 1) % currentCount;
		default:
			break;
		}
	}
	currentMenu = temp;
	steps--;
	currentIndex = 0;
	showMenu();
}
void up() {
	currentIndex = (currentCount + currentIndex - 1) % currentCount;
	op[steps] = UP;
	steps++;
	showMenu();

}
void down() {
	currentIndex = (currentCount + currentIndex + 1) % currentCount;
	op[steps] = DOWN;
	steps++;
	showMenu();
}
int main()
{
	currentMenu = home;
	currentCount = 3;
	showMenu();
	char input;
	while (true)
	{
		input = getchar();
		switch (input)
		{
		case 'w':
			up();
			break;
		case 's':
			down();
			break;
		case 'a':
			back();
			break;
		case 'd':
			go();
			break;
		default:
			break;
		}
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
