#include <iostream>
#include "TAD_ListaSimples.h"
#include "TAD_ListaDupla.h"
#include "TAD_ListaCircular.h"
#include "TAD_Pilha.h"
#include "TAD_Fila.h"

using namespace std;

<<<<<<< HEAD
enum Tela { MENU, SENSORES, CARGAS, NAVES, CAMERAS, LOGS, HANGAR };

=======
>>>>>>> 9fc09abfc6fd86123b6582c62c7f97574ff00786
int main(){
    const int largura = 800;
    const int altura = 600;
    InitWindow(largura,altura,"teste");
    Tela tela_atual = MENU;
    

<<<<<<< HEAD
    while(!WindowShouldClose()){
        DrawText()
        






    }






    return 0;
}
=======
    ListaSimples *cargas = criarListaSimples();
    Nave *naves = criarNave();
    ListaCircular *cameras = criarListaCircular();
    Pilha *logs = criarPilhaLog();
    Fila *hangar = criarFila();

    int modulo;

    do {
        cout << "\nESTACAO ESPACIAL\n";
        cout << "1 - Inventario de Cargas (Lista Simples)\n";
        cout << "2 - Historico de Naves (Lista Dupla)\n";
        cout << "3 - Monitoramento (Lista Circular)\n";
        cout << "4 - Central de Logs (Pilha)\n";
        cout << "5 - Controle de Hangar (Fila)\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> modulo;
        cin.ignore();

        switch(modulo){

        case 1: {
            int op, valor;

            do{
                cout << "\nCARGAS\n";
                cout << "1 - Inserir carga\n";
                cout << "2 - Remover carga\n";
                cout << "3 - Exibir cargas\n";
                cout << "0 - Voltar\n";
                cin >> op;

                switch(op){
                    case 1:
                        cout << "Valor: ";
                        cin >> valor;
                        inserirCarga(cargas, valor);
                        break;

                    case 2:
                        cout << "Valor a remover: ";
                        cin >> valor;
                        removerCarga(cargas, valor);
                        break;

                    case 3:
                        exibirCarga(cargas);
                        break;
                }

            } while(op != 0);
            break;
        }

        case 2: {
            int op;
            string nome;

            do{
                cout << "\nNAVES\n";
                cout << "1 - Inserir nave\n";
                cout << "2 - Remover nave\n";
                cout << "3 - Exibir naves\n";
                cout << "0 - Voltar\n";
                cin >> op;
                cin.ignore();

                switch(op){
                    case 1:
                        cout << "Nome: ";
                        getline(cin, nome);
                        inserirNave(nome, naves);
                        break;

                    case 2:
                        cout << "Nome a remover: ";
                        getline(cin, nome);
                        removerNave(naves, nome);
                        break;

                    case 3: {
                        NoDuplo *aux = naves->head;
                        while(aux != NULL){
                            cout << aux->nome << " <-> ";
                            aux = aux->proximo;
                        }
                        cout << "NULL\n";
                        break;
                    }
                }

            } while(op != 0);
            break;
        }

        case 3: {
            int op;
            string nome;

            do{
                cout << "\nCAMERAS\n";
                cout << "1 - Inserir camera\n";
                cout << "2 - Remover camera\n";
                cout << "3 - Exibir cameras\n";
                cout << "0 - Voltar\n";
                cin >> op;
                cin.ignore();

                switch(op){
                    case 1:
                        cout << "Nome: ";
                        getline(cin, nome);
                        inserirCamera(cameras, nome);
                        break;

                    case 2:
                        cout << "Nome a remover: ";
                        getline(cin, nome);
                        removerCamera(cameras, nome);
                        break;

                    case 3:
                        exibirCircular(cameras);
                        break;
                }

            } while(op != 0);
            break;
        }

        case 4: {
            int op;
            string log;

            do{
                cout << "\nLOGS\n";
                cout << "1 - Push\n";
                cout << "2 - Pop\n";
                cout << "0 - Voltar\n";
                cin >> op;
                cin.ignore();

                switch(op){
                    case 1:
                        cout << "Mensagem: ";
                        getline(cin, log);
                        pushLog(logs, log);
                        break;

                    case 2:
                        popLog(logs);
                        break;
                }

            } while(op != 0);
            break;
        }

        case 5: {
            int op, id;

            do{
                cout << "\nHANGAR\n";
                cout << "1 - Enqueue (chegada)\n";
                cout << "2 - Dequeue (saida)\n";
                cout << "0 - Voltar\n";
                cin >> op;

                switch(op){
                    case 1:
                        cout << "ID do aviao: ";
                        cin >> id;
                        enqueue(hangar, id);
                        break;

                    case 2:
                        dequeue(hangar);
                        break;
                }

            } while(op != 0);
            break;
        }

        }

    } while(modulo != 0);

    cout << "\nSistema encerrado.\n";
    return 0;
}
/*
int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;
  InitWindow(screenWidth, screenHeight, "raylib basic window");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("It works!", 20, 20, 20, BLACK);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
  */
>>>>>>> 9fc09abfc6fd86123b6582c62c7f97574ff00786
