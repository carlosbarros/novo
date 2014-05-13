#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <locale.h>
#include <vector>

using namespace std;
typedef vector <double > vetor;
void selecaoAtividadesRecursivo(vetor s, vetor f, int, int, int*);

void ler(vetor &s, vetor &f)
{
	double numero;
	int qtdInstancias;
	ifstream in("entrada.in");
	if (!in)cout << "O arquivo não pode ser aberto!";
	in >> qtdInstancias;
	cout << "Instancias =" << qtdInstancias;
	int cont=0;
	while (!in.eof())
	{
		if (cont < qtdInstancias){
			in >> numero;
			s.push_back(numero);		
		}
		if (cont > qtdInstancias){
			in >> numero;
			f.push_back(numero);
		}
		cont++;		
	}
	in.close();
}
void salvar(vetor &v)  // funcao para salvar o arquivo txt  em um outro mas ordenado
{
	ofstream saida;
	saida.open("atividades.out", fstream::out);
	for (int i = 0; i< v.size(); i++)
	{
		saida << v[i] << endl;
	}
	saida.close();
}
int main(int argc, char** argv)
{
	vetor s,f;
	ler(s,f);	
	setlocale(LC_ALL, "Portuguese");
	cout << endl;
	for each(double i in s) {
		cout << " " << i;
	}
	cout << endl;
	for each(double j in f) {
		cout << " " << j;
	}
	system("color 2");	
	int a1[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int len = s.size();
	selecaoAtividadesRecursivo(s, f, 0, len, a1);
	printf("\n Solução : ");
	for (int i = 0; i<len; i++){
		if (a1[i] == 1)
			printf("%d ", i + 1);
	}
	cout << endl;
	system("pause");
}
void selecaoAtividadesRecursivo(vetor s, vetor f, int i, int j, int a[])
{
	int m = i + 1;
	while (m < j && s.at(m) < f.at(i)){
		m = m + 1;
	}
	if (m < j){
		a[m] = 1;
		selecaoAtividadesRecursivo(s, f, m, j, a);
	}
}