class BookNode {
  public:
  	string id; 
    string title;
	string author;
	string year;
	int quantity;
	int price;
    BookNode *next;
	
  	BookNode(string _id, string _title, string _author, string _year, int _quantity, int _price) {
		id = _id;
	    title = _title;
		author = _author;
		year = _year;
		quantity = _quantity;
		price = _price;
	    next = NULL;
    }

  	void setNext(BookNode *nn) {
  		next = nn;
  	}

  	BookNode* getNext() {
  		return next;
  	}
    
  	string getTitle() {
      return title;
  	}
};
