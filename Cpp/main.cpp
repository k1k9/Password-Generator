#include <iostream>
#include <stdlib.h>     // cls
#include <stdlib.h>     // srand, rand
#include <time.h>       // timie
#include <fstream>      // fstream
#include <cstdlib>      // exit
#define ARRSIZE(array) (sizeof((array))/sizeof((array[0]))) // Get array length

using namespace std;

int main()
{
    char charTab[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0','q',
    'w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',
    'z','x','c','v','b','n','m','!','@','#','$','%','^','&','*','(',')','-',
    '_','=','+','`','~','[',']',';'};
    int power=0; // How many characters in password

    cout<<"\n\tSelect Power of ur password\n"
    <<"\t1. Low (64 characters)"
    <<"\n\t2. Medium (128 characters)"
    <<"\n\t3. Hihg (512 characters)"
    <<"\n\t4. Strong (1024 characters)"
    <<"\n\t5. Ultra (2048 characters)\n"
    <<"\n\nchoose: ";
    int menuOption; cin>>menuOption;

    // Check value from menu
    if(menuOption==1)
        power = 64;
    else if(menuOption==2)
        power = 128;
    else if(menuOption==3)
        power = 512;
    else if(menuOption==4)
        power = 1024;
    else if(menuOption==5)
        power = 2048;
    else
        cout<<"Insert number from menu (1-5)"<<endl<<endl;

    // Create password
    while(power)
    {
        string password; // This variable is be useful later to write generated password
        srand (time(NULL)); //initialize random seed
        int charTabSize = ARRSIZE(charTab); // Get size of charTa

        for(int i=0; i<power; i++)
        {
            int secretNum = rand() % charTabSize + 1; // Get random char form charTab
            char newChar = charTab[secretNum];

            password += newChar; // and add this to password
        }
        system("cls");
        cout<<"Your password: "<<endl<<endl<<password;

        // Optioanl option: save this password to file
        cout<<endl<<endl<<"Do u want to save this password to file? (y/n): ";
        string canSave; cin>>canSave;

        if(canSave=="y")
        {
            fstream passFile;
            passFile.open("password.txt", ios::out | ios::app); // Create file and if file exist add to him password (does not overwrite)

            cout<<endl<<"Remember ur password will be save in program location"<<endl;
            cout<<endl<<"If you want u can add note for ur password or leave it blank (example: pass to my mail): ";
            string passNote="";

            cin.ignore(); // Clear stream
            getline(cin,passNote); // and get note for pass and save it

            if (passNote == "")
                passNote="mypass";

            passFile<<passNote<<": "<<password<<endl<<endl<<endl; // Write password to file (it will be save in program location)
            passFile.close();

            cout<<endl<<"Your password has been saved with an attached note: "<<passNote;
        }

        break;
    }

    cout<<endl<<endl<<"Press any key to end program...";
    cin.get();

    return 0;
}
