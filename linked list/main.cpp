#include "ll.h"

int main() {
	ll obj;
	int ch, ele, pos, ret;
	do {
		cout<<"1. Insert At Beg\n2. Insert At End\n3. Insert At Pos"<<endl;
		cout<<"4. Delete From Beg\n5. Delete From End\n6. Delete From Pos"<<endl;
		cout<<"7. Display\n8. Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch) {
			case 1:
				cout<<"Enter Element:"<<endl;
				cin>>ele;
				if(obj.insertAtBeg(ele))
					cout<<ele<<" added at beginning"<<endl;
				break;
			case 2:
				cout<<"Enter Element:"<<endl;
				cin>>ele;
				if(obj.insertAtEnd(ele))
					cout<<ele<<" added at end"<<endl;
				break;
			case 3:
				cout<<"Enter Element:"<<endl;
				cin>>ele;
				cout<<"Enter Position:"<<endl;
				cin>>pos;
				if(obj.insertAtPos(ele, pos))
					cout<<ele<<" Added at position "<<pos<<endl;
				break;
			case 4:
				ret = obj.deleteAtBeg();
				cout<<ret<<" deleted"<<endl;
				break;
			case 5:
				ret = obj.deleteAtEnd();
				cout<<ret<<" deleted"<<endl;
				break;
			case 6:
				cout<<"Enter Position:"<<endl;
				cin>>pos;
				ret = obj.deleteAtPos(pos);
				cout<<ret<<" deleted from position "<<pos<<endl;
				break;
			case 7:
				obj.display();
				break;
			case 8:
				exit(0);
			default:
				cout<<"Invalid choice!"<<endl;
		}
	}while(ch!=8);
	return 0;
}
