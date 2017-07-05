#include <iostream>

using namespace std;

void hanoi(int n , char source, char target, char aux){
    if(n > 0){
    	// move n - 1 disks from source to auxiliary, so they are out of the way
        hanoi(n-1, source, aux, target);
        
        // move the nth disk from source to target
		cout << source << "->" << target << endl;
		
		// move the n - 1 disks that we left on auxiliary onto target
        hanoi(n-1, aux, target, source);
    }
}

int main(){
    int n;
    cout << "Enter number of disks:" ;
    cin >> n;
    hanoi(n,'A','C','B');
    return 0;
}
