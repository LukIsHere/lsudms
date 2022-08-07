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
            ums::user u = ums::user("{\"haj\":\"hi\"}");
            cout << u.gets("haj") << endl;
        }
        if(first=="usrTST"){
            
            ums::user u = ums::user("{\"haj\":\"hi\"}");
            cout << u.getS() << endl;
        }
    }
    
}