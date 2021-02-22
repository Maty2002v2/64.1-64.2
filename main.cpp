#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class ciagi{
	public:
		fstream plik;
		ofstream plik2;
		vector<int> szesciany;
		
		ciagi();
		~ciagi();
		void wczytajLiczby();
		int w();
		
	private:
};

ciagi::ciagi(){
	if(plik.good()) {
		plik.open("c:\\bledne.txt", ios::in);  
		plik2.open("c:\\od.txt");
	}
	else
		cout<<"Cos poszlo nie tak przy otwieraniu pliku.";
};

ciagi::~ciagi(){
	plik.close();  
	plik2.close();
}

void ciagi::wczytajLiczby()
{
	int r;
	int r2;
	
	while(!plik.eof())  
    {
    	int dlugosc;
    	int liczba;
	    for(int q = 0; q < 21; q++)
	    {
	    	szesciany.clear(); 
	    	
	        plik >> dlugosc;
	        for(int i = 0; i < dlugosc; i++)
	        {
	        	plik >> liczba;
				szesciany.push_back(liczba);
			}
			
			r = szesciany[1] - szesciany[0];
			r2 = szesciany[2] - szesciany[1];
			
			if (r != r2) {
				r = szesciany[3] - szesciany[2];
			}

			for (int i = 0; i < dlugosc; i++) {
				if (szesciany[i+1] - szesciany[i] != r) {
					plik2<<szesciany[i]<<"\n";
					break;
				}
			}
	    }            
    }
}

int main(int argc, char** argv) {
	ciagi b;
	
	b.wczytajLiczby();
	return 0;
}
