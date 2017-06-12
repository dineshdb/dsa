#include <stdlib.h>
#include <iostream>
#define MAX 5
using namespace std;

class Queue {
private:
    int items[MAX] = {0};
    int fr,rear;

public:
    Queue(){
        fr=0;
        rear=-1;
    }
    void display(){
        for(int p=0;p<MAX;p++)
        cout<<items[p]<<"\t";
    }
    void enqueue(int n){
        if(rear==MAX-1){
            cout<<"queue is full \n";
            return;
        } else {
            rear+=1;
            items[rear]=n;
        }
        display();
    }
    int dequeue(){
        if(fr>rear){
               cout<<"queue is empty";
            return 0;
        } else{
		    int data;
		    data=items[fr];
		    items[fr]=0;
		    fr+=1;
		    display();
		    return data;
	    }
    }
};
int main(){
   Queue q;
    char ch;
    do{
            int n;
    cout<<"Enter ur choice: \n 1.Enqueue \n 2.Dequeue\n";
    cin>>n;
    switch(n)
    {
    case 1:
        int data;
        cout<<"\n Enter the data to be entered::::";
        cin>>data;
        q.enqueue(data);
        break;
    case 2:
        cout<<"\n The dequeued data is:::"<<q.dequeue();
        break;
    default:
        break;
    }
    cout<<"\n Do u want to operate more on queue?\n";
    cin>>ch;
}while(ch!='n');
}

