#include<iostream>
#include<sm.h>
#include<fstream>
using namespace std;
void hangbanguanlixitong()
{

	int xuanzegongneng;
	while (true)
	{
		cout << "��ѡ����Ҫ�����Ĺ��ܣ�" << endl;
		cout << "1.��Ӻ�����Ϣ����" << endl;
		cout << "2.��ʾ���к�����Ϣ����" << endl;
		cout << "3.��ѯ������Ϣ����" << endl;
		cout << "4.�޸ĺ�����Ϣ����" << endl;
		cout << "5.ɾ��������Ϣ����" << endl;
		cout << "6.�˳�ϵͳ" << endl;
		cin >> xuanzegongneng;
		switch (xuanzegongneng)
		{
		case 1:tianjiahangbangongneng(); break;
		case 2:xianshisuoyouhangbanxinxigongneng(); break;
		case 3:chaxunhangbanxinxigongneng(); break;
		case 4:xiugaihangbanxinxigongneng(); break;
		case 5:shanchuhangbanxinxigongneng(); break;
		case 6:jinruxitong(); break;
		}
	}
}
void tianjiahangbangongneng()
{
	hangbanxinxi a;
	hangbanxinxi b;//������a�Աȶ���
	while (true)
	{
		cout << "������Ҫ��ӵĺ���ĺ����" << endl;
		cin >> a.hangbanhao;
		ofstream ofile;
		ifstream ifile;
		ifile.open("mayuan.hangbanxinxi.txt", ios::binary | ios::in);
		ifile.seekg(0, ios::end);
		int len = ifile.tellg();
		int n = len / sizeof(b);
		ifile.seekg(0, ios::beg);
		int jiance = 0;
		for (int i = 0; i < n; i++)
		{
			ifile.read((char*)&b, sizeof(b));
			if (b.hangbanhao == a.hangbanhao) { jiance = 1; }
		}
		ifile.close();
		if (jiance == 0) { break; }
		else { cout << "������ظ�������������" << endl; }
	}
	cout << "������Ҫ��ӵĺ���ĺ��չ�˾" << endl;
	cin >> a.hangkonggongsi;
	cout << "������Ҫ��ӵĺ���İ���" << endl;
	cin >> a.banqi;
	cout << "������Ҫ��ӵĺ����ʼ������" << endl;
	cin >> a.shifachengshi;
	cout << "������Ҫ��ӵĺ���ĵִ����" << endl;
	cin >> a.didachengshi;
	cout << "������Ҫ��ӵĺ���ĵִﺽվ¥" << endl;
	cin >> a.didahangzhanlou;
	cout << "������Ҫ��ӵĺ����ʱ��" << endl;
	cin >> a.shijian;
	cout << "������Ҫ��ӵĺ����ͷ�Ȳ���" << endl;
	cin >> a.toudengcangshu;
	cout << "������Ҫ��ӵĺ���Ĺ������" << endl;
	cin >> a.gongwucangshu;
	cout << "������Ҫ��ӵĺ���ľ��ò���" << endl;
	cin >> a.jingjicangshu;
	ofstream ofile;
	ofile.open("mayuan.hangbanxinxi.txt", ios::binary | ios::app|ios::out);
	ofile.write((char*)&a, sizeof(a));
	ofile.close();
	hangbanguanlixitong();
}
void xianshisuoyouhangbanxinxigongneng()
{
	hangbanxinxi b;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(b);
	if (n == 0) { cout << "�޺�����Ϣ" << endl; }
	else {
		ifile.seekg(0, ios::beg);
		for (int i = 0; i < n; i++)
		{
			ifile.read((char*)&b, sizeof(b));
			cout << i + 1 << "," << "�����" << b.hangbanhao << "���չ�˾" << b.hangkonggongsi << "����" << b.banqi << "ʼ������" << b.shifachengshi << "�ִ����" << b.didachengshi << "�ִﺽվ¥" << b.didahangzhanlou << "ʱ��" << b.shijian << "ͷ�Ȳ���" << b.toudengcangshu << "�������" << b.gongwucangshu << "���ò���" << b.jingjicangshu << endl;
		}
	}
	ifile.close();
	hangbanguanlixitong();
}
void xianshisuoyouhangbanxinxigongnen()
{
	hangbanxinxi b;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(b);
	ifile.seekg(0, ios::beg);
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		ifile.read((char*)&b, sizeof(b));
		cout << i + 1 << "," << "�����" << b.hangbanhao << "���չ�˾" << b.hangkonggongsi << "����" << b.banqi << "ʼ������" << b.shifachengshi << "�ִ����" << b.didachengshi << "�ִﺽվ¥" << b.didahangzhanlou << "ʱ��" << b.shijian << "ͷ�Ȳ���" << b.toudengcangshu << "�������" << b.gongwucangshu << "���ò���" << b.jingjicangshu << endl;
	}
	ifile.close();
}
void chaxunhangbanxinxigongneng()
{
	int xuanze;
	cout << "��������Ҫ��ѯ�ĺ������Ϣ" << endl;
	cout << "1.���պ���Ų�ѯ" << endl;
	cout << "2.����ʼ�����в�ѯ" << endl;
	cin >> xuanze;
	switch (xuanze)
	{
	case 1:anzhaohangbanhaochaxun();
	case 2:anzhaoshifachengshichaxun();
	}
	hangbanguanlixitong();

}
void anzhaohangbanhaochaxun()
{
	hangbanxinxi a;
	cout << "������Ҫ��ѯ�ĺ���ĺ����" << endl;
	cin >> a.hangbanhao;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(hangbanxinxi);
	hangbanxinxi b;
	int c = 0;//�ж���û���ҵ���Ϣ��
	ifile.seekg(0, ios::beg);
	for (int i = 0; i < n; i++)
	{
		ifile.read((char*)&b, sizeof(hangbanxinxi));
		if (a.hangbanhao == b.hangbanhao)
		{
			cout << "�Ѳ�ѯ���ú�����Ϣ��" << endl;
			cout << "�ú��ຽ���Ϊ" << b.hangbanhao << "���չ�˾" << b.hangkonggongsi << "����Ϊ" << b.banqi << "ʼ������Ϊ" << b.shifachengshi << "�ִ����Ϊ" << b.didachengshi << "�ִﺽվ¥Ϊ" << b.didahangzhanlou << "ʱ��Ϊ" << b.shijian << "ͷ�Ȳ���Ϊ" << b.toudengcangshu << "�������Ϊ" << b.gongwucangshu << "���ò���Ϊ" << b.jingjicangshu << endl;
			c = 1;
			break;

		}
	}
	if (c == 0) { cout << "�޷��ҵ��ú�����Ϣ"; }
	ifile.close();
	hangbanguanlixitong();
}
void anzhaoshifachengshichaxun()
{
	hangbanxinxi a;
	cout << "������Ҫ��ѯ�ĺ����ʼ������" << endl;
	cin >> a.shifachengshi;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(hangbanxinxi);
	hangbanxinxi b;
	int c = 0;
	ifile.seekg(0, ios::beg);
	for (int i = 0; i < n; i++)
	{
		ifile.read((char*)&b, sizeof(hangbanxinxi));
		if (a.shifachengshi == b.shifachengshi)
		{
			cout << "�Ѳ�ѯ���ú�����Ϣ��" << endl;
			cout << "�ú��ຽ���Ϊ" << b.hangbanhao << "���չ�˾" << b.hangkonggongsi << "����Ϊ" << b.banqi << "ʼ������Ϊ" << b.shifachengshi << "�ִ����Ϊ" << b.didachengshi << "�ִﺽվ¥Ϊ" << b.didahangzhanlou << "ʱ��Ϊ" << b.shijian << "ͷ�Ȳ���Ϊ" << b.toudengcangshu << "�������Ϊ" << b.gongwucangshu << "���ò���Ϊ" << b.jingjicangshu << endl;
			c = 1;
		}
	}
	if (c == 0) { cout << "�޷��ҵ��ú�����Ϣ"; }
	ifile.close();
	hangbanguanlixitong();
}
void xiugaihangbanxinxigongneng()
{
	hangbanxinxi a;
	cout << "������Ҫ�޸ĺ���ĺ����" << endl;
	cin >> a.hangbanhao;
	hangbanxinxi b;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(hangbanxinxi);
	int c; c = 0;//�ж��Ƿ��ѯ������Ϣ
	ifile.seekg(0, ios::beg);
	int i;
	for (i = 0; i < n; i++)
	{
		ifile.read((char*)&b, sizeof(hangbanxinxi));
		if (b.hangbanhao == a.hangbanhao)
		{
		 c = 1;
			cout << "�Ѳ�ѯ���ú�����Ϣ��" << endl;
			cout << "�ú��ຽ���Ϊ" << b.hangbanhao << "���չ�˾" << b.hangkonggongsi << "����Ϊ" << b.banqi << "ʼ������Ϊ" << b.shifachengshi << "�ִ����Ϊ" << b.didachengshi << "�ִﺽվ¥Ϊ" << b.didahangzhanlou << "ʱ��Ϊ" << b.shijian << "ͷ�Ȳ���Ϊ" << b.toudengcangshu << "�������Ϊ" << b.gongwucangshu << "���ò���Ϊ" << b.jingjicangshu << endl;
			break;
		}
	}
	ifile.close();
	if (c == 0) { cout << "δ���ҵ��ú���" << endl; }
	else
	{
		hangbanxinxi c;
		hangbanxinxi d;
		int s = a.hangbanhao;
		int i;
		ifstream ifile;
		ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
		ifile.seekg(0, ios::end);
		int len = ifile.tellg();
		int n = len / sizeof(hangbanxinxi);
		for (i = 0; i < n; i++)
		{
			ifile.seekg(sizeof(hangbanxinxi) * i);
			ifile.read((char*)&c, sizeof(hangbanxinxi));
			if (s == c.hangbanhao) { break; }
		}
		ifile.close();
		ofstream ofile;
		ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
		ofile.open("mayuan.zhongjie.txt", ios::binary | ios::trunc);
		ofile.close();
		ofile.open("mayuan.zhongjie.txt", ios::binary | ios::out);
		for (int j = 0; j < n; j++)
		{
				ifile.seekg(sizeof(hangbanxinxi) * j);
				ifile.read((char*)&c, sizeof(hangbanxinxi));
				if (j != i)
				{
					d.hangbanhao = c.hangbanhao;
					d.hangkonggongsi = c.hangkonggongsi;
					d.banqi = c.banqi;
					d.shifachengshi = c.shifachengshi;
					d.didachengshi = c.didachengshi;
					d.didahangzhanlou = c.didahangzhanlou;
					d.shijian = c.shijian;
					d.toudengcangshu = c.toudengcangshu;
					d.jingjicangshu = c.jingjicangshu;
					d.gongwucangshu = c.gongwucangshu;
					ofile.write((char*)&d, sizeof(hangbanxinxi));
				}
		}
		ifile.close();
		ofile.close();
		ifile.open("mayuan.zhongjie.txt", ios::binary);
		ofile.open("mayuan.hangbanxinxi.txt", ios::trunc);
		ofile.close();
		ofile.open("mayuan.hangbanxinxi.txt", ios::binary | ios::out | ios::app);
		for (int k = 0; k < n - 1; k++)
			{
				ifile.seekg(sizeof(hangbanxinxi) * k);
				ifile.read((char*)&d, sizeof(d));
				c.hangbanhao = d.hangbanhao;
				c.hangkonggongsi = d.hangkonggongsi;
				c.banqi = d.banqi;
				c.shifachengshi = d.shifachengshi;
				c.didachengshi = d.didachengshi;
				c.didahangzhanlou = d.didahangzhanlou;
				c.shijian =d.shijian;
				c.toudengcangshu = d.toudengcangshu;
				c.jingjicangshu = d.jingjicangshu;
				c.gongwucangshu = d.gongwucangshu;
				ofile.write((char*)&c, sizeof(c));
		}
		ifile.close();
		ofile.close();
		ofile.open("mayuan.zhongjie.txt", ios::trunc);
		ofile.close();
		cout << "�������޸ĺ�ĺ������Ϣ" << endl;
		cout << "����ĺ��չ�˾" << endl;
		cin >> a.hangkonggongsi;
		cout << "����İ���" << endl;
		cin >> a.banqi;
		cout << "�����ʼ������" << endl;
		cin >> a.shifachengshi;
		cout << "����ĵִ����" << endl;
		cin >> a.didachengshi;
		cout << "����ĵִﺽվ¥" << endl;
		cin >> a.didahangzhanlou;
		cout << "�����ʱ��" << endl;
		cin >> a.shijian;
		cout << "�����ͷ�Ȳ���" << endl;
		cin >> a.toudengcangshu;
		cout << "����Ĺ������" << endl;
		cin >> a.gongwucangshu;
		cout << "����ľ��ò���" << endl;
		cin >> a.jingjicangshu;
		ofile.open("mayuan.hangbanxinxi.txt", ios::binary | ios::out|ios::app);
		ofile.write((char*)&a, sizeof(hangbanxinxi));
		ofile.close();
		cout << "�޸ĳɹ����Ƿ�鿴��" << endl;
		cout << "����1�鿴�޸ĺ�����к�����Ϣ������������0" << endl;
		int xuanze;
		cin >> xuanze;
		if (xuanze == 1) { xianshisuoyouhangbanxinxigongneng(); }
		else { ; }
	}
	hangbanguanlixitong();
}
void shanchuhangbanxinxigongneng()
{
	hangbanxinxi a;
	hangbanxinxi b;
	cout << "����������ɾ������ĺ����" << endl;
	int s;
	cin >> s;
	int z; z = 0;
	int i;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(hangbanxinxi);
	for (i = 0; i < n; i++)
	{
		ifile.seekg(sizeof(hangbanxinxi) * i);
		ifile.read((char*)&a, sizeof(hangbanxinxi));
		if (s == a.hangbanhao) { z = 1; break; }
	}
	ifile.close();
	if (z == 0) { cout << "δ�ҵ��ú���" << endl; }
	else
	{
		ifstream ifile;
		ofstream ofile;
		ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
		ofile.open("mayuan.zhongjie.txt",ios::binary| ios::trunc);
		ofile.close();
		ofile.open("mayuan.zhongjie.txt", ios::binary | ios::out);
		for (int j = 0; j < n; j++)
		{
			ifile.seekg(sizeof(hangbanxinxi) * j);
			ifile.read((char*)&a, sizeof(hangbanxinxi));
			if (j != i)
			{ 
				b.hangbanhao = a.hangbanhao;
				b.hangkonggongsi = a.hangkonggongsi;
				b.banqi = a.banqi;
				b.shifachengshi = a.shifachengshi;
				b.didachengshi = a.didachengshi;
				b.didahangzhanlou = a.didahangzhanlou;
				b.shijian = a.shijian;
				b.toudengcangshu = a.toudengcangshu;
				b.jingjicangshu = a.jingjicangshu;
				b.gongwucangshu = a.gongwucangshu;
				ofile.write((char*)&b, sizeof(hangbanxinxi));
			}
		}
		ifile.close();
		ofile.close();
		ifile.open("mayuan.zhongjie.txt", ios::binary);
		ofile.open("mayuan.hangbanxinxi.txt", ios::trunc);
		ofile.close();
		ofile.open("mayuan.hangbanxinxi.txt", ios::binary | ios::out|ios::app);
		for (int k = 0; k < n - 1; k++)
		{
			ifile.seekg(sizeof(hangbanxinxi) * k);
			ifile.read((char*)&b, sizeof(b));
			a.hangbanhao = b.hangbanhao;
			a.hangkonggongsi = b.hangkonggongsi;
			a.banqi = b.banqi;
			a.shifachengshi = b.shifachengshi;
			a.didachengshi = b.didachengshi;
			a.didahangzhanlou = b.didahangzhanlou;
			a.shijian = b.shijian;
			a.toudengcangshu = b.toudengcangshu;
			a.jingjicangshu = b.jingjicangshu;
			a.gongwucangshu = b.gongwucangshu;
			ofile.write((char*)&a, sizeof(a));
		}
		ifile.close();
		ofile.close();
		ofile.open("mayuan.zhongjie.txt", ios::trunc);
		ofile.close();
		cout << "ɾ���ɹ���" << endl;
	}
	hangbanguanlixitong();
}


