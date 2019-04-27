#include "dll.h"

int main() {
	dll obj;
	int ch, ele, pos, ret;
	int count;
	do{
		cout<<"\n1: Insert at Beg\n2: Insert before Pos\n3: Insert after Pos\n4: Insert at End"<<endl;
		cout<<"5: Delete from Beg\n6: Delete before Pos\n7: Delete after Pos\n8: Delete from End"<<endl;
		cout<<"9: Count nodes\n10: Display\n11: Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		cin>>ch;
		switch(ch) {
			case 1:
				cout<<"Enter Element:"<<endl;
				cin>>ele;
				if(obj.addAtBeg(ele))
					cout<<ele<<" added at beginning."<<endl;
				break;
			case 2:
				cout<<"Enter Element:"<<endl;
				cin>>ele;
				cout<<"Enter Position:"<<endl;
				cin>>pos;
				if(obj.addBeforePos(ele, pos))
					cout<<ele<<" added before position "<<pos<<"."<<endl;
				break;
			case 3:
				cout<<"Enter Element:"<<endl;
				cin>>ele;
				cout<<"Enter Position:"<<endl;
				cin>>pos;
				if(obj.addAfterPos(ele, pos))
					cout<<ele<<" added after position "<<pos<<"."<<endl;
				break;
			case 4:
				cout<<"Enter Element:"<<endl;
				cin>>ele;
				if(obj.addAtEnd(ele))
					cout<<ele<<" added at end."<<endl;
				break;
			case 5:
				if(ret = obj.deleteAtBeg())
					cout<<ret<<" deleted."<<endl;
				break;
			case 6:
				cout<<"Enter Position:"<<endl;
				cin>>pos;
				if(ret = obj.deleteBeforePos(pos))
					cout<<ret<<" deleted before position "<<pos<<"."<<endl;
				break;
			case 7:
				cout<<"Enter Position:"<<endl;
				cin>>pos;
				if(ret = obj.deleteAfterPos(pos))
					cout<<ret<<" deleted after position "<<pos<<"."<<endl;
				break;
			case 8:
				if(ret = obj.deleteAtEnd())
					cout<<ret<<" deleted."<<endl;
				break;
			case 9:
				count = obj.nodeCount();
				cout<<count<<" nodes in the list."<<endl;
				break;
			case 10:
				obj.display();
				break;
			case 11:
				exit(0);
			default:
				cout<<"Invalid choice!"<<endl;
		}
	}while(ch!=11);
	return 0;
}
