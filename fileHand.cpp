#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    fstream myfile;
    myfile.open("WriteModeFile.txt", ios::app);
    if(myfile.is_open()){
        char ch;
        string input;
        do{
            cout<<"\nEnter the Data in your file: ";
            getline(cin, input);
            myfile<<input<<endl;
            cout<<"\nDo you want to exit (y/n)? ";
            cin>>ch;
            cin.ignore();    
        } 
		while(ch != 'y' && ch != 'Y');
        myfile.close();
    } 
	else{
        cout<<"\nUnable to open file!";
        return 1;
    }
    return 0;
}
