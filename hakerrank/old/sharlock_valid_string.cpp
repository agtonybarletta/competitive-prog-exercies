#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
	vector<int> occ('z'-'a',0);
	bool isValid = false;	
	for(char c : s){
		occ[c - 'a']++;
	}
	int ndiff = 0;
	int presents = 0;
	map<int,int> occMap{};
	// occ number of occurencies for each letter
	// occMap number of letters for each occurrency value
	// eg occ = {0,1,2}
	// occMap = {1:1,2:1}
	for(int i = 0;  i< occ.size(); i++){
		//std::cout << occ[i] << ", ";
		if(occ[i] != 0){
			presents++;
			if(occMap.count(occ[i]) == 0){
				occMap[occ[i]] = 1;
			} else {
				occMap[occ[i]]++;
			}
		}
	}
	/*
	std::cout << endl;
	for(pair<int,int> p: occMap){
		std::cout << p.first <<  ": " << p.second << endl;
	}*/
	if(occMap.size() == 1){
		isValid = true;	
	} 
	if(occMap.size() == 2){
		std::map<int,int>::iterator k = std::find_if(occMap.begin(),
							occMap.end(),
						[](const pair<int,int>&  a) {return a.second == 1;});
		if(k !=  occMap.end()){
			if(occMap[k->first - 1] != 0){
				isValid = true;
			}
			if(k->first == 1){
				isValid = true;
			}
		} else {
			isValid = false;
		}
	} 
	return isValid ? "YES": "NO";
}


int main(int argc, char* argv[])
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string s;
    ifstream fin(argv[2]);
    cin.rdbuf(fin.rdbuf());
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
