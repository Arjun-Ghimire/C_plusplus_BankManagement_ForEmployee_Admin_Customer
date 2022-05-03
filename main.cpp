#include "namespace.cpp"

int main(){
    int c_count=0,e_count=0,deposite_amount,withdraw_amount,selected;
    string name,password;
    int log;
    BankAdmin ba;
    BankCustomer bc[10];
    BankEmployee be[10];

    int choice;

    mymain:
    cout<<"\n\nChoose Your Role ? \n \n- Enter 1 for admin  \n- Enter 2 for employee \n- Enter 3 for customer \n- Enter 4 to exit program \n"<<endl;
        
    cout<<"Enter option = ";
    cin>>choice;

        switch(choice){
            case 1: cout<<"\n\nYou choosed role as Admin \n "; 
                    
                    cout<<"\n- Enter 1 to login as admin \n- Enter 2 to go back to the menu \n";
                    
                    cout<<"\nEnter option = ";
                    cin>>choice;

                    switch(choice){
                        case 1: cout<<"\n\nLogin To Your Admin Pannel"<<endl;
                        
                        if(ba.validate() == true){
                            loggedadmin:
                            cout<<"\n\nChoose action you want to perform - \n \n";
                            cout<<"\n- Enter 1 to add an customer \n- Enter 2 to add employee \n- Enter 3 to go to admin menu\n \n- Enter 4 to go to main menu\n";
                            cout<<"\n\nEnter option = ";
                            cin>>choice;
                            
                            if(choice == 1){
                                if(bc[c_count].c_input()==true){
                                    cout<<"\nSuccessfully Created customer ~! \n\n";
                                    bc[c_count].c_display();
                                    c_count++;
                                    cout<<"\n\n Now you can choose another action \n\n";
                                    goto loggedadmin;
                                }

                                else{
                                    cout<<"\nFailed to create customer \n";
                                    cout<<"\n\n Now you can choose another action \n\n";
                                    goto loggedadmin;
                                    
                                }

                            }
                            else if(choice ==2){
                                if(be[e_count].e_input()==true){
                                    cout<<"\nSuccessfully Created employee ~! \n\n";
                                    be[e_count].e_display();
                                    e_count++;
                                    cout<<"\n\n Now you can choose another action \n\n";
                                    goto loggedadmin;
                                }

                                else{
                                    cout<<"\nFailed to create employee\n";
                                    cout<<"\n\n Now you can choose another action \n\n";
                                    goto loggedadmin;
                                }
                            }
                            else if(choice ==3){
                                    cout<<"\n\n Now you can choose another action \n\n";
                                    goto loggedadmin;
                            }
                            else if(choice ==4)
                            {
                                goto mymain;
                            }
                            else{
                                cout<<"\n\n Invalid Action \n\n";
                                goto mymain;
                            }

                        }else{
                            cout<<"\nLogin incorrect ~~~!!\n\n Please choose another action! \n";
                            goto mymain;
                            break;
                        }
                        break;

                        case 3: cout<<"\n\nYou choosed to go to menu";
                        goto mymain;
                        break;
                        
                    }

            break;

            case 2: cout<<"\n\nYou choosed role as Employee \n\n ";
                    
                cout<<"\n- Enter 1 to login to Employee Panel \n-Enter 2 to go back to the menu \n\n";
                cout<<"\n\nYour choice = ";
                cin>>choice;

                if(choice ==1){

                    cout<<"\nEnter username = ";
                    cin>>name;
                    cout<<"\nEnter password = ";
                    cin>>password;
                    for(int i=0;i<=e_count;i++){
                        if( be[i].ename()==name && be[i].epass()==password ){
                            log=1;
                        }   
                    }

                    if(log==1){
                        cout<<"\n\nLogin Successful\n";
                        loggedinemployee:
                        cout<<"\n- Enter 1 to Create customer \n-Enter 2 to go back to the menu \n- Enter 3 to go to main menu\n \n\n";
                        cout<<"\n\n Your choice = ";
                        cin>>choice;

                        if(choice==1){
                            if(bc[c_count].c_input()==true){
                                cout<<"\nSuccessfully Created customer ~! \n\n";
                                bc[c_count].c_display();
                        
                                c_count++;
                                goto mymain;
                            }

                            else{
                                cout<<"\nFailed to create customer \n";
                                goto mymain;
                            }
                        }

                        else if(choice ==2){
                            goto loggedinemployee;
                        }

                        else if(choice ==3){
                            goto mymain;
                            
                        }

                        else{
                            cout<<"\n\n Invalid Action \n\n";
                            goto mymain;
                        }
                       
                    }
                    else{
                        cout<<"\n\nLogin Failed\n";
                        goto mymain;
                    }
                }

                else if(choice==2){
                    goto mymain;
                }
                else{
                    cout<<"\n\n Invalid Action \n\n";
                    goto mymain;
                }

            break;

            case 3: cout<<"\n\nYou choosed role as Customer \n ";
                    
                cout<<"\n- Enter 1 to login to as Customer \n - Enter 2 to go back to the menu \n\n";
                cout<<"\n\nYour choice = ";
                cin>>choice;

                if(choice ==1){

                    cout<<"\n\nEnter username = ";
                    cin>>name;
                    cout<<"\nEnter password = ";
                    cin>>password;
                    for(int i=0;i<=e_count;i++){
                        if( bc[i].cname()==name && bc[i].cpass()==password ){
                            log=2;
                            selected=i;

                        }   
                    }

                    if(log==2){
                        cout<<"\nLogin Successful\n\n";
                        loggedcustomer:
                        cout<<"\n- Enter 1 to deposite balance \n- Enter 2 to withdraw balance \n- Enter 3 to check account balance \n- Enter 4 to go to customer menu\n- Enter 5 to go to main menu \n\n";
                        cout<<"\n\n\n Your choice = ";
                        cin>>choice;

                        if(choice ==1){

                            cout<<"\n\nEnter amount you want to deposite - ";
                            cin>>deposite_amount;
                            if(deposite_amount > 1000){
                                bc[selected].amount(deposite_amount);
                                cout<<"\n\nDeposite is successful";
                                cout<<"\n\n Now you can select another action \n";
                                goto loggedcustomer;
                            }else{
                                cout<<"\n\nThe minimum deposite amount is 1,000 \n\n";
                                goto loggedcustomer;
                            }

                        }
                        else if(choice ==2){

                            cout<<"\n\nEnter amount you want to withdraw - ";
                            cin>>withdraw_amount;
                            if(deposite_amount > 1000){
                                if(bc[selected].getbalance()>withdraw_amount){
                                    bc[selected].amount(-withdraw_amount);
                                    cout<<"\n\nWithdraw is successful \n";
                                }
                                else{
                                    cout<<"\n\nYou have insufficient balance \n";
                                    cout<<"\n\n Select another action please \n\n";
                                    goto loggedcustomer;
                                }
                            }else{
                                cout<<"\n\nThe minimum withdraw amount is 1,000 \n\n";
                                cout<<"\n\n Select another action please \n\n";
                                goto loggedcustomer;
                            }

                        }
                        else if(choice ==3){
                            cout<<"\n\n Your account balance is = "<<bc[selected].getbalance()<<endl;
                        }
                        else if(choice ==4){
                            goto loggedcustomer;
                        }
                        else if(choice==5){
                            goto mymain;
                        }
                        else{
                            cout<<"\n\n Invalid Action \n\n";
                            goto mymain;
                        }
                    }
                    else{
                        cout<<"\n\nLogin Failed\n";
                        goto mymain;
                    }
                }

                else if(choice==2){
                    goto mymain;
                }

                else{
                    cout<<"\n\n Invalid Action \n\n";
                    goto mymain;
                }
                  
            break;
        }

        if(choice == 4){

            cout<<"\n\nProgram is successfully Exited \n \n"<<endl;
            
        }

    return 0;

}