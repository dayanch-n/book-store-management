#include <vector>
#include <ctime>

#include <algorithm>

class Book{
     public:
     string title;
     string author;
     string year;
     int price;
};

class PurchasedBooks: public Book{
     public:
     string ID;
     string date;
};

class SortBooks: public Book {
     public:
     int quantity;
};




class BooksList {
    CategoryNode *head;    
  public:
    BooksList() {
      head = NULL;           
    }

    bool isEmpty() {
      return (head==NULL);     
    }

    vector<PurchasedBooks> allTransactions;

    bool Search(string query, int val) { // searc a book / category..
         bool retFound = false;
         if(!isEmpty()){
             CategoryNode *curr=head,*ret=NULL;
             bool found=false;
             
               while(curr!=NULL && !found){
                    
                    if(curr->category == query && val == 2) { // search in category
                         
                         cout<<"\n\t\t\tCategory : "<<curr->category<<"\n";
                         found=true;
                         BookNode* sBooks = curr->books; 
                         while(sBooks != NULL && found) {
                                   cout<<"\n\tt** All books under '"<< curr->category<<"' category **\n";
                                   cout<<"\n\tTitle : "<<sBooks->title;
                                   cout<<"\n\tAuthor : "<<sBooks->author;
                                   cout<<"\n\tYear : "<<sBooks->year;
                                   sBooks = sBooks->next;
                         }
                    }
                    else if (val == 1) { // search in books..
                         BookNode* sBooks = curr->books;
                         bool bookF = false; 
                         while(sBooks != NULL && !bookF) {
                                   if(sBooks->title == query) {
                                        bookF = true;
                                        cout<<"\n\tBook title : "<<sBooks->title;
                                        cout<<"\n\tBook author : "<<sBooks->author;
                                        cout<<"\n\tBook year : "<<sBooks->year;
                                        cout<<"\n\tBook quantity : "<<sBooks->quantity;
                                   }
                                   else {
                                        sBooks = sBooks->next;
                                   }
                         }
                         if(bookF) {
                              cout<<"\n\t\t\tCategory : "<<curr->category<<"\n";
                              found = retFound = true;
                         }       
                    }
                    curr=curr->next;        
               }  
             retFound = found;        
         }
         return retFound;
    }

    bool DeleteBookByTitle(string bookName) {
        bool retResult = false;
        if(!isEmpty()){
             CategoryNode *curr=head,*ret=NULL;
             bool deleted=false;
             while(curr!=NULL && !deleted) {
                        bool found = false;
                        BookNode* currBook = curr->books; 
                        BookNode* prevBook = NULL;
                        while(currBook != NULL && !found) {
                              if(currBook->title == bookName) {
                                   found = true;
                              }
                              else {
                                   prevBook = currBook;
                                   currBook = currBook->next;
                              }
                        }
                        if(found) {
                             BookNode* node = currBook;
                             if(prevBook == NULL) {
                                  curr->books = currBook->next;
                             }
                             else {
                                  prevBook->next = currBook->next;
                             }
                             delete (node);
                             deleted = true;
                        }
                        else // move to next category
                             curr=curr->next;          
             }  
             retResult = deleted;        
         }
         return retResult;
    }

    bool InsertCategory(string cat) {
       bool retInserted = false;
       CategoryNode *newnode = new CategoryNode(cat);
       if(isEmpty()) {
           head = newnode;   
           retInserted = true;           
       }
       else {
           newnode->next = head;
           head = newnode;
           retInserted = true; 
       }
       return retInserted;
    }

    bool InsertBook(string bookId, string bookTitle, string bookAuthor, string bookYear, int quantity, int price, int catID) {
       bool retInserted = false; 
       BookNode *newBook = new BookNode(bookId, bookTitle, bookAuthor, bookYear, quantity, price);
       if(!isEmpty()) { // categories available
           int i=1;
           CategoryNode *curr = head,*prev = NULL;
           bool CanInsert=false;
           i = 1;
           while(i <= catID && curr!=NULL && !CanInsert) {
             if(i == catID) {
               	if(curr->books == NULL) {
                      CanInsert = true;
                }
                else{
                   BookNode *sBooks = curr->books;
                   bool foundBook = false;
                   while(sBooks!=NULL && !foundBook) {
                         if(sBooks->title == bookTitle) { // book found
                             foundBook = true;          
                         }
                         else {
                             sBooks = sBooks->next;     
                         }            
                   } 
                   if(!foundBook) {
                      CanInsert = true; 
                   }
                }
             }
             else{
                  curr = curr->next;
                  i++;
             }
           }
           if( CanInsert && curr != NULL ) {
              if(curr->books == NULL){
                   curr->books = newBook;
                   retInserted = true;
              }
              else {
                   newBook->next = curr->books;
                   curr->books = newBook;
                   retInserted = true;
              }
           }
       }
       return retInserted;
    }

    bool DeleteCategoryByID(int catID) {
        bool retDeleted = false;
        if(!isEmpty()){
             CategoryNode* curr = head;
             CategoryNode* prev = NULL;
             int i=1;
             bool canDelete = false;
             while(curr!=NULL && i<=catID && !canDelete) {
                   if(i == catID){
                        canDelete = true;
                   }
                   else{
                        prev = curr;
                        curr = curr->next;
                        i++;
                   }
             }
             if(canDelete) {
                  if(prev == NULL) { // delete First
                        CategoryNode *node = curr;
                        head = curr->next;
                        delete (node);
                        retDeleted = true;
                  }
                  else {
                       CategoryNode *node = curr;
                       prev->next = curr->next;
                       delete (node);
                       retDeleted = true;
                  }
             }
        }
        return retDeleted;
    }

    void InsertNewCategory() {
        string categ;
        cout<<"\n\tCategory Name : "; 
        fflush(stdin);
        getline(cin,categ);
        convertToLower(categ);
        if(InsertCategory(categ)) {
           cout<<"\n\t** Category Created Successfully! **\n";
        }
        else {
           cout<<"Already Exists.! \n";     
        }
    }

    void InsertNewBook() {
        if(!isEmpty()){
            string bookId = "";
            string bookTitle = "";
            string bookAuthor = "";
            string bookYear = "";
            int quantity = 0;
            int price = 0;
            int categ = -1, i = 1;
            CategoryNode *ptr = head;

            cout<<"ID: ";
            cin >> bookId;
            cin.sync();

            cout<<"Book title : ";
            cin >> bookTitle; 
            cin.sync();

            cout<<"Author: ";
            cin >> bookAuthor; 
            cin.sync();
            
            cout<<"Year: ";
            cin >> bookYear; 
            cin.sync();

            cout<<"Quantity: ";
            cin >> quantity; 
            cin.sync();

            cout<<"Price: $";
            cin >> price; 
            cin.sync();
            
            fflush(stdin);
            convertToLower(bookId);
            convertToLower(bookTitle);
            convertToLower(bookAuthor);
            convertToLower(bookYear);
            

            cout<<"\n\t\tAvailable Books Categories\n";
            while(ptr!=NULL) {
               	cout<<i<<". "<<ptr->category<<endl;
               	ptr = ptr->next;
               	i++;
            }
            cout<<"\n\tChoose Category :"; cin>>categ;

            if( InsertBook(bookId, bookTitle, bookAuthor, bookYear, quantity, price, categ) ) {
               cout<<"Inserted..\n";
            }
            else {
               cout<<"Book Already Exist.! \n";     
            }
        }
        else {
             cout<<"No Categories Available!\n";
        }
    }

    void DeleteCategory() {
        if(!isEmpty()) {
            int categ = -1, i = 1;
            CategoryNode *ptr = head;
            cout<<"\n\t\tAvailable Books Categories\n";
            while(ptr!=NULL) {
               	cout<<i<<".\t"<<ptr->category<<endl;
               	ptr = ptr->next;
               	i++;
            }
            cout<<"Choose Category to delete :"; cin>>categ;
            if( DeleteCategoryByID(categ) ) {
               cout<<"Deleted..\n";
            }
            else {
               cout<<"Category not exist.! \n";     
            }
        }
        else {
             cout<<"No Categories Available!\n";
        }
    }

    void DeleteBook() {
        if(!isEmpty()) {
            string bookTitle = "";
            cout<<"\nEnter book title to delete: "; 
            fflush(stdin);
            getline(cin,bookTitle);
            convertToLower(bookTitle);
            if( DeleteBookByTitle(bookTitle) ) {
               cout<<"Book Deleted..\n";
            }
            else {
               cout<<"No Category exist.! \n";     
            }
        }
        else {
             cout<<"No Categories Available!\n";
        }
    }

    void SearchBook() {
        if(!isEmpty()) {
             string bookTitle = "";
             cout<<"\nBook title to search :"; 
             fflush(stdin);
             getline(cin,bookTitle);
             convertToLower(bookTitle);
             if(!Search(bookTitle,1))
                 cout<<"Book Not Found!\n";
        }
        else {
            cout<<"No Categories Available!\n";
        }  
    }

     void FilterByCategory() {
          if(!isEmpty()) {
               string Categ = "";
               int count = 0;
               CategoryNode* currCategory = head;
               
               cout << "\n\t\tAvailable categories: \n";

               while (currCategory != NULL){

                    count ++;
                    cout << "\n\t\t" << count << ". " << currCategory->category;

                    currCategory=currCategory->next;  
               }
               
               cout<<"\n\t\tEnter category name to filter :"; 
               fflush(stdin);
               getline(cin,Categ);

               convertToLower(Categ);
               if(!Search(Categ,2))
                    cout<<"Category Not Found!\n";
          }
          else {
               cout<<"No Categories Available!\n";
          }  
     }

    void PrintAll() {
        if(!isEmpty()) {
             CategoryNode* currCateg = head;
             int i=1,j=1;
             while(currCateg!=NULL) {
                   cout<<"\tCategory "<<i<<": "<<currCateg->category<<"\n";
                   BookNode *currBook = currCateg->books;
                   j=1;
                   while(currBook!=NULL) {
                         cout<<"\n\t\t"<<j<<" book 📙"; 
                         cout<<"\n\t\tID: "<<currBook->id<<"\n";
                         cout<<"\t\tTitle: "<<currBook->title<<"\n";
                         cout<<"\t\tAuthor: "<<currBook->author<<"\n";
                         cout<<"\t\tYear: "<<currBook->year<<"\n";
                         cout<<"\t\tQuantity: "<<currBook->quantity<<"\n";
                         
                         currBook = currBook->next;
                         j++;
                   }
                   currCateg = currCateg->next;
                   i++;
             }
        }
        else {
            cout<<"\n\tNo Categories Available!\n";
        }     
    }

     struct sort_desc {
          
          inline bool operator() (const SortBooks& lhs, const SortBooks& rhs)
          {
               return (lhs.quantity > rhs.quantity);
          }
     };

    void SortProduct() {
         if (!isEmpty()){
               CategoryNode* currCateg = head;

               vector<SortBooks> sortBookVector; 
               cout << "\n\t\tAll the Books sorted by quantity availability";
              
                while(currCateg!=NULL) {

                    BookNode *currBook = currCateg->books;
                    
                    while (currBook != NULL){
                    

                         SortBooks sortedBooks;
                         
                         sortedBooks.title =  currBook->title;
                         sortedBooks.author =  currBook->author;
                         sortedBooks.year =  currBook->year;
                         sortedBooks.price =  currBook->price;
                         sortedBooks.quantity =  currBook->quantity;
                         
                         // Inserting book details into vector
                         sortBookVector.push_back(sortedBooks);

                         // next node
                         currBook = currBook->next;
                    }
                    currCateg = currCateg->next;    
               }
          
               for (int i = 0; i < sortBookVector.size(); i++){

                    sort(sortBookVector.begin(), 
                         sortBookVector.end(), sort_desc());
                        

                    cout << "\n\tTitle: " << sortBookVector[i].title;
                    cout << "\n\tAuthor: " << sortBookVector[i].author;
                    cout << "\n\tYear: " << sortBookVector[i].year;
                    cout << "\n\tPrice: $" << sortBookVector[i].price;
                    cout << "\n\tQuantity: " << sortBookVector[i].quantity << "\n";
               }
          }
     }

     struct sort_purchase {
          
          inline bool operator() (const PurchasedBooks& lhs, const PurchasedBooks& rhs)
          {
               return (lhs.price > rhs.price);
          }
     };

     void SortPurchase(){
          if (!allTransactions.empty()){
               cout<<"\n\t\t\tBooks sorted by total price";

               for (int i = 0; i < allTransactions.size(); i++){

                    sort(allTransactions.begin(), 
                         allTransactions.end(), sort_purchase());
                        

                    cout << "\n\tTitle: " << allTransactions[i].title;
                    cout << "\n\tAuthor: " << allTransactions[i].author;
                    cout << "\n\tYear: " << allTransactions[i].year;
                    cout << "\n\tPrice: $" << allTransactions[i].price;
                    cout << "\n\tPurchased Date: " << allTransactions[i].date << "\n";

               }
               
          }else {
               cout << "\n\tNo purchase transactions made yet!";
          }
     }

     void getPurchasedBooks(){

          cout<<"\n\t\t\tAll Purchases Transactions"<<"\n";
          if (!allTransactions.empty()){

               for (int i = 0; i < allTransactions.size(); i++){
                    cout << "\n\tTransactionID: " << allTransactions[i].ID;
                    cout << "\n\tTitle: " << allTransactions[i].title;
                    cout << "\n\tAuthor: " << allTransactions[i].author;
                    cout << "\n\tYear: " << allTransactions[i].year;
                    cout << "\n\tPrice: $" << allTransactions[i].price;
                    cout << "\n\tPurchased Date: " << allTransactions[i].date;
               }
          }else {
               cout << "\n\t** No purchases made yet! **";
          }
     }


     void purchaseBook(){

          char again='y';    

          string transactionID = "";

          cout << "\n\tEnter Transaction ID: "; 
     
          fflush(stdin);
          getline(cin,transactionID);

          auto it = find_if(allTransactions.begin(), allTransactions.end(), [&transactionID](const PurchasedBooks& obj) {return obj.ID == transactionID;});

          if (it != allTransactions.end()) {
               cout<<"\n\tThis ID is already exists!\n";
          }else {
               do {

               addPurchase(transactionID);

               cout<<"\n\t\t Do you want to make more purchase? (y/n) : "; 
               cin >> again;

               }while(again!='n');
          }
     }
  
     void addPurchase(string transactionID) {
        if (!isEmpty()) {
             
               CategoryNode *curr=head;

               string bookTitle;

               bool duplicate = false;
          
               while(curr!=NULL) {

                    BookNode *sBooks = curr->books;
                    bool bookF = false;

                    cout <<"\n\tEnter Book title to purchase : "; 
                    fflush(stdin);
                    getline(cin,bookTitle);
               

                    while(sBooks != NULL && !bookF) {
                             
                         if(sBooks->title == bookTitle) {

                              bookF = true;

                              time_t now = time(0);
                              char* dt = ctime(&now);

                              // using c++11 features as auto and lambda function, if you have older version, please install correct one. You can find command in main.cpp file. 
                              auto it = find_if(allTransactions.begin(), allTransactions.end(), [&bookTitle](const PurchasedBooks& obj) {return obj.title == bookTitle;});

                              if (it != allTransactions.end()) {
                                   cout << "\n\tAlready Exists\n\t** You can not purchase same twice! ** ";
                              }
                              else {    

                                   PurchasedBooks purchasedbooks;

                                   purchasedbooks.ID = transactionID;
                                   purchasedbooks.title = sBooks->title;
                                   purchasedbooks.author = sBooks->author;
                                   purchasedbooks.year = sBooks->year;
                                   purchasedbooks.price = sBooks->price;
                                   purchasedbooks.date = dt;

                                   allTransactions.push_back(purchasedbooks);

                                   cout<<"\n\t\t\t** Book Successfully Purchased! **" << " ";
                              }
                         }
                         else {
                              sBooks = sBooks->next;
                         }
                    }
                    curr = curr->next;
               }
          }
     }


     void Purchase_Detail(){

          string transactionID;
          vector<string> v;

          cout <<"\n\t\tAll Performed Transactions 📝"<<"\n";

          // only display unique transaction ID 
          for (int i = 0; i < allTransactions.size(); i++){

               if (!(find(v.begin(), v.end(), allTransactions[i].ID) != v.end())){
                    v.push_back(allTransactions[i].ID);
                    cout <<"\n\t"<<i+1<<" Transcation: "<<"\n";
                    cout <<"\n\tID: "<<allTransactions[i].ID;
                    cout <<"\n\tTime Performed: "<<allTransactions[i].date;
                    
               }
          }


          cout << "\n\tEnter Transaction ID to check details: "<<"\n";
          fflush(stdin);
          getline(cin,transactionID);

          for (int i = 0; i < allTransactions.size(); i++){

               if (allTransactions[i].ID == transactionID){

                    cout << "\n\tTransactionID: " << allTransactions[i].ID;
                    cout << "\n\tTitle: " << allTransactions[i].title;
                    cout << "\n\tAuthor: " << allTransactions[i].author;
                    cout << "\n\tYear: " << allTransactions[i].year;
                    cout << "\n\tPrice: $" << allTransactions[i].price;
                    cout << "\n\tPurchased Date: " << allTransactions[i].date;
               }
               
          }
          
     }

     void updateBook(){
          if (!isEmpty()){
               CategoryNode *curr=head;
               string bookTitle = "";
               char input;
               char again='n';

               while (curr != NULL){

                    BookNode *sBooks = curr->books;
                    bool bookF = false;

                    cout << "Enter book name to update: "; 
                    fflush(stdin);
                    getline(cin,bookTitle);

                    while (sBooks != NULL && !bookF){
                         if (sBooks->title == bookTitle){

                              do {
                                   cout << "\n\t\tWhat do you want to modify:  \n";
                              
                                   cout << "\n\t1. Title:  " << sBooks->title;
                                   cout << "\n\t2. Author:  " << sBooks->author;
                                   cout << "\n\t3. Year:  " << sBooks->year;
                                   cout << "\n\t4. Quantity:  " << sBooks->quantity;
                                   cout << "\n\t5. Price:  $" << sBooks->price<<"\n";

                                   cout << "\n\n\tEnter your option: ";
                                   cin >>input;

                                   switch (input)
                                   {
                                   case '1':
                                        cout << "\n\tEnter new title: ";
                                        cin >> sBooks->title; 
                                        break;
                                   case '2':
                                        cout << "\n\tEnter new Auhtor name: ";
                                        cin >> sBooks->author; 
                                        break;

                                   case '3':
                                        cout << "\n\tEnter new Year: ";
                                        cin >> sBooks->year; 
                                        break;

                                   case '4':
                                        cout << "\n\tEnter new Quantity: ";
                                        cin >> sBooks->quantity; 
                                        break;
                                   case '5':
                                        cout << "\n\tEnter new Price: $";
                                        cin >> sBooks->price; 
                                        break;
                                   
                                   default:
                                        cout<<"Invalid Option.\n";
                                        break;
                                   }

                                   cout<<"\n\t\t Do you want to update more? (y/n) : "; 
                                   cin>>again;

                                    if (again == 'n'){
                                        
                                        cout << "\n\t\t ** Modified Book ** \n";
                                        cout << "\n\t1. Title:  " << sBooks->title;
                                        cout << "\n\t2. Author:  " << sBooks->author;
                                        cout << "\n\t3. Year:  " << sBooks->year;
                                        cout << "\n\t4. Quantity:  " << sBooks->quantity;
                                        cout << "\n\t5. Price: $" << sBooks->price<<"\n";
                                   }   
                              }while(again!='n');
                                   break;
                    
                     
                         }else {
                              sBooks = sBooks->next;
                         }
                    } 
                    curr = curr->next;
               }
          }
     }
};