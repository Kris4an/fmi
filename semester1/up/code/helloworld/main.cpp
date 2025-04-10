#include<iostream>
#include<math.h>
#include <compare>

using namespace std;

enum season  {
        spring,
        summer,
        autum,
        winter
    };

int main() {
    season s = winter;
    cout << "A string that continues \
    on the next line\n";
    cout<<s;
    //for(int i = 1, j = 1; i < 10 && j < 15; i++) cout<<"nigidi ";
    return 0;
}