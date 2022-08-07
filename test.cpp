#include <iostream>
#include "lsudms.hpp"

using namespace std;

int main(){
    ums::connect();
    while (true)
    {
        string in;
        cin >> in;
        ums::cmd cmd = ums::cmd(in);
        string first =cmd.get(0);
        if(first=="start"){
            cout << ums::stoi64("9038223974") << endl;
        }
    }
    
}