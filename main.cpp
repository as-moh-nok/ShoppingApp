#include<iostream>
#include<fstream>
#include <cstdlib>

using namespace std;

class shopping
{
private:
    int pcode;
    string pname;
    float price;
    float discount;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void remov();
    void list();
    void receipt();
};

void shopping :: menu()
{
    jmenu:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t_________________________________\n";
    cout<<"\t\t\t\t                                 \n";
    cout<<"\t\t\t\t     Supermarket Main Menu       \n";
    cout<<"\t\t\t\t                                 \n";
    cout<<"\t\t\t\t_________________________________\n";
    cout<<"\t\t\t\t                                 \n";
    cout<<"\t\t\t\t| 1) Aministrator     |\n";
    cout<<"\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t| 2) Buyer            |\n";
    cout<<"\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t| 3) Exit             |\n";
    cout<<"\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t Please select!";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"\t\t\t Please Login  \n";
        cout<<"\t\t\t Enter Email   \n\t\t\t";
        cin>>email;
        cout<<"\t\t\t Password      \n\t\t\t";
        cin>>password;

        if(email=="asma" && password=="pass")
        {
            administrator();
        }
        else
        {
            cout<<"Invalid email/password";
        }
        break;

    case 2:
        {
            buyer();
        }
    case 3:
        {
            exit(0);
            //menu();
        }
    default:
        {
            cout<<"Please select from the given options";
        }
    }
goto jmenu;
}

void shopping:: administrator()
{
    jmenu:
    int choice;
    cout<<"\n\n\n\t\t\t Aministrator menu";
    cout<<"\n\t\t\t|____1) Add the product______|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|____2) Modify the product___|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|____3) Delete the product___|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|____4) Back to main menu____|";

    cout<<"\n\n\t  Please enter your choice ";
    cin>> choice;

    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        remov();
        break;

    case 4:
        menu();
        break;

    default:
        cout<<"Invalid choice!";
    }
    goto jmenu;
}

void shopping:: buyer()
{
    jmenu:
    int choice;
    cout<<"\t\t\t Buyer:      \n";
    cout<<"                     \n";
    cout<<"\t\t\t1) Buy product \n";
    cout<<"                     \n";
    cout<<"\t\t\t2) Go back             \n";
    cout<<"\t\t\t Enter your choice : ";

    cin>>choice;

    switch(choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout<<"Invalid choice";
    }
    goto jmenu;
}

void shopping ::add()
{
    jmenu:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product\n\n\t\t\t";
    cout<<"\n\n\t Product code of the product :";
    cin>>pcode;
    cout<<"\n\n\t Name of the product: ";
    cin>>pname;
    cout<<"\n\n\t Price of the product: ";
    cin>>price;
    cout<<"\n\n\t Discount on product: ";
    cin>>discount;

    data.open("database.txt",ios::in);//open in read mode , ios::out ->writing mode

    if(!data)
    {
        cout<<"!data yes \n";
        cout<<"\ncreate a database";
        data.open("database.txt", ios::app | ios::out );//ios::app set position of indicator end of file
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d; //initilize file indext
        while(!data.eof()) //eof:end of file
        {
            if(c == pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();


    if(token==1)
        goto jmenu; //we had
        else{ //if don't decrement and didn't add
            data.open("database.txt", ios::out |ios::app);

            data<<" "<<pcode<<" "<<pname<< " "<<price<<" "<<discount<<"\n";
            data.close();
        }
    }
    cout<<"\n\n\t Recorde inserted !";

}

void shopping:: edit()
{
    fstream data, data1;
    int product_key;
    int token=0;
    int c;//code
    float p;//price
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record\n\n\t\t\t";
    //list();
    cout<<"\n\t\t\t Product code :";
    cin>>product_key;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile dosen't exit!";
    }
    else{
        //for edit we should create new file and replace with older:
        data1.open("database1.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(product_key==pcode)
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                //create new database:
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token== 0)
        {
            cout<<"\n\n Record not found,sorry!";
        }
    }
}

void shopping:: remov()
{
    list();
    fstream data,data1;
    int product_key; //code user enter to delete
    int token = 0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product code :";
    cin>>product_key;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File doesn't exist";
    }
    else{
       data1.open("database1.txt",ios::app|ios::out);
       data>>pcode>>pname>>price>>discount;
       while(!data.eof())
       {
           if(pcode==product_key)
           {
               cout<<"\n\n\t Product delete successfully";
               token++;
           }
           else
           {
            data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
           }
           data>>pcode>>pname>>price>>discount;
       }
       data.close();
       data1.close();
       remove("database.txt");
       rename("database1.txt","database.txt");

       if(token==0)
       {
           cout<<"\n\n Record not found";
       }
    }
}

void shopping:: list()
{

    fstream data;
    data.open(("database.txt"), ios::in);
    cout<<"\n\n|----------------------------------------\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n-----------------------------------------\n";
    data>>pcode>>pname>>price>>discount;//take out to access
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>discount;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;

    int arr_codes[100];
    int arr_quantity[100];
    char choice;
    int counter = 0 ;
    float amount= 0;
    float discount=0;
    float total=0;

    cout<<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else{
        data.close();
        jmenu:
        list();
        cout<<"\n-----------------------------------\n";
        cout<<"\n|                                  \n";
        cout<<"\n|      Please place the order      \n";
        cout<<"\n|                                  \n";
        cout<<"\n------------------------------------\n";
        do
        {
            cout<<"\n\n Enter Product code :";
            cin>>arr_codes[counter];//first product
            cout<<"\n\n Enter the product quantity :";
            cin>>arr_quantity[counter];
            for(int i=0;i<counter; i++)
            {
                if(arr_codes[i]==arr_codes[counter])
                {
                    cout<<"\n\n Duplicate product code. Please try again!";
                    goto jmenu;
                }
            }
                counter++;
                cout<<"\n\n Do you want to buy another poduct? if yes then press y else n.";
                cin>>choice;
        }
        while(choice== 'y');//until user response is yes


            cout<<"\n\n\t\t\t-----------------RECEIPT----------------\n";
            cout<<"\n ProductNo  Product Name  Product quantity  price  Amount  Amount with discount\n";

            for(int i=0;i<counter; i++)
            {
                data.open("database.txt", ios::in);//use database for use their price
                data>>pcode>>pname>>price>>discount;
                while(!data.eof())
                {
                    if(pcode==arr_codes[i])
                    {
                        amount=price*arr_quantity[i];
                        discount   =amount - (amount* discount/100);//calculate discount
                        total = total + discount;
                        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t"<<arr_quantity[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<discount;
                    }
                    data>>pcode>>pname>>price>>discount; //compare with next product
                }
                data.close();
            }

        }
        cout<<"\n\n--------------------------------------------------------";
        cout<<"\n Total Amount : "<<total;

}

int main()
{
    shopping myshopping;
    myshopping.menu();

}
