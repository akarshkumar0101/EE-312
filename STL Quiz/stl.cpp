#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define N 10

using namespace std;

void quiz(){
	
	//Write your implementation here
    
    vector<char> list(N);
    
    
    vector<char>::iterator it;
    for(it=list.begin();it!=list.end();it++){
        cin>>*it;
    }
    sort(list.begin(), list.end());
    cout<<endl;
    cout<<endl;
    cout<<endl;
    for(it=list.begin();it!=list.end();it++){
        cout<<*it<<endl;
    }
};

int main() {
    quiz();
    return 0;
}

