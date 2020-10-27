#include <iostream>
#include <string.h>
using namespace std;

std::string fun(const std::string& str) {
    string maxstr;
    for (int i = 0; i < str.size();i++)
        for (int j = (str.size() - i); j >=1 ; j--)
        {

            string subs = str.substr(i, j);
            //std::cout << subs<< endl;
            int front = str.find(subs);
            int back = str.rfind(subs);
            if (front != back && subs.size() > maxstr.size())
                maxstr = subs;
        }
    return maxstr;
}


int main() {
    string test;
    getline(cin, test);
    //cout << "OUTPUT: "+fun(test) << endl;
    cout << fun(test) << endl;
    return 0;
}
