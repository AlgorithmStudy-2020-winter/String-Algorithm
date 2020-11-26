#include <iostream>
#include <string.h>
using namespace std;
string S, P;
int main_16916(int argc, const char* argv[]) {
    char P[1000001], S[1000001];
    cin >> S >> P;

    char* ptr = strstr(S, P);

    if (ptr == NULL) {
        cout << 0;
    }
    else {
        cout << 1;
    }
    return 0;
}