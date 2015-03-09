// dynamic allocation and polymorphism
#include <iostream>
#include <string>

using namespace std;

class Book {
	//protected:
    
	protected:
		int callNo;
		string title;
		string author;
  	public:
    		Book(string name_c, string author_c, int callNo_c)
		{
			callNo = callNo_c;
			title = name_c;
			author = author_c;
		}
		virtual void print() 
		{
			cout << "BOOK DETAILS : " << endl;
			cout << "Title : " << title << " Author : " << author << endl;
			cout << "Call No : " << callNo;	
		}
		bool equals(Book* b1)
		{
			if( (b1->author == author) and (b1->title == title) )
			{
				return 1;
			}
			return 0;
		}
		void fart()
		{
			cout << "PFFFFT";
		}
};

class Journal: public Book {
  	public:
		Journal(string name_c, string author_c, int callNo_c, int vol_c) : Book(name_c,author_c,callNo_c) 
		{
			volume = vol_c;
		}
		void print()
		{
			print();
			cout << "JOURNAL DETAILS : " << endl;
			cout << "Title : " << title << " Author : " << author << endl;
			cout << "Call No : " << callNo;	
			cout << "Vol No : " << volume;
			
		}
		void p()
		{
			cout << "JPIRNAL";
		}
	
	private:
		int volume;
    
};



int main(){
	/*Book* b1 = new Book("Norton’s Star Atlas", "Norton", 510);
	Book* b2 = new Book("Pocket Sky Atlas", "Sinot", 511);
	cout << "Are books equal? " << b1->equals(b2) << "\n" ;
	b1->print();*/


	/*Book* B = new Journal("MyJournal", "John Smith", 123, 456);
	B->print();*/
	

	Journal myJourn("MyJournal", "John Smith", 123, 456);
	myJourn.Book::print();
	myJourn.p();


}
