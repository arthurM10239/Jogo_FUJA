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

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float distancia = Vector2Distance(bola, npc);

        if (!gameOver) {
            // Movimento do NPC em direção à bola
            if (npc.x != bola.x || npc.y != bola.y) {
                if (npc.y > bola.y) npc.y--;
                else if (npc.y < bola.y) npc.y++;
                
                if (npc.x > bola.x) npc.x--;
                else if (npc.x < bola.x) npc.x++;

                else if(npc.y > bola.y && npc.x > bola.x){
                npc.x--;
                npc.y--;    
                }
                else if(npc.y < bola.y && npc.x < bola.x){
                npc.x++;
                npc.y++;    
                }
            }

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
            DrawText("[ FACIL ]", 300 + MeasureText("NPC - nivel ", 20), 10, 20, GREEN);
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
