//program for solution of Tower Hanoi (recursion)

#include <iostream>
using namespace std;

void toh(int ndisk, char source, char temp, char dest);

int main()
 {
	
    char source = 'S', temp = 'T', dest = 'D';
    int ndisk;
    cout << "Enter the number of disks: ";
    cin >> ndisk;
    cout<<endl;
    cout << "Sequence Is:" << endl;
    toh(ndisk, source, temp, dest);
    
    return 0;
}

void toh(int ndisk, char source, char temp, char dest)
 {
    if (ndisk > 0) 
	{
        toh(ndisk - 1, source, dest, temp);
        cout << "Move Disk " << ndisk << " from " << source << " to " << dest << endl;
        toh(ndisk - 1, temp, source, dest);
    }
}