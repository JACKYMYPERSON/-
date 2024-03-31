#include<iostream>
#include<fstream>
#include<sm.h>
#include<cmath>
using namespace std;
void jinruxitong()
{
	while (true)
	{
		int xuanze;
		cout << "请选择进入的系统：          " << endl;
		cout << "1.航班管理系统         " << endl;
		cout << "2.订退票管理系统    " << endl;
		cout << "3.售票管理系统" << endl;
		cout << "4.退出" << endl;
		cin >> xuanze;
		switch (xuanze)
		{
		case 1:hangbanguanlixitong(); break;
		case 2:dingtuipiaoxitong(); break;
		case 3:shoupiaoguanlixitong(); break;
		case 4: exit; break;
		}
		if (xuanze >= 1 && xuanze <= 4)break;
		else cout << "请输入数字1-4以进入或退出系统！" << endl;
	}
}