#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int activityNotifications(vector<int> expenditure, int d) {
    vector<int> v;
    
    int included = 0;
    int ret = 0;
    for(int i = 0; i < expenditure.size() ; i++){
        /*for(int j = 0; j < v.size(); j++){
            cout << v.at(j) <<", ";
        }
        cout << endl;*/
        if(included < d){
           //cout << "skip" << expenditure.at(i) << endl;
            //v.push_back(expenditure.at(i));
            v.insert(std::lower_bound(v.begin(), v.end(), expenditure.at(i)),expenditure.at(i));
            included++;
        } else {
            //sort(v.begin(),v.end());
            double mean; //= (double)tot/d;
            if(v.size() % 2 == 0){
                mean = (v.at(d/2 -1 ) + v.at((d/2) )) /2.0;
                //std::cout << "mean " << mean << std::endl;
            } else {
                mean = v.at(d/2);
            }
               // cout << "mean: " << mean << " %2 ? " << v.size() %2 == 0<< endl;
            
            //cout << "mean " << mean<< endl;
            if(expenditure.at(i) >= 2*mean){
               ret++; 
            }
            //v.push_back(expenditure.at(i));
            //cout << " inserting  " << expenditure.at(i)<< endl;
            v.insert(std::lower_bound(v.begin(), v.end(), expenditure.at(i)),expenditure.at(i));
            //tot += expenditure.at(i);
            //tot -= expenditure.at(i-d);
            //v.erase(v.begin());
            if(i-d>=0){
                // expanditure  
                //cout << "expenditure" << endl;
                //for(int j = 0; j < expenditure.size(); j++){
                //    cout << expenditure.at(j) <<", ";
                //}
                //cout << endl;
                // v  
                //cout << "v" << endl;
                //for(int j = 0; j < v.size(); j++){
                //    cout << v.at(j) <<", ";
                //}
                //cout << endl;
                v.erase(std::lower_bound(v.begin(), v.end(), expenditure.at(i-d)));
                //cout << " erasing " << expenditure.at(i-d+1)<<","<< i-d << endl;
            }
        }
    }
    return ret;
}

int main(int argc, char** argv)
{
    ofstream fout(getenv("OUTPUT_PATH"));
    cout << getenv("OUTPUT_PATH") << endl;
    for(int i = 0; i < argc; i++){

        cout <<  argv[i] << endl;
    }
    string first_multiple_input_temp;
    std::ifstream in(argv[2]);
    //std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);
    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
