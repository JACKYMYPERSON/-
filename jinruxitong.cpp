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
		cout << "��ѡ������ϵͳ��          " << endl;
		cout << "1.�������ϵͳ         " << endl;
		cout << "2.����Ʊ����ϵͳ    " << endl;
		cout << "3.��Ʊ����ϵͳ" << endl;
		cout << "4.�˳�" << endl;
		cin >> xuanze;
		switch (xuanze)
		{
		case 1:hangbanguanlixitong(); break;
		case 2:dingtuipiaoxitong(); break;
		case 3:shoupiaoguanlixitong(); break;
		case 4: exit; break;
		}
		if (xuanze >= 1 && xuanze <= 4)break;
		else cout << "����������1-4�Խ�����˳�ϵͳ��" << endl;
	}
}