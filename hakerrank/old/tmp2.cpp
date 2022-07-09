#include <iostream>
#include <algorithm>
#include <vector>

int main (int argc, char** argv){
	//int v[5] = {2,4,6,8,10};
	std::vector<int> v = {2,4,6,8,10};
	v.insert(
		std::upper_bound(
			v.begin(),
			v.end(), 4)
		,100);

	for(int i = 0; i < v.size() ; i++){
		std::cout << v.at(i) << " " ;
	}
	std:: cout << std::endl;
	return 0;
}