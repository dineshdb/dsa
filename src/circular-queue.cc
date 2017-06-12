#include <iostream>
#define MAX 4
using namespace std;

class CircularQueue {
private:
    int items[MAX] = {0};
    int fr,rear;
    int counter;
public:
    CircularQueue(){
        rear=-1;
        fr=-1;
        counter=0;
    }
    void display(int p){
        for( ; p < MAX; p++)
	        cout<<items[p]<<"\t";
    }
    void enqueue(int n){ 
    	if (counter==MAX) {
            cout<<"\n queue is full";
            return;
        } else {
            rear= (rear + 1) % MAX;
            items[rear] = n;
            counter++;
    	}
    	display(fr+1);
    }
    int dequeue() {
        if( counter==0){
              cout<<"\n queue is empty";
              return 0;
        } else{
	        fr=(fr+1)%MAX;
    	    int data=items[fr];
    	    items[fr]='\0';
    	    counter--;
    	    display(fr);
    	    return data;
        }
    }
};
int main() {
   CircularQueue q;
    char ch;
    do{
		int n;
    	cout<<"Enter your choice: \n 1.Enqueue \n 2.Dequeue\n";
	    cin>>n;
    	switch(n) {
		    case 1:
    		    int data;
    		    cout<<"\n enter the data to be entered::::";
    		    cin>>data;
    		    q.enqueue(data);
    		    break;
    		case 2:
    		    cout<<"\n the dequeued data is:::"<<q.dequeue()<<"\n";
    		    break;
	    }
	    cout<<"\ndo you want to operate more on queue?\n";
	    cin>>ch;
	}while(ch!='n');
}
