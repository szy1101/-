//与用户沟通的菜单
//功能实现
//文件读写

#include"StudentManager.h"

StudentManager::StudentManager()  //在构造函数载入文件，分三种情况
// 1、文件不存在
// 2、文件存在，且为空
// 3、文件存在，不为空，载入数据
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_stuNum = 0;  //初始化文件中的人数
		this->m_stuArray = NULL;  ////初始化数组指针
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //文件不存在就不进行其他代码了，直接return
	}
	
	//文件存在且为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_stuNum = 0;  //初始化文件中的人数
		this->m_stuArray = NULL;  ////初始化数组指针
		this->m_FileIsEmpty = true;
		ifs.close();
		return;  //文件不存在就不进行其他代码了，直接return
	}

	//文件存在且有数据
	int num = this->getStudentNumber();  //读取文件中学生人数
	cout << "学生人数为：" << num << endl;
	this->m_stuNum = num;

	this->m_stuArray = new Student * [num]; //开辟新空间
	this->initStudent(); //初始化文件中学生信息

	for (int i = 0; i < this->m_stuNum; i++)  //显示数据
	{
		cout << "学生学号：" << this->m_stuArray[i]->m_Id
			<< "\t学生姓名：" << this->m_stuArray[i]->m_Name
			<< "\t语文成绩：" << this->m_stuArray[i]->m_ChineseScores
			<< "\t数学成绩：" << this->m_stuArray[i]->m_MathScores
			<< "\t英语成绩：" << this->m_stuArray[i]->m_EnglishScores
			<< "\t平均成绩：" << this->m_stuArray[i]->m_averageScores << endl;
	}
}
void StudentManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


void StudentManager::showMenu()
{
	cout << "**************************************" << endl;
	cout << "*********欢迎使用学生管理系统*********" << endl;
	cout << "**********0、退出管理系统*************" << endl;
	cout << "**********1、添加学生信息*************" << endl;
	cout << "**********2、显示学生信息*************" << endl;
	cout << "**********3、排序学生成绩*************" << endl;
	cout << "**********4、查找学生信息*************" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}
void StudentManager::addStudent()
{
	cout << "请输入添加学生人数" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//添加学生
		int newSize = this->m_stuNum + addNum;  //计算添加空间大小
		Student** newSpace = new Student * [newSize];  //开辟新空间
		if (this->m_stuArray != NULL)
		{
			for (int i = 0; i < this->m_stuNum; i++)
			{
				newSpace[i] = this->m_stuArray[i];
			}
		}
		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			float chinese;
			float math;
			float english;

			cout << "请输入第" << i + 1 << "个新学生学号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新学生姓名：" << endl;
			cin >> name;

			cout << "请输入第" << i + 1 << "个新学生语文成绩：" << endl;
			cin >> chinese;

			cout << "请输入第" << i + 1 << "个新学生数学成绩：" << endl;
			cin >> math;

			cout << "请输入第" << i + 1 << "个新学生英语成绩：" << endl;
			cin >> english;
			
			Student* stu = new Student(id, name, chinese, math, english);

			newSpace[this->m_stuNum + i] = stu;
		}

		
		delete[] this->m_stuArray;  //释放原有的空间
		this->m_stuArray = newSpace;  //更改新空间指向
		this->m_stuNum = newSize;  //更新学生人数

		cout << "成功添加" << addNum << "名学生" << endl;
		this->save();
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");
}
void StudentManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	//将每个人的数据写入文件
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

	while (ifs >> id && ifs >> name && ifs >> ch && ifs >> ma && ifs >> en && ifs >> average) //信息完全计数
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
		cout << "暂无数据" << endl;
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
		cout << "暂无数据" << endl;
	}
	else
	{
		for (int i = 0; i < m_stuNum; i++)  //选择排序
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
		cout << "排序成功,其结果为" << endl;
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
	//添加学生
	int newSize = this->m_stuNum + addNum;  //计算添加空间大小
	Student** newSpace = new Student * [newSize];  //开辟新空间
	if (this->m_stuArray != NULL)
	{
		for (int i = 0; i < this->m_stuNum; i++)
		{
			newSpace[i] = this->m_stuArray[i];
		}
	}
	//添加新数据
	for (int i = 0; i < addNum; i++)
	{
		string name;
		float chinese;
		float math;
		float english;

		cout << "请输入新学生姓名：" << endl;
		cin >> name;

		cout << "请输入新学生语文成绩：" << endl;
		cin >> chinese;

		cout << "请输入新学生数学成绩：" << endl;
		cin >> math;

		cout << "请输入新学生英语成绩：" << endl;
		cin >> english;

		Student* stu = new Student(id, name, chinese, math, english);

		newSpace[this->m_stuNum + i] = stu;
	}


	delete[] this->m_stuArray;  //释放原有的空间
	this->m_stuArray = newSpace;  //更改新空间指向
	this->m_stuNum = newSize;  //更新学生人数

	cout << "成功添加"<< endl;
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
		cout << "无记录" << endl;
	}
	else
	{
		int id;
		cout << "请输入查找的id" << endl;
		cin >> id;
		int ret = isExist(id);
		if (ret != -1)
		{
			cout << "排序：" << ret << endl;
			cout << "信息如下：" << endl;
			this->m_stuArray[ret]->showInfo();
		}
		else
		{
			cout << "查无此人" << endl;
			cout << "进行添加" << endl;
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