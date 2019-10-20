#include <iostream>
#include <ctime>

using namespace std;

class kvartira{
public:
	void Init(int d, float n){
		this->dohod = d;
		this->nalog = n;
	}

	void Display(){
		cout << "dohod in total: " << this->dohod << endl;
		cout << "NALOGI: " << this->nalog << endl;
	}

	double Nalogi(){
		return this->dohod * this->nalog;
	}
private:
	int dohod;
	float nalog;
};

class hrushevka{
public:
	void Init(kvartira k[10], float v){
		for (int i = 0; i < 10; i++)
			this->kv[i] = k[i];
		this->vkarman = v;
		this->profit = 0;
	}

	void Display(){
		cout << "% v karman: " << this->vkarman << endl;
		cout << "Profit: " << this->profit << endl;
	}

	double Profit(){
		for (int i = 0; i < 10; i++)
			this->profit += this->kv[i].Nalogi() * this->vkarman;
		return this->profit;
	}
private:
	kvartira kv[10];
	float vkarman;
	double profit;
};

int main(){
	kvartira kv[10];
	hrushevka hrush;
	srand(time(0));
	for (int i = 0; i < 10; i++){
		int dohod = 10000 + rand() % 50000;
		kv[i].Init(dohod, 0.20);
	}
	hrush.Init(kv, 0.4);
	hrush.Profit();
	for (int i = 0; i < 10; i++){
		cout << "Kvartira #" << i + 1 << ": " << endl;
		kv[i].Display();
	}
	hrush.Display();
	return 0;
}