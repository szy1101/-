#include"student.h"

Student::Student(int id, string name, float chinese, float math, float english)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_ChineseScores = chinese;
	this->m_MathScores = math;
	this->m_EnglishScores = english;
	this->m_averageScores = (this->m_ChineseScores + m_MathScores + m_EnglishScores) / 3;
}
void Student::showInfo()
{
	cout << "学生学号：" << this->m_Id
		<< "\t学生姓名：" << this->m_Name
		<< "\t语文成绩：" << this->m_ChineseScores
		<< "\t数学成绩：" << this->m_MathScores
		<< "\t英语成绩：" << this->m_EnglishScores
		<< "\t平均成绩：" << this->m_averageScores << endl;
}