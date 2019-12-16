#include<iostream>
#include<string.h>
using namespace std;

        static int z=0;
        float sgrades[20][20],g_sum=0,s_sum=0;
        float grades[3][10]={
                          {3.0,1.50,3.0,1.50,1.50,3.0,3.0,0.75,1.50},
                          {3.0,3.0,1.50,3.0,1.50,2.0,3.0,0.75,3.0,1.5},
                          {3.0,1.50,3.0,1.50,3.0,1.50,3.0,0.75,3.0}
                          };

        string subname[3][10]={
                             {"CSE-101","CSE-102","EEE-163","EEE-164","CE-150","MATH-141","CHEM-101","Hum-101","HUM-102"},
                             {"CSE-103","CSE-105","CSE-106","EEE-169","EEE-170","ME-181","PHY-103","PHY-104","MATH-143","HUM-102"},
                             {"CSE-201","CSE-202","CSE-203","CSE-204","CSE-205","CSE-206","EEE-269","EEE-270","MATH-245"}
                            };
        string name;
        string id,n_id;
class record{
public:
    string name;
    string id;
    float rec;
    void setname_id(string sname,string s_id)
    {
        name=sname;
        id=s_id;

    }
    void setgpa(float x)
    {
        rec=x;
    }
    string getname()
    {
        return name;
    }
    string getid()
    {
        return id;
    }
    float getgpa()
    {
        return rec;
    }

    };

class info{

public:
    float arr[100];
    float sgrade[100];
    float grade[100];

};
class cgpa:public info
{
    public:
    void set_grade(float grades,int x)
    {
        grade[x]=grades;

    }

    float get_grade(int x)
    {
        return grade[x];
    }
     void set_sgrade(float grades,int x)
    {
        sgrade[x]=grades;

    }
    float calculation(int x)
    {
        for(int i=0;i<x;i++)
        {
            g_sum=sgrade[i]*grade[i]+g_sum;
            s_sum=grade[i]+s_sum;

        }
        return g_sum/s_sum;
    }

};

int main()
{
    cgpa scgpa;
    record rec[100];
    int l,t,i,n,x;
    float f;
    char ch,ch1,choice='y';
    cout<<"Welcome To BAIUST CGPA Analysis system.";
    while(choice=='y')
    {
        cout<<"\nEnter your Choice\n";
        cout<<"Press 1 for admin.\tPress 2 for Student.\n";
        cin>>ch1;
        if(ch1=='1')
            {
                cout<<"Press 1. For Modify Credit Hour.\n";
                cin>>ch;
                if(ch=='1')
                {

                   cout<<"Please enter your Level and Term\nLevel: ";
            cin>>l;
            cout<<"\nTerm:\t";
            cin>>t;
            cout<<"Enter New Grades\n";
            cout<<"Subject Name\tSubject Grades\n";
            cout<<"------------\t---------------\n";
                if(l==1 && t==1 )
                {
                    n=9;
                    x=0;
                }
                else if(l==1 && t==2 )
                   {
                       n=10;
                       x=1;
                   }
                else if(l=2 && t==1)
                    {

                        n=9;
                        x=2;
                    }
                else
                    cout<<"WRONG INPUT.\n";
                for(i=0;i<n;i++)
                    {
                            cout<<subname[x][i]<<"\t\t";
                            cin>>grades[x][i];
                             if(grades[x][i]>3 || grades[x][i]<0)
                     {
                         cout<<"Wrong input.Please try again\n";
                         i--;
                     }
                    }

                }
                else
                    cout<<"WRONG CHOICE\n";

            }
        else if(ch1=='2')
          {

            cout<<"Press 1 For CGPA Calculation.\nPress 2 For Display Result.\nPress 3 for Display Credit Hour and Subjects\n";
            cin>>ch;
            if(ch=='1')
        {


            cout<<"Please enter your Level and Term\nLevel: ";
            cin>>l;
            cout<<"\nTerm:\t";
            cin>>t;
            cout<<"0% and above\tA+\t4.0\n75% to below 80%\tA\t3.75\n70% to below 75%\tA-\t3.5\n65% to below 70%\tB+\t3.25\n60% to below 65%\tB\t3.00\n55% to below 60%\tB-\t2.75\n50% to below 55%\tC+\t2.50\n45% to below 50%\tC\t2.25\n40% to below 45%\tD\t2.00\nBelow 40%\t\tF\t0.00\n";
            cout<<"Subject Name\tSubject Credit Hour\n";
            cout<<"------------\t---------------\n";
            if(l==1 && t==1 )
            {
                n=9;
                x=0;
            }
            else if(l==1 && t==2 )
               {
                   n=10;
                   x=1;
               }
            else if(l=2 && t==1)
                {

                    n=9;
                    x=2;
                }
            else
                cout<<"WRONG INPUT.\n";
                for(i=0;i<n;i++)
                {
                    scgpa.set_grade(grades[x][i],i);
                }
                for(i=0;i<n;i++)
                {
                    cout<<subname[x][i]<<"\t\t";
                    cout<<scgpa.get_grade(i)<<"\n";
                }
                cout<<"Enter your Name\n";
                cin>>name;
                cout<<"Enter your id\n";
                cin>>id;
                cout<<"Enter your Grades : \n";
                 for(i=0;i<n;i++)
                 {
                     cout<<subname[x][i]<<"\t";
                     cin>>sgrades[x][i];
                     if(sgrades[x][i]>4 || sgrades[x][i]<0)
                     {
                         cout<<"Wrong input.Please try again\n";
                         i--;
                     }
                 }
                 for(i=0;i<n;i++)
                {
                    scgpa.set_sgrade(sgrades[x][i],i);
                }
                f=scgpa.calculation(n);
                cout<<"Your CGPA is :"<<f;

                rec[z].setname_id(name,id);
                rec[z].setgpa(f);
                z++;


        }
    else if(ch=='2')
     {
        if(z==0)
            cout<<"You Have to set your result first";
        else
        {
        cout<<"Enter Your ID\n";
        cin>>n_id;
        for(i=0;i<z;i++)
        {
            string sid=rec[i].getid();
            if(sid==n_id)
            {
                cout<<"Name :"<<rec[i].getname()<<"\nID :"<<rec[i].getid()<<"\nCGPA :"<<rec[i].getgpa();
            }

        }
        }
      }
      else if(ch=='3')
      {
            cout<<"Please enter your Level and Term\nLevel: ";
            cin>>l;
            cout<<"\nTerm:\t";
            cin>>t;
            cout<<"Subject Name\tSubject Grades\n";
            cout<<"------------\t---------------\n";
            if(l==1 && t==1 )
            {
                n=9;
                x=0;
            }
            else if(l==1 && t==2 )
               {
                   n=10;
                   x=1;
               }
            else if(l=2 && t==1)
                {

                    n=9;
                    x=2;
                }
            else
                cout<<"WRONG INPUT.\n";
             for(i=0;i<n;i++)
                 {
                     cout<<subname[x][i]<<"\t"<<grades[x][i]<<"\n";
                 }
      }
       else
            cout<<"WRONG CHOICE.\n";

    }

     else
            cout<<"WRONG CHOICE.\n";

        cout<<"\nDo you want to try again?? [Press y to continue.Any key to exit... ]\n";
        cin>>choice;
    }

    cout<<"Thank You!!  :-) ";

    return 0;

}
