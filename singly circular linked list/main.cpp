#include "scll.h"

int main() {
	scll obj;
	int ch, ele, pos, ret;
	int c;
	do {
		cout<<"1. Insert At Beg\n2. Insert At End\n3. Insert At Pos"<<endl;
		cout<<"4. Delete From Beg\n5. Delete From End\n6. Delete From Pos"<<endl;
		cout<<"7. Display\n8. Count nodes\n9. Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch) {
			case 1:
				cout<<"Enter Element:"<<endl;
				cin>>ele;
				if(obj.addAtBeg(ele))
					cout<<ele<<" added at beginning"<<endl;
				break;
			case 2:
				cout<<"Enter Element:"<<endl;
				cin>>ele;
				if(obj.addAtEnd(ele))
					cout<<ele<<" added at end"<<endl;
				break;
			case 3:
				cout<<"Enter Element:"<<endl;
				cin>>ele;
				cout<<"Enter Position:"<<endl;
				cin>>pos;
				if(obj.addAtPos(ele, pos))
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
				c = obj.nodeCount();
				cout<<c<<" nodes in the list"<<endl;
				break;
			case 9:
				exit(0);
			default:
				cout<<"Invalid choice!"<<endl;
		}
	}while(ch!=9);
	return 0;
}
