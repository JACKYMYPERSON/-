#include<iostream>
#include<fstream>
#include<sm.h>
using namespace std;
void shoupiaoguanlixitong()
{
	while (true) {
		int xuanze;
		cout << "��ӭ������Ʊ����ϵͳ" << endl;
		cout << "��������Ҫ�����Ĺ��ܣ�" << endl;
		cout << "1.��ʾ���ж�����Ϣ" << endl;
		cout << "2.�˳�ϵͳ" << endl;
		cin >> xuanze;
		switch (xuanze)
		{
		case 1: {xianshisuoyoudingdanxinxi(); break; }
		case 2: {jinruxitong(); break; }
		}
		if (xuanze == 1 || xuanze == 2) break;
		else { cout << "������1��2" << endl; }
	}
	jinruxitong();
}

void xianshisuoyoudingdanxinxi()
{
	dingdanmingxixinxi b;
	ifstream ifile;
	ifile.open("mayuan.dingdan.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len2 = ifile.tellg();
	int n = len2 / sizeof(dingdanmingxixinxi);
	if (n == 0) { cout << "�޶�����Ϣ" << endl; }
	else 
	{
		for (int i = 0; i < n; i++)
		{
			ifile.seekg(sizeof(b) * i);
			ifile.read((char*)&b, sizeof(b));
			cout << i << "," << "������" << b.dingdanhao << "  �����" << b.hangbanhao << "��������" << b.chufariqi << "��λ�ȼ�" << b.zuoweidengji << " �˿�����" << b.chengkexingming << "�绰����" << b.dianhuahaoma << "���֤��" << b.shenfenzhenghao << endl;
		}
	}
	ifile.close();
	shoupiaoguanlixitong();
}