#include <iostream>
#include<iomanip>		//for setw()
#include<windows.h>		//for colours
#include<stdlib.h>		//for clearing screen
#include<conio.h>		//for getch()
using namespace std;
 
struct node     //creating stucture node
  {
    int id;
    char name [50];
    char qua[30];
    char addrs[50];     // data fields of link list
    char city[30];
    char jobtitle[30];
    int salry;
    char date[30];
    node *next;         //link field of link list
 
};
  
class employ    //creating class employ
{
     private:
         node *head;    //declaring head node of link list
         char ch;        
     public:
        employ()        //constructor
        {
            head=NULL;  //initializing head Null
        }
        
        void menu()      //drop down main menu
        {
            cout<<"\n .............MAIN MENU.............."<<endl;
            cout<<"\n 1-Add a record:";
            cout<<"\n 2-Search a record:";
            cout<<"\n 3-Update a record:";
            cout<<"\n 4-Delete a record:";
            cout<<"\n 5-Display a record:";
            cout<<"\n 6-EXIT:";
        }
     
        void get_data(struct node *t)       //to get information from user
        {
        	cout<<"\n\t\t Enter the Employee ID: ";
          cin>>t->id;
 
          cout<<"\t\t Enter the employee Name: " ;
          cin.getline(t->name,50);
         cin>>t->name;
 
          cout<<"\t\t Enter the Qualification: ";
          cin.getline(t->qua,30);
          cin>>t->qua;
 
          cout<<"\t\t Enter the Address of Employee: ";
          //cin.getline(t->addrs ,50);
          cin>>t->addrs;
 
          cout<<"\t\t Enter the City: ";
         // cin.getline(t->city,30);
          cin>>t->city;
 
          cout<<"\t\t Enter the employee Job title: ";
         // cin.getline(t->jobtitle,50);
         cin>>t->jobtitle;
 
          cout<<"\t\t Enter the Employee the Salary: ";
          cin>>t->salry;
 
          cout<<"\t\t Enter the start Date: ";
          //cin.getline(t->date,30);
          cin>>t->date; 
}

        void add_first()        //to add first of link list
        {
             node * newer=new node;
             get_data(newer);
             if(head==NULL)      //if link is empty
             {
                 newer->next=NULL;
                 head=newer;
             }
             else
             {
                 newer->next=head;
                 head=newer;
             }
             cout<<"\n\t\tRecord has been added Succesfully!"<<endl;
        }
        
        void add_last()
        {
            if (head==NULL)         //if list is empty
            {
               cout<<"\n\t\tLink is empty !"<<endl;
               cout<<"\n\t\tAdd a new record\n\t\tPress Y or N: " ;     // giving user choice of adding new record
               cin>>ch;         //storing user choice
               if (ch=='Y'||ch=='y')        //chcecking conditions
                   {
                   add_first();
                   }
            }
            else
            {
                 node *temp=head;
                 while(temp->next!=NULL)
                 {
                     temp=temp->next;
                 }
                 node  *newer=new node;
                 get_data(newer);
                  newer->next=NULL;
                  temp->next=newer;
            }
            cout<<"\n\t\tRecord has been added Succesfully!"<<endl;
        }
        
        void add_after()            //to add record after user entered ID
        {
             if (head==NULL)        //if list is empty
              {
             	  cout<<"\n\t\tLink is empty !"<<endl;
           	    cout<<"\n\t\tAdd a new record \n\t\tPress Y or N: ";   
           	    cin>>ch;
            	   if (ch=='Y'||ch=='y')
            	   {
            	         add_first();
            	   }
              }
       		else
    	    {
      	      int val;
      	       bool flag=0;
 
      	      cout<<"\n\t\tEnter the ID after which you want to add a new record: ";
     	       cin>>val;
    	         node *temp=head;
    	         node *p=head;
                 while(temp!=NULL)
                  {
              
                if(flag=1)            // if (temp->id==val)
                {
                    node *newer=new node ;
                    get_data(newer);
 
                   if (temp->next!=NULL)
                   {
                       newer->next=temp->next;
                       p=temp->next;
                       temp->next=newer;
                   }
                   else
                   {
                      newer->next=temp->next;
                       temp->next=newer;
                   }
                   flag=1;
                   }
                    temp=temp->next;
                    temp=NULL;
                  }
                  if(flag==0)
                 {
                     cout<<"\n\t\tID is not Found!"<<endl;
                    }
             }
    }
   
   void add_before()                //to add record after user entered ID
   {
       if (head==NULL)      //if list is empty
       {
            cout<<"\n\t\tLink is empty !"<<endl;
               cout<<"\n\t\tAdd a new record\n\t\tPress Y or N: "; 
               cin>>ch;                                             
               if (ch=='Y'||ch=='y')                               
               {
                   add_first();
               }
        }
        else
        {
            int val;
            cout<<"\n\t\tEnter the ID Before which you want to add a new record: ";
            cin>>val;
            //bool flag=false;
            node *temp=head;
            node *p=new node;
            if(temp->id==val&&temp==head)
            {
                add_first();
            }
            else
            {
            while(temp->id!=val)
        		{
        			if(temp->next==NULL)
        				break;
        			else
        			{
        			    p=temp;
        				temp=temp->next;
        			}	
}
if(temp->id!=val&&temp->next==NULL)
cout<<"\n\t\t ID Not Found! "<<endl;
else 
{
    node *newer=new node;
    get_data(newer);
    newer->next=temp;
    p->next=newer;
}  
}
 
       }
 
    }
 
 
   void del()               //to delete user entered ID record
   {
       if (head==NULL)          //if link is empty
       {
               cout<<"\n\t\tLink is empty !"<<endl;
               cout<<"\n\t\tAdd a new record\n\t\tPress Y or N: ";
               cin>>ch;
               if (ch=='Y'||ch=='y')
               {
                   add_first();
               }
       }
           else
            {
            int val;
            cout<<"\n\t\tEnter the employee ID which you want to search  a  record: ";
            cin>>val;
 
            node *temp=head;
            node *p=head;
            while(temp->id!=val&&temp!=NULL)
        		{
        				p=temp;
        				temp=temp->next;
}
if(temp->id!=val&&temp->next==NULL)
cout<<"\n\t\t ID Not Found! "<<endl;
else
{
if(temp==head)
{
head=head->next;
delete temp;
}
else if(temp->next==NULL)
{
p->next=NULL;
delete temp;
}
else
{
p->next=temp->next;
delete temp;
}
}
       	}
}
 
   void show()              //to display values
   {
       if (head==NULL)          //if list is empty
       {
               cout<<"\n\t\tLink is empty !"<<endl;
               cout<<"\n\t\tAdd a new record\n\t\tPress Y or N:" ;
               cin>>ch;
               if (ch=='Y'||ch=='y')
               {
                   add_first();
               }
        }
    	else
    	{
    		node *temp=head;
int s=1;
cout<<endl<<"...............INFORMATION OF EMPLOYEE.............."<<endl
<<setw(5)<<"S no."<<setw(4)<<"ID"<<setw(15)<<"Name"<<setw(17)<<"Qualification"<<setw(25)<<"Address"<<setw(15)<<"City"<<setw(15)<<"Job Title"<<setw(10)<<"Salary"<<setw(17)<<"Start Date"<<endl;
            while(temp!=NULL)
                {
                    cout<<setw(5)<<s<<setw(4)<<temp->id<<setw(15)<<temp->name<<setw(17)<<temp->qua<<setw(25)<<temp->addrs<<setw(15)<<temp->city<<setw(15)<<temp->jobtitle<<setw(10)<<temp->salry<<setw(17)<<temp->date<<endl;
                    temp=temp->next;
                    s++;
                }
}
   }
   
   void search()            //for searching and displaying user entered ID
   {
       if (head==NULL)
       {
            cout<<"\n\t\tLink is empty !"<<endl;
               cout<<"\n\t\tAdd a new record\n\t\tPress Y or N: ";
               cin>>ch;
               if (ch=='Y'||ch=='y')
               {
                   add_first();
               }
            }
            else
            {
            int val;
            cout<<"\n\t\tEnter the employee ID which you want to search  a  record: ";
            cin>>val;
 
            node *temp=head;
            while(temp->id!=val&&temp!=NULL)
        		{
        				temp=temp->next;
}
if(temp->id!=val&&temp->next==NULL)
cout<<"\n\t\t ID Not Found! "<<endl;
else
{
cout<<endl<<setw(4)<<"ID"<<setw(15)<<"Name"<<setw(17)<<"Qualification"<<setw(20)<<"Address"<<setw(15)<<"City"<<setw(15)<<"Job Title"<<setw(10)<<"Salary"<<setw(17)<<"Start Date"<<endl
            		<<setw(4)<<temp->id<<setw(15)<<temp->name<<setw(17)<<temp->qua<<setw(20)<<temp->addrs<<setw(15)<<temp->city<<setw(15)<<temp->jobtitle<<setw(10)<<temp->salry<<setw(17)<<temp->date<<endl;
}
}
       }
 
   void update()            //for updating user entered ID
   {
      if (head==NULL)
       {
            cout<<"\n\t\tLink is empty !"<<endl;
               cout<<"\n\t\tAdd a new record\n\t\tPress Y or N: ";
               cin>>ch;
               if (ch=='Y'||ch=='y')
               {
                   add_first();
               }
 
        }
               else
 
                 {
                   int val;
                   cout<<"\n\t\tEnter the ID after which you want to update: ";
                   cin>>val;
node *temp=head;
     		       while(temp->id!=val)
        			{
        				if(temp->next==NULL)
        					break;
        				else
        					temp=temp->next;	
}
if(temp->id!=val&&temp->next==NULL)
cout<<"\n\t\t ID Not Found! "<<endl;
else
{
get_data(temp);
}
                 }
    }
 
};
int main()
{
    int n;
    char ch;
    employ em;          //creating object of class employ
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE); //for colours
        SetConsoleTextAttribute(color, 1);		//for blue colour
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t WELCOME TO \n\t\t\t\t   EMPLOYEE RECORD SYSTEM\n\n\n\n\n\n\n\nPress any key to continue"<<endl;
    getch();
    system("CLS");
    SetConsoleTextAttribute(color, 14);
    cout<<"\n**************************************THE EMPLOYEE RECORD SYSTEM**********************************"<<endl;
    x2 :            //this is label
    SetConsoleTextAttribute(color, 14);			//for light pink colur
     em.menu();
    cout<<"\n\nEnter your choice: ";
    cin>>n;
    if(n==1)        //for adding value
    {
        x1:
        	SetConsoleTextAttribute(color, 10);		//for for green colour
            cout<<"\n\t Where you want to add record:- ";
            cout<<"\n\t 1- Add at first position:";
            cout<<"\n\t 2- Add at last position: ";
            cout<<"\n\t 3- Add after record: ";
            cout<<"\n\t 4- Add before record: ";
            cout<<"\n\n\t Enter choice: ";
            cin>>n;
            
            if(n==1)        //for adding at first position
            {
            	SetConsoleTextAttribute(color, 13); 		//for purple colour
                em.add_first();
                cout<<"\n\t\t Do you want to go main menu?"<<endl;
                 cout<<"\n\t\t Press Y: ";
                cin>>ch;
                if (ch=='Y'||ch=='y')
               {
                   goto x2;
               }
                 else
                 {
                   return 0;
 
                 }
            }
            else if(n==2)       //for adding at last position
            {
            	SetConsoleTextAttribute(color, 13);
                em.add_last() ;
                cout<<"\n\t\t Do you want to go main menu?"<<endl;
                 cout<<"\n\t\t Press Y: ";
                cin>>ch;
 
                if (ch=='Y'||ch=='y')
               {
                   goto x2;
               }
                 else
                 {
                     return 0;
 
                 }
 
 
            }
          else if (n==3)        //for adding befor user entered value
          {
          	  SetConsoleTextAttribute(color, 13);
              em.add_after();
              cout<<"\n\t\t Do you want to go main menu?"<<endl;
               cout<<"\n\t\t press Y: ";
                cin>>ch;
 
                if (ch=='Y'||ch=='y')
                   goto x2;
               
                 else
                 {
                   return 0;
                 }
          }
          
          else if(n==4)         //for adding before user entered value
          {
          	  SetConsoleTextAttribute(color, 13);
              em.add_before();
              cout<<"\n\t\t Do you want to go main menu?"<<endl;
               cout<<"\n\t\t Press Y: ";
                cin>>ch;
 
                if (ch=='Y'||ch=='y')
               {
                   goto x2;
               }
                 else
                 {
                    return 0;
                 }
          }
          else
          {
          		SetConsoleTextAttribute(color, 13);
              cout<<"\n\t\t Choose correct answer:"<<endl;
              goto x1;
          }
    }
    
    else if(n==2)       //for searching and displaying user entered value
    {
    	SetConsoleTextAttribute(color, 10);
        em.search();
             	 cout<<"\n\t\t Do you want to go main menu?"<<endl;
        		cout<<"\n\t\t press Y: ";
                cin>>ch;
                if (ch=='Y'||ch=='y')
                   goto x2;
                else
                    return 0;
    }
 
    else if(n==3)       //for updating user entered value
    {
    	SetConsoleTextAttribute(color, 10);
        em.update();
              cout<<"\n\t\t Do you want to go main menu?"<<endl;
              cout<<"\n\t\t Press Y: ";
                cin>>ch;
 
                if (ch=='Y'||ch=='y')
                   goto x2;
                else
                   return 0;
    }
    
    else if (n==4)      //for deleting user entered value
    {
    	SetConsoleTextAttribute(color, 10);
        em.del();
              cout<<"\n\t\t Do you want to go main menu?"<<endl;
              cout<<"\n\t\t Press Y: ";
                cin>>ch;
                if (ch=='Y'||ch=='y')
                   goto x2;
                else
                    return 0;
    }
    
    else if (n==5)      //for displaying all values
    {
    	SetConsoleTextAttribute(color, 10);
        em.show();
              cout<<"\n\t\t Do you want to go main menu?"<<endl;
              cout<<"\n\t\t Press Y: ";
                cin>>ch;
 
                if (ch=='Y'||ch=='y')
                   goto x2;
                else
                   return 0;
    }
    
    else if (n==6)      //for exiting program
    {
        return 0;
    }
    
    else                //for wrong inputed answer
    {
    	SetConsoleTextAttribute(color, 10);
        cout<<"\n\t\t Choose correct answer:"<<endl;
        goto x2;
    }
return 0;
}


