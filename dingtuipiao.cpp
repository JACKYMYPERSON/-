#include<iostream>
#include<fstream>
#include<sm.h>
#include<cmath>
using namespace std;
void dingtuipiaoxitong()
{
	cout << "���Ѿ��붩��Ʊϵͳ***" << "��ѡ������ѡ�" << endl;
	cout << "1.��Ʊ" << endl;
	cout << "2.��Ʊ" << endl;
	cout << "3.�˳�ϵͳ" << endl;
	int xuanze;
	cin >> xuanze;
	if (xuanze >= 1 && xuanze <= 3)
	{
		switch (xuanze)
		{
		case 1:dingpiao();
		case 2:tuipiao();
		case 3:jinruxitong();
		}
	}
	else { cout << "��������"; }
}
void dingpiao()
{
	int z1 ;
	z1 = 0;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary|ios::in);
	hangbanxinxi w;
	ifile.seekg(0, ios::end);
	int lenk = ifile.tellg() / sizeof(w);
	ifile.seekg(0, ios::beg);
	for (int i = 0; i < lenk; i++)
	{
		ifile.read((char*)&w, sizeof(w));
		cout << i + 1 << "," << "�����" << w.hangbanhao << "���չ�˾" << w.hangkonggongsi << "����" << w.banqi << "ʼ������" << w.shifachengshi << "�ִ����" << w.didachengshi << "�ִﺽվ¥" << w.didahangzhanlou << "ʱ��" << w.shijian << "ͷ�Ȳ���" << w.toudengcangshu << "�������" << w.gongwucangshu << "���ò���" << w.jingjicangshu << endl;
	}
	ifile.close();
	int q;//���溽���
	int i;
	int z; z = 0;//���Һ����ʧ��
	int z2; z2 = 0;//������λ�ȼ�
	int riqi;//��ʼ���ڵ�ת��
	hangbanxinxi a;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary|ios::in);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	cout << len<<endl;
	int n = len / sizeof(hangbanxinxi);
	cout << n << endl;
	while (true)
	{
		cout << "��������Ҫ���ĺ���ĺ����" << endl;
		cin >> q;
		for (i = 0; i < n; i++)
		{
			ifile.seekg(sizeof(a) * i);
			ifile.read((char*)&a, sizeof(a));
			if (a.hangbanhao == q) { z = 1; break; }

		}
		if (z != 1) { cout << "����ĺ��������"; }
		else { break; }
	}
	ifile.close();
	if (z == 1)
	{
		
		cout << "��Ϊ���ҵ������Ϊ" << q << "�ĺ���" << endl;
		cout << "�ú���İ���Ϊ��" << a.banqi << endl;
		//��ʼƥ�����ںͰ���
		while (true)
		{
			cout << "����������ѡ������ڣ�" << "��ʽΪxxxx��xx��xx�գ��������ּ��ɣ�" << endl;
			cin >> riqi;
			int year, month, day;
			year = riqi / 10000;
			month = riqi / 100 - year;
			day = riqi % 100;
			if (month == 1 || month == 2)
			{
				month += 12;
				--year;
			}
			int weekday;
			weekday = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;//�����˻�ķ����ɭ��ʽ��������
			month -= 12;
			++year;
			int p = 0;//����ת��ѭ��������
			int cun;//��a.���ڵĴ洢
			cun = a.banqi;
			while (cun != 0)
			{
				cun = cun / 10;
				++p;
			}
			cun = a.banqi;
			for (int k = 0; k < p; k++)
			{
				int bencixingqishu;
				int xiaci = cun;
				bencixingqishu = xiaci;
				if (cun / 10 != 0) { bencixingqishu = cun / pow(10, p - (k + 1)); xiaci = cun - bencixingqishu * pow(10, p - (k + 1)); }//�Ѱ���ת��Ϊ����
				else { bencixingqishu = cun % 10; }
				if ((weekday + 1) == bencixingqishu)
				{
					cout << "�Ѿ�Ϊ���ҵ�����Ϊ" << riqi << "�����Ϊ" << q << "�ĺ���";
					z1 = 1;
					break;
				}

			}
			if (z1 == 0) { cout << "û���ҵ��ú���,������������ѡ�������" << endl; }

			else {  break; }

		}
		dingdanmingxixinxi b;
		dingdanmingxixinxi c;
		int toudengcangshuliang = 0;
		int gongwucangshuliang = 0;
		int jingjicangshuliang = 0;
		ofstream ofile;
		ofile.open("mayuan.dingdan.txt", ios::out | ios::binary|ios::app);
		ofile.close();
		ifstream ifile;
		ifile.open("mayuan.dingdan.txt", ios::in | ios::binary);
		ifile.seekg(0, ios::end);
		int len1 = ifile.tellg();
		int n1 = len1 / sizeof(dingdanmingxixinxi); 
		for (int k = 0; k < n1; k++)
		{
				ifile.seekg(sizeof(dingdanmingxixinxi) * k);
				ifile.read((char*)&b, sizeof(dingdanmingxixinxi));
				
				if (b.zuoweidengji == "toudengcang")
				{
					toudengcangshuliang += 1;
				}
				if (b.zuoweidengji == "gongwucang")
				{
					gongwucangshuliang += 1;
				}
				if (b.zuoweidengji == "jingjicang")
				{
					jingjicangshuliang += 1;
				}
		}
		ifile.close(); 
		cout << "�Ѿ�Ϊ��ѡ�񺽰��Ϊ" << q << "����Ϊ" << riqi << "�ĺ���" << endl;
		cout << "�ú����ͷ�Ȳ���Ϊ��" << a.toudengcangshu << "   �������Ϊ��" << a.gongwucangshu << "  ���ò���Ϊ��" << a.jingjicangshu << endl;
		cout << "�ú���ͷ�Ȳ�ʣ������Ϊ" << a.toudengcangshu - toudengcangshuliang << "  �����ʣ������Ϊ" << a.gongwucangshu - gongwucangshuliang << "  ���ò�ʣ������Ϊ" << a.jingjicangshu - jingjicangshuliang << endl;
		if (a.toudengcangshu - toudengcangshuliang != 0 && a.gongwucangshu - gongwucangshuliang != 0 && a.jingjicangshu - jingjicangshuliang != 0)
		{
				cout << "��ѡ����Ҫѡ����λ�ȼ�" << endl;
				cout << "1.ͷ�Ȳ�" << endl;
				cout << "2.�����" << endl;
				cout << "3.���ò�" << endl;
				int r;
				cin >> r;
				while (true)
				{
					switch (r)
					{
					case 1:if (a.toudengcangshu - toudengcangshuliang == 0) { cout << "ͷ�Ȳ���Ŀ����" << "������������Ҫѡ�����λ�ȼ�" << endl; break; }
						  else { z2 = 1; c.zuoweidengji = "toudengcang"; break; }
					case 2:if (a.gongwucangshu - toudengcangshuliang == 0) { cout << "�������Ŀ����" << "������������Ҫѡ�����λ�ȼ�" << endl; break; }
						  else { z2 = 1; c.zuoweidengji = "gongwucang"; break; }
					case 3:if (a.jingjicangshu - jingjicangshuliang == 0) { cout << "���ò���Ŀ����" << "������������Ҫѡ�����λ�ȼ�" << endl; break; }
						  else { z2 = 1; c.zuoweidengji = "jingjicang"; break; }
					}
					if (z2 == 1) { break; }
				}
				if (z2 == 1)
				{
					cout << "��Ʊ�ɹ���" << endl;
					cout << "��������������" << endl;
					cin >> c.chengkexingming;
					cout << "�����������ֻ���" << endl;
					cin >> c.dianhuahaoma;
					cout << "�������������֤��" << endl;
					cin >> c.shenfenzhenghao;
					c.chufariqi = riqi;
					c.hangbanhao = q;
					ifile.open("mayuan.dingdan.txt", ios::in | ios::binary);
					ifile.seekg(0, ios::end);
					int len1 = ifile.tellg();
					int n1 = len1 / sizeof(dingdanmingxixinxi); 
					c.dingdanhao = 220 + n1;
					ifile.close();
					ofile.open("mayuan.dingdan.txt", ios::app | ios::binary |ios::out);
					ofile.write((char*)&c, sizeof(c));
					ofile.close();
					cout << "���Ķ�����Ϣ�����룡" << endl;
					cout << "������Ϊ��" << c.dingdanhao;
				}
		}
		else
		{
				cout << "�ܱ�Ǹ" << "�����Ϊ" << q << "����Ϊ" << riqi << "�ĺ���" << "��λ����" << endl;
		}
	}
	dingtuipiaoxitong();
		
}
void tuipiao()
{
	cout << "��׼��Ϊ����Ʊ���������������֤��" << endl;
	long long int shenfenzheng;
	cin >> shenfenzheng;
	int n = 0;//���ϵ�����
	dingdanmingxixinxi a;
	dingdanmingxixinxi b;
	ifstream ifile;
	ifile.open("mayuan.dingdan.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len2 = ifile.tellg();
	int u = len2 / sizeof(dingdanmingxixinxi);
	ofstream ofile;
	ofile.open("mayuan.dingdan1.txt", ios::binary | ios::out|ios::app);
	for (int i = 0; i < u; i++)
	{
		ifile.seekg(sizeof(a) * i);
		ifile.read((char*)&a, sizeof(a));
		if (shenfenzheng == a.shenfenzhenghao)
		{
			cout << "dingdanhao��" << a.dingdanhao;
			b.dingdanhao = a.dingdanhao;
			b.hangbanhao = a.hangbanhao;
			b.chufariqi = a.chufariqi;
			b.zuoweidengji = a.zuoweidengji;
			b.chengkexingming = a.chengkexingming;
			b.shenfenzhenghao = a.shenfenzhenghao;
			b.dianhuahaoma = a.dianhuahaoma;
			ofile.write((char*)&b, sizeof(b));
			++n;
		}
	}
	ifile.close();
	ofile.close();
	if (n == 0) { cout << "δ�ҵ����֤��Ϊ" << shenfenzheng << "�ĳ˿�" << endl; }
	else
	{
		cout << "���ҵ����֤��Ϊ" << shenfenzheng << "�ĳ˿�" << endl;
		ifile.open("mayuan.dindan1.txt", ios::binary | ios::in);
		for (int i = 0; i < n; i++)
		{
			ifile.seekg(sizeof(a) * i);
			ifile.read((char*)&a, sizeof(a));
			cout << i + 1 << "." << "������Ϊ:" << a.dingdanhao << "�˿�����Ϊ:" << a.chengkexingming << "�绰����Ϊ:" << a.dianhuahaoma << "�����Ϊ:" << a.hangbanhao << "��������Ϊ:" << a.chufariqi << "��λ�ȼ�Ϊ:" << a.zuoweidengji << endl;
		}
		cout << "��������Ҫ��Ʊ�Ķ�����" << endl;
		int dingdanhao;
		int y = 0;
		while (true)
		{
			cin >> dingdanhao;
			for (int i = 0; i < n; i++)
			{
				ifile.seekg(sizeof(a) * i);
				ifile.read((char*)&a, sizeof(a));
				if (dingdanhao == a.dingdanhao)
				{
					y =1;
					break;
				}
			}
			if (y == 0) { cout << "δ�ҵ��ö����ţ�����������" << endl; }
			else { break; }
		}
		ifile.close();
		ifile.open("mayuan.dingdan1.txt", ios::binary | ios::trunc);
		ifile.close();
		ofile.close();
		if (y == 1)
		{
			dingdanmingxixinxi a;
			ifile.open("mayuan.dingdan.txt", ios::binary);
			ofile.open("mayuan.dingdan2.txt", ios::trunc | ios::binary);
			ofile.close();
			ofile.open("mayuan.dingdan2.txt", ios::trunc | ios::out);
			for (int i = 0; i < u; i++)
			{
				ifile.seekg(sizeof(dingdanmingxixinxi) * i);
				ifile.read((char*)&a, sizeof(a));
				if (a.shenfenzhenghao != shenfenzheng && a.dingdanhao != dingdanhao)
				{
					ofile.write((char*)&a, sizeof(a));
				}
			}
			ifile.close();
			ofile.close();
			ifile.open("mayuan.dingdan2.txt", ios::binary);
			ofile.open("mayuan.dingdan.txt", ios::trunc | ios::binary);
			ofile.close();
			ofile.open("mayuan.dingdan.txt", ios::binary | ios::out);
			for (int i = 0; i < u - 1; i++)
			{
				ifile.seekg(sizeof(a) * i);
				ifile.read((char*)&a, sizeof(a));
				ofile.write((char*)&a, sizeof(a));
			}
			cout << "��Ʊ�ɹ���" << endl;
			ifile.close();
			ofile.close();
			ofile.open("mayuan.dingdan2.txt", ios::binary | ios::trunc);
			ofile.close();
			dingtuipiaoxitong();
		}	
	}
}