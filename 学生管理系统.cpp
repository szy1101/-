/*
���˼·��
1��ѧ���ࣨstudent���͹���ʵ����(StudentManager)�ֿ���д
2��ѧ�������ѧ���ĸ��֡����������ṩ��ʾ�����Ĺ���
3������ʵ����ֺ���ʵ�ָ��ֹ��ܴ���˳������
-----�˵����˳�
-----���
-----�ļ�����
-----��ʾ
-----���򡢲���
*/

#include"StudentManager.h"
#include<iostream>
#include<string>
#include"student.h"
using namespace std;
int main()
{
	//���Դ���
	//Student stu(1, "szy", 1, 100, 1);
	//stu.showInfo();
	int choice = 0;
	StudentManager sm;
	while (true)
	{
		sm.showMenu();
		cout << "���������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			sm.exitSystem();
			break;
		case 1:
			sm.addStudent();
			break;
		case 2:
			sm.showStudent();
			break;
		case 3:
			sm.sortStudent();
			break;
		case 4:
			sm.findStudent();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	system("cls");
	return 0;
}