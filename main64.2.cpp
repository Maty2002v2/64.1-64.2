#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class file {
	protected:
		ifstream input;
 		ofstream output;
 		
 		vector<string> s1;
 		string s;
 		int howMuch = 0;
		
		file();
		~file();
		
		void pobierz();
};

file::file() {
	input.open("c:\\dane_obrazki.txt");
 	output.open("wyjscie.txt");
}

file::~file() {
	input.close();
 	output.close();
}

void file::pobierz() {
	input>>s;
}

class zadanie64_2 :public file{
	public:
		void symmetry();
};

void zadanie64_2::symmetry(){
	bool isRewersY = true;
	bool isRewersX = true;
	
	
	while(!input.eof()){		
		this->pobierz();	//pobranie kolejnego
		
		if (s.length() == 21) {		//sprawdznie czy nie jest ostatnim wierszem
			s1.push_back(s);
			
			for( int i = 0; i < 10; i++ ) {		//sprawdzenie symertii kazdej linii 
				if (s[i] != s[i+10]) {
					isRewersX = false;
					break;
				}	
			}
		} 
		else {
			for( int i = 0; i < 10; i++ ) {		//sprawdzenie symetrii gora dol
				if (s1[i] != s1[i+10]) {
					isRewersY = false;
					break;
				}
			}
			
			if (isRewersY && isRewersX) {	//podsumowanie 
				howMuch++;
				for( int i = 0; i < s1.size()-1; i++ ) {
					cout<<s1[i]<<endl;
				}
				cout<<endl;
			}
			
			isRewersY = true;	//restart
			isRewersX = true;
			s1.clear();
		}
	}
	
	cout<<"Wszystkich: "<<howMuch; 
}

int main(int argc, char** argv) {
	zadanie64_2 l;
	l.symmetry();
		
	return 0;
}
