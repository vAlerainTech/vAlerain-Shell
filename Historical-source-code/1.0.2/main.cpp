#include <iostream>
#include "all.h"

using namespace std;
void COLOR_PRINT(const char* s, int color)
{
 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
 printf(s);
 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
} //一坨答辩 
/*0 = 黑色 8 = 灰色
1 = 蓝色 9 = 淡蓝色
2 = 绿色 10 = 淡绿色
3 = 浅绿色 11 = 淡浅绿色
4 = 红色 12 = 淡红色
5 = 紫色 13 = 淡紫色
6 = 黄色 14 = 淡黄色
7 = 白色 15 = 亮白色*/

int hwnd_to_int(HWND hwnd)
{
	return reinterpret_cast<intptr_t>(hwnd); //hwnd转换int 
}	

HWND temp1 = GetForegroundWindow(); //获取窗口句柄api 

void intput() {
    string temp_1;
    while (true) {
        COLOR_PRINT("vAlerain-Shell>>", 13);
        cin >> temp_1;
        
        if (temp_1 == "getHwnd") {
            Sleep(2000);
            temp1 = GetForegroundWindow(); //获取窗口句柄api 
            string temp1_str = "[*]Handle to the window where the mouse is currently located:" + to_string(hwnd_to_int(temp1)) + "\n";
            COLOR_PRINT("", 1);
            cout << temp1_str;
        }

        if (temp_1 == "SendCloseGen") {
            int tempGen;
            cout << "inputHwnd：";
            cin >> tempGen;
            HWND temp__ = reinterpret_cast<HWND>(static_cast<long>(tempGen));

            SendMessage(temp__, WM_CLOSE, 0, 0);

            cout << "ok！\n";
        }

        if (temp_1 == "Ark") {
            system("vAlerianArk.exe");
        }
    }
}


int main() {
	COLOR_PRINT("vAlerain-Shell \n",13); 
	string temp1_str = "[*]Handle to the window where the mouse is currently located:"+to_string(hwnd_to_int(temp1))+"\n";
	COLOR_PRINT("",1); 
	cout<<temp1_str;
	
	intput();
	return 0;
}
