#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct cliente{
    vector<string> datepc;
    vector<string> nomes;
    string nome;
    string data_string;
    int Dia;
    int Mes;
    int Ano;
    int es;
    int dominio;
};

int main(){
    int A;
    int c=0;
    cliente cons;
    cons.dominio=0;

    do{
        cout << "Para marcar uma consulta aperte [1] e para editar aperte [2]: ";
        cin >> cons.es;


        if (cons.es == 1){

            for (c;c<1;++c){
            cout << "Nome: ";
            cin.ignore();
            getline(cin, cons.nome);
            cons.nomes.push_back(cons.nome);


            do{cout << "\nInforme o dia: ";
            cin >> cons.Dia;
            }while((cons.Dia > 32) || (cons.Dia < 0));

            do{cout << "Informe o mês: ";
            cin >> cons.Mes;
            }while((cons.Mes > 12) || (cons.Mes < 1));

            cout << "Informe o Ano: ";
            cin >> cons.Ano;

            cons.data_string=to_string(cons.Dia) + "/" + to_string(cons.Mes) + "/" + to_string(cons.Ano);
            cons.datepc.push_back(cons.data_string);

            cout << "\nCliente: " << cons.nome << "  Data da consulta: " << cons.data_string << endl;
            }
            c=0;

        }else if (cons.es == 2){
            for(size_t i=0;i < cons.nomes.size();++i){
                const string& nome = cons.nomes[i];
                const string& data_string = cons.datepc[i];

                cout << i + 1 << "  Nome: " << nome << " Data: " << data_string << endl;
            }
            do{cout << "Qual deseja editar: ";
            cin >> A;
            }while((A < 1)||(A > cons.nomes.size()));

            cin.ignore();



            cout << A << "Nome: ";
            getline(cin, cons.nomes[A-1]);


            do{cout << "\nInforme o dia: ";
            cin >> cons.Dia;
            }while((cons.Dia > 32) || (cons.Dia < 0));

            do{cout << "Informe o mês: ";
            cin >> cons.Mes;
            }while((cons.Mes > 12) || (cons.Mes < 1));

            cout << "Informe o Ano: ";
            cin >> cons.Ano;

            cons.data_string=to_string(cons.Dia) + "/" + to_string(cons.Mes) + "/" + to_string(cons.Ano);
            cons.datepc[A-1]=cons.data_string;

            cout << "\nCliente: " << cons.nomes[A-1] << "  Data da consulta: " << cons.data_string << endl;
        }
    }while(cons.dominio==0);


    return 0;
}
