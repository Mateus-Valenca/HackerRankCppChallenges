#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        cout << hex << left << showbase << nouppercase; // formatting
        cout << (long long) A << endl;
        int width = 15;
        
        cout<<right
            <<setfill('_')
            <<setw(width)
            <<showpos
            <<fixed
            <<setprecision(2);
        cout<<B<<endl;
        
        cout << scientific << uppercase << noshowpos << setprecision(9);
        cout<<C<<endl;
	}
	return 0;

}
