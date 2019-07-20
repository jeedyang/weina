// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../../weina/plclib/ButterflyS7.h"
#include "../../weina/snap7/snap7.h"
#include <Windows.h>

#pragma comment (lib,"snap7.lib")
#pragma comment (lib,"ButterflyS7.lib")
using namespace ButterflyS7;

using namespace std;

#define SNAP7

void  func(void* usrPtr, int opCode, int opResult)
{
	cout <<"usrPtr: "<< (int)usrPtr <<"opCode: "<< opCode <<"opResult: "<< opResult << endl;
}

int main()
{



	DWORD start, end;
	string info;

	pfn_CliCompletion pfunc=func;

#ifdef SNAP7
	TS7Client plc;
	int a = plc.ConnectTo("192.168.2.1", 0, 1);
	start = GetTickCount();
	unsigned char databuf[100];
	bool val = true;
	char user = 'y';
	plc.SetAsCallback(pfunc, &user);
	
	for (int i = 0; i < 10000; i++)
	{
		//plc.ReadArea(S7AreaDB, 1, 0, 100, S7WLByte, databuf);
		val = !val;
		plc.AsWriteArea(S7AreaPA,1,7,1,S7WLBit,&val);
		cout <<(int)&user << endl;
		Sleep(200);
	}
	
	end = GetTickCount() - start;
	info = "snap7";
#else
	PlcHandle h = CreatePlc();
	unsigned char ipdr[4] = { 192,168,2,1 };
	int a = ConnectPlc(h, ipdr, 0, 1);
	start = GetTickCount();
	unsigned char databuf[100];
	for (int i = 0; i < 10000; i++)
	{
		ReadBlockAsByte(h, AreaDB, 1, 0, 100, databuf);
	}	
	end = GetTickCount() - start;
	info = "ButterflyS7";
#endif


	cout <<info<<"\nused time;"<< end << endl;

}




// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
