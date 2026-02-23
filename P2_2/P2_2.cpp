#include<iostream>
#include<string.h>
using namespace std;
class studentRecord
{
	int rollNo;
	float marks1,marks2,marks3;
	char name[30];
public:
	studentRecord()
	{
		rollNo=1;
		strcpy(name,"xyz");
		marks1=marks2=marks3=0;
	}

	void average();
	char searchStudent(int);
	void addStudent(int x,studentRecord *);
};
int main()
{
	studentRecord s[30];
	int x=0,i,rn;
	int c;
	r1:
	cout<<"\n1-Add Student\n2-Find Average\n0-Exit\nEnter Choice :";
	cin>>c;
	switch(c)
	{
		case 1:
			s[x].addStudent(x,s);
			x++;
			goto r1;
		case 2:
			cout<<"Enter Roll No. : ";
			cin>>rn;
			for(i=0;i<x;i++)
			{
				if(s[i].searchStudent(rn)=='y')
				{
					s[i].average();
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nStudent not found!\n";
			}
			goto r1;
		case 0:
			cout<<"\n......Exiting......\n";
			return 0;
		default:
			cout<<"\nInvalid Choice!\n";
			goto r1;
	}

}

void studentRecord::addStudent(int x,studentRecord *s)
{
	int i;
	r2:
	cout<<"\nEnter RollNo. : ";
	cin>>rollNo;
	for(i=0;i<x;i++)
	{
		if(rollNo==s[i].rollNo)
		{
			cout<<"\nDuplicate Roll No. exists\n";
			goto r2;
		}
	}
	getchar();
	cout<<"Enter Name : ";
	cin.getline(name,30);
	cout<<"Enter Marks 1 : ";
	cin>>marks1;
	cout<<"Enter Marks 2 : ";
	cin>>marks2;
	cout<<"Enter Marks 3 : ";
	cin>>marks3;
}

char studentRecord::searchStudent(int rn)
{
	if(rn==rollNo)
		return 'y';
	return 'n';
}

void studentRecord::average()
{
	cout<<"\nAverage : "<<(float)(marks1+marks2+marks3)/3<<endl;
}
