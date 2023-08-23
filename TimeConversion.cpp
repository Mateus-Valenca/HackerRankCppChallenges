#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string mHour;
    int hour=0;
    hour = std::stoi(s.substr(0,2));
    if(s.find("AM") != string::npos){
        if(hour+12 == 24){
            mHour = "00";
        }
        else if (hour<10){
            mHour = "0" + std::to_string(hour); 
        }else{
            mHour = std::to_string(hour); 
        }

    }else{
        if(hour <12){
            hour+=12;
            
        }
        mHour = std::to_string(hour);
    }

    mHour += s.substr(2,s.length()-4);
    return mHour;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
