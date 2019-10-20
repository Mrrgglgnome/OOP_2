#include <iostream>

using namespace std;

class Element{
public:
	void Init(int w, double p){
		this->weight = w;
		this->price = p;
	}

	void Display(){
		cout << "Weight: " << this->weight << "g" << endl;
		cout << "Price for gram: " << this->price << endl;
	}

	double Price(){
		return this->weight*this->price;
	}
private:
	int weight;
	double price;
};

class Izdelie{
public:
	void Init(char n[20], Element el[3], int am[3]){
		for (int i = 0; i < 3; i++){
			this->elems[i] = el[i];
			this->amount[i] = am[i];
		}
		this->price = 0;
		for (int i = 0; i < 3; i++)
			this->price += this->elems[i].Price()*this->amount[i];
		for (int i = 0; i < 10; i++)
			this->name[i] = n[i];
	}

	void Display(){
		cout << "Name: " << this->name << endl;
		for (int i = 0; i < 3; i++){
			cout << "Amount of elem #" << i + 1 << ": " << this->amount[i] << endl;
		}
		cout << "Price: " << this->price << endl;
	}

	double Price(){
		return this->price;
	}

	Element Max(){
		Element max = elems[0];
		for (int i = 1; i < 3; i++)
			if (this->elems[i].Price() > max.Price())
				max = elems[i];
		return max;
	}
private:
	char name[20];
	Element elems[3];
	int amount[3];
	double price;
};

int main(){
	Element el[3];
	Element elMax;
	Izdelie izd;
	int am[3];
	for (int i = 1; i < 4; i++){
		el[i - 1].Init(i * 50, i * 30);
		am[i - 1] = i;
		el[i - 1].Display();
	}
	izd.Init("Something", el, am);
	izd.Display();
	elMax = izd.Max();
	cout << "Max Element: " << endl;
	elMax.Display();
	return 0;
}