#include "namespace.cpp"

class BankBase{
    string name,address;

    public:
    void input(){
        cout<<"\nEnter name = ";
        cin>>name;
        cout<<"\nEnter address = ";
        cin>>address;
    }

    void display(){
        cout<<"Name = "<<name<<"\n Address = "<<address;
    }
    
};

class BankCustomer : public BankBase{
    
    string uname,pass;
    int acc_balance,acc_number;
    
    public:

    int getbalance(){
        return acc_balance;
    }
    void amount(int amount){
        acc_balance=acc_balance+amount;
    }
    BankCustomer(){
        acc_number = 364586;
    }
    bool c_input(){
        cout<<"\n Enter customer details \n";
        input();
        cout<<"\n Enter the username = ";
        cin>>uname;
        cout<<"\n Enter the password = ";
        cin>>pass;

        acc_balance = 0;
        acc_number = acc_number + 22;
        return true;
    }
    void c_display(){
        cout<<"\n Customer details below  \n\n";
        display();
        cout<<"\n Customer Bank balance = "<<acc_balance<<"\n\n Customer Bank account number = "<<acc_number<<"\n\n Customer Username - "<<uname<<"\n\n Customer Password - "<<pass;
    }
    string cname(){
        return uname;
    }

    string cpass(){
        return pass;
    }
};

class BankEmployee : public BankBase{
    int number;
    string uname,password;

    public:
    string ename(){
        return uname;
    }

    bool e_input(){
        cout<<"\n Enter employee details \n\n";
        input();
        cout<<"\nEnter Employee phone number = ";
        cin>>number;
        cout<<"\n\nEnter Employee username = ";
        cin>>uname;
        cout<<"\n\nEnter Employee password = ";
        cin>>password;

        return true;
    }

    void e_display(){
        cout<<"\n\n Employees details are  \n\n";
        display();
        cout<<"\n\n Employe Number - "<<number;

        cout<<"\n\n Employe Username - "<<uname;
        cout<<"\n Employe Password - "<<password;
    }

    string epass(){
        return password;
    }
};

class BankAdmin : public BankBase{
    
    string uname,pass;
    
    public:
    bool validate(){
        cout<<"\n\nEnter username - ";
        cin>>uname;
        cout<<"\n\nEnter password - ";
        cin>>pass;

        if(uname=="admin" && pass == "pass"){
            cout<<"\n\nWelcome to admin pannel! \n\nYour login is successful!\n ";
            return true;
        }
        else{
            return false;
        }
    }

};