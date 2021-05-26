
#include<iostream>
using namespace std;
#include<cstring>
#include<fstream>
//#include<stdio.h>
#include<iomanip>
struct Date
{
    int day;
    int month;
    int year;

};
 int total=0;
struct BP
{
    int high;
    int low;

};
int checkdate(struct Date date);
class report
{
    char name[20];
    long double idno;
    struct Date visitdate;
    int age;
    float weight;
    float height;
    float bmi ;
    struct BP blood_pressure;
    float sugarlevel;

    public:

    report()
    {

        strcpy(name,"no name");
        age=0;
        weight=0;
        bmi=0;
        idno=-1;

    }

    void getreportdata(struct Date date,long double i);
    void showreport();
    int getreport();
    void searchreport(char *t);
    void searchreportidno(long double t);
    void searchreportdate(struct Date d);
    void viewallreports();
	int idnocheck(long double t);
    void updatereport(long double id);
    friend ostream &operator<<(ostream &stream, report o);
    int readablereports();
    void analysis();
	void getupdatedata(struct Date date,long double i);
	void deletereport(long double i);
	int filecheck();
};

    void report::analysis()
    {

        if(bmi<=18)
        {
            cout<<"\t\t"<<name<<" is underweight\n";

        }
        else
        {
            if(25<bmi&&bmi<=30)
            {
                cout<<"\t\t"<<name<<" is over weight\n";
            }
            else
            {
                if(bmi>30)
                cout<<"\t\t"<<name<<" is suffering from obesity\n";
                else
                cout<<"\t\tbmi is normal\n";

            }



        }
        if(100<sugarlevel&&sugarlevel<=125)
        {
            cout<<"\t\t"<<name<<" is prediabetic\n";

        }
        else
        {
            if(sugarlevel>125)
            cout<<"\t\t"<<name<<" is diabetic\n";
            else
            cout<<"\t\tsugarlevel is normal\n";



        }
        if(blood_pressure.high<=90||blood_pressure.low<=60)
        {
            cout<<"\t\t"<<name<<" has low BP\n";

        }
        else
        {
            if(blood_pressure.high>=140||blood_pressure.low>=90)
            cout<<"\t\t"<<name<<" has high BP\n";
            else
            cout<<"\t\tblood pressure is normal\n";

        }







    }
    void report::getreportdata(struct Date date,long double i)
    {

        idno=i;

        cout<<"enter the name \n";
 	cin>>name;


        visitdate.day=date.day;
        visitdate.month=date.month;
        visitdate.year=date.year;
        cout<<"enter the age\n";
        cin>>age;
        cout<<"enter the weight(in Kgs)\n";
        cin>>weight;
        cout<<"enter the height(in mts)\n";
        cin>>height;
        bmi = weight/(height*height) ;
        cout<<"enter the bloodpressure upper by lower\n";
        cin>>blood_pressure.high>>blood_pressure.low;
        cout<<"enter the sugarlevelfor fasting sugar test in mg/dl\n";
        cin>>sugarlevel;

    }
 void report::getupdatedata(struct Date date,long double i)
    {

       idno=i;

        cout<<"enter the name \n";
        cin>>name;


        visitdate.day=date.day;
        visitdate.month=date.month;
        visitdate.year=date.year;
        cout<<"enter the age\n";
        cin>>age;
        cout<<"enter the weight(in Kgs)\n";
        cin>>weight;
        cout<<"enter the height(in mts)\n";
        cin>>height;
        bmi = weight/(height*height) ;
        cout<<"enter the bloodpressure upper by lower\n";
        cin>>blood_pressure.high>>blood_pressure.low;
        cout<<"enter the sugarlevelfor fasting sugar test in mg/dl\n";
        cin>>sugarlevel;

    }

    void report::showreport()
    {

        cout<<"\t\tName"<<setw(12)<<":  "<<name<<endl;
	cout<<"\t\tID "<<setw(13)<<":  "<<idno<<endl;
        cout<<"\t\tVisit Date "<<setw(5)<<":  "<<visitdate.day<<"-"<<visitdate.month<<"-"<<visitdate.year<<endl;
        cout<<"\t\tAge"<<setw(13)<<":  "<<age<<"years"<<endl;
        cout<<"\t\tWeight"<<setw(10)<<":  "<<weight<<"kgs"<<endl;
        cout<<"\t\tHeight"<<setw(10)<<":  "<<height<<"mts"<<endl;
        cout<<"\t\tBMI"<<setw(13)<<":  "<<bmi<<endl;
        cout<<"\t\tBP "<<setw(13)<<":  "<<blood_pressure.high<<"/"<<blood_pressure.low<<endl;
        cout<<"\t\tSugarlevel "<<setw(5)<<":  "<<sugarlevel<<"mg/dl"<<endl;
        cout<<endl;
        cout<<"\t\t\tDISPLAYING ANALYSIS\n";
	cout<<endl;
        analysis();
         for(int i=0;i<80;i++)
            cout<<"*";
            cout<<"\n";

    }
    int report::getreport()
    {

        if(age==0&&weight==0)
        {
            cout<<"data not initialised";
        }
        else
        {
        ofstream fout;
        fout.open("medicalrecords",ios::out|ios::binary|ios::app);

            if(!fout)
            {

                cout<<"data not initialised ";

            }
            else
            {
                fout.write((char *)this,sizeof(*this));
                fout.close();

            }

        }




    }
    void report::searchreport(char *t)
    {
        int count=0;
        ifstream fin;
        fin.open("medicalrecords",ios::in|ios::binary);
        fin.read((char *)this,sizeof(*this));
	if(idno==-1)       
	{
	
		cout<<"\t\t\tNO RECORDS FOUND\n";
		fin.close();
	}
	else
	{
	while(!fin.eof())
        {
            if(!strcmp(name,t))
            {
                count++;
                cout<<"\n\tRECORD FOUND\n";
		cout<<"\t\t\tDISPLAYING RECORD\n";
                showreport();

            }
            fin.read((char *)this,sizeof(*this));

        }
        if(count==0)
        {
            cout<<"\n record not found\n";

        }
        fin.close();
	}
    }

     void report::searchreportidno(long double t)
    {
        int count=0;
        ifstream fin;
        fin.open("medicalrecords",ios::in|ios::binary);
        fin.read((char *)this,sizeof(*this));
	if(idno==-1)
	{
		cout<<"\t\t\t NO records found\n";
		fin.close();
	
	}
	else
	{

	while(!fin.eof())
        {
            if(t==idno)
            {
                count++;
                cout<<"\n\tRECORD FOUND\n";
		cout<<"\t\t\tDISPLAYING RECORD\n";
                showreport();

            }
            fin.read((char *)this,sizeof(*this));

        }
        if(count==0)
        {
            cout<<"\n RECORD NOT FOUND\n";

        }
        fin.close();
	}
    }
  int report::idnocheck(long double t)
    {

        ifstream fin;
        fin.open("medicalrecords",ios::in|ios::binary);
        fin.read((char *)this,sizeof(*this));
        while(!fin.eof())
        {
            if(idno==-1)
            {
                fin.close();
                return 1;
            }
            if(idno==t)
            {
		fin.close();
                return 0;


            }
            fin.read((char *)this,sizeof(*this));

        }

        fin.close();
	return 1;
    }

     void report::searchreportdate(struct Date d)
    {
        int count=0;
        ifstream fin;
        fin.open("medicalrecords",ios::in|ios::binary);
        fin.read((char *)this,sizeof(*this));
       cout<<"\n";
	if(idno==-1)
	{
	
		cout<<"\t\t\t NO RECORDS FOUND\n";
		fin.close();
	
	}
	else
	{	
       while(!fin.eof())
        {
            if(d.day==visitdate.day&&d.month==visitdate.month&&d.year==visitdate.year)
            {
                count++;

                showreport();

            }
            fin.read((char *)this,sizeof(*this));

        }

        if(count==0)
        {
            cout<<"\n records not found enter another date\n";

        }
        else
        {
            cout<<"total no of patients is visited on that day is "<<count<<endl;
		  for(int i=0;i<80;i++)
            cout<<"*";
            cout<<"\n";

       	}
        fin.close();
	}
    }
    void report::viewallreports()
    {
        ifstream fin;
        fin.open("medicalrecords",ios::in|ios::binary);
        fin.read((char *)this,sizeof(*this));
	if(age==0&&weight==0)
	{

	cout<<"\t\t\tNO RECORDS AVAILABLE\n";
	}
	else
	{
        while(!fin.eof())
        {
            showreport();
		total++;
            fin.read((char *)this,sizeof(*this));
        }
        fin.close();
	}
    }
    void report::updatereport(long double i)
    {
        int count=0;
        fstream file;
        file.open("medicalrecords",ios::in|ios::ate|ios::out|ios::binary);
        file.seekg(0);
        file.read((char *)this,sizeof(*this));

        while(!file.eof())
        {
            if(idno==i)
            {
                struct Date date;
                count++;

                 while(1)
                    {
                        cout<<"enter the correct visit date\n";
                        cin>>date.day>>date.month>>date.year;
                        if(checkdate(date))
                        break;

                    }
                    getupdatedata(date,i);

                file.seekp(file.tellp()-sizeof(*this));
                file.write((char *)this,sizeof(*this));
                cout<<"\t\t\tUPDATED  RECORD\n";
                showreport();
            }
            file.read((char *)this,sizeof(*this));




        }
        if(count==0)
        {
            cout<<"\t\t\tRECORD NOT FOUND\n";
        }
            file.close();
  }


     ostream &operator<<(ostream &stream, report o)
	{
	 stream<<"\t\tName"<<setw(12)<<":  "<<o.name<<endl;
	stream<<"\t\tID "<<setw(13)<<":  "<<o.idno<<endl;
        stream<<"\t\tVisit Date "<<setw(5)<<":  "<<o.visitdate.day<<"-"<<o.visitdate.month<<"-"<<o.visitdate.year<<endl;
        stream<<"\t\tAge"<<setw(13)<<":  "<<o.age<<"years"<<endl;
        stream<<"\t\tWeight"<<setw(10)<<":  "<<o.weight<<"kg"<<endl;
        stream<<"\t\tHeight"<<setw(10)<<":  "<<o.height<<"mt"<<endl;
        stream<<"\t\tBMI"<<setw(13)<<":  "<<o.bmi<<endl;
        stream<<"\t\tBP "<<setw(13)<<":  "<<o.blood_pressure.high<<"/"<<o.blood_pressure.low<<endl;
        stream<<"\t\tSugarlevel "<<setw(5)<<":  "<<o.sugarlevel<<"mg/dl"<<endl;


         for(int i=0;i<50;i++)
            stream<<"*";
            stream<<"\n";
		return stream;
	}
 int report::readablereports()
{
        fstream pb("medicalread",ios::in|ios::out|ios::binary|ios::app);
        if(!pb)
        {
            cout<<"cannot open medical read\n";
            return 1;
        }
        ifstream fin;
        fin.open("medicalrecords",ios::in|ios::binary);
        fin.read((char *)this,sizeof(*this));
	if(idno==-1)
	{
		cout<<"\t\t\tNO RECORDS FOUND\n";
		fin.close();
		pb.close();

	
	}
	else
	{
        while(!fin.eof())
        {
                pb<<*this;

            fin.read((char *)this,sizeof(*this));
        }
        fin.close();
        pb.close();
	}
}
int checkdate(struct Date date)
{

        if(date.month==1||date.month==3||date.month==5||date.month==7||date.month==8||date.month==10||date.month==12)
    {
        if(date.day<=31)
        return 1;
        else
        return 0;

    }
        if(date.month==4||date.month==6||date.month==9||date.month==11)
    {
        if(date.day<=30)
        return 1;
        else
        return 0;
    }

    if(date.month==2)
    {
        if(date.day<=28)
        return 1;
        else
	{
		if(date.day==29)
		{
			if(date.year%100==0)
			{
				if(date.year%400==0)
					return 1;
				else
					return 0;

			}
			else
			{
				if(date.year%4==0)
					return 1;
				else
					return 0;


			}
		}
        	return 0;
	}
    }
    return 0;


}
void report::deletereport(long double i)
{
		ifstream fin ;
		ofstream fout ;
        	fin.open("medicalrecords",ios::in|ios::binary);
        	if(!fin)
		{
			cout<<"\nFile not found" ;
		}
		else
		{
			fout.open("temp",ios::out|ios::binary);
			fin.read((char *)this,sizeof(*this));
			while(!fin.eof())
			{
				if(idno!=i)
				{
                    fout.write((char *)this,sizeof(*this));
                }
				fin.read((char *)this,sizeof(*this));
			}
			fin.close();
			fout.close() ;
			remove ("medicalrecords") ;
			rename ("temp","medicalrecords") ;
			//showreport() ;
		}
}
int report::filecheck()
{
  ifstream fin;
        fin.open("medicalrecords",ios::in|ios::binary);
        fin.read((char *)this,sizeof(*this));
       cout<<"\n";
        if(idno==-1)
        {

                
                fin.close();
		return 0;
        }
	else
	{
		fin.close();
		return 1;
	}


}
int main()
{
    report rp;
    int choice;
    int flag=0;
    struct Date date;

    do
    {
    cout<<"\n1)to add report\n2)to view all reports \n3)to search for the report based on name\n4)to search based on idno \n5)to find no of patients on paticular day\n6)to update arecord\n7)to generate a readable file\n8)to delete one record \n9)to quit\n";
        cout<<"\nenter the choice "<<endl;
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1:
			long double t;
			cout<<"enter the id no";
			cin>>t;
            if(!rp.idnocheck(t))
			{

				cout<<"\t\t\t ID ALREADY EXISTS\n";
			}
			else
			{

			 while(1)
                	{
                       	 cout<<"enter the correct visit date\n";
                        cin>>date.day>>date.month>>date.year;
                        if(checkdate(date))
                        break;

                    }

                    rp.getreportdata(date,t);
                    rp.getreport();
                 	cout<<"\t\t\tDISPLAYING THE RECORD\n";
		    rp.showreport();
			}
                    break;
            case 2:
                    cout<<"\t\t\tDISPLAYING ALL REPORTS "<<endl;
                    cout<<"\n";
                    rp.viewallreports();
	 	    cout<<"total no of records is "<<total<<endl;
		       for(int i=0;i<80;i++)
	        	    cout<<"*";
        	    cout<<"\n";
        	    total=0;


		    break;
            case 3:
                    char name[20];
			if(rp.filecheck())
			{
                        	cout<<"enter the name ";
                       		 cin>>name;
                       		 rp.searchreport(name);
			}
			else
			{
				cout<<"\t\t\t NO RECORDS FOUND ENTER SOME RECORDS\n";
			
			}
                    break;
            case 4:
                    long double id;
			 if(rp.filecheck())
			{
                        cout<<"enter the idno ";
                        cin>>id;
                        rp.searchreportidno(id);
			}
			   else
                        {
                                cout<<"\t\t\t NO RECORDS FOUND ENTER SOME RECORDS\n";

                        }


                break;
            case 5:
                    struct Date no;
			 if(rp.filecheck())
			{
                        cout<<"enter the day ,month and year  ";
                        cin>>no.day>>no.month>>no.year;
                        rp.searchreportdate(no);
			} else
                        {
                                cout<<"\t\t\t NO RECORDS FOUND ENTER SOME RECORDS\n";
                        
                        }

                break;
            case 6:
                    long double i;
			 if(rp.filecheck())
			{
                        cout<<"enter the id to update\n";
                        cin>>i;
                        rp.updatereport(i);
			} else
                        {
                                cout<<"\t\t\t NO RECORDS FOUND ENTER SOME RECORDS\n";
                        
                        }
			
                    break;

            case 7:
			 if(rp.filecheck())
			{
                        remove("medicalread");
                        rp.readablereports();
                        cout<<"readable file generated you can find the file in curent directory\n";
			} else
                        {
                                cout<<"\t\t\t NO RECORDS FOUND ENTER SOME RECORDS\n";
                        
                        }

                    break;
          

		   

	    case 8:
            long double k;
            if(rp.filecheck())
         {

	    cout<<"Enter the id number  ";
		    cin>>k;
            if(rp.idnocheck(k))
            {
                cout<<"ID NUMBER NOT FOUND\n";
            }
            else
            {
                rp.deletereport(k);
                cout<<"\t\t\t RECORD DELETED\n";

	   }
	}
	    else
         {
                                cout<<"\t\t\t NO RECORDS FOUND ENTER SOME RECORDS\n";

         }



			break;
        case 9:
            break;
        default:
        cout<<"enter the correct choice\n";
        }

    }while(choice!=9);
    return 0;
}


