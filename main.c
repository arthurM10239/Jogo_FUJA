#include <raylib.h>
#include <raymath.h>
#include <math.h>

typedef enum GameScreen {
    MENU = 0,
    JOGO,
    FACIL,
    MEDIO,
    DIFICIL,
    IMPOSSIVEL,
    SAIR
} GameScreen;

const int screenWidth = 800;
const int screenHeight = 450;

int score = 0;
int segundos = 0;
float contador = 0;
void npcfacil();
void npcmedio();
void npcdificil();
void npcimpossivel();

GameScreen telaAtual = MENU;

int main() {

    
    
    InitWindow(screenWidth, screenHeight, "JOGO FUJA");
    SetTargetFPS(60);

    
    while (!WindowShouldClose()) {

        ClearBackground(BLACK);

        if(telaAtual == MENU){//MENU 
        Vector2 mouse = GetMousePosition();

        static Vector2 tamanho = {10,10};
        static Vector2 tamanhobotao = {35, 10};
    
        static Vector2 tamanho2 = {10,10};
        static Vector2 tamanhobotao2 = {28, 10};
            
        Vector2 botao1 = {350,150};
        Vector2 botao2 = {360,200};
        int largura = MeasureText("Jogar", 30);//conta quantos pixels a palavra ocupa
        int largura2 = MeasureText("Sair", 30);//conta quantos pixels a palavra ocupa


        static Vector2 bola = {400, 110};
        static Vector2 bola2 = {350, 110};

        float velanimacao = 5.0;
        
        BeginDrawing();
            

            bool mousebotao1 = //verdade se mouse estiver em cima no botao 1
            mouse.x >= botao1.x-35 && mouse.x <= botao1.x + largura+30 &&
            mouse.y >= botao1.y && mouse.y <= botao1.y + 30;

            bool mousebotao2 = //verdade se mouse estiver em cima no botao 2
            mouse.x >= botao2.x-45 && mouse.x <= botao2.x + largura2+45 &&
            mouse.y >= botao2.y && mouse.y <= botao2.y + 30;

            DrawText("FUJA", 330, 50, 50, WHITE);

            if(bola.x <= 480 && bola.y == 110)bola.x+=velanimacao;
            
            if(bola.y >= 30 && bola.x == 480) bola.y-=velanimacao;

            if(bola.x > 310 && bola.y == 30) bola.x-=velanimacao;

            if(bola.x == 310 && bola.y < 110) bola.y+=velanimacao;



            if(bola2.x <= 480 && bola2.y == 110)bola2.x+=velanimacao;
            
            if(bola2.y >= 30 && bola2.x == 480) bola2.y-=velanimacao;

            if(bola2.x > 310 && bola2.y == 30) bola2.x-=velanimacao;

            if(bola2.x == 310 && bola2.y < 110) bola2.y+=velanimacao;

            

            DrawCircleV(bola,10,BLUE);
            DrawCircleV(bola2,10,RED);

            DrawRectangleLines(botao1.x-35,botao1.y-2,150,35,WHITE);

            if(mousebotao1){//iniciando animacao do botao
            
            if(tamanhobotao.x > -30){
            tamanho.x+=9.7 * 2;
            tamanhobotao.x-=4.9 * 2;
            }else if(tamanhobotao.y > 1){
            tamanho.y+=2.6* 2;
            tamanhobotao.y-=1.2 *2 ;    
            }
            
            
            }else{//invertendo animacao

                if(tamanhobotao.y < 10){
                tamanho.y-=2 * 2;
                tamanhobotao.y+=1 * 2;    
                }
                else if(tamanhobotao.x < 35){
                tamanho.x-=9.7 * 2;
                tamanhobotao.x+=5 * 2;
                } 

                else{
                tamanhobotao.x = 35;
                tamanhobotao.y = 10;
                tamanho.x = 10;
                tamanho.y = 10;
                }
            }
            
            DrawRectangle(botao1.x+tamanhobotao.x,botao1.y+tamanhobotao.y,tamanho.x,tamanho.y,tamanhobotao.x < 35 ? GREEN : BLACK);
            DrawText("Jogar", botao1.x,botao1.y, 30, WHITE);
            DrawRectangleLines(botao2.x-45,botao2.y-2,150,35,WHITE);

            if(mousebotao2){//iniciando animacao botao
             
            if(tamanhobotao2.x > -39){
            tamanho2.x+=9.7 *2;
            tamanhobotao2.x-=5.1 *2;
            }
            else if(tamanhobotao2.y > 1){
            tamanho2.y+=2.6 * 2;
            tamanhobotao2.y-=1.2 * 2;
            }


            }else{//invertendo animacao do botao


            if(tamanhobotao2.y < 10){
            tamanho2.y-=2.6 * 2;
            tamanhobotao2.y+=1.2 * 2;
            }  
            else if(tamanhobotao2.x < 28){
            tamanho2.x-=9.7 *2;
            tamanhobotao2.x+=5.1 *2;
            } 
            else{
            tamanho2.x = 10;
            tamanhobotao2.x = 28; 
            tamanho2.y = 10;   
            tamanhobotao2.y = 10; 
            }

            }

            DrawRectangle(botao2.x+tamanhobotao2.x,botao2.y+tamanhobotao2.y,tamanho2.x,tamanho2.y,tamanhobotao2.x < 28 ? RED : BLACK);
            DrawText("Sair", botao2.x, botao2.y, 30, WHITE);
            
            

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mousebotao1) {
                telaAtual = JOGO;

            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mousebotao2) {
                telaAtual = SAIR;
                
            }
        

        EndDrawing();

        if(telaAtual == SAIR){
            CloseWindow();
        }

    }
            

    if(telaAtual == JOGO){//tela pra escolher a dificuldade

    Vector2 mouse = GetMousePosition();

    static Vector2 tamanho = {10,10};
    static Vector2 tamanhobotao = {23, 5};
    
    static Vector2 tamanho2 = {10,10};
    static Vector2 tamanhobotao2 = {23, 5};

    static Vector2 tamanho3 = {10,10};
    static Vector2 tamanhobotao3 = {23, 5};

    static Vector2 tamanho4 = {10,10};
    static Vector2 tamanhobotao4 = {23, 5};
            
    Vector2 botao1 = {371,150};
    Vector2 botao2 = {364,200};
    Vector2 botao3 = {360, 250};
    Vector2 botao4 = {336, 300};
    Vector2 voltar = {10,10};
    int largura = MeasureText("FACIL", 20);//conta quantos pixels a palavra ocupa
    int largura2 = MeasureText("MEDIA", 20);//conta quantos pixels a palavra ocupa
    int largura3 = MeasureText("DIFICIL", 20);//conta quantos pixels a palavra ocupa
    int largura4 = MeasureText("IMPOSSIVEL", 20);//conta quantos pixels a palavra ocupa
    int voltarlarg = MeasureText("VOLTAR", 15);


     BeginDrawing();

     bool VOLTAR = //verdade se mouse estiver em cima no botao 1
     mouse.x >= voltar.x && mouse.x <= voltar.x + voltarlarg &&
     mouse.y >= voltar.y && mouse.y <= voltar.y + 15;

     bool mousebotao1 = //verdade se mouse estiver em cima no botao 1
     mouse.x >= botao1.x && mouse.x <= botao1.x + largura &&
     mouse.y >= botao1.y && mouse.y <= botao1.y + 20;
     
     bool mousebotao2 = //verdade se mouse estiver em cima no botao 1
     mouse.x >= botao2.x && mouse.x <= botao2.x + largura2 &&
     mouse.y >= botao2.y && mouse.y <= botao2.y + 20;

     bool mousebotao3 = //verdade se mouse estiver em cima no botao 1
     mouse.x >= botao3.x && mouse.x <= botao3.x + largura3 &&
     mouse.y >= botao3.y && mouse.y <= botao3.y + 20;

     bool mousebotao4 = //verdade se mouse estiver em cima no botao 1
     mouse.x >= botao4.x && mouse.x <= botao4.x + largura4 &&
     mouse.y >= botao4.y && mouse.y <= botao4.y + 20;

        
        DrawText("[ Nivel de Dificuldade ]",285,100,20,WHITE);


        if(mousebotao1){

        if(tamanhobotao.y > -5){
        tamanho.y+=2;    
        tamanhobotao.y-= 1;    
        }         
        else if(tamanhobotao.x > -23){
        tamanho.x+=6 *3;    
        tamanhobotao.x-= 3 *3;
        }
           
            
        }else{
            if(tamanhobotao.y < 5){
            tamanho.y-=2;    
            tamanhobotao.y+= 1;    
            }         
            else if(tamanhobotao.x < 23){
            tamanho.x-=6 *2;    
            tamanhobotao.x+= 3 *2;
            }  
            else{
                tamanho.x = 10;
                tamanho.y = 10;
                tamanhobotao.x = 23;
                tamanhobotao.y = 5;
            }
        }

        if(mousebotao1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            telaAtual = FACIL;
        }

        DrawRectangle(botao1.x+tamanhobotao.x,botao1.y+tamanhobotao.y,tamanho.x,tamanho.y, tamanhobotao.x < 23 ? GREEN : BLACK);
        DrawText("FACIL", botao1.x,botao1.y, 20, mousebotao1 ? BLACK : WHITE);


        if(mousebotao2){

        if(tamanhobotao2.y > -5){
        tamanho2.y+=2;    
        tamanhobotao2.y-= 1;    
        }         
        else if(tamanhobotao2.x > -23){
        tamanho2.x+= 4.7 *3;    
        tamanhobotao2.x-= 2.1 *3;
        }
           
            
        }else{
            if(tamanhobotao2.y < 5){
            tamanho2.y-=2;    
            tamanhobotao2.y+= 1;    
            }         
            else if(tamanhobotao2.x < 23){
            tamanho2.x-=6 *2;    
            tamanhobotao2.x+= 3 *2;
            }else{
                tamanho2.x = 10;
                tamanho2.y = 10;
                tamanhobotao2.x = 23;
                tamanhobotao2.y = 5;
            }
        }

        if(mousebotao2 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            telaAtual = MEDIO;
        }

        DrawRectangle(botao2.x+tamanhobotao2.x,botao2.y+tamanhobotao2.y,tamanho2.x,tamanho2.y, tamanhobotao2.x < 23 ? YELLOW : BLACK);
        DrawText("MEDIA", botao2.x,botao2.y, 20, mousebotao2 ? BLACK : WHITE);


        if(mousebotao3){

            if(tamanhobotao3.y > -5){
            tamanho3.y+=2;    
            tamanhobotao3.y-= 1;    
            }         
            else if(tamanhobotao3.x > -23){
            tamanho3.x+= 4.7 *3;    
            tamanhobotao3.x-= 2.1 *3;
            }
               
                
            }else{
                if(tamanhobotao3.y < 5){
                tamanho3.y-=2;    
                tamanhobotao3.y+= 1;    
                }         
                else if(tamanhobotao3.x < 23){
                tamanho3.x-=6 *2;    
                tamanhobotao3.x+= 3 *2;
                }else{
                    tamanho3.x = 10;
                    tamanho3.y = 10;
                    tamanhobotao3.x = 23;
                    tamanhobotao3.y = 5;
                }
            }
    
        if(mousebotao3 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            telaAtual = DIFICIL;
        }

        DrawRectangle(botao3.x+tamanhobotao3.x+5,botao3.y+tamanhobotao3.y,tamanho3.x,tamanho3.y, tamanhobotao3.x < 23 ? RED : BLACK);
        DrawText("DIFICIL", botao3.x,botao3.y, 20,mousebotao3 ? BLACK : WHITE);

        if(mousebotao4){

            if(tamanhobotao4.y > -5){
            tamanho4.y+=2;    
            tamanhobotao4.y-= 1;    
            }         
            else if(tamanhobotao4.x > -23){
            tamanho4.x+= 6.5 *3;    
            tamanhobotao4.x-= 2.1 *3;
            }
               
                
            }else{
                if(tamanhobotao4.y < 5){
                tamanho4.y-=2;    
                tamanhobotao4.y+= 1;    
                }         
                else if(tamanhobotao4.x < 23){
                tamanho4.x-=6 *2;    
                tamanhobotao4.x+= 3 *2;
                }else{
                    tamanho4.x = 10;
                    tamanho4.y = 10;
                    tamanhobotao4.x = 23;
                    tamanhobotao4.y = 5;
                }
            }
    
        if(mousebotao4 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            telaAtual = IMPOSSIVEL;
        }

        DrawRectangle(botao4.x+tamanhobotao4.x+5,botao4.y+tamanhobotao4.y,tamanho4.x,tamanho4.y, tamanhobotao4.x < 23 ? LIGHTGRAY : BLACK);
        DrawText("IMPOSSÍVEL", botao4.x,botao4.y, 20, mousebotao4 ? BLACK: WHITE);
        
        DrawRectangleLines(270,90,255,250,WHITE);
        




        if(VOLTAR && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            telaAtual = MENU;
        }
        DrawText("VOLTAR",voltar.x,voltar.x,15,VOLTAR ? RED : WHITE);



        EndDrawing();
    }
        
    if(telaAtual == FACIL){

        npcfacil();

    }

    if(telaAtual == MEDIO){

        npcmedio();

    }

    if(telaAtual == DIFICIL){

        npcdificil();

    }
             
    if(telaAtual == IMPOSSIVEL){

        npcimpossivel();

    }
}


    return 0;
}


void npcfacil(){

    static Vector2 bola = { screenWidth / 2.0f, screenHeight / 2.0f };
    static Vector2 npc = {100, 100};
    static float velocidade = 4.0f;
    static bool gameOver = false;

    SetTargetFPS(60);

    float distancia = Vector2Distance(bola, npc);

        if (!gameOver) {

            contador++;
            if(contador >= 60){
            contador = 0;
            segundos++;    
            }


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
            DrawCircleV(bola, 15, BLUE);
            DrawCircleV(npc, 15, GREEN);

            DrawText(TextFormat("Distancia: %.1f",distancia), 10, 80, 20, distancia < 100 ? RED : (distancia > 300 ? GREEN : YELLOW));
            DrawText(TextFormat("Tempo Vivo: %d , %.2f", segundos, contador),10,10,20,WHITE);
            DrawText("SCORE ---",10,30,20,WHITE);
            DrawText("Missao: ---",10,50,20,WHITE);
            


            Vector2 mouse = GetMousePosition();
            Vector2 novamente = {screenWidth/2 - 80, screenHeight/2-20};
            Vector2 voltarmenu = {screenWidth/2 - 80, screenHeight/2+10};
            int largura2 = MeasureText("Tentar Novamente", 20);
            int largura = MeasureText("Voltar para menu", 20);
    
    
            bool NOVAMENTE = 
                mouse.x >= novamente.x && mouse.x <= novamente.x + largura2 &&
                mouse.y >= novamente.y && mouse.y <= novamente.y + 30;
    
            bool VOLTARMN= 
                mouse.x >= voltarmenu.x && mouse.x <= voltarmenu.x + largura &&
                mouse.y >= voltarmenu.y && mouse.y <= voltarmenu.y + 30;   
            

            if (gameOver) {
                DrawText("GAME OVER", screenWidth/2 - 80, screenHeight/2 - 60, 30, WHITE);   
                DrawText("Tente Novamente", novamente.x, novamente.y, 20, NOVAMENTE ? GREEN : WHITE);
                DrawText("Voltar Para Menu", voltarmenu.x, voltarmenu.y, 20,VOLTARMN ? GREEN : WHITE);
                
                if(NOVAMENTE && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    velocidade = 4.0f;
                    gameOver = false; 
                    segundos = 0;
                }
                
                if(VOLTARMN && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    telaAtual = MENU;
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    velocidade = 4.0f;
                    gameOver = false; 
                    segundos = 0;
                }

            }

        EndDrawing();
    

}

void npcmedio(){

    static Vector2 bola = { screenWidth / 2.0f, screenHeight / 2.0f };
    static Vector2 npc = {100, 100};
    static float velocidade = 4.0f;
    static bool gameOver = false;
    static bool Victory = false;
    static float velocidadeNPC = 2.0f;
    

    SetTargetFPS(60);

    

        Vector2 direcao = Vector2Normalize(Vector2Subtract(bola, npc));
        float distancia = Vector2Distance(bola, npc);
        if (!gameOver && !Victory) {

            contador++;
            if(contador >= 60){
            contador = 0;
            segundos++;    
            
            if(distancia > 300){
            score+= 3;
            }else if(distancia > 100 && distancia < 300 ){
            score+= 2;
            }else{
            score+= 1;    
            }

            }
            
            
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
            if(score >= 100){
            score = 100;
            Victory = true;
                
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

            DrawText(TextFormat("Distancia: %.1f",distancia), 10, 80, 20, distancia < 100 ? RED : (distancia > 300 ? GREEN : YELLOW));
            DrawText(TextFormat("Tempo Vivo: %d , %.2f", segundos, contador+39),10,10,20,WHITE);
            DrawText(TextFormat("Score: %d", score),10,30,20,WHITE);
            DrawText("Missao: ",10,50,20,WHITE);
            DrawText("100 Pontos",10 + MeasureText("Missao ", 20),50,20,YELLOW);

            DrawCircleV(bola, 15, BLUE);
            DrawCircleV(npc, 15, YELLOW);

        Vector2 mouse = GetMousePosition();
        Vector2 novamente = {screenWidth/2 - 80, screenHeight/2-20};
        Vector2 voltarmenu = {screenWidth/2 - 80, screenHeight/2+10};
        int largura2 = MeasureText("Tentar Novamente", 20);
        int largura = MeasureText("Voltar para menu", 20);


        bool NOVAMENTE = 
            mouse.x >= novamente.x && mouse.x <= novamente.x + largura2 &&
            mouse.y >= novamente.y && mouse.y <= novamente.y + 30;

        bool VOLTARMN= 
            mouse.x >= voltarmenu.x && mouse.x <= voltarmenu.x + largura &&
            mouse.y >= voltarmenu.y && mouse.y <= voltarmenu.y + 30;    


            if(Victory){
                DrawText("Vitoria", screenWidth/2 - 40, screenHeight/2 - 60, 30, GREEN);   
                DrawText("Tente Novamente", novamente.x, novamente.y, 20, NOVAMENTE ? BLUE : WHITE);
                DrawText("Voltar Para Menu", voltarmenu.x, voltarmenu.y, 20,VOLTARMN ? BLUE : WHITE);
                if(NOVAMENTE && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 2.0f;
                    segundos = 0;
                    score = 0;
                }
                
                if(VOLTARMN && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    telaAtual = MENU;
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 2.0f;
                    segundos = 0;
                    score = 0;
                }
            }

            if (gameOver) {
                DrawText("GAME OVER", screenWidth/2 - 80, screenHeight/2 - 60, 30, WHITE);   
                DrawText("Tente Novamente", novamente.x, novamente.y, 20, NOVAMENTE ? GREEN : WHITE);
                DrawText("Voltar Para Menu", voltarmenu.x, voltarmenu.y, 20,VOLTARMN ? GREEN : WHITE);
                
                if(NOVAMENTE && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 2.0f;
                    segundos = 0;
                    score = 0;
                }
                
                if(VOLTARMN && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    telaAtual = MENU;
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 2.0f;
                    segundos = 0;
                    score = 0;
                }

            }
        EndDrawing();
    }

void npcdificil(){


    static Vector2 bola = { screenWidth / 2.0f, screenHeight / 2.0f };
    static Vector2 npc = { 100, 100 };
    Vector2 ultimaPos = bola;
    static Vector2 direcaoJogador = {0, 0};
    static float velocidade = 4.0f;
    static float velocidadeNPC = 2.0f;
    static bool gameOver = false;
    static bool Victory = false;

    SetTargetFPS(60);

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


        float distancia = Vector2Distance(bola, npc);
        
        if (!gameOver && !Victory) {

            
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
            

            contador++;
            if(contador >= 60){
            contador = 0;
            segundos++;    
            
            if(distancia > 300){
            score+= 3;
            }else if(distancia > 100 && distancia < 300 ){
            score+= 2;
            }else{
            score+= 1;    
            }

            }
            
            float velocidadeFinal = velocidadeNPC + (300.0f - distancia) / 175.0f;
            if (velocidadeFinal < velocidadeNPC) velocidadeFinal = velocidadeNPC;

            npc = Vector2Add(npc, Vector2Scale(direcao, velocidadeFinal));

            // Verifica colisão
            if (Vector2Distance(bola, npc) < 15 * 2) {
                gameOver = true;
            }
            
            if(score >= 100){
            score = 100;
            Victory = true;
                    
            }
            
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // Texto com cor dinâmica para distância
        float dist = Vector2Distance(bola, npc);

        DrawText(TextFormat("Distancia: %.1f",distancia), 10, 80, 20, distancia < 100 ? RED : (distancia > 300 ? GREEN : YELLOW));
        DrawText(TextFormat("Tempo Vivo: %d , %.2f", segundos, contador+39),10,10,20,WHITE);
        DrawText(TextFormat("Score: %d", score),10,30,20,WHITE);
        DrawText("Missao: ",10,50,20,WHITE);
        DrawText("100 Pontos",10 + MeasureText("Missao ", 20),50,20,YELLOW);

        DrawText("NPC - nivel ", 300, 10, 20, WHITE);
        DrawText("[ DIFICIL ]", 300 + MeasureText("NPC - nivel ", 20), 10, 20, RED);

        DrawCircleV(bola, 15, BLUE);
        DrawCircleV(npc, 15, RED);

        Vector2 mouse = GetMousePosition();
        Vector2 novamente = {screenWidth/2 - 80, screenHeight/2-20};
        Vector2 voltarmenu = {screenWidth/2 - 80, screenHeight/2+10};
        int largura2 = MeasureText("Tentar Novamente", 20);
        int largura = MeasureText("Voltar para menu", 20);


        bool NOVAMENTE = 
            mouse.x >= novamente.x && mouse.x <= novamente.x + largura2 &&
            mouse.y >= novamente.y && mouse.y <= novamente.y + 30;

        bool VOLTARMN= 
            mouse.x >= voltarmenu.x && mouse.x <= voltarmenu.x + largura &&
            mouse.y >= voltarmenu.y && mouse.y <= voltarmenu.y + 30;    


            if(Victory){
                DrawText("Vitoria", screenWidth/2 - 40, screenHeight/2 - 60, 30, GREEN);   
                DrawText("Tente Novamente", novamente.x, novamente.y, 20, NOVAMENTE ? BLUE : WHITE);
                DrawText("Voltar Para Menu", voltarmenu.x, voltarmenu.y, 20,VOLTARMN ? BLUE : WHITE);
                if(NOVAMENTE && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 2.0f;
                    segundos = 0;
                    score = 0;
                }
                
                if(VOLTARMN && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    telaAtual = MENU;
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 2.0f;
                    segundos = 0;
                    score = 0;
                }
            }


            if (gameOver) {
                DrawText("GAME OVER", screenWidth/2 - 80, screenHeight/2 - 60, 30, WHITE);   
                DrawText("Tente Novamente", novamente.x, novamente.y, 20, NOVAMENTE ? GREEN : WHITE);
                DrawText("Voltar Para Menu", voltarmenu.x, voltarmenu.y, 20,VOLTARMN ? GREEN : WHITE);
                
                if(NOVAMENTE && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    direcaoJogador.x = 0;
                    direcaoJogador.y = 0;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 1.5f;
                    segundos = 0;
                    score = 0;

                }
                
                if(VOLTARMN && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    telaAtual = MENU;
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    direcaoJogador.x = 0;
                    direcaoJogador.y = 0;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 1.5f;
                    segundos = 0;
                    score = 0;
                }

            }

        EndDrawing();
}

void npcimpossivel(){

    static Vector2 bola = { screenWidth / 2.0f, screenHeight / 2.0f };
    static Vector2 npc = { 100, 100 };
    Vector2 ultimaPos = bola;
    static Vector2 direcaoJogador = {0, 0};
    static float velocidade = 4.0f;
    static float velocidadeNPC = 1.5f;
    static bool gameOver = false;
    static bool Victory = false;

    SetTargetFPS(60);

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


        float distancia = Vector2Distance(bola, npc);
        
        if (!gameOver && !Victory) {

            
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
            

            contador++;
            if(contador >= 60){
            contador = 0;
            segundos++;    
            
            if(distancia > 300){
            score+= 3;
            }else if(distancia > 100 && distancia < 300 ){
            score+= 2;
            }else{
            score+= 1;    
            }

            }
            
            float velocidadeFinal = velocidadeNPC + (300.0f - distancia) / 100.0f;
            if (velocidadeFinal < velocidadeNPC) velocidadeFinal = velocidadeNPC;

            npc = Vector2Add(npc, Vector2Scale(direcao, velocidadeFinal));

            // Verifica colisão
            if (Vector2Distance(bola, npc) < 15 * 2) {
                gameOver = true;
            }
            
            if(score >= 100){
            score = 100;
            Victory = true;
                    
            }
            
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // Texto com cor dinâmica para distância
        float dist = Vector2Distance(bola, npc);

        DrawText(TextFormat("Distancia: %.1f",distancia), 10, 80, 20, distancia < 100 ? RED : (distancia > 300 ? GREEN : YELLOW));
        DrawText(TextFormat("Tempo Vivo: %d , %.2f", segundos, contador+39),10,10,20,WHITE);
        DrawText(TextFormat("Score: %d", score),10,30,20,WHITE);
        DrawText("Missao: ",10,50,20,WHITE);
        DrawText("100 Pontos",10 + MeasureText("Missao ", 20),50,20,YELLOW);

        DrawText("NPC - nivel ", 300, 10, 20, WHITE);
        DrawText("[ IMPOSSIVEL ]", 300 + MeasureText("NPC - nivel ", 20), 10, 20, LIGHTGRAY);

        DrawCircleV(bola, 15, BLUE);
        DrawCircleLinesV(npc, 15, WHITE);

        Vector2 mouse = GetMousePosition();
        Vector2 novamente = {screenWidth/2 - 80, screenHeight/2-20};
        Vector2 voltarmenu = {screenWidth/2 - 80, screenHeight/2+10};
        int largura2 = MeasureText("Tentar Novamente", 20);
        int largura = MeasureText("Voltar para menu", 20);


        bool NOVAMENTE = 
            mouse.x >= novamente.x && mouse.x <= novamente.x + largura2 &&
            mouse.y >= novamente.y && mouse.y <= novamente.y + 30;

        bool VOLTARMN= 
            mouse.x >= voltarmenu.x && mouse.x <= voltarmenu.x + largura &&
            mouse.y >= voltarmenu.y && mouse.y <= voltarmenu.y + 30;    


            if(Victory){
                DrawText("Vitoria", screenWidth/2 - 40, screenHeight/2 - 60, 30, GREEN);   
                DrawText("Tente Novamente", novamente.x, novamente.y, 20, NOVAMENTE ? BLUE : WHITE);
                DrawText("Voltar Para Menu", voltarmenu.x, voltarmenu.y, 20,VOLTARMN ? BLUE : WHITE);
                if(NOVAMENTE && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 2.0f;
                    segundos = 0;
                    score = 0;
                }
                
                if(VOLTARMN && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    telaAtual = MENU;
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 2.0f;
                    segundos = 0;
                    score = 0;
                }
            }


            if (gameOver) {
                DrawText("GAME OVER", screenWidth/2 - 80, screenHeight/2 - 60, 30, WHITE);   
                DrawText("Tente Novamente", novamente.x, novamente.y, 20, NOVAMENTE ? GREEN : WHITE);
                DrawText("Voltar Para Menu", voltarmenu.x, voltarmenu.y, 20,VOLTARMN ? GREEN : WHITE);
                
                if(NOVAMENTE && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    direcaoJogador.x = 0;
                    direcaoJogador.y = 0;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 1.5f;
                    segundos = 0;
                    score = 0;

                }
                
                if(VOLTARMN && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                    telaAtual = MENU;
                    bola.x = screenWidth / 2.0f;
                    bola.y = screenHeight / 2.0f;
                    npc.x = 100;
                    npc.y = 100;
                    direcaoJogador.x = 0;
                    direcaoJogador.y = 0;
                    velocidade = 4.0f;
                    gameOver = false;
                    Victory = false;
                    velocidadeNPC = 1.5f;
                    segundos = 0;
                    score = 0;
                }

            }

        EndDrawing();
}



