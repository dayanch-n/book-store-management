/*
                                                                    ***** ATTENTION ******

/////////////// Use this command to make available c++17 fetures. run in terminal on main.cpp page  << g++ -std=c++17 -g main.cpp -o main >> ////////////////////


*/

#include <iostream>
#include <fstream>

using namespace std;
#include "Globel.h"
#include <string>

int main() {
	BooksList* bookList = new BooksList();
	char again='n';
    cout << "\n"
    
 

<<"\t\t         _       __________   __________  __  _________\n"
<<"\t\t        | |     / / ____/ /  / ____/ __ '/  |/  / ____/\n"
<<"\t\t        | | /| / / __/ / /  / /   / / / / /|_/ / __/\n"     
<<"\t\t        | |/ |/ / /___/ /__/ /___/ /_/ / /  / / /___\n"    
<<"\t\t        |__/|__/_____/_____|____/'____/_/  /_/_____/\n\n"


<<"\t     __________     ____  ____  ____  __ __    _______________  ____  ______\n"
<<"\t    /_  __/ __ )   / __ )/ __ )/ __ '/ //_/   / ___/_  __/ __ '/ __ '/ ____/\n"  
<<"\t     / / / / / /  / __  / / / / / / / , <     '__ ' / / / / / / /_/ / __/\n"      
<<"\t    / / / /_/ /  / /_/ / /_/ / /_/ / /| |    ___/ // / / /_/ / _, _/ /___\n"       
<<"\t   /_/  (____/  /_____/'____)(____/_/ |_|   /____//_/  (____/_/ |_/_____/\n"; 

	do {

        char ch;
        char input;
        cout << "\n\n\t=================================================================" << endl;
        cout<<"\n\t\t\t********* Main Menu **********\n\n";
        cout<<"Please Select Option\n";
        cout<<"\n\t 1. Inventory 🎮\n\n";
        cout<<"\t 2. Transaction 💰\n\n";
        cout<<"Enter : ";
        cin >> input;

        if(input == '1'){
            cout<<"\n\nPlease Select Option\n\n";
            cout<<"\n\t 1. Add New Category\n\n";
            cout<<"\t 2. Add New Book\n\n";
            cout<<"\t 3. Delete a Category\n\n";
            cout<<"\t 4. Delete a Book\n\n";
            cout<<"\t 5. Filter by Category\n\n";
            cout<<"\t 6. Update Book\n\n";
            cout<<"\t 7. Search a Book\n\n";
            cout<<"\t 8. Print All\n\n";
            cout<<"\t 9. Sort Product\n\n";
            cout<<"Enter : ";
            cin>>ch;
            switch(ch) {
                case '1':
                    bookList->InsertNewCategory();
                    break;
                case '2':
                    bookList->InsertNewBook();
                    break;
                case '3':
                    bookList->DeleteCategory();
                    break;
                case '4':
                    bookList ->DeleteBook();
                    break;
                case '5':
                    bookList->FilterByCategory();
                    break;
                case '6':
                    bookList->updateBook();
                    break;
                case '7':
                    bookList->SearchBook();
                    break;
                case '8':
                    bookList->PrintAll();
                    break;
                case '9':
                    bookList->SortProduct();
                    break;
                default:
                    cout<<"Invalid option.\n";
                    break;
            }
        }else if (input == '2') {
            cout<<"\n\t 1. Add Purchase\n\n";
            cout<<"\n\t 2. View Purchased Book\n\n";
            cout<<"\n\t 3. Sort Purchase Transactions\n\n";
            cout<<"\n\t 4. Purchase Details\n\n";
            cout<<"Enter : ";
            cin>>ch;
            switch(ch){
                case '1':
                    bookList->purchaseBook();
                    break;
                case '2':
                    bookList->getPurchasedBooks();
                    break;
                case '3':
                    bookList->SortPurchase();
                    break;
                case '4':
                    bookList->Purchase_Detail();
                    break;
                default:
                    cout<<"Invalid option.\n";
                    break;
            }
        }else{
            cout <<"Invalid option.\n";
        }
        
        cout<<"\n\t\t Go to the main menu (y/n) : "; cin>>again;

    }while(again!='n');
        cout << "\n\t\t\tSEE YOU SOON !\n\n";
        system("pause");
}


    
 

    
                                                                                                                                                                                             




