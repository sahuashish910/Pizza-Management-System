//username: babu password:coder
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;
void m1();
void update_item();
void delete_item();
void add_item();
void show_menu();
void entry_menu();
void custom();
void order();
float total=0,k=0;
long long int phone;
char name[50],address[100];
int p1,r;char n1[50];char* t[100];float o;
char hc;
//----------------------------------------------------------------------------------------------------------------------------
class menu
{
	float price;
	char name_item[100];
	int item_no;

	public:

		void get_item()
		{
			cout<<"\n\n\t\t\t\t\t\t\t\tITEM NO. : ";
	        cin>>item_no;
			cout<<"\n\n\t\t\t\t\t\t\t\tITEM NAME : ";
			cin.ignore();
	        cin.getline(name_item,100);
	        cout<<"\n\n\t\t\t\t\t\t\t\tPRICE : ";
	        cin>>price;
	    }
		void show_item()
		{
			cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tITEM NAME : "<<name_item;
	        cout<<"\n\t\t\t\t\t\t\t\tPRICE : "<<price;
		}
		void layout()
		{
			cout<<"\t\t\t\t\t\t\t"<<setw(6)<<item_no<<setw(30)<<name_item<<"\t\t "<<setprecision(2)<<setw(6)<<price<<"\n";
		}
		int backitemno()
		{
			return item_no;
		}
		float backprice()
		{
			return price;
		}
		char* backnameitem()
		{
			return name_item;
		}
};


//-------------------------------------------------------------------------------------------------------------------------
class customer:public menu
{
	long long int phone;
    char name[50],address[100];
    public:
    void getdata()
		{
			cout<<"\n\n\t\t\t\t\t\t\t\tNAME : ";
			cin.ignore();
	        cin.getline(name,50);
	        cout<<"\n\n\t\t\t\t\t\t\t\tADDRESS : ";
			cin.ignore();
	        cin.getline(address,100);
	        cout<<"\n\n\t\t\t\t\t\t\t\tMOBILE NO. : ";
	        cin>>phone;
		}
    long long int back()
	{
		return phone;
	}
	char* backname()
	{
		return name;
	}
};
//---------------------------------------------------------------------------------------------------------------------
void heading()
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,6|FOREGROUND_INTENSITY);
    cout<<"\n\t\t\t                                          LOVELY   PROFESSIONAL   UNIVERSITY";
    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
    cout<<"\n\t\t\t                                      Transforming Education Transforming India";
    SetConsoleTextAttribute(h,5|FOREGROUND_INTENSITY);
    cout<<"\n\n\t\t\t                                                 LPU   PIZZA   HUT\n";
    SetConsoleTextAttribute(h,3|FOREGROUND_INTENSITY);
    cout<<"\t\t\t                                           THINK PIZZA. THINK PIZZA HUT.\n\n\n\n";

    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
}
//----------------------------------------------------------------------------------------------------------------------
void intro()
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,6|FOREGROUND_INTENSITY);
    cout<<"\n\t\t\t\t                                          LOVELY   PROFESSIONAL   UNIVERSITY";
    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
    cout<<"\n\t\t\t\t                                      Transforming Education Transforming India\n\n\n\n";
	SetConsoleTextAttribute(h,2|FOREGROUND_INTENSITY);
    cout<<"\n\t\t\t\t\t\t  -----------------------------------------------------------------------------\n\n";
    cout<<"\t\t\t\t\t\t                                    PIZZA HUT                      \n";
    cout<<"\t\t\t\t\t\t                                MANAGEMENT SYSTEM                          \n\n";
    cout<<"\t\t\t\t\t\t  -----------------------------------------------------------------------------\n\n\n\n";

	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"\t\t\t\t\t\t\t                 CREATED  BY    :    ASHISH  SAHU\n";
    cout<<"\t\t\t\t\t\t\t                 SUBMITTED TO   :    MR.PARVEEN  SIR\n";
    cout<<"\t\t\t\t\t\t\t                 SECTION        :    K17EC\n";
    cout<<"\t\t\t\t\t\t\t                 REGIS. NO.     :    11702971\n";
    cout<<"\t\t\t\t\t\t\t                 ROLL NO.       :    45\n\n\n";
    cout<<"\t\t\t\t\t\t\tPress any key to continue...";
    getch();
}
//---------------------------------------------------------------------------------------------------------------------
void delete_(int n)
{
	system("cls");
	heading();
	cout<<"\n\n\n\n\n";
	menu st;
	ifstream inFile;
	if(n==1)
	{
		cout<<"\t\t\t\t\t\t\t\t                 VEG PIZZA\n";
	    cout<<"\t\t\t\t\t\t\t\t             ---------------\n\n";
		inFile.open("veg_pizza.dat",ios::binary);
	}
	else if(n==2)
	{
		cout<<"\t\t\t\t\t\t\t\t                 NON VEG PIZZA\n";
    	cout<<"\t\t\t\t\t\t\t\t              -------------------\n\n";
	    inFile.open("nonveg_pizza.dat",ios::binary);
	}
	else if(n==3)
	{
	    cout<<"\t\t\t\t\t\t\t\t                 SIDES\n";
	    cout<<"\t\t\t\t\t\t\t\t              -----------\n\n";
	    inFile.open("sides.dat",ios::binary);
	}
	else if(n==4)
	{
		cout<<"\t\t\t\t\t\t\t\t                 MEALS\n";
	    cout<<"\t\t\t\t\t\t\t\t              -----------\n\n";
        inFile.open("meals.dat",ios::binary);
	}
	else if(n==5)
	{
		cout<<"\t\t\t\t\t\t\t\t                 DRINKS\n";
	    cout<<"\t\t\t\t\t\t\t\t              ------------\n\n";
	    inFile.open("drinks.dat",ios::binary);
	}
	else if(n==6)
	{
		cout<<"\t\t\t\t\t\t\t\t                 DESSERTS\n";
	    cout<<"\t\t\t\t\t\t\t\t              -------------\n\n";
	    inFile.open("desserts.dat",ios::binary);
	}
	else if(n==7)
	{
		cout<<"\t\t\t\t\t\t\t\t               MAGIC PAN\n";
	    cout<<"\t\t\t\t\t\t\t\t            ---------------\n\n";
    	inFile.open("magic.dat",ios::binary);
	}
	else if(n==8)
	{
		entry_menu();
	}
	if(n>8)
	{
		delete_item();
	}
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	{
		st.layout();
	}
    inFile.close();

    ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	ifstream iFile;
	iFile.seekg(0,ios::beg);
	cout<<"\n\n\t\t\t\t\t\t\tENTER ITEM NO TO DELETE : ";
	    int m;
	    cin>>m;
	if(n==1)
	{
		iFile.open("veg_pizza.dat",ios::binary);
		while(iFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	    {
		if(st.backitemno()!=m)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(menu));
		}
	    }
	outFile.close();
	iFile.close();
	remove("veg_pizza.dat");
	rename("Temp.dat","veg_pizza.dat");
	}
	else if(n==2)
	{
	    iFile.open("nonveg_pizza.dat",ios::binary);
	    while(iFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	{
		if(st.backitemno()!=m)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(menu));
		}
	}
	outFile.close();
	iFile.close();
	remove("nonveg_pizza.dat");
	rename("Temp.dat","nonveg_pizza.dat");
	}
	else if(n==3)
	{
	    iFile.open("sides.dat",ios::binary);
	    while(iFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	{
		if(st.backitemno()!=m)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(menu));
		}
	}
	outFile.close();
	iFile.close();
	remove("sides.dat");
	rename("Temp.dat","sides.dat");
	}
	else if(n==4)
	{
        iFile.open("meals.dat",ios::binary);
        while(iFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	{
		if(st.backitemno()!=m)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(menu));
		}
	}
	outFile.close();
	iFile.close();
	remove("meals.dat");
	rename("Temp.dat","meals.dat");
	}
	else if(n==5)
	{
	    iFile.open("drinks.dat",ios::binary);
	    while(iFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	{
		if(st.backitemno()!=m)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(menu));
		}
	}
	outFile.close();
	iFile.close();
	remove("drinks.dat");
	rename("Temp.dat","drinks.dat");
	}
	else if(n==6)
	{
	    iFile.open("desserts.dat",ios::binary);
	    while(iFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	{
		if(st.backitemno()!=m)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(menu));
		}
	}
	outFile.close();
	iFile.close();
	remove("desserts.dat");
	rename("Temp.dat","desserts.dat");
	}
	else if(n==7)
	{
    	iFile.open("magic.dat",ios::binary);
    	while(iFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	{
		if(st.backitemno()!=m)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(menu));
		}
	}
	outFile.close();
	iFile.close();
	remove("magic.dat");
	rename("Temp.dat","magic.dat");
	}
	else if(n==8)
	{
		entry_menu();
	}
	if(n>8)
	{
		delete_item();
	}

	cout<<"\n\n\t\t\t\t\t\t\t\tDELETED.....  ";
	cin.ignore();
	cin.get();
	delete_item();
}
//----------------------------------------------------------------------------------------------------------------------
void delete_item()
{
	system("cls");
	heading();
    int ch=0;
    cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t                 DELETE MENU\n";
	cout<<"\t\t\t\t\t\t\t              ------------------\n\n";
    cout<<"\t\t\t\t\t\t\t                1. VEG PIZZA\n\n";
    cout<<"\t\t\t\t\t\t\t                2. NON-VEG PIZZA\n\n";
    cout<<"\t\t\t\t\t\t\t                3. SIDES\n\n";
    cout<<"\t\t\t\t\t\t\t                4. MEALS\n\n";
    cout<<"\t\t\t\t\t\t\t                5. DRINKS\n\n";
    cout<<"\t\t\t\t\t\t\t                6. DESSERTS\n\n";
    cout<<"\t\t\t\t\t\t\t                7. MAGIC PAN\n\n";
    cout<<"\t\t\t\t\t\t\t                8. GO BACK\n\n";
    cout<<"\t\t\t\t\t\t\t\tYour choice : ";
    cin>>ch;
    delete_(ch);
}
//-------------------------------------------------------------------------------------------------------------------------
void update(int n)
{
	system("cls");
	heading();
	cout<<"\n\n\n\n\n";
	menu st;
	ifstream inFile;
	if(n==1)
	{
		cout<<"\t\t\t\t\t\t\t\t                 VEG PIZZA\n";
	    cout<<"\t\t\t\t\t\t\t\t             ---------------\n\n";
		inFile.open("veg_pizza.dat",ios::binary);
	}
	else if(n==2)
	{
		cout<<"\t\t\t\t\t\t\t\t                 NON VEG PIZZA\n";
    	cout<<"\t\t\t\t\t\t\t\t              -------------------\n\n";
	    inFile.open("nonveg_pizza.dat",ios::binary);
	}
	else if(n==3)
	{
	    cout<<"\t\t\t\t\t\t\t\t                 SIDES\n";
	    cout<<"\t\t\t\t\t\t\t\t              -----------\n\n";
	    inFile.open("sides.dat",ios::binary);
	}
	else if(n==4)
	{
		cout<<"\t\t\t\t\t\t\t\t                 MEALS\n";
	    cout<<"\t\t\t\t\t\t\t\t              -----------\n\n";
        inFile.open("meals.dat",ios::binary);
	}
	else if(n==5)
	{
		cout<<"\t\t\t\t\t\t\t\t                 DRINKS\n";
	    cout<<"\t\t\t\t\t\t\t\t              ------------\n\n";
	    inFile.open("drinks.dat",ios::binary);
	}
	else if(n==6)
	{
		cout<<"\t\t\t\t\t\t\t\t                 DESSERTS\n";
	    cout<<"\t\t\t\t\t\t\t\t              -------------\n\n";
	    inFile.open("desserts.dat",ios::binary);
	}
	else if(n==7)
	{
		cout<<"\t\t\t\t\t\t\t\t               MAGIC PAN\n";
	    cout<<"\t\t\t\t\t\t\t\t            ---------------\n\n";
    	inFile.open("magic.dat",ios::binary);
	}
	else if(n==8)
	{
		entry_menu();
	}
	if(n>8)
	{
		show_menu();
	}
	if(!inFile)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...NO ITEM FOUND...";
	    cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		cin.ignore();
	    cin.get();
	    show_menu();
    }
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	{
		st.layout();
	}
    inFile.close();

	bool found=false;
	fstream File;
	if(n==1)
		File.open("veg_pizza.dat",ios::binary|ios::in|ios::out);
	else if(n==2)
	    File.open("nonveg_pizza.dat",ios::binary|ios::in|ios::out);
	else if(n==3)
	    File.open("sides.dat",ios::binary|ios::in|ios::out);
	else if(n==4)
	    File.open("meals.dat",ios::binary|ios::in|ios::out);
	else if(n==5)
	    File.open("drinks.dat",ios::binary|ios::in|ios::out);
	else if(n==6)
        File.open("desserts.dat",ios::binary|ios::in|ios::out);
	else if(n==7)
	    File.open("magic.dat",ios::binary|ios::in|ios::out);
	else if(n==8)
	    entry_menu();
	if(n>8)
	    update_item();
	if(!File)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...NO ITEM FOUND...";
	    cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		cin.ignore();
	    cin.get();
	    update_item();
    }
        cout<<"\n\n\t\t\t\t\t\t\tENTER ITEM NO TO UPDATE : ";
	    int m;
	    cin>>m;
    while(!File.eof() && found==false)
	{
File.read(reinterpret_cast<char *> (&st), sizeof(menu));
		if(st.backitemno()==m)
		{
			cout<<"\n\n\t\t\t\t\t\t\tENTER NEW DETAILS OF ITEM : "<<endl;
			st.get_item();
		    	int pos=(-1)*static_cast<int>(sizeof(st));
		    	File.seekp(pos,ios::cur);
		    	File.write(reinterpret_cast<char *> (&st), sizeof(menu));
		    	cout<<"\n\n\t\t\t\t\t\t\tUPDATED..... ";
		    	found=true;
		    	File.close();
		    	cin.ignore();
	            cin.get();
	            update_item();
		}
	}
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();
}
//-------------------------------------------------------------------------------------------------------------------
void update_item()
{
	system("cls");
	heading();
    int ch;
    cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t                 UPDATE MENU\n";
	cout<<"\t\t\t\t\t\t\t              -----------------\n\n";
    cout<<"\t\t\t\t\t\t\t                1. VEG PIZZA\n\n";
    cout<<"\t\t\t\t\t\t\t                2. NON-VEG PIZZA\n\n";
    cout<<"\t\t\t\t\t\t\t                3. SIDES\n\n";
    cout<<"\t\t\t\t\t\t\t                4. MEALS\n\n";
    cout<<"\t\t\t\t\t\t\t                5. DRINKS\n\n";
    cout<<"\t\t\t\t\t\t\t                6. DESSERTS\n\n";
    cout<<"\t\t\t\t\t\t\t                7. MAGIC PAN\n\n";
    cout<<"\t\t\t\t\t\t\t                8. GO BACK\n\n";
    cout<<"\t\t\t\t\t\t\t\tYour choice : ";
    cin>>ch;
    update(ch);
}
//-----------------------------------------------------------------------------------------------------------------------
void show(int n)
{
	system("cls");
	heading();
	cout<<"\n\n\n\n\n";
	menu st;
	ifstream inFile;
	if(n==1)
	{
		cout<<"\t\t\t\t\t\t\t\t                 VEG PIZZA\n";
	    cout<<"\t\t\t\t\t\t\t\t             ---------------\n\n";
		inFile.open("veg_pizza.dat",ios::binary);
	}
	else if(n==2)
	{
		cout<<"\t\t\t\t\t\t\t\t                 NON VEG PIZZA\n";
    	cout<<"\t\t\t\t\t\t\t\t              -------------------\n\n";
	    inFile.open("nonveg_pizza.dat",ios::binary);
	}
	else if(n==3)
	{
	    cout<<"\t\t\t\t\t\t\t\t                 SIDES\n";
	    cout<<"\t\t\t\t\t\t\t\t              -----------\n\n";
	    inFile.open("sides.dat",ios::binary);
	}
	else if(n==4)
	{
		cout<<"\t\t\t\t\t\t\t\t                 MEALS\n";
	    cout<<"\t\t\t\t\t\t\t\t              -----------\n\n";
        inFile.open("meals.dat",ios::binary);
	}
	else if(n==5)
	{
		cout<<"\t\t\t\t\t\t\t\t                 DRINKS\n";
	    cout<<"\t\t\t\t\t\t\t\t              ------------\n\n";
	    inFile.open("drinks.dat",ios::binary);
	}
	else if(n==6)
	{
		cout<<"\t\t\t\t\t\t\t\t                 DESSERTS\n";
	    cout<<"\t\t\t\t\t\t\t\t              -------------\n\n";
	    inFile.open("desserts.dat",ios::binary);
	}
	else if(n==7)
	{
		cout<<"\t\t\t\t\t\t\t\t               MAGIC PAN\n";
	    cout<<"\t\t\t\t\t\t\t\t            ---------------\n\n";
    	inFile.open("magic.dat",ios::binary);
	}
	else if(n==8)
	{
		entry_menu();
	}
	if(n>8)
	{
		show_menu();
	}
	if(!inFile)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...NO ITEM FOUND...";
	    cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		cin.ignore();
	    cin.get();
	    show_menu();
    }
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	{
		st.layout();
	}
    inFile.close();
    cin.ignore();
    cin.get();
    show_menu();
}
//------------------------------------------------------------------------------------------------------------------------
void show_menu()
{
	system("cls");
	heading();
    int ch;
    cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t                 SHOW MENU\n";
	cout<<"\t\t\t\t\t\t\t              ---------------\n\n";
    cout<<"\t\t\t\t\t\t\t                1. VEG PIZZA\n\n";
    cout<<"\t\t\t\t\t\t\t                2. NON-VEG PIZZA\n\n";
    cout<<"\t\t\t\t\t\t\t                3. SIDES\n\n";
    cout<<"\t\t\t\t\t\t\t                4. MEALS\n\n";
    cout<<"\t\t\t\t\t\t\t                5. DRINKS\n\n";
    cout<<"\t\t\t\t\t\t\t                6. DESSERTS\n\n";
    cout<<"\t\t\t\t\t\t\t                7. MAGIC PAN\n\n";
    cout<<"\t\t\t\t\t\t\t                8. GO BACK\n\n";
    cout<<"\t\t\t\t\t\t\t\tYour choice : ";
    cin>>ch;
    show(ch);
}
//-----------------------------------------------------------------------------------------------------------------
void add(int n)
{
	system("cls");
	heading();
	menu st;
	ofstream outFile;
	if(n==1)
	{
		cout<<"\t\t\t\t\t\t\t                 ADD VEG PIZZA\n";
	    cout<<"\t\t\t\t\t\t\t              -------------------\n\n";
		outFile.open("veg_pizza.dat",ios::binary|ios::app);
	}
	else if(n==2)
	{
		cout<<"\t\t\t\t\t\t\t                 ADD NON VEG PIZZA\n";
    	cout<<"\t\t\t\t\t\t\t              -----------------------\n\n";
	    outFile.open("nonveg_pizza.dat",ios::binary|ios::app);
	}
	else if(n==3)
	{
	    cout<<"\t\t\t\t\t\t\t                 ADD SIDES\n";
	    cout<<"\t\t\t\t\t\t\t              ---------------\n\n";
	    outFile.open("sides.dat",ios::binary|ios::app);
	}
	else if(n==4)
	{
		cout<<"\t\t\t\t\t\t\t                 ADD MEALS\n";
	    cout<<"\t\t\t\t\t\t\t              ---------------\n\n";
        outFile.open("meals.dat",ios::binary|ios::app);
	}
	else if(n==5)
	{
		cout<<"\t\t\t\t\t\t\t                 ADD DRINKS\n";
	    cout<<"\t\t\t\t\t\t\t              ----------------\n\n";
	    outFile.open("drinks.dat",ios::binary|ios::app);
	}
	else if(n==6)
	{
		cout<<"\t\t\t\t\t\t\t                 ADD DESSERTS\n";
	    cout<<"\t\t\t\t\t\t\t              -----------------\n\n";
	    outFile.open("desserts.dat",ios::binary|ios::app);
	}
	else if(n==7)
	{
		cout<<"\t\t\t\t\t\t\t               ADD MAGIC PAN\n";
	    cout<<"\t\t\t\t\t\t\t            -------------------\n\n";
    	outFile.open("magic.dat",ios::binary|ios::app);
	}
	else if(n==8)
	{
		entry_menu();
	}
	if(n>8)
	{
		add_item();
	}
	st.get_item();
	outFile.write(reinterpret_cast<char *> (&st), sizeof(menu));
	outFile.close();
    cout<<"\n\n\t\t\t\t\t\t\t\tITEM IS ADDED TO THE RESPECTIVE MENU.";
	cin.ignore();
	cin.get();
	add_item();
}
//-------------------------------------------------------------------------------------------------------------------------

void add_item()
{
	system("cls");
	heading();
    int ch=0;
    cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t                 ADD MENU\n";
	cout<<"\t\t\t\t\t\t\t              ---------------\n\n";
    cout<<"\t\t\t\t\t\t\t                1. VEG PIZZA\n\n";
    cout<<"\t\t\t\t\t\t\t                2. NON-VEG PIZZA\n\n";
    cout<<"\t\t\t\t\t\t\t                3. SIDES\n\n";
    cout<<"\t\t\t\t\t\t\t                4. MEALS\n\n";
    cout<<"\t\t\t\t\t\t\t                5. DRINKS\n\n";
    cout<<"\t\t\t\t\t\t\t                6. DESSERTS\n\n";
    cout<<"\t\t\t\t\t\t\t                7. MAGIC PAN\n\n";
    cout<<"\t\t\t\t\t\t\t                8. GO BACK\n\n";
    cout<<"\t\t\t\t\t\t\t\tYour choice : ";
    cin>>ch;
    add(ch);
}



//-------------------------------------------------------------------------------------------------------------------------
void entry_menu()
{
	system("cls");
	heading();
    char ch;
    cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t                 ENTRY MENU\n";
	cout<<"\t\t\t\t\t\t\t              ---------------\n\n";
    cout<<"\t\t\t\t\t\t\t                1. ADD ITEM\n\n";
    cout<<"\t\t\t\t\t\t\t                2. SHOW MENU\n\n";
    cout<<"\t\t\t\t\t\t\t                3. UPDATE ITEM\n\n";
    cout<<"\t\t\t\t\t\t\t                4. DELETE ITEM\n\n";
    cout<<"\t\t\t\t\t\t\t                5. GO BACK\n\n\n";
    cout<<"\t\t\t\t\t\t\t\tYour choice : ";
    cin>>ch;
    switch(ch)
    {
    	case'1':  add_item();
    	          break;
    	case'2':  show_menu();
		          break;
		case'3':  update_item();
		          break;
		case'4':  delete_item();
		          break;
		case'5':  m1();
		          break;
		default:  entry_menu();
	}
}

//-------------------------------------------------------------------------------------------------------------------------
void ologin()
{
	system("cls");
	heading();
	int i=0;
	char ch,a,uname[30]="babu";
	char pass[30]="coder";
	char ename[30],epass[30];
	cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tUSERNAME : ";
	cin>>ename;
	cout<<"\t\t\t\t\t\t\t\tPASSWORD : ";
	while(1)
	{
		ch=getch();
		if(ch==13)
		break;
		else if(ch==8 && i!=0)
		{
            i--;
            cout<<"\b"<<" "<<"\b";
            continue;
    }
        else if(ch==8)
        continue;
		else
		{
			cout<<"*";
			epass[i]=ch;
			i++;
		}
	}
	if((strcmp(uname,ename)==0)&&(strcmp(pass,epass)==0))
	{
		cout<<"\n\n\n\n\t\t\t\t\t\t\t\tYou have successfully logged into your account.";
		cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		getch();
		entry_menu();
	}
	else
	{
		cout<<"\n\n\n\n\t\t\t\t\t\t\t\tYou have entered wrong credentials.";
		cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		getch();
		m1();
	}
}
//------------------------------------------------------------------------------------------------------------------



void calculate(int e,int f,int g)
{
	menu st;
	ifstream inFile;
	if(e==1)
    inFile.open("veg_pizza.dat",ios::binary);
	else if(e==2)
	inFile.open("nonveg_pizza.dat",ios::binary);
	else if(e==3)
	inFile.open("sides.dat",ios::binary);
	else if(e==4)
	inFile.open("meals.dat",ios::binary);
	else if(e==5)
	inFile.open("drinks.dat",ios::binary);
	else if(e==6)
	inFile.open("desserts.dat",ios::binary);
	else if(e==7)
	inFile.open("magic.dat",ios::binary);
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	{
		if(st.backitemno()==f)
		{
	  		 float k=(st.backprice())*g;
	  		 flag=true;
	  		  
	  		 
	  		 system("cls");
   heading();
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t                   BILL\n";
	cout<<"\t\t\t\t\t\t\t\t             ---------------\n\n";
	cout<<"\n\n\t\t\t\t\t\t\t\tNAME : ";
	cin.ignore();
	cin.getline(n1,50);

	cout<<"\n\t\t\t\t\t\t\tQUANTITY\t\t\tNAME\t\t\tPRICE/ITEM";
	cout<<"\n\t\t\t\t\t\t\t-------------------------------------------------------------------";
	 cout<<"\t\t\t\t\t\t\t"<<setw(50)<<g;
	 cout<<"\t\t"<<setw(30)<<st.backnameitem();
	cout<<"\t\t"<<setprecision(2)<<setw(6)<<st.backprice();
	cout<<"\n\n\t\t\t\t\t\t\t-------------------------------------------------------------------";
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tTOTAL"<<k;
     cin.ignore();
	cin.get();
	m1();
        }
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
	order();
	
	
}
void showcu(int n)
{
	system("cls");
	heading();
	cout<<"\n\n\n\n\n";
	menu st;
	ifstream inFile;
	if(n==1)
	{
		cout<<"\t\t\t\t\t\t\t\t                 VEG PIZZA\n";
	    cout<<"\t\t\t\t\t\t\t\t             ---------------\n\n";
		inFile.open("veg_pizza.dat",ios::binary);
	}
	else if(n==2)
	{
		cout<<"\t\t\t\t\t\t\t\t                 NON VEG PIZZA\n";
    	cout<<"\t\t\t\t\t\t\t\t              -------------------\n\n";
	    inFile.open("nonveg_pizza.dat",ios::binary);
	}
	else if(n==3)
	{
	    cout<<"\t\t\t\t\t\t\t\t                 SIDES\n";
	    cout<<"\t\t\t\t\t\t\t\t              -----------\n\n";
	    inFile.open("sides.dat",ios::binary);
	}
	else if(n==4)
	{
		cout<<"\t\t\t\t\t\t\t\t                 MEALS\n";
	    cout<<"\t\t\t\t\t\t\t\t              -----------\n\n";
        inFile.open("meals.dat",ios::binary);
	}
	else if(n==5)
	{
		cout<<"\t\t\t\t\t\t\t\t                 DRINKS\n";
	    cout<<"\t\t\t\t\t\t\t\t              ------------\n\n";
	    inFile.open("drinks.dat",ios::binary);
	}
	else if(n==6)
	{
		cout<<"\t\t\t\t\t\t\t\t                 DESSERTS\n";
	    cout<<"\t\t\t\t\t\t\t\t              -------------\n\n";
	    inFile.open("desserts.dat",ios::binary);
	}
	else if(n==7)
	{
		cout<<"\t\t\t\t\t\t\t\t               MAGIC PAN\n";
	    cout<<"\t\t\t\t\t\t\t\t            ---------------\n\n";
    	inFile.open("magic.dat",ios::binary);
	}
	else if(n==8)
	{
		custom();
	}
	if(n>8)
	{
		order();
	}
	if(!inFile)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...NO ITEM FOUND...";
	    cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		cin.ignore();
	    cin.get();
	    order();
    }
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(menu)))
	st.layout();
		cout<<"\n\n\t\t\t\t\t\t\t\tWANT TO ORDER(y/Y) : ";
		char q;  cin>>q;
		if((q=='y')||(q=='Y'))
		{
		int a=0;
		cout<<"\n\t\t\t\t\t\t\t\tENTER THE ITEM NO. U WANT : ";
		cin>>a;
		cout<<"\n\t\t\t\t\t\t\t\tHOW MANY : ";
		int quan=0;
		cin>>quan;
		inFile.close();
		calculate(n,a,quan);
	   }

    inFile.close();
}
//------------------------------------------------------------------------------------------------------------------------
void order()
{
	system("cls");
	heading();
    int ch;
    cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t                    MENU\n";
	cout<<"\t\t\t\t\t\t\t              ---------------\n\n";
    cout<<"\t\t\t\t\t\t\t                1. VEG PIZZA\n\n";
    cout<<"\t\t\t\t\t\t\t                2. NON-VEG PIZZA\n\n";
    cout<<"\t\t\t\t\t\t\t                3. SIDES\n\n";
    cout<<"\t\t\t\t\t\t\t                4. MEALS\n\n";
    cout<<"\t\t\t\t\t\t\t                5. DRINKS\n\n";
    cout<<"\t\t\t\t\t\t\t                6. DESSERTS\n\n";
    cout<<"\t\t\t\t\t\t\t                7. MAGIC PAN\n\n";
    cout<<"\t\t\t\t\t\t\t                8. GO BACK\n\n";
    cout<<"\t\t\t\t\t\t\t\tYour choice : ";
    cin>>ch;
    showcu(ch);
}
//-------------------------------------------------------------------------------------------------------------------------
void login()
{
	system("cls");
	heading();
	long long int mobile;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t                    LOGIN\n";
	cout<<"\t\t\t\t\t\t\t                 -----------\n\n\n";
	cout<<"\t\t\t\t\t\t\t                MOBILE NO. : ";
	cin>>mobile;
    customer co;
	ifstream inFile;
	inFile.open("database.dat",ios::binary);
	if(!inFile)
	{

		cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...NO ITEM FOUND...";
	    cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		cin.ignore();
		cin.get();
		custom();
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&co), sizeof(customer)))
	{
	if(co.back()==mobile)
		{
		cout<<"\n\n\n\n\t\t\t\t\t\t\t\tYou have successfully logged into your account.";
		    cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		    cin.ignore();
		    cin.get();
		    order();
			flag=true;
		}
	}

	inFile.close();
	if(flag==false)
	{
	    cout<<"\n\n\n\n\t\t\t\t\t\t\t\tRecord does not exist.";
	    cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
        cin.ignore();
		cin.get();
		custom();
	}
}
//------------------------------------------------------------------------------------------------------------------
void registers()
{
	system("cls");
	heading();
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t                 SIGN UP\n";
	cout<<"\t\t\t\t\t\t\t              --------------\n\n\n";
	customer co;
	ofstream outFile;
	outFile.open("database.dat",ios::binary|ios::app);
	co.getdata();
	outFile.write(reinterpret_cast<char *> (&co), sizeof(customer));
	outFile.close();
    cout<<"\n\n\n\n\t\t\t\t\t\t\t\tYou have successfully registered.";
	cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
	cin.ignore();
	cin.get();
	custom();
}
//------------------------------------------------------------------------------------------------------------------
void custom()
{
	system("cls");
	heading();
	char ch;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t                 WELCOME\n";
	cout<<"\t\t\t\t\t\t\t              -------------\n\n\n";
	cout<<"\t\t\t\t\t\t\t                1. LOGIN\n\n";
    cout<<"\t\t\t\t\t\t\t                2. REGISTER\n\n";
    cout<<"\t\t\t\t\t\t\t                3. GO BACK\n\n\n";
    cout<<"\t\t\t\t\t\t\t\tYour choice : ";
	cin>>ch;
    switch(ch)
    {
    	case '1': login();
    	          break;
    	case '2': registers();
    	          break;
        case '3': m1();
        default:  custom();
	}
}

//---------------------------------------------------------------------------------------------------------------------
void m1()
{
	system("cls");
	heading();
    char ch;
    cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t                1. FOR OFFICIAL USE\n\n";
    cout<<"\t\t\t\t\t\t\t                2. FOR CUSTOMER USE\n\n";
    cout<<"\t\t\t\t\t\t\t                3. EXIT\n\n\n";
    cout<<"\t\t\t\t\t\t\t\tYour choice : ";
    cin>>ch;
    switch(ch)
    {
    	case '1': ologin();
    	          break;
    	case '2': custom();
    	          break;
        case '3': cout<<"\n\n\t\t\t\t\t\t\t                THANKU...PLEASE VISIT AGAIN...";
		          exit(0);
        default:  m1();
	}
}
//-------------------------------------------------------------------------------------------------------------------------
int main()
{
	//system("COLOR 1a");
    intro();
    cout.setf(ios::fixed|ios::showpoint);

    m1();
}






