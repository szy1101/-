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
	cout << "ѧ��ѧ�ţ�" << this->m_Id
		<< "\tѧ��������" << this->m_Name
		<< "\t���ĳɼ���" << this->m_ChineseScores
		<< "\t��ѧ�ɼ���" << this->m_MathScores
		<< "\tӢ��ɼ���" << this->m_EnglishScores
		<< "\tƽ���ɼ���" << this->m_averageScores << endl;
}