#include "raylib.h"
#include <raymath.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "NPC Difícil - Raylib");

    Vector2 bola = { screenWidth / 2.0f, screenHeight / 2.0f };
    Vector2 npc = { 100, 100 };
    Vector2 ultimaPos = bola;
    Vector2 direcaoJogador = {0, 0};
    float velocidade = 4.0f;
    float velocidadeNPC = 1.5f;
    bool gameOver = false;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Vector2 movimento = {0, 0};


        if(bola.x <= 15){
            bola.x+= velocidade;
        }
        if(bola.x >= GetScreenWidth() - 15){
            bola.x-= velocidade;
        }
        if(bola.y <= 15){
            bola.y+= velocidade; 
        }
        if(bola.y >= GetScreenHeight() - 15){
            bola.y-= velocidade;
        }


        // Movimento do jogador
        if (IsKeyDown(KEY_W)) movimento.y -= 1;
        if (IsKeyDown(KEY_S)) movimento.y += 1;
        if (IsKeyDown(KEY_A)) movimento.x -= 1;
        if (IsKeyDown(KEY_D)) movimento.x += 1;

        if (!gameOver) {
            // Atualiza posição da bola
            if (Vector2Length(movimento) > 0) {
                movimento = Vector2Normalize(movimento);
                direcaoJogador = movimento;
                bola = Vector2Add(bola, Vector2Scale(movimento, velocidade));
            }

            // prever a posicao do player
            Vector2 posPrevista = Vector2Add(bola, Vector2Scale(direcaoJogador, 20)); // previsão 30px à frente

            // Direção do NPC para a posição prevista
            Vector2 direcao = Vector2Normalize(Vector2Subtract(posPrevista, npc));
            float distancia = Vector2Distance(bola, npc);

            
            float velocidadeFinal = velocidadeNPC + (300.0f - distancia) / 100.0f;
            if (velocidadeFinal < velocidadeNPC) velocidadeFinal = velocidadeNPC;

            npc = Vector2Add(npc, Vector2Scale(direcao, velocidadeFinal));

            // Verifica colisão
            if (Vector2Distance(bola, npc) < 15 * 2) {
                gameOver = true;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // Texto com cor dinâmica para distância
        float dist = Vector2Distance(bola, npc);
        Color corDistancia = dist < 100 ? RED : (dist > 300 ? GREEN : YELLOW);
        DrawText(TextFormat("Distancia: %.1f", dist), 10, 10, 20, corDistancia);

        DrawText("NPC - nivel ", 300, 10, 20, WHITE);
        DrawText("[ IMPOSSÍVEL ]", 300 + MeasureText("NPC - nivel ", 20), 10, 20, GRAY);

        DrawCircleV(bola, 15, BLUE);
        DrawCircleV(npc, 15, RED);

        if (gameOver) {
            DrawText("GAME OVER", screenWidth / 2 - 80, screenHeight / 2, 30, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
