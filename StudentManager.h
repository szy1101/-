#pragma once
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
#define FILENAME "stuFile.txt"
#include"student.h"

class StudentManager
{
public:
	StudentManager();
	void showMenu();  //显示菜单
	void exitSystem();  //退出系统
	void addStudent();  //添加学生
	void save();  //保存文件
	~StudentManager();
	int getStudentNumber();
	void initStudent();  //初始化数据，文件有数据时使用
	void showStudent();  //展示学生信息
	void sortStudent();  //排序
	void findStudent();  //查找
	int isExist(int);  //判断学生是否存在
	void makeTrouble(int);  //完成第三题,查找不存在的数据然后添加

private:
	int m_Id = 0;  //学号
	string m_Name;  //姓名
	float m_Chinese = 0;  //语文成绩
	float m_Math = 0;  //数学成绩
	float m_English = 0;  //英语成绩
	double m_averageGrade = 0;  //平均成绩
	int m_stuNum; //记录文件中学生人数
	Student** m_stuArray; //二级指针，指向一个指针数组，数组中的指针接收堆区开辟的学生类
	bool m_FileIsEmpty;
};
