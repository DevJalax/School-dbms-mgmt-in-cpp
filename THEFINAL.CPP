// new version of jvm pro
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include <conio.h>
class student
{
	int admnno,year,clas,srlno,age;
	char name[30],sec,mt[15];
	char fn[30],mn[30],f_oc[30],m_oc[30],addr[50],gender;
	long int dob,mob_no;
	int total;
	float avg;
	public:
	student();
	void ReadStudentData();//gets student info and writes it into the file
	void appen1();//to append a student record in a file
	void mod1();//to modify file contents
	void del1();//to delete the record
	void ins1();//to insert a record
	void disp1();//to display the record
	void read1();//to read the record
	void sear1();//to search the record
	void check1();//to display male report
	void check2();//to display female report
	void print1();//to call disp1()
	void create1();//to create a record
}s;
class teacher
{
	char addr[50],name[30],subj[20],gender;
	long int dob,mob_no;
	public:
	teacher();
	void mod();//to modify teacher record
	void del();// to delete teacher record
	void ins();//to insert a teacher record
	void sear();//to search for a teacher record
	void disp();//to display a teacher record
	void appen();//to append a teacher record
	void read();//to read a teacher record
	void input();//to input the record and write in file
	void check();//to display teachers report
	void print();//to  display record from the file
	void create();//to create a teacher record
 }t;
 void student::ReadStudentData() //to input student data and write into the file
{
	fstream f;
	char ch;
	f.open("student.dat",ios::binary|ios::in|ios::out);
	do
	{
	f.read((char*)&s,sizeof(s));
	cout<<"enter the name"<<endl;
	gets(name);
	cout<<"enter the gender"<<endl;
	cin>>gender;
	cout<<"enter the year"<<endl;
	cin>>year;
	cout<<"enter date of birth"<<endl;
	cin>>dob;
	cout<<"enter the mother tongue"<<endl;
	gets(mt);
	cout<<"enter the class"<<endl;
	cin>>year;
	cout<<"enter the section"<<endl;
	cin>>sec;
	cout<<"enter the total marks secured by student"<<endl;
	cin>>total;
	avg=total/5;
	cout<<"enter the serial number"<<endl;
	cin>>srlno;
	cout<<"enter the admission number"<<endl;
	cin>>admnno;
	cout<<"enter name of father"<<endl;
	gets(fn);
	cout<<"enter name of the mother"<<endl;
	gets(mn);
	cout<<"enter the occupation of the father"<<endl;
	gets(f_oc);
	cout<<"enter the occupation of the mother"<<endl;
	gets(m_oc);
	cout<<"enter the address"<<endl;
	gets(addr);
	cout << "enter the mobile number"<<endl;
	cin>>mob_no;
	f.write((char*)&s,sizeof(s));
	cout << "Thank you. Press a key to continue ";
	getch();
	cout<<"want to enter any more data?:";
	cin>>ch;
      }while(ch=='y'||ch=='Y');
      f.close();
      cout<<"op success";
}
void teacher::input()
{
	fstream f;
	char ch;
	f.open("teacher.dat",ios::binary|ios::in|ios::out);
	do
	{
	cout<<"enter the address";
	gets(t.addr);
	cout<<"enter name:";
	gets(name);
	cout<<"enter the gender(M/F)";
	cin>>gender;
	cout<<"enter the subject:";
	gets(subj);
	cout<<"enter the date of b";
	cin>>dob;
	cout<<"enter the mobile no";
	cin>>mob_no;
	cout<<"Press any key to continue";
	getch();
	cout<<"do u want to continue?";
	cin>>ch;
	}while(ch=='y'||ch=='Y');
	f.close();
	cout<<"op success";
}
void student::sear1()                   //done
{
	ifstream f1;
	int admn_n;
	char found='n';
	f1.open("student.dat",ios::binary);
	cout<<"enter the admnno of the record to be modified";
	cin>>admn_n;
	while(!f1.eof())
	{
	f1.read((char*)&s,sizeof(s));
	if(s.admnno==admn_n)
	 {
	  cout<<"name of the student:"<<s.name<<'\n';
	  cout<<"admission no:"<<s.admnno<<'\n';
	  cout<<"class:"<<s.clas<<'\n';
	  cout<<"section:"<<s.sec;
	  found='y';
	 }
		 }
		 if(found=='n')
		 {
		 cout<<"admission no not found in file!!"<<'\n';
		 }
		 f1.close();
		cout<<"op success:";
		}
void teacher::sear()     //done
{
	char nm[20],found='n';
	ifstream f1;
	f1.open("teacher.dat",ios::binary);
	cout<<"enter the name of teacher";
	gets(nm);
	while(!f1.eof())
	{
	 f1.read((char*)&t,sizeof(t));
	 if(strcmpi(name,nm)==0)
	 {
		print();
		found='y';
		break;
	  }
	}
	if(found=='n')
	{
	 cout<<"name not found in file!!"<<'\n';
	}
	cout<<"op success:";
	f1.close();
}
void student::read1()
{                                            //read the file
	ifstream f1;
	f1.open("student.dat", ios::binary);
	while(f1.read((char*)&s,sizeof(s)))
	{

	  print1();
	  f1.close();
	  cout<<"op success:";
	  getch();
	}

}
void teacher::read()
{
	ifstream f1;
	f1.open("teacher.dat",ios::binary);
	while(!f1.eof())
	{
	f1.read((char*)&t,sizeof(t));
	print();
	cout<<"op success";
	getch();
	}
	f1.close();
}
void student::check1()
{
	int countm=0;
	fstream f;
	f.open("student.dat",ios::in|ios::out|ios::binary);
	cout<<"\t\t\t\tREPORT FOR THE YEAR(BOYS):"<<'\n';
	while(!f.eof())
	{
	 f.read((char*)&s,sizeof(s));
	if(s.gender=='m'||s.gender=='M')
	{
		countm++;

	}
	}
	f.close();
	cout<<"no of boys in the school:"<<countm;
	print1();
}
 void student::check2()
 {

	int countf=0;
	fstream f;
	f.open("student.dat",ios::in|ios::out|ios::binary);
	cout<<"\t\t\t\tREPORT FOR THE YEAR(GIRLS):"<<'\n';
	while(!f.eof())
	{
	 f.read((char*)&s,sizeof(s));
	if(s.gender=='F'||s.gender=='f')
	{
		countf++;

	}
	}
	f.close();
	cout<<"no of girls in the school :"<<countf;
	print1();
	cout<<"op success:";
}
void teacher::check()
{
 int countm=0,countf=0;
 fstream f;
 f.open("teacher.dat",ios::in|ios::out|ios::binary);
 cout<<"\t\t\t\tREPORT FOR TEACHERS :"<<'\n';
 while(!f.eof())
 {
  f.read((char*)&t,sizeof(t));
  if(t.gender=='m'||t.gender=='M')
  {
   countm++;
   }
   else if(t.gender=='f'||t.gender=='F')
	{
	 countf++;
	}
   }
   f.close();
  cout<<"no of male teachers in the school:"<<countm<<'\n';
  cout<<"no of female teachers in the school :"<<countf<<'\n';
  print();
}
 void intro1()
{

cout<<"     ___     ____  __    ____   ____ _   _  ___   ___  _     \n"
    <<"    | \\ \\   / |  \\/  |  / ___| / ___| | | |/ _ \\ / _ \\| |    \n"
    <<" _  | |\\ \\ / /| |\\/| |  \\___ \\| |   | |_| | | | | | | | |    \n"
    <<"| |_| | \\ V / | |  | |   ___) | |___|  _  | |_| | |_| | |___ \n"
    <<" \\___/   \\_/  |_|  |_|  |____/ \\____|_| |_|\\___/ \\___/|_____|\n\n\n";

cout<<" ____    _  _____  _    ____    _    ____  _____ \n"
    <<"|  _ \\  / \\|_   _|/ \\  | __ )  / \\  / ___|| ____|\n"
    <<"| | | |/ _ \\ | | / _ \\ |  _ \\ / _ \\ \\___ \\|  _|  \n"
    <<"| |_| / ___ \\| |/ ___ \\| |_) / ___ \\ ___) | |___ \n"
    <<"|____/_/   \\_|_/_/   \\_|____/_/   \\_|____/|_____|\n";
}
void student::ins1()
{
 int d;
 student tem;
 ifstream f("student.dat",ios::binary);
 ofstream g("temp.dat",ios::binary);
 cout<<"enter admission no to be inserted";
 cin>>d;
 cout<<"enter details of new record to be inserted";
 ReadStudentData();
 f.read((char*)&s,sizeof(s));
 while(!f.eof())
 {
  if(s.admnno==d)
  {
   g.write((char*)&tem,sizeof(tem));
   g.write((char*)&s,sizeof(s));
   f.read((char*)&s,sizeof(s));
  }
  else
  cout<<"admission no not found:";
  }
  f.close();
  g.close();
  int k=remove("student.dat");
  k=rename("temp.dat","student.dat");
}
void teacher::ins()
{
  char nm1[30];
 teacher tem;
 ifstream f("teacher.dat",ios::binary);
 ofstream g("temp.dat",ios::binary);
 cout<<"enter the teacher name to be inserted";
 gets(nm1);
 cout<<"enter details of new record to be inserted";
 input();
 f.read((char*)&s,sizeof(s));
 while(!f.eof())
 {
  if(strcmpi(t.name,nm1)==0)
  {
   g.write((char*)&tem,sizeof(tem));
   g.write((char*)&t,sizeof(t));
   f.read((char*)&t,sizeof(t));
  }
  else
  cout<<"admission no not found:";
  }
  f.close();
  g.close();
  int k=remove("teacher.dat");
  k=rename("temp.dat","teacher.dat");
}
void student::disp1()//to display student info          //done
{
	read1();
	cout<<"NAME :";
	puts(name);
	cout<<'\n';
	cout<<"GENDER :"<<gender<<'\n';
	cout<<"CLASS :"<<clas<<'\n';
	cout<<"SECTION :"<<sec<<'\n';
	cout<<"ADMISSION NO :"<<admnno<<'\n';
	cout<<"ROLL NO :"<<srlno<<'\n';
	cout<<"YEAR OF STUDY:"<<year<<'\n';
	cout<<"MOTHER TONGUE :";
	puts(mt);
	cout<<'\n';
	cout<<"FATHER NAME :";
	puts(fn);
	cout<<'\n';
	cout<<"MOTHER NAME :";
	puts(mn);
	cout<<'\n';
	cout<<"FATHER's OCCUPATION :";
	puts(f_oc);
	cout<<'\n';
	cout<<"MOTHER's OCCUPATION :";
	puts(m_oc);
	cout<<'\n';
	cout<<"RESIDENTIAL ADDRESS :";
	puts(addr);
	cout<<'\n';
	cout<<"DATE OF BIRTH:"<<dob<<'\n';
	cout<<"MOBILE NO :"<<mob_no;
	getch();
}
void teacher::disp()
{
	ofstream f;
	f.open("teacher.dat",ios::binary);
	while(!f.eof())
	{
	cout<<"NAME OF THE TEACHER :";
	puts(t.name);
	cout<<'\n';
	cout<<"SUBJECT TAKEN BY TEACHER :";
	puts(t.subj);
	cout<<'\n';
	cout<<"GENDER :"<<t.gender<<'\n';
	cout<<" DATE OF BIRTH :"<<t.dob<<'\n';
	cout<<"MOBILE NO :"<<t.mob_no<<'\n';
	cout<<"ADDRESS :";
	puts(t.addr);
	getch();
	}
}

void student::print1()
{
ifstream f("student.dat",ios::binary);
f.read((char*)&s,sizeof(s));
while(!f.eof())
{
 s.disp1();
 f.read((char*)&s,sizeof(s));
}
f.close();
}
void teacher::print()
{
ifstream f("teacher.dat",ios::binary);
f.read((char*)&t,sizeof(t));
while(!f.eof())
{
 t.disp();
 f.read((char*)&t,sizeof(t));
}
f.close();
}
void student::appen1()  //appending a record        //done
{
	ofstream f2;
	char an='y';
	f2.open("student.dat",ios::binary|ios::app);
	while(an=='y')
	{
	ReadStudentData();
	f2.write((char*)&s,sizeof(s));
	cout<<"op success"<<'\n';
	cout<<"Record added to the file"<<'\n';
	cout<<"want to enter more records?(y/n)..";
	cin>>an;
	}
	f2.close();
}
void teacher::appen()  //appending a record        //done
{
	ofstream f2;
	char an='y';
	f2.open("teacher.dat",ios::binary|ios::app);
	while(an=='y')
	{
	input();
	f2.write((char*)&s,sizeof(s));
	cout<<"op success"<<'\n';
	cout<<"Record added to the file"<<'\n';
	cout<<"want to enter more records?(y/n)..";
	cin>>an;
	}
	f2.close();
}
student::student()
{
 admnno=0;
 year=0;
 clas=0;
 srlno=0;
 dob=0;
 total=0;
 avg=0;
 mob_no=0;
 sec='\0';
 strcpy(mt,"NULL");
 strcpy(name,"NULL");
 strcpy(fn,"NULL");
 strcpy(mn,"NULL");
 strcpy(f_oc,"NULL");
 strcpy(m_oc,"NULL");
 strcpy(addr,"NULL");
 strcpy(mt,"NULL");
}
teacher::teacher()
{
	strcpy(addr,"NULL");
	strcpy(name,"NULL");
	strcpy(subj,"NULL");
	dob=0;
	mob_no=0;
}

void student::del1()            //done
{
	ifstream f1;
	ofstream f2;
	int admn_n;
	f1.open("student.dat",ios::binary);
	f2.open("temp.dat",ios::binary);
	char found='N',conf='n';
	cout<<"enter the admnno to be deleted";
	cin>>admn_n;
	while(!f1.eof())
	{
	 f1.read((char*)&s,sizeof(s));
	 if(s.admnno==admn_n)
	 {
	  found='f';
	  cout<<"do u want to delete this record(y/n):";
	  cin>>conf;
	  if(conf=='n')
	  {
	  f2.write((char*)&s,sizeof(s));
	 }
	}
	 f2.write((char*)&s,sizeof(s));
		 }
		 if(found=='N')
		 {
	cout<<"record not found!!"<<'\n';}
	f1.close();
	f2.close();
	remove("student.dat");
	rename("temp.dat","student.dat");
	f1.open("student.dat",ios::in);
	cout<<"now the file contains:"<<'\n';
	 read1();
	f1.close();
	cout<<"op success:";
}
void teacher::del()            //done
{
	ifstream f1;
	ofstream f2;
	char nm1[30];
	f1.open("teacher.dat",ios::binary);
	f2.open("temp.dat",ios::binary);
	char found='N',conf='n';
	cout<<"enter the name of the teacher whose record to be deleted";
	gets(nm1);
	while(!f1.eof())
	{
	 f1.read((char*)&s,sizeof(s));
	 if(strcmpi(t.name,nm1)==0)
	 {
	  found='f';
	  cout<<"do u want to delete this record(y/n):";
	  cin>>conf;
	  if(conf=='n')
	  {
	  f2.write((char*)&s,sizeof(s));
	 }
	}
	 f2.write((char*)&s,sizeof(s));
		 }
		 if(found=='N')
		 {
	cout<<"record not found!!"<<'\n';}
	else if(found=='f')
	     {
	      cout<<"record found in the file";
	     }
	f1.close();
	f2.close();
	remove("teacher.dat");
	rename("temp.dat","teacher.dat");
	f1.open("teacher.dat",ios::in);
	cout<<"now the file contains:"<<'\n';
	 print();
	f1.close();
	cout<<"op success:";
}
void student::create1()
{
 char opt;
 ofstream f("student.dat",ios::binary);
 do
 {
  ReadStudentData();
 f.write((char*)&s,sizeof(s));
 cout<<"any more records?";
 cin>>opt;
 }while(opt=='Y'||opt=='y');
 f.close();
}
void teacher::create()
{
 char opt;
 ofstream f("teacher.dat",ios::binary);
 do
 {
 t.input();
 f.write((char*)&t,sizeof(t));
 cout<<"any more records?";
 cin>>opt;
 }while(opt=='Y'||opt=='y');
 f.close();
}
void student::mod1()
{
 char nm1[30];
 fstream f;
 f.open("student.dat",ios::binary|ios::in|ios::out);
 while(!f.eof())
 {
  f.read((char*)&s,sizeof(s));
 cout<<"enter the name to be modified";
 gets(nm1);
 if(strcmpi(name,nm1)==0)
 {
  cout<<"enter the details of new student";
  ReadStudentData();
  f.write((char*)&s,sizeof(s));
 }
  else
 cout<<"name not found in file";}
 f.close();
 }
 void teacher::mod()
{
 char nm1[30];
 fstream f;
 f.open("teacher.dat",ios::binary|ios::in|ios::out);
 while(!f.eof())
 {
  f.read((char*)&t,sizeof(t));
 cout<<"enter the name to be modified";
 gets(nm1);
 if(strcmpi(name,nm1)==0)
 {
  cout<<"enter the details of new teacher";
  t.input();
  f.write((char*)&t,sizeof(t));
 }
 else
 cout<<"name not found in file";}
 f.close();
 }
void main()
{
	clrscr();
	intro1();
	int clas,n,opt,tg,ch3,ch2,ch,a;
	char sec,choice,ach,ch1,ch5,d;
	student s;
	teacher t;
	fstream f,f1;
	do
	{

		cout<<"enter class and section";
		cin >> clas >> sec;
		cout<<"enter the no of students in this section";
		cin>>n;
		cout<<"enter the no of teachers in the school";
		cin>>tg;
		cout << "Student database or teacher database?(s/t)";
		cin >> choice;
		if(choice=='s')
		{
			cout<<"Student database:"<<'\n';
			cout<<"1.Read student Info"<<'\n';
			cout<<"2.Display Student Info"<<'\n';
			cout<<"3.search for a record"<<'\n';
			cout<<"4.modification"<<'\n';
			cout<<"5.deletion"<<'\n';
			cout<<"6.insertion"<<'\n';
			cout<<"7.report for the year for boys"<<'\n';
			cout<<"8.report for year for girls"<<'\n';
			cout<<"9.read"<<'\n';
			cout<<"10.append a record :"<<'\n';
			cout<<"11.creation of student record:"<<'n';
			cout<<"enter ur choice";
			cin>>opt;
			switch(opt)
			{
				case 1:
					s.ReadStudentData();
					break;
				case 2:
					s.disp1();
					break;
				case 3:
					s.sear1();
					break;
				case 4:
					s.mod1();
					break;
				case 5:
					s.del1();
					break;
				case 6:
					s.ins1();
					break;
				case 7:
					cout<<"report for boys:";
					s.check1();
					break;
				case 8:
					cout<<"report for girls:";
					s.check2();
					break;
				case 9:
					s.read1();
					break;
				case 10:
					 s.appen1();
					break;
				case 11:
					 s.create1();
					 break;
				default:
					cout<<"enter a correct option";
					break;
			}
		}
		else if(choice == 't')
		{
			cout<<"Teacher database:"<<'\n';
			cout<<"1.input"<<'\n';
			cout<<"2.append a record"<<'\n';
			cout<<"3.search for a record"<<'\n';
			cout<<"4.modification"<<'\n';
			cout<<"5.deletion"<<'\n';
			cout<<"6.insertion"<<'\n';
			cout<<"7.report for teachers "<<'\n';
			cout<<"8.read"<<'\n';
			cout<<"9.creation of a teacher record"<<'\n';
			cout<<"enter ur choice";
			cin>>opt;
			switch(opt)
			{
				case 1:
					t.input();
					break;
				case 2:
					t.appen();
					break;
				case 3:
					t.sear();
						 break;
				case 4:
					t.mod();
					break;
				case 5:
					t.del();
					break;
				case 6:
					t.ins();
					break;
				case 7:
					t.disp();
					break;
				case 8:
					t.read();
					break;
				case 9:
					t.create();
					break;
					default:
					cout<<"enter a correct option";
					break;
				}
			}
			cout<<"do u want to continue ? (Y/N)";
			cin>>ch5;
				 }while(ch5=='Y' || ch5=='y' );

		if(ch5=='N'||ch5=='n')
		{
		 cout<<"do u want to display student or teacher database?";
		 cin>>d;
		 if(d=='s'||d=='S')
			s.read1();
		 else if(d=='t'||d=='T')
			t.read();
		  else
		  cout<<"GOOD BYE";
			 }
			 f.close();
			 f1.close();
			 }






