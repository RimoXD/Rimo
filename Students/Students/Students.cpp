#include <iostream>
#include <fstream>
using namespace std;

struct student{
	short stu_id;
	short score;
};

int main()
{
	int number,i;
	cin >> number;
	student* stu;
	stu = new student[number];
	for (i = 0;i < number;i++)
	{
		cin >> stu[i].stu_id;
		cin >> stu[i].score;
	}
	ofstream file("out.txt", ios::out|ios::binary);
	ifstream bfile("out.txt",  ios::in | ios::binary);
	ofstream cfile("out.txt", ios::out |ios::app);
//	file.put('1');
	file.write((char*)stu, 2*sizeof(student));
	delete stu;
	stu = new student[number];
//	file.seekp(0, file.beg);
	for(int i=0;i<number;i++)
	bfile.read((char*)stu, sizeof(student));
//	bfile.seekg(0, file.end);
	cfile.put('\n');
//	cfile.put('3');
	cfile.write((char*)stu, 2 * sizeof(student));
	delete stu;
	file.close();
	bfile.close();
	cfile.close();
	return 0;
}
