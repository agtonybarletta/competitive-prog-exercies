#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    vector<char> compact;
    vector<int> multiciplicity;

    int occ = 1;
    for(int i=0; i < s.length(); i++){
	    while(s[i] == s[i+1]){
		occ++;
		i++;
		continue;
	    } 
	    compact.push_back(s[i]);
	    multiciplicity.push_back(occ);
	    occ = 1;
    }
    long ret = 0;
    /*for(int m: multiciplicity)cout << ", "<< m ;
    cout << endl;
    for(char m: compact)cout << ", "<< m ;
    cout << endl;
    */
    for(int i = 0 ; i < compact.size(); i++){
	    //count for sub string |l| = 1
	    long fact = multiciplicity[i]*(multiciplicity[i]+1)/2;
	    //cout << "fact("<< multiciplicity[i] << "): "<< fact << endl;
	    ret+=fact;
	    //count for sub string |l| >=2
	    if(i > 1 && compact[i] == compact[i-2] &&  multiciplicity[i] > multiciplicity[i-2] && multiciplicity[i-1] == 1 ){
		   ret += multiciplicity[i-2];
	    }
	    if(i > 1 && compact[i] == compact[i-2] && multiciplicity[i] <= multiciplicity[i-2] && multiciplicity[i-1] == 1){
		   ret += multiciplicity[i];
	    }
    }
    return ret;


}

int main(int argc, char* argv[])
{
    ofstream fout(getenv("OUTPUT_PATH"));
    ifstream fin(argv[2]);
    int n;
    cin.rdbuf(fin.rdbuf());
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
