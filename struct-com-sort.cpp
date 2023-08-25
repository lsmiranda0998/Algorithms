#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct tpPessoa{
	string nome; 
	int idade; 
	double dinheiro;
};

bool cmp (tpPessoa a, tpPessoa b){
	if (a.nome == b.nome){ //houve empate no nome, então precede o que tem menor idade
		if (a.idade == b.idade) //houve empate na idade, então precede o que tem mais dinheiro
			return a.dinheiro > b.dinheiro; //precede maior dinheiro
		return a.idade < b.idade; //precede menor idade
	}
	return a.nome < b.nome; //precede menor nome
}

int main (void){
	vector<tpPessoa> vec;
	tpPessoa p;
	
	for (int i = 0; i < 5; i++){
		cout << " -> Digite o nome\n ";
		getline(cin, p.nome); //equivalente ao gets, mas em c++ (aceita espaços no nome)
		cout << " -> Digite a idade e dinheiro da pessoa: \n";
		cin >> p.idade >> p.dinheiro; getchar(); //limpar o buffer igual no scanf, já que vai ser lido uma string depois
		vec.push_back(p);
	}
	
	cout << "\n ==> Exibindo a entrada... \n";
	for (int i = 0; i < 5; i++)
		cout << vec[i].nome << ": idade = " << vec[i].idade << " dinheiro = " << vec[i].dinheiro << "\n";
	cout << "\n ==> Exibindo de maneira ordenada, pelo nome e, em casos de empate, pela idade e, em casos de empate, pelo dinheiro\n";
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < 5; i++)
		cout << vec[i].nome << ": idade = " << vec[i].idade << " dinheiro = " << vec[i].dinheiro << "\n";
	
}
