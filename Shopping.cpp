#include <fstream>
#include "Shopping.h"


void Shopping::menu() {
    m:
    int choice ;
    string email ;
    string password;
    cout<<"\t\t\t\t_______________________________________\n" ;
    cout<<"\t\t\t\t                                       \n" ;
    cout<<"\t\t\t\t         SuperMarket Main Menu         \n" ;
    cout<<"\t\t\t\t                                       \n" ;
    cout<<"\t\t\t\t______________________________________ \n" ;
    cout<<"\t\t\t\t                                       \n" ;
    cout<<"\t\t\t\t|   1) Administrator                  |\n" ;
    cout<<"\t\t\t\t|                                     |\n" ;
    cout<<"\t\t\t\t|   2) Buyer                          |\n" ;
    cout<<"\t\t\t\t|                                     |\n" ;
    cout<<"\t\t\t\t|   3) Exit                           |\n" ;
    cout<<"\t\t\t\t|                                     |\n" ;
    cout <<"\n\t\t\t Please Select!" ;
    cin >> choice ;

    switch(choice){
        case 1:
            cout <<"\t\t\t Please Login \n" ;
            cout <<"\t\t\t Enter Email   \n" ;
            cin>> email ;
            cout <<"\t\t\t Enter password \n" ;
            cin>> password ;
            if(email == "mohanad@test.com" && password =="password") administrator();
            else cout << "Invalid Email/password" ;
            break;
        case 2:
            buyer() ;
        case 3:
            exit(0) ;
        default:
            cout << "please Seclect From the Given Option" ;
    }
    goto m ;

}//end of function

void Shopping::administrator() {
    m:
    int choice ;
    cout <<"\n\n\n\t\t\t Administrator menu" ;
    cout <<"\n\t\t\t|____1) Add a Product_____|";
    cout <<"\n\t\t\t|                         |";
    cout <<"\n\t\t\t|____2) Modify a Product__|";
    cout <<"\n\t\t\t|                         |";
    cout <<"\n\t\t\t|____3) Delete a Product__|";
    cout <<"\n\t\t\t|                         |";
    cout <<"\n\t\t\t|____4) Back To Main Menu_|";
    cout << "\n\n\t Please Enter Your Choice " ;
    cin >> choice ;

    switch(choice){
        case 1:
            add() ;
            break;
        case 2:
            edit() ;
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout << "Invalid Choice" ;
    }
    goto m ;

}//end of function

void Shopping::buyer() {
    m:
    int choice;
    cout << "\t\t\t Buyer      \n";
    cout << "\t\t\t____________ \n";
    cout << "\t\t\t              \n";
    cout << "\t\t\t1) Buy Product  \n";
    cout << "\t\t\t                 \n";
    cout << "\t\t\t2) Go Back         \n";
    cout << "\t\t\t Enter Your Choice : ";
    cin >> choice;
    switch (choice) {
        case 1:
            receipt();
            break;
        case 2 :
            menu();
            break;
        default:
                cout<<"invalid Choice" ;
    }

    goto m;


}//end of function

void Shopping::add() {
    m:
    fstream  data ;
    int c ;
    int token{0} ;
    float  p ;
    float d ;
    string n ;

    cout << "\n\n\t\t Add New Product" ;
    cout << "\n\n\t par Code of the product" ;
    cin >>parCode ;
    cout << "\n\n\t Price of the product" ;
    cin >>price ;
    cout << "\n\n\t Discount of the product" ;
    cin >>discount;
    data.open("database.txt" , ios::in);// writing
    if(!data){
        data.open("database.txt" , ios::app|ios::out) ;
        data << " " << parCode <<  " " << productName << " " <<  price <<  " " << discount <<  "\n";
    }else{
        data >> c >> n >> p >> d ;
        while (!data.eof()){
            if(c == parCode) token++ ;
            data >> c >> n >> p >> d ;
        }
        data.close();
    }

    if(token == 1 ) goto m ;
    else{
        data.open("database.txt" , ios::app|ios::out) ;
        data << " " << parCode <<  " " << productName << " " <<  price <<  " " << discount <<  "\n";
    }
    cout << "\n\n\t Record Inserted ! " ;

}//end of function

void Shopping::edit() {
    fstream  data , data1 ;
    int pkey ;
    int token{0};
    int nc ;
    float  p ;
    float  d ;
    string n ;

    cout<<"\n\t\t\t Modify Product" ;
    cout<<"\n\t\t\t Product Code: " ;
    cin >> pkey ;
    data.open("database.txt" , ios::in) ;
    if(!data){
        cout << "\n\nfile does not exist:" ;
    }else{
        data1.open("database1.txt" , ios::app|ios::out) ;
        data >> parCode >> productName >> price >> discount ;
        while (!data.eof()){//itterate if the record found we'll take the new input if not will basically add the same record
            if(pkey == parCode){
                cout << "\n\t\t Product New Code : ";
                cin >> nc ;
                cout << "\n\t\t Product New Name : ";
                cin >> n ;
                cout << "\n\t\t Product New Price : ";
                cin >> p ;
                cout << "\n\t\t Product  discount : ";
                cin >> d ;
                data1<<" " << nc << " " << n << " " << p << " " << d << "\n" ;

                cout << "\n\n\t\t Record Edited " ;
                token++ ;
            }else{
                data1<<" " << parCode << " " << productName << " " << price << " " << discount << "\n" ;
            }
            data >> parCode >> productName >> price >> discount ;
        }
        data.close();
        data1.close();
        remove("database.txt") ;
        rename("database1.txt" , "database.txt") ;
        if(token == 0 ) cout << "\n\n Record Not Found !" ;
    }


}//end of function

void Shopping::rem() {
    fstream  data , data1 ;
    int pkey ;
    int token{0};

    cout<<"\n\t\t\t Remove Product:" ;
    cout<<"\n\t\t\t Product Code: " ;
    cin >> pkey ;
    data.open("database.txt" , ios::in) ;
    if(!data) cout<<"file does not exist" << endl ;
    else{
        data1.open("database1.txt"  , ios::app|ios::out) ;
        data >> parCode >> productName >> price >> discount ;
        while (!data.eof()){
            if(parCode == pkey){
                cout << "\n\n\tproduct Deleted" ;
                token++;
            }else{
                data1 << " " <<parCode << " " << productName <<" " << price <<" " << discount <<"\n";
            }
            data >> parCode >> productName >> price >> discount ;
        }
        data.close();
        data1.close();
        remove("database.txt") ;
        rename("database1.txt" , "database.txt") ;
        if(token == 0 ) cout << "\n\n Record Not Found !" ;

    }
}//end of function

void Shopping::list() {
    fstream data;
    data.open( "database.txt", ios::in) ;
    cout<<"\n\n |__________________________________\n";
    cout<< "ProNo\t\t Name \t price \t dis" ;
    cout<<"\n\n |__________________________________\n";
    data >> parCode >> productName >> price >> discount ;
    while(!data.eof () ){
        cout<<parCode<<"\t\t"<<productName<<"\t\t"<<price<<"\n";
        data>>parCode>> productName>>price>>discount;
    }
    data.close() ;
}
void Shopping::receipt(){
    fstream data ;
    int arrC[100] ;
    int arrQ[100] ;
    int c = 0 ; float amount, dis, total ;
    amount =  dis =  total = 0 ;
    char choice ;
    cout << "\n\n\t\t\t RECEIPT " ;
    data.open("database.txt" , ios::in );
    if(!data) cout <<"\n\n empty DataBase" ;
    else{
        data.close() ;
        list() ;
        cout<<"\t\t\t\t_______________________________________\n" ;
        cout<<"\t\t\t\t                                       \n" ;
        cout<<"\t\t\t\t         Please Place The Order        \n" ;
        cout<<"\t\t\t\t                                       \n" ;
        cout<<"\t\t\t\t______________________________________ \n" ;
        do {
            m:
            cout << "\n\n Enter The Product Code : " ;
            cin >> arrC[c] ;
            cout << "\n\n Enter The Product Quantity : " ;
            cin >> arrQ[c] ;
            for (int i = 0; i < c ; ++i) {
                if(arrC[c] == arrC[i]){
                    cout << "\n\n Duplicate product, please select Another" ;
                    goto m;
                }
            }
            c++ ;
            cout << "\n\n Do You Want Another Product ? (y/n)" ;
            cin >> choice ;
        } while (choice == 'y') ;
        cout << "\n\n\t\t\t____________________RECEIPT________\n" ;
        cout << "\nProduct No \t Name \t quantity \t price \t amount \t amount with Discount  \n" ;

        for (int i = 0; i < c ; ++i) {
            data.open("database.txt" , ios::in) ;
            data>>parCode >> productName >> price >> discount ;
            while (!data.eof()){
                if(parCode == arrC[i]){
                    amount = price * arrQ[i] ;
                    discount = amount - (amount * discount/100) ;
                    total += discount ;
                    cout << "\n" << parCode <<  "\t\t" << productName <<  "\t\t" << arrQ[i] <<  "\t" << price <<  "\t" << amount <<  "\t" << discount;
                }
                data>>parCode >> productName >> price >> discount ;

            }
        }
        data.close() ;
    }
    cout <<"\n\n_____________________________" ;
    cout <<"\n Total Amount: " << total ;

};
