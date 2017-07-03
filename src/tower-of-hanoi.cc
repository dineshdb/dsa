#include <iostream>

using namespace std;

void hanoi(int n , char sour,char aux, char dest){
    if(n == 1)
        cout << sour<<" -> "<<dest << endl;
    else {
        hanoi(n-1, sour, dest, aux);
        hanoi(1, sour, aux, dest);
        hanoi(n-1, aux, sour, dest);
    }
}

int main(){
    int n;
    cout << "Enter number of disks:" ;
    cin >> n;
    hanoi(n,'A','C','B');
    return 0;
}
