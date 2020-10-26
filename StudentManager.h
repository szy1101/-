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
	void showMenu();  //��ʾ�˵�
	void exitSystem();  //�˳�ϵͳ
	void addStudent();  //���ѧ��
	void save();  //�����ļ�
	~StudentManager();
	int getStudentNumber();
	void initStudent();  //��ʼ�����ݣ��ļ�������ʱʹ��
	void showStudent();  //չʾѧ����Ϣ
	void sortStudent();  //����
	void findStudent();  //����
	int isExist(int);  //�ж�ѧ���Ƿ����
	void makeTrouble(int);  //��ɵ�����,���Ҳ����ڵ�����Ȼ�����

private:
	int m_Id = 0;  //ѧ��
	string m_Name;  //����
	float m_Chinese = 0;  //���ĳɼ�
	float m_Math = 0;  //��ѧ�ɼ�
	float m_English = 0;  //Ӣ��ɼ�
	double m_averageGrade = 0;  //ƽ���ɼ�
	int m_stuNum; //��¼�ļ���ѧ������
	Student** m_stuArray; //����ָ�룬ָ��һ��ָ�����飬�����е�ָ����ն������ٵ�ѧ����
	bool m_FileIsEmpty;
};
