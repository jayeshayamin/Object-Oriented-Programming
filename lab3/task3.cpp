#include<iostream>
using namespace std;

class Planner{
	private:
	string tasks[12][31];
	
	public:
		
		Planner()
		{
			for (int i=0;i<12;i++)
			{
				for(int j=0;j<31;j++)
				{
					if(i==1 && j>27)
					{
						tasks[i][j]="Not Accessible.";
					}
					else
					tasks[i][j]="No Task Added!";
				}
			}
		}
		void addtasks(int month,int day,string task)
		{
			int check=0;
			if(day<1 || day>31 || month<1 || month>12)
			{
				cout<<"Invalid entry.Please choose the correct month(1-12) and day(1-31)."<<endl;
				check=1;
			}
			if(month==2 && day>28)
				{
					cout<<"February only has 28 days!"<<endl;
					check=1;
				}
			if(check==0){
			if(tasks[month-1][day-1]!="No Task Added!")
			{
				cout<<"Task has already been added. Cannot overwrite."<<endl;
			}
			else
			{
				tasks[month-1][day-1]=task;
				cout<<"Task added!"<<endl;
			}}
		}
		
		void removetasks(int month,int day)
		{
			int check=0;
			if(day<1 || day>31 || month<1 || month>12)
			{
				cout<<"Invalid entry.Please choose the correct month(1-12) and day(1-31)."<<endl;
				check=1;
			}
			if(month==2 && day>28)
				{
					check=1;
				}
			if(check==0)
			{
			if(tasks[month-1][day-1]!="No Task Added!")
			{
				tasks[month-1][day-1]="No Task Added!";
				cout<<"Task removed."<<endl;
			}
			else
			{
				cout<<"No task to remove."<<endl;
			}}
		}
		
		void update(int month,int day,string task)
		{
			int invalid=0;
			if(day<1 || day>31 || month<1 || month>12)

			{
				cout<<"Invalid entry.Please choose the correct month(1-12) and day(1-31)."<<endl;
				invalid=1;
			}
			if(month==2 && day>28)
				{
					cout<<"February only has 28 days!"<<endl;
					invalid=1;
				}
			if(!invalid)
			{
				tasks[month-1][day-1]=task;
				cout<<"Task updated!"<<endl;
			}
		}
		
		void display()
		{
			for(int i=0;i<12;i++)
			{
				for(int j=0;j<31;j++)
				{
					if(i==1 && j>27)
					{
					continue;
					}
					else if(tasks[i][j]!="No Task Added!")
					{
						cout<<"Month: "<<i+1<<" Day: "<<j+1<<" Task: "<<tasks[i][j]<<endl;
					}
				}
			}
			cout<<"All Added Tasks Displayed."<<endl;
		}

};

int main()
{
	Planner planner;
	int choice,month,day;
	string task;
	cout<<"Welcome to your planner!"<<endl;
	while(1)
	{
		cout<<"************"<<endl;
		cout<<"MENU: "<<endl;
		cout<<"1.Add Task."<<endl;
		cout<<"2.Remove Task"<<endl;
		cout<<"3.Update Task"<<endl;
		cout<<"4.Display Task"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				cout<<"Enter month: ";
				cin>>month;
				cout<<"Enter day: ";
				cin>>day;
				cout<<"Enter task to be added: ";
				cin.ignore();
				getline(cin, task);;
				planner.addtasks(month,day,task);
				break;
			case 2:
				cout<<"Enter month: ";
				cin>>month;
				cout<<"Enter day: ";
				cin>>day;
				planner.removetasks(month,day);
				break;
			case 3:
				cout<<"Enter month: ";
				cin>>month;
				cout<<"Enter day: ";
				cin>>day;
				cout<<"Enter task to be updated: ";
				cin.ignore();
				getline(cin, task);
				planner.update(month,day,task);
				break;
			case 4:
				planner.display();
				break;
			case 5:
				cout<<"Exiting..."<<endl;
				return 0;
				break;
			default:
				cout<<"Invalid choice."<<endl;
		}
	}
}