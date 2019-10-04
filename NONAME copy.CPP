#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iomanip.h>
#include<fstream.h>
#include<stdlib.h>
int counter=0,points=0;
class quiz
{
	private:int no;
		char question[200],answer[100],userans[100];
		char *q;
	public: void createq()
		{
		fstream file;
		file.open("quizz.dat",ios::in|ios::app|ios::out|ios::binary);
		char ch='y';
		do
		{
		cout<<"Question no. "<<endl;
		cin>>no;
		cout<<"Enter a question to be added to the roster"<<endl;
		gets(question);
		cout<<"Enter the answer to the question"<<endl;
		gets(answer);
		file.write((char*)&quest,sizeof(quest));
		++counter;
		cout<<"Do you want to add more questions?(y/n)"<<endl;
		cin>>ch;
		}while(ch=='y');
		}
		void viewall()
		{
		fstream f1;
		f1.open("quizz.dat",ios::in|ios::out|ios::binary|ios::app);
		while(f1.read((char*)&quest,sizeof(quest)))
		{       cout<<"No. "<<no<<endl;
			cout<<"The question is : ";
			puts(question);
			cout<<endl<<"The answer is : ";
			puts(answer);
			cout<<endl<<endl<<endl;
		}
		}
		void modifyq()
		{
		int n;
		char found;
		cout<<"Enter the question no. to be modified"<<endl;
		cin>>n;
		ifstream f2("quizz.dat", ios::in | ios::binary);
		ofstream f3("tempp.dat",ios::out | ios::binary);
		found='n';
			while(f2.read((char*) &quest, sizeof(quest)))
			{

				if(no==n)
				{
					updatedata();
					f3.write((char*)&quest, sizeof(quest));
					found='y';
					cout<<"Question has been modified"<<endl;
				}
				else
				{	f3.write((char*)&quest, sizeof(quest));
				}
			}
				if(found=='n')
				{
				cout<<"No such question exists";
				}
			f2.close();
			f3.close();    
			remove("quizz.dat");
			rename("tempp.dat","quizz.dat");
		}
		void updatedata()
		{
		char q[200], a[100],nn;
		cout<<"Question no"<<endl;
		cin>>nn;
		cout<<"New question"<<endl;
		gets(q);
		cout<<"Answer"<<endl;
		gets(a);
		}
		void userquestion(int qn)
		{
		fstream fil;
		fil.open("quizz.dat",ios::in|ios::out|ios::app|ios::binary);
			while(fil.read((char*)&quest,sizeof(quest)))
			{
				if(qn==no)
				{
				puts(question);
				}
			}
		}
		void delq()
		{
		int del;
		cout<<"Enter the question no. to be deleted"<<endl;
		cin>>del;
		fstream f5,f6;
		f5.open("quizz.dat",ios::in|ios::out|ios::app|ios::binary);
		f6.open("tempp.dat",ios::in|ios::out|ios::app|ios::binary);
		while(f5.read((char*)&quest,sizeof(quest)))
		{
			if(del==no)
			{
			}
			else
			{
			f6.write((char*)&quest,sizeof(quest));
			cout<<"The question is successfully deleted.";
			}
		}
		remove("quizz.dat");
		rename("tempp.dat","quizz.dat");
		}
		/*void removeq()
		{
		fstream file1;
		file1.open("quizz.dat",ios::in|ios::out|ios::binary|ios::app);
		cout<<"The file is being removed"<<endl;
		remove("quizz.dat");
		}  */
		int anscheck(char tempp,int no1)
		{
		fstream file2;
		file2.open("quizz.dat",ios::in|ios::out|ios::binary|ios::app);
		while(file2.read((char*)&quest,sizeof(quest)))
		{
			if(no1==no)
			{
			if(tempp==*answer)
				{
					cout<<"The answer is correct."<<endl;
					++points;
					return 1;
				}
				else
				{
					cout<<"The answer is incorrect."<<endl;
					cout<<"\t\t\t GAME OVER"<<endl;
					points=0;
					return 0;
				}
			}
		}
		}
}quest;

void main()
{
clrscr();
int option,var,var1;
char ans[100],name[100],qno;
cout<<"     ______________________________________________________ "<<endl;
cout<<"      *      Welcome to the Quiz Show!!!!!!!!!!!          *"<<endl;
for(int i=0; i<20;i++)
{
	      if(i==10)
	      {
cout<<"      *    Press 1 to enter questions, 2 to modify a      * \n      *    question , 3 to delete a question, 4 to view   *\n      *        the roster and 5 to play a game.           *"<<endl;
	      continue;
	      }
cout<<"      *                                                   *"<<endl;
}
cout<<"     _______________________________________________________"<<endl;
cin>>option;
switch(option)
{
	case 1:clrscr();
	       quest.createq();
	       break;
	case 2:clrscr();
	       quest.modifyq();
	       break;
	case 3:clrscr();
	       quest.delq();
	       break;
	case 4:clrscr();
	       quest.viewall();
	       break;
	case 5:clrscr();

	       randomize();
	       cout<<"Enter your name "<<endl;
	       gets(name);
	       cout<<"Get ready to play!!!!"<<endl;
	       a:
	       var=randomize(counter)+1;//try random too
	       qno=var;
	       quest.userquestion(qno);
	       cout<<"Your answer is"<<endl;
	       gets(ans);
	       var1=quest.anscheck(*ans,qno);
	       if(var1==1)
	       {
	       cout<<"Your score is"<<points<<endl;
	       goto a;
	       }
	       else
	       {
	       cout<<"Your final score is"<<points<<endl;
	       break;
	       }
	default:
	       break;
}
getch();
}

