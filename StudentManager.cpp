//���û���ͨ�Ĳ˵�
//����ʵ��
//�ļ���д

#include"StudentManager.h"

StudentManager::StudentManager()  //�ڹ��캯�������ļ������������
// 1���ļ�������
// 2���ļ����ڣ���Ϊ��
// 3���ļ����ڣ���Ϊ�գ���������
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_stuNum = 0;  //��ʼ���ļ��е�����
		this->m_stuArray = NULL;  ////��ʼ������ָ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //�ļ������ھͲ��������������ˣ�ֱ��return
	}
	
	//�ļ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_stuNum = 0;  //��ʼ���ļ��е�����
		this->m_stuArray = NULL;  ////��ʼ������ָ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //�ļ������ھͲ��������������ˣ�ֱ��return
	}

	//�ļ�������������
	int num = this->getStudentNumber();  //��ȡ�ļ���ѧ������
	cout << "ѧ������Ϊ��" << num << endl;
	this->m_stuNum = num;

	this->m_stuArray = new Student * [num]; //�����¿ռ�
	this->initStudent(); //��ʼ���ļ���ѧ����Ϣ

	for (int i = 0; i < this->m_stuNum; i++)  //��ʾ����
	{
		cout << "ѧ��ѧ�ţ�" << this->m_stuArray[i]->m_Id
			<< "\tѧ��������" << this->m_stuArray[i]->m_Name
			<< "\t���ĳɼ���" << this->m_stuArray[i]->m_ChineseScores
			<< "\t��ѧ�ɼ���" << this->m_stuArray[i]->m_MathScores
			<< "\tӢ��ɼ���" << this->m_stuArray[i]->m_EnglishScores
			<< "\tƽ���ɼ���" << this->m_stuArray[i]->m_averageScores << endl;
	}
}
void StudentManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


void StudentManager::showMenu()
{
	cout << "**************************************" << endl;
	cout << "*********��ӭʹ��ѧ������ϵͳ*********" << endl;
	cout << "**********0���˳�����ϵͳ*************" << endl;
	cout << "**********1�����ѧ����Ϣ*************" << endl;
	cout << "**********2����ʾѧ����Ϣ*************" << endl;
	cout << "**********3������ѧ���ɼ�*************" << endl;
	cout << "**********4������ѧ����Ϣ*************" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}
void StudentManager::addStudent()
{
	cout << "���������ѧ������" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//���ѧ��
		int newSize = this->m_stuNum + addNum;  //������ӿռ��С
		Student** newSpace = new Student * [newSize];  //�����¿ռ�
		if (this->m_stuArray != NULL)
		{
			for (int i = 0; i < this->m_stuNum; i++)
			{
				newSpace[i] = this->m_stuArray[i];
			}
		}
		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			float chinese;
			float math;
			float english;

			cout << "�������" << i + 1 << "����ѧ��ѧ�ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ѧ��������" << endl;
			cin >> name;

			cout << "�������" << i + 1 << "����ѧ�����ĳɼ���" << endl;
			cin >> chinese;

			cout << "�������" << i + 1 << "����ѧ����ѧ�ɼ���" << endl;
			cin >> math;

			cout << "�������" << i + 1 << "����ѧ��Ӣ��ɼ���" << endl;
			cin >> english;
			
			Student* stu = new Student(id, name, chinese, math, english);

			newSpace[this->m_stuNum + i] = stu;
		}

		
		delete[] this->m_stuArray;  //�ͷ�ԭ�еĿռ�
		this->m_stuArray = newSpace;  //�����¿ռ�ָ��
		this->m_stuNum = newSize;  //����ѧ������

		cout << "�ɹ����" << addNum << "��ѧ��" << endl;
		this->save();
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}
void StudentManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	//��ÿ���˵�����д���ļ�
	for (int i = 0; i < this->m_stuNum; i++)
	{
		ofs << this->m_stuArray[i]->m_Id << " "
			<< this->m_stuArray[i]->m_Name << " "
			<< this->m_stuArray[i]->m_ChineseScores << " "
			<< this->m_stuArray[i]->m_MathScores << " "
			<< this->m_stuArray[i]->m_EnglishScores << " "
			<< this->m_stuArray[i]->m_averageScores << endl;
	}
	ofs.close();
}
int StudentManager::getStudentNumber()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	float ch;
	float ma;
	float en;
	double average;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> ch && ifs >> ma && ifs >> en && ifs >> average) //��Ϣ��ȫ����
	{
		num++;
	}
	ifs.close();
	return num;
}
void StudentManager::initStudent()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	float ch;
	float ma;
	float en;
	double average;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> ch && ifs >> ma && ifs >> en && ifs >> average)
	{
		Student* stu = new Student(id, name, ch, ma, en);
		this->m_stuArray[index] = stu;
		index++;
	}
	ifs.close();
}
void StudentManager::showStudent()
{
	if (this->m_FileIsEmpty)
	{
		cout << "��������" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_stuNum; i++)
		{
			this->m_stuArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void StudentManager::sortStudent()
{
	if (this->m_FileIsEmpty)
	{
		cout << "��������" << endl;
	}
	else
	{
		for (int i = 0; i < m_stuNum; i++)  //ѡ������
		{
			int min = i;
			for (int j = i + 1; j < m_stuNum; j++)
			{
				if (m_stuArray[i]->m_averageScores > m_stuArray[j]->m_averageScores)
				{
					min = j;
				}
			}
			if (i != min)
			{
				Student* temp = m_stuArray[i];
				m_stuArray[i] = m_stuArray[min];
				m_stuArray[min] = temp;

			}
		}
		cout << "����ɹ�,����Ϊ" << endl;
		this->save();
		this->showStudent();
	}
}
int StudentManager::isExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_stuNum; i++)
	{
		if (this->m_stuArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void StudentManager::makeTrouble(int id)
{
	int addNum = 1;
	//���ѧ��
	int newSize = this->m_stuNum + addNum;  //������ӿռ��С
	Student** newSpace = new Student * [newSize];  //�����¿ռ�
	if (this->m_stuArray != NULL)
	{
		for (int i = 0; i < this->m_stuNum; i++)
		{
			newSpace[i] = this->m_stuArray[i];
		}
	}
	//���������
	for (int i = 0; i < addNum; i++)
	{
		string name;
		float chinese;
		float math;
		float english;

		cout << "��������ѧ��������" << endl;
		cin >> name;

		cout << "��������ѧ�����ĳɼ���" << endl;
		cin >> chinese;

		cout << "��������ѧ����ѧ�ɼ���" << endl;
		cin >> math;

		cout << "��������ѧ��Ӣ��ɼ���" << endl;
		cin >> english;

		Student* stu = new Student(id, name, chinese, math, english);

		newSpace[this->m_stuNum + i] = stu;
	}


	delete[] this->m_stuArray;  //�ͷ�ԭ�еĿռ�
	this->m_stuArray = newSpace;  //�����¿ռ�ָ��
	this->m_stuNum = newSize;  //����ѧ������

	cout << "�ɹ����"<< endl;
	this->save();
	this->m_FileIsEmpty = false;
	this->sortStudent();
	this->showStudent();


	system("pause");
	system("cls");
}
void StudentManager::findStudent()
{
	sortStudent();
	if (this->m_FileIsEmpty)
	{
		cout << "�޼�¼" << endl;
	}
	else
	{
		int id;
		cout << "��������ҵ�id" << endl;
		cin >> id;
		int ret = isExist(id);
		if (ret != -1)
		{
			cout << "����" << ret << endl;
			cout << "��Ϣ���£�" << endl;
			this->m_stuArray[ret]->showInfo();
		}
		else
		{
			cout << "���޴���" << endl;
			cout << "�������" << endl;
			makeTrouble(id);
		}
	}
	system("pause");
	system("cls");
}
StudentManager::~StudentManager()
{
	if (this->m_stuArray != NULL)
	{
		delete[] this->m_stuArray;
		this->m_stuArray = NULL;
	}
}