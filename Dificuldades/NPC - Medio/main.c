#include "raylib.h"
#include <raymath.h>
#include <math.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Bola controlada com W A S D");

    Vector2 bola = { screenWidth / 2.0f, screenHeight / 2.0f };
    Vector2 npc = {100, 100};
    float velocidade = 4.0f;
    bool gameOver = false;
    float velocidadeNPC = 2.0f;
    

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        Vector2 direcao = Vector2Normalize(Vector2Subtract(bola, npc));
        float distancia = Vector2Distance(bola, npc);
        if (!gameOver) {
            
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

            // Movimento do NPC em direção à bola
            npc = Vector2Add(npc, Vector2Scale(direcao, velocidadeNPC));



            

            // Verifica colisão entre NPC e jogador
            
            if (distancia < 15 * 2) {  // raio da bola + raio do npc
                gameOver = true;
            }

            // Movimento do jogador
            if (IsKeyDown(KEY_W)) bola.y -= velocidade;
            if (IsKeyDown(KEY_S)) bola.y += velocidade;
            if (IsKeyDown(KEY_A)) bola.x -= velocidade;
            if (IsKeyDown(KEY_D)) bola.x += velocidade;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("NPC - nivel ", 300, 10, 20, WHITE);
            DrawText("[ MEDIO ]", 300 + MeasureText("NPC - nivel ", 20), 10, 20, YELLOW);

            
            DrawText(TextFormat("Distancia: %.1f",distancia), 10, 10, 20, distancia < 100 ? RED : (distancia > 300 ? GREEN : YELLOW));
            
            DrawCircleV(bola, 15, BLUE);
            DrawCircleV(npc, 15, RED);

            if (gameOver) {
                DrawText("GAME OVER", screenWidth/2 - 80, screenHeight/2, 30, WHITE);
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
