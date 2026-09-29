#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h> // <--- Necessário para carregar imagens
#include <iostream>

// Dimensões da tela
const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;

// Estrutura para representar o Jogador
struct Jogador {
    float x, y;
    float largura, altura;
    float vel_x, vel_y;
    bool no_chao;
};

// Estrutura para representar uma Plataforma
struct Plataforma {
    float x, y, largura, altura;
};

int main() {
    // 1. Inicialização do Allegro
    if (!al_init()) {
        std::cerr << "Falha ao inicializar o Allegro!" << std::endl;
        return -1;
    }

    al_init_primitives_addon();
    al_init_font_addon();
    al_init_image_addon(); // <--- Inicializar o addon de imagens
    al_install_keyboard();

    ALLEGRO_DISPLAY* janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) {
        std::cerr << "Falha ao criar a janela!" << std::endl;
        return -1;
    }
    al_set_window_title(janela, "Jogo Estilo Mario com Imagem - Allegro 5");

    ALLEGRO_EVENT_QUEUE* fila_eventos = al_create_event_queue();
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0); // 60 FPS
    ALLEGRO_FONT* fonte = al_create_builtin_font();

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));

    // --- CARREGAR A IMAGEM DO PERSONAGEM ---
    ALLEGRO_BITMAP* img_jogador = al_load_bitmap("personagem.jpg");
    if (!img_jogador) {
        std::cerr << "Aviso: Nao foi possivel carregar 'personagem.jpg'. Usando quadrado vermelho padrao." << std::endl;
    }

    // 2. Inicialização do Jogador e Cenário
    Jogador player = { 100, 400, 30, 40, 0, 0, false };
    
    Plataforma plataformas[4] = {
        { 0, 520, 800, 80 },    // Chão principal
        { 200, 400, 150, 20 },  // Plataforma 1
        { 450, 300, 180, 20 },  // Plataforma 2
        { 150, 200, 120, 20 }   // Plataforma 3
    };

    const float GRAVIDADE = 0.5f;
    const float FORCA_PULO = -10.0f;
    const float VELOCIDADE_MOVIMENTO = 4.0f;

    bool tecla_esquerda = false;
    bool tecla_direita = false;

    bool rodando = true;
    bool redesenhar = true;

    al_start_timer(timer);

    // 3. Loop Principal
    while (rodando) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_eventos, &evento);

        if (evento.type == ALLEGRO_EVENT_TIMER) {
            redesenhar = true;

            // Movimento Horizontal
            player.vel_x = 0;
            if (tecla_esquerda) player.vel_x = -VELOCIDADE_MOVIMENTO;
            if (tecla_direita) player.vel_x = VELOCIDADE_MOVIMENTO;
            
            player.x += player.vel_x;

            // Gravidade
            player.vel_y += GRAVIDADE;
            player.y += player.vel_y;

            player.no_chao = false;

            // Colisão com Plataformas
            for (int i = 0; i < 4; i++) {
                Plataforma p = plataformas[i];

                if (player.x + player.largura > p.x &&
                    player.x < p.x + p.largura &&
                    player.y + player.altura > p.y &&
                    player.y < p.y + p.altura) {
                    
                    if (player.vel_y > 0 && player.y + player.altura - player.vel_y <= p.y + 5) {
                        player.y = p.y - player.altura;
                        player.vel_y = 0;
                        player.no_chao = true;
                    }
                }
            }

            // Limites da tela
            if (player.x < 0) player.x = 0;
            if (player.x + player.largura > LARGURA_TELA) player.x = LARGURA_TELA - player.largura;

        }
        else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            rodando = false;
        }
        else if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT || evento.keyboard.keycode == ALLEGRO_KEY_A) {
                tecla_esquerda = true;
            }
            if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT || evento.keyboard.keycode == ALLEGRO_KEY_D) {
                tecla_direita = true;
            }
            if ((evento.keyboard.keycode == ALLEGRO_KEY_UP || evento.keyboard.keycode == ALLEGRO_KEY_W || evento.keyboard.keycode == ALLEGRO_KEY_SPACE) && player.no_chao) {
                player.vel_y = FORCA_PULO;
                player.no_chao = false;
            }
            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                rodando = false;
            }
        }
        else if (evento.type == ALLEGRO_EVENT_KEY_UP) {
            if (evento.keyboard.keycode == ALLEGRO_KEY_LEFT || evento.keyboard.keycode == ALLEGRO_KEY_A) {
                tecla_esquerda = false;
            }
            if (evento.keyboard.keycode == ALLEGRO_KEY_RIGHT || evento.keyboard.keycode == ALLEGRO_KEY_D) {
                tecla_direita = false;
            }
        }

        // 4. Renderização
        if (redesenhar && al_is_event_queue_empty(fila_eventos)) {
            redesenhar = false;

            // Fundo azul claro
            al_clear_to_color(al_map_rgb(135, 206, 235));

            // Desenhar Plataformas
            for (int i = 0; i < 4; i++) {
                al_draw_filled_rectangle(
                    plataformas[i].x, plataformas[i].y,
                    plataformas[i].x + plataformas[i].largura,
                    plataformas[i].y + plataformas[i].altura,
                    al_map_rgb(139, 69, 19)
                );
            }

            // Desenhar Jogador (com imagem se carregada, senão com retângulo vermelho)
            if (img_jogador) {
                al_draw_scaled_bitmap(
                    img_jogador, 
                    0, 0, al_get_bitmap_width(img_jogador), al_get_bitmap_height(img_jogador), // Origem (tamanho total da imagem)
                    player.x, player.y, player.largura, player.altura, // Destino na tela (encaixado na física)
                    0
                );
            } else {
                al_draw_filled_rectangle(player.x, player.y, player.x + player.largura, player.y + player.altura, al_map_rgb(255, 0, 0));
            }

            al_draw_text(fonte, al_map_rgb(0, 0, 0), 20, 20, 0, "Use SETAS/AD para mover e ESPACO/W para pular.");

            al_flip_display();
        }
    }

    // 5. Limpeza de Recursos
    if (img_jogador) al_destroy_bitmap(img_jogador);
    al_destroy_font(fonte);
    al_destroy_timer(timer);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}