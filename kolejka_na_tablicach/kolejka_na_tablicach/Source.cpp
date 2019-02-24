#include <iostream>
#include <ctime>

using namespace std;

const int MAXINT = -2147483647;

// Definicja typu obiektowego queue
//---------------------------------
class queue
{
private:
	int n;      // rozmiar tablicy
	int poczatek;   // wskaŸnik pocz¹tku kolejki
	int koniec;   // licznik elementów
	int * Q;    // tablica dynamiczna

public:
	queue(int x); // konstruktor
	~queue();     // destruktor
	bool empty(void);
	int  front(void);
	void push(int v);
	void pop(void);
};

//---------------------
// Metody obiektu queue
//---------------------

// Konstruktor - tworzy tablicê dla kolejki
//-----------------------------------------
queue::queue(int x)
{
	n = x;
	Q = new int[x];
	poczatek = koniec = 0;
}

// Destruktor - zwalnia tablicê dynamiczn¹
//----------------------------------------
queue::~queue()
{
	delete[] Q;
}

// Sprawdza, czy kolejka jest pusta
//---------------------------------
bool queue::empty(void)
{
	return !koniec;
}

// Zwraca pocz¹tek kolejki.
// Wartoœæ specjalna to -MAXINT
//-----------------------------
int queue::front(void)
{
	if (koniec) return Q[poczatek];
	return -MAXINT;
}

// Zapisuje do kolejki
//--------------------
void queue::push(int v)
{
	int i;
	if (koniec < n)
	{
		i = poczatek + koniec++;
		if (i >= n) i -= n;
		Q[i] = v;
	}
}

// Usuwa z kolejki
//----------------
void queue::pop(void)
{
	if (koniec)
	{
		koniec--;
		poczatek++;
		if (poczatek == n) poczatek = 0;
	}
}

//---------------
// Program g³ówny
//---------------

int main()
{
	clock_t start, finish;
	double duration;
	start = clock();

	int pom;

	pom = 500000;

	queue Q(pom); // tworzymy kolejkê na 10 elementów
	int i;

	for (i = 1; i <= pom; i++) Q.push(i*10);
	while (!Q.empty())
	{
		cout << Q.front() << endl;
		Q.pop();
	}

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\nCzas wykonywania programu %2.5f seconds\n", duration);

	system("pause");
}