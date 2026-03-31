#include "raylib.h"
#include <string>
#include <iostream>
#include <cmath> // Para o desenho circular

// Incluindo seus TADs (certifique-se que os arquivos batem com a imagem anterior)
#include "TAD_Fila.h"
#include "TAD_Pilha.h"
#include "TAD_ListaSimples.h"
#include "TAD_ListaDupla.h"
#include "TAD_ListaCircular.h"
#include "TAD_ListaEstatica.h"

using namespace std;

// Estados do Menu
enum Tela { MENU, SENSORES, CARGAS, NAVES, CAMERAS, LOGS, HANGAR };

int main() {
    // 1. Setup da Janela
    const int screenWidth = 1100;
    const int screenHeight = 700;
    InitWindow(screenWidth, screenHeight, "UNIVALI - Simulador de Logistica Estelar - Leonardo");
    SetTargetFPS(60);

    // 2. Inicializacao das Estruturas (Usando suas funcoes)
    Tela telaAtual = MENU;
    
    ListaSensores sensores; // Estatitica
    inicializarSensores(sensores);
    
    ListaSimples* cargas = criarListaSimples();
    Nave* naves = criarNave();
    ListaCircular* cameras = criarListaCircular();
    Pilha* logs = criarPilhaLog();
    Fila* hangar = criarFila();

    // Auxiliares de Visualizacao
    NoDuplo* navSelecionado = NULL;
    string msgStatus = "Aguardando comando...";

    while (!WindowShouldClose()) {
        // --- LOGICA DE NAVEGACAO ---
        if (IsKeyPressed(KEY_M)) telaAtual = MENU;

        if (telaAtual == MENU) {
            if (IsKeyPressed(KEY_ONE)) telaAtual = SENSORES;
            if (IsKeyPressed(KEY_TWO)) telaAtual = CARGAS;
            if (IsKeyPressed(KEY_THREE)) { telaAtual = NAVES; navSelecionado = naves->head; }
            if (IsKeyPressed(KEY_FOUR)) telaAtual = CAMERAS;
            if (IsKeyPressed(KEY_FIVE)) telaAtual = LOGS;
            if (IsKeyPressed(KEY_SIX)) telaAtual = HANGAR;
        }

        // --- LÓGICA DE INTERACAO (A = Adicionar, D = Deletar) ---
        switch (telaAtual) {
            case SENSORES: // ESTATICA
                if (IsKeyPressed(KEY_A)) {
                    int id = GetRandomValue(1, 100);
                    inserirSensor(sensores, id);
                    msgStatus = "Sensor " + to_string(id) + " inserido.";
                }
                if (IsKeyPressed(KEY_D) && sensores.tamanho > 0) {
                    removerSensor(sensores, sensores.dados[0].id); // Remove o primeiro
                    msgStatus = "Primeiro sensor removido.";
                }
                break;
            case CARGAS: // SIMPLES
                if (IsKeyPressed(KEY_A)) {
                    int v = GetRandomValue(1000, 9999);
                    inserirCarga(cargas, v); // Inserir no inicio
                    msgStatus = "Carga ID " + to_string(v) + " inserida (no inicio).";
                }
                if (IsKeyPressed(KEY_D) && cargas->inicio) {
                    removerCarga(cargas, cargas->inicio->valor);
                    msgStatus = "Carga removida.";
                }
                break;
            case NAVES: // DUPLA (Com Seleção)
                if (IsKeyPressed(KEY_A)) {
                    inserirNave("NAVE-" + to_string(GetRandomValue(1, 100)), naves);
                    if (!navSelecionado) navSelecionado = naves->head;
                }
                if (IsKeyPressed(KEY_D) && navSelecionado) {
                    string nomeApagar = navSelecionado->nome;
                    navSelecionado = (navSelecionado->proximo) ? navSelecionado->proximo : navSelecionado->anterior;
                    removerNave(naves, nomeApagar);
                }
                // Navegacao
                if (IsKeyPressed(KEY_RIGHT) && navSelecionado && navSelecionado->proximo) navSelecionado = navSelecionado->proximo;
                if (IsKeyPressed(KEY_LEFT) && navSelecionado && navSelecionado->anterior) navSelecionado = navSelecionado->anterior;
                break;
            case CAMERAS: // CIRCULAR
                if (IsKeyPressed(KEY_A)) {
                    string n = "CAM-" + to_string(GetRandomValue(1, 20));
                    inserirCamera(cameras, n);
                    msgStatus = "Camera " + n + " inserida.";
                }
                if (IsKeyPressed(KEY_D) && cameras->inicio) {
                    removerCamera(cameras, cameras->inicio->nome);
                    msgStatus = "Camera removida.";
                }
                break;
            case LOGS: // PILHA
                if (IsKeyPressed(KEY_A)) pushLog(logs, "Log #" + to_string(GetRandomValue(1, 500)));
                if (IsKeyPressed(KEY_D)) popLog(logs);
                break;
            case HANGAR: // FILA
                if (IsKeyPressed(KEY_A)) enqueue(hangar, GetRandomValue(1, 99));
                if (IsKeyPressed(KEY_D)) dequeue(hangar);
                break;
        }

        // --- DESENHO (RENDERIZACAO) ---
        BeginDrawing();
        ClearBackground(GetColor(0x18181DFF)); // Fundo "Espaço Profundo"

        // Barra de Status (Requisito 4)
        DrawRectangle(0, screenHeight - 40, screenWidth, 40, DARKGRAY);
        DrawText(msgStatus.c_str(), 20, screenHeight - 30, 18, RAYWHITE);

        if (telaAtual == MENU) {
            DrawText("ESTAÇÃO ESPACIAL OMNI", 380, 80, 35, GOLD);
            DrawText("Pressione o número para entrar no setor:", 410, 150, 18, LIGHTGRAY);
            
            DrawText("1. Sensores (Estatica)", 350, 220, 22, LIGHTGRAY);
            DrawText("2. Cargas (Simples)", 350, 260, 22, LIGHTGRAY);
            DrawText("3. Naves (Dupla)", 350, 300, 22, LIGHTGRAY);
            DrawText("4. Câmeras (Circular)", 350, 340, 22, LIGHTGRAY);
            DrawText("5. Logs (Pilha)", 350, 380, 22, LIGHTGRAY);
            DrawText("6. Hangar (Fila)", 350, 420, 22, LIGHTGRAY);
        } else {
            DrawText("[M] Menu | [A] Adicionar | [D] Remover", 20, 20, 18, GREEN);
        }

        // --- VISUALIZACAO DE CADA MODULO ---

        if (telaAtual == SENSORES) { // 1. ESTATICA
            DrawText("SENSORES TÉRMICOS (LISTA ESTÁTICA)", 350, 50, 25, SKYBLUE);
            for (int i = 0; i < MAX; i++) {
                Rectangle r = {(float)150 + (i * 100), 300, 80, 60};
                DrawRectangleLinesEx(r, 2, GRAY);
                DrawText(to_string(i).c_str(), r.x + 35, r.y - 20, 15, GRAY); // ID do Indice
                if (i < sensores.tamanho) {
                    DrawRectangleRec(r, DARKBLUE);
                    DrawText(to_string(sensores.dados[i].id).c_str(), r.x + 30, r.y + 20, 20, WHITE);
                }
            }
        }

        if (telaAtual == CARGAS) { // 2. SIMPLES (Insercao no Inicio)
            DrawText("INVENTÁRIO DE CARGAS (LISTA SIMPLES)", 350, 50, 25, MAROON);
            NoSimples* aux = cargas->inicio;
            int i = 0;
            while (aux) {
                DrawRectangle(100 + (i * 140), 350, 120, 50, DARKGREEN);
                DrawText(TextFormat("ID:%d", aux->valor), 120 + (i * 140), 365, 18, WHITE);
                if (aux->proximo) {
                    DrawLineEx({(float)220 + (i * 140), 375}, {(float)240 + (i * 140), 375}, 3, RED); // Seta Next
                }
                aux = aux->proximo; i++;
            }
        }

        if (telaAtual == NAVES) { // 3. DUPLA (Navegacao Bidirecional)
            DrawText("HISTÓRICO DE NAVES (LISTA DUPLA)", 350, 50, 25, PURPLE);
            DrawText("Use as SETAS para navegar", 400, 90, 18, LIGHTGRAY);
            NoDuplo* aux = naves->head;
            int i = 0;
            while (aux) {
                Color cor = (aux == navSelecionado) ? YELLOW : PURPLE; // Selecao
                DrawRectangle(100 + (i * 160), 400, 140, 60, DARKPURPLE);
                DrawRectangleLinesEx({(float)100 + (i * 160), 400, 140, 60}, 2, cor);
                DrawText(aux->nome.c_str(), 120 + (i * 160), 425, 15, WHITE);
                
                if (aux->proximo) DrawLineEx({(float)240 + (i * 160), 415}, {(float)260 + (i * 160), 415}, 2, RED); // Next
                if (aux->anterior) DrawLineEx({(float)100 + (i * 160), 445}, {(float)80 + (i * 160), 445}, 2, BLUE); // Prev
                
                aux = aux->proximo; i++;
            }
        }

        if (telaAtual == CAMERAS) { // 4. CIRCULAR
            DrawText("MONITORAMENTO (LISTA CIRCULAR)", 350, 50, 25, ORANGE);
            if (cameras->inicio) {
                NoCircular* aux = cameras->inicio;
                int i = 0;
                int count = 0;
                // Conta o numero de cameras
                do { count++; aux = aux->proximo; } while (aux != cameras->inicio);
                
                aux = cameras->inicio;
                do {
                    // Desenho Circular (x,y = centro + cos/sin * raio)
                    float angulo = (360.0f / count) * i;
                    float rad = angulo * DEG2RAD;
                    float x = 550 + cos(rad) * 150;
                    float y = 350 + sin(rad) * 150;
                    
                    DrawCircle(x, y, 30, DARKBROWN);
                    DrawCircleLines(x, y, 30, ORANGE);
                    DrawText(aux->nome.c_str(), x - 25, y - 8, 15, WHITE);
                    
                    // Seta Circular
                    float p_angulo = (360.0f / count) * (i+1);
                    float p_rad = p_angulo * DEG2RAD;
                    DrawLineEx({x,y}, {550 + cos(p_rad)*150, 350+sin(p_rad)*150}, 2, RED);

                    aux = aux->proximo; i++;
                } while (aux != cameras->inicio);
            }
        }

        if (telaAtual == LOGS) { // 5. PILHA (LIFO)
            DrawText("CENTRAL DE LOGS (PILHA)", 350, 50, 25, MAROON);
            NoPilha* aux = logs->topo; // Comeca do topo
            int i = 0;
            while (aux) {
                // Desenha de baixo para cima (Pilha)
                DrawRectangle(450, 550 - (i * 45), 200, 40, DARKGREEN);
                DrawText(aux->log.c_str(), 460, 560 - (i * 45), 16, RAYWHITE);
                aux = aux->anterior; i++;
            }
        }

        if (telaAtual == HANGAR) { // 6. FILA (FIFO)
            DrawText("CONTROLE DE HANGAR (FILA)", 350, 50, 25, GOLD);
            NoFila* aux = hangar->inicio; // Comeca do inicio
            int i = 0;
            while (aux) {
                DrawRectangle(100 + (i * 140), 400, 120, 50, DARKBLUE);
                DrawText(TextFormat("Aeron: %d", aux->id), 120 + (i * 140), 415, 18, RAYWHITE);
                if (aux->prox) {
                    DrawLineEx({(float)220 + (i * 140), 425}, {(float)240 + (i * 140), 425}, 3, RED); // Seta Next
                }
                aux = aux->prox; i++;
            }
        }

        EndDrawing();
    }

    // --- Limpeza (Delete) - Importante para a nota do Gadelha! ---
    CloseWindow();
    return 0;
}