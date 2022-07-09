//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
long long merge(vector<int> &working, int a, int middle, int b, vector<int> &arr);
long long mergeSort2(vector<int> &arr, int a, int b, vector<int> &working);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
long long countInversions(vector<int> arr) {
	
	long long ret = 0;
	vector<int> working(arr);
	ret = mergeSort2(arr,0,arr.size(),working );
    /*
	std::cout << "array sorted: " << std::endl;
	for(int i : arr){
		std::cout << i << ", " ;
	}
    cout << std::endl;
    cout << ret << endl;
    */
	return ret;
}

long long mergeSort2(vector<int> &arr, int a, int b, vector<int>& working){
	long long ret  = 0;
	if(b-a <= 1){
		return 0;	
	} else{
		int middle = (a+b)/2;
		ret += mergeSort2(arr,a,middle,working);
        if(ret < 0){
            cout << "ret < 0 at " << a << ", " << b << endl;
        }
		ret += mergeSort2(arr,middle,b,working);
        if(ret < 0){
            cout << "ret < 0 at " << a << ", " << b << endl;
        }

		ret+=merge(working, a, middle, b, arr);
        if(ret < 0){
            cout << "ret < 0 at " << a << ", " << b << endl;
        }
	}
	return ret;
}
long long merge(vector<int> &working, int a, int middle, int b, vector<int> &arr){
	
	long long ret = 0;
	int counter = a;
	int i = a;
	int j = middle;
    int picked_left = 0;
    int picked_right = 0;
	for(; counter < b; counter ++ ){
		if(i < middle && j < b){
			if( working[i] <= working[j]){
				arr[counter] = working[i];
                picked_left++;
				i++;
			} else {
				arr[counter] = working[j];
				ret += middle-i;
                picked_right++;
				j++;
			}

		} else if(i < middle && j >= b){
				arr[counter] = working[i];
                picked_left++;
				i++;

		} else if(i >= middle && j < b){
				arr[counter] = working[j];
                picked_right++;
				j++;
		}
	}
	//working = arr;
	std::copy(arr.begin()+a, arr.begin()+b,working.begin()+a);
	return ret;
}



int main(int argc, char** argv)
{
     ofstream fout(getenv("OUTPUT_PATH"));
    ifstream fin(argv[2]);
    std::cin.rdbuf(fin.rdbuf());
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long long result = countInversions(arr);

        fout << result << "\n";
    }

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
