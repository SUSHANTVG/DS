#include "stack.h"

int main() {
	int ch, ret, ele;
	stack obj;		
	do {
		cout<<"1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch) {
			case 1:
				cout<<"Enter element:"<<endl;
				cin>>ele;
				if(obj.push(ele))
					cout<<ele<<" pushed successfully"<<endl;
				break;
			case 2:
				if(ret = obj.pop())
					cout<<ret<<" popped"<<endl;
				break;
			case 3:
				if(ret = obj.peek())
					cout<<ret<<" is at top"<<endl;
				break;
			case 4:
				obj.display();
				break;
			case 5:
				exit(0);
			default:
				cout<<"Invalid choice!"<<endl;
		}
	}while(ch!=5);
	return 0;
}
