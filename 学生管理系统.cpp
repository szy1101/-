/*
编程思路：
1、学生类（student）和功能实现类(StudentManager)分开编写
2、学生类包含学生的各种“参数”并提供显示参数的功能
3、功能实现类分函数实现各种功能大致顺序如下
-----菜单、退出
-----添加
-----文件交互
-----显示
-----排序、查找
*/

#include"StudentManager.h"
#include<iostream>
#include<string>
#include"student.h"
using namespace std;
int main()
{
	//测试代码
	//Student stu(1, "szy", 1, 100, 1);
	//stu.showInfo();
	int choice = 0;
	StudentManager sm;
	while (true)
	{
		sm.showMenu();
		cout << "请输入你的选择：" << endl;
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