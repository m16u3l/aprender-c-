#include <iostream>
#include <string>

using namespace std;

int *pre_kmp(string pattern){
	int size = pattern.size();
	int *pie=new int [size];
	pie[0] = 0;
	int k=0;
	for(int i=1;i<size;i++){
		while(k>0 && pattern[k] != pattern[i] ){
			k=pie[k-1];
		}
		if( pattern[k] == pattern[i] ){
			k=k+1;
		}
		pie[i]=k;
	}
	return pie;
}

size_t kmp(string text,string pattern) {
	size_t res = 0;
	int* pie=pre_kmp(pattern);
	int matched_pos=0;
	for(int current=0; current< text.length(); current++){
		while (matched_pos > 0 && pattern[matched_pos] != text[current] )
			matched_pos = pie[matched_pos-1];
			
		if(pattern[matched_pos] == text[current])
			matched_pos = matched_pos+1;
			
		if( matched_pos == (pattern.length()) ){
			//cout<<"Pattern occurs with shift "<< current - (pattern.length() -1 )<<'\n';
			matched_pos = pie[matched_pos-1];
			res++;
			cout<<matched_pos<<'\n';
		}
	}
	return res;
}

int main() {
	string text,pattern;
	cout<<"enter text:";
	cin>>text;
	cout<<"enter pattern:";
	cin>>pattern;
	
	kmp(text,pattern);
	
	return 0;
}