#include<list>
#include<ctime>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#include "node.hpp"
#include "linkedlist.hpp"


void imprimir( list<int>&Lista){
    for (list<int>::iterator it=Lista.begin(); it != Lista.end(); ++it)
        cout << ' ' << *it;
    cout<<"\n";
}

void imprimir1(linkedlist<int>&Lista){
    linkedlist<int>::Iterator it;
    for(it=Lista.getHead(); it!=Lista.getfin();it.operator++())
         cout<<' ' <<(it.getvalor());
    cout<<"\n";
}

int main()
{
    cout<<"\nPRUEBA DE  LISTA GENERALIZADA LINKEDLIST CON SUS METODOS"<<endl; //USO DE LA LISTA GENERALIZADA LINKEDLIST
    linkedlist<char> Caracteres;
	linkedlist<double> Flotantes;
	linkedlist<int> Enteros;

	for(int i=0;i<10;i++){
		Flotantes.pushfront(((float)i)*2.1);
	}
	cout<<"Lista de flotantes con pushfront= "<<endl;
	cout<<Flotantes<<endl;

	Caracteres.pushfront('A');
	cout<<"Lista de caracteres con pushfront= "<<Caracteres<<endl;
	Caracteres.pushend('B');
	cout<<"Lista de caracteres con pushend= "<<Caracteres<<endl;
	Caracteres.pushfront('C');
	cout<<"Lista de caracteres con pushfront= "<<Caracteres<<endl;
	Caracteres.pushend('D');
	cout<<"Lista de caracteres con pushend= "<<Caracteres<<endl;
	Caracteres.push(3,'E');
	cout<<"Lista de caracteres con push= "<<Caracteres<<endl;
	Caracteres.popfront();
	cout<<"Lista de caracteres con popfront= "<<Caracteres<<endl;
	Caracteres.popend();
	cout<<"Lista de caracteres con popend= "<<Caracteres<<endl;
	Caracteres.eliminar(2);
	cout<<"Lista de caracteres con eliminar= "<<Caracteres<<endl;

	for(int i =0 ; i < 10; i++){
		Enteros.pushend(i+1);
	}
	cout<<"Lista de enteros con pushend= "<<endl;
	cout<<Enteros<<endl;


    cout<<"\nCOMPARACION DE LA LISTA EN STL CON LINKEDLIST "<<endl;
    int n=5;
    unsigned t0, t1;

    //USO DE LISTA EN STL
    list<int>numeros;
    //Ingreso de elementos a la cabeza y al final
    t0=clock();
    srand((unsigned)time(0));
    for(int i=0;i<n;i++){
        numeros.push_front(0+rand() % 5);
        numeros.push_back(0+rand() % 5);
    }
    imprimir(numeros);//impresion con la libreria stl
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl;

    //USO DE LISTA LINKEDLIST
    linkedlist<int> lista;
    //Ingreso de elementos a la cabeza y al final
    t0=clock();
    for(int i=0;i<n;i++){
        lista.pushfront(0+rand() % 5);
        lista.pushend(0+rand() % 5);
    }
    imprimir1(lista);//Impresion con patron iterator
    t1=clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion: " << time << endl;
    return 0;
    //UNA VEZ COMPILADO LA DIFERENCIA ES DE ALREDEDOR 0 A 0.002 SEGUNDOS PARA 5 ELEMENTOS RANDOM
    //LO QUE NOS DA LA IDEA DE UNA ADECUADA IMPLEMENTACION DE LA CLASE LINKEDLIST.

}
