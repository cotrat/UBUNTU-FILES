#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;

class Stack {
    public:
        //Stack() {};
	virtual void push(int a)=0;
	virtual int pop()=0;
    private:
   
};

class v_Stack: public Stack {
	public:
		//v_Stack() {};
		 void push(int a) { m_stack.push_back(a); }
		int pop() 
			{ 
			int retval = m_stack.at(m_stack.size() - 1);
			m_stack.pop_back();
			return retval;
			}
		void p() { int c = 6 + 7; }
		
		
	private:
		vector<int> m_stack;
};

int main()
{
	//Stack * myStack = new v_Stack();
	v_Stack myStack;
	myStack.push(7);

}	
