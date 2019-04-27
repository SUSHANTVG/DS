#include"queue.h"

using namespace std;

int main(){
	queue obj;
	int ch, ele, ret;
	do	
	{
		cout<<"1. Add\n2. Delete\n3. Peek\n4. Display\n5. Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch) {
			case 1: 
				cout<<"Enter the element"<<endl;
				cin>>ele;
				if(obj.add(ele))
					cout<<ele<<" Successfully added"<<endl;
				break;
			case 2:
				if(ret = obj.del())
					cout<<ret<<" Deleted"<<endl;
				break;
			case 3:
				obj.peek();
				break;
			case 4:
				obj.display();
				break;
			case 5:  
				exit(0);
			default:
				cout<<"Invalid choice!";
		}
	}while(ch!=5);
	return 0;
}
