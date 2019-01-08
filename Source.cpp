#include<iostream>
#include<windows.h>
#include<windef.h>
using namespace std;

BOOL SetConsoleColor(WORD wAttributes)
{
	//控制台输出设备的句柄
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;
	//设置控制台设备的属性
	return SetConsoleTextAttribute(hConsole, wAttributes);
}

int main()
{
	//方法1
	//0黑色 1蓝色 2绿色 3湖蓝色 4红色 5紫色 6黄色 7白色 8灰色 9淡蓝色 A淡绿色 B淡浅绿色 C淡红色 D淡紫色 E淡黄色 F亮白色（16种）
	//字符1代表背景颜色 字符2代表字体颜色
	//system("color F0");

	//方法2
	//一共有16种文字颜色，16种背景颜色，组合有256种 传入的值应当小于256  
	printf("Console default text and background color\n");
	printf("MoreWindows\n");
	printf("-----------------------------------\n\n");

	SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	printf("Console output red text and blue background\n");
	printf("MoreWindows\n");
	printf("-----------------------------------\n\n");

	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("restore as default color\n");
	printf("MoreWindows\n");
	printf("-----------------------------------\n\n");
	return 0;
}

