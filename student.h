#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student(int, string, float, float, float);
	void showInfo();
	
	int m_Id;
	string m_Name;
	float m_ChineseScores;
	float m_MathScores;
	float m_EnglishScores;
	double m_averageScores;
};