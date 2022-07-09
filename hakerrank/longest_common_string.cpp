#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

struct Entity{
	int length;
	string match;
	int last_i_a;
	int last_i_b;
};

Entity longestCommonChild(string s1, string s2){


	int ret = 0;
	map<string, Entity> m{};
	//if 0, return
	if(s1.length() == 0 || s2.length() == 0){
		return {0, "", 0};
	}

	//if match return

	cout << "f(" << s1 << ", " << s2 << "); "<< endl ;
	//Entity e3 = longestCommonChild(s1.substr(1), s2.substr(1));
	int diff1[3] = {1,0};
	int diff2[3] = {0,1};
	int max_diff_i = 0;
	Entity e_ret{-1,"",0,0};
	for(int i = 0; i < 3; i++){

		string new_s1 = s1.substr(diff1[i]);
		string new_s2 = s2.substr(diff2[i]);
		Entity e1;
		if(m.find(new_s1) != m.end() &&
			m.find(new_s2) != m.end()
		){
		Entity found1 = m.find(new_s1)->second;
		Entity found2 = m.find(new_s2)->second;
			if(found1.length > found2.length){
				e1 = found1;
			} else{
				e1 = found2;
			}
			m[new_s1] = e1;
			m[new_s2] = e1;
		} else{
			e1 = longestCommonChild(new_s1, new_s2);
			m[new_s1] = e1;
			m[new_s2] = e1;
		}
		if(e1.length > e_ret.length){
			e_ret = e1;
			max_diff_i = i;
		}
	}

	Entity e_new = {0,""};
	if(s1[diff1[max_diff_i]]+e_ret.match == s2[diff2[max_diff_i]]+e_ret.match &&
	 s1.length()-diff1[max_diff_i] >= e_ret.last_i_a &&
	 s2.length()-diff2[max_diff_i] >= e_ret.last_i_b
	 )
	{
		e_ret = {e_ret.length+1, s1[diff1[max_diff_i]]+e_ret.match, (int)s1.length(), (int)s2.length()};
	}
		cout << "f(" << s1 << ", " << s2 << "); " ;
		cout << "returning " << e_ret.match << endl;
	return e_ret;
}

int commonChild(string s1, string s2) {

	    //max common child = max(max common child -)
	    Entity e = longestCommonChild(s1,s2);
	    cout << "returning " << e.match << endl;
	    return e.length;
}




int main(int argc, char* argv[])
{
    ofstream fout(getenv("OUTPUT_PATH"));

    ifstream fin(argv[2]);

    cin.rdbuf(fin.rdbuf());
    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
