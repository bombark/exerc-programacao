#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

// Dimensões da tela
const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;

// Estrutura simples para representar um botão
struct Botao {
    float x, y, largura, altura;
    const char* texto;
    bool hover;
};

// Função auxiliar para verificar se o mouse está sobre o botão
bool mouse_sobre_botao(float mx, float my, const Botao& b) {
    return (mx >= b.x && mx <= b.x + b.largura && my >= b.y && my <= b.y + b.altura);
}

int main() {
    // 1. Inicialização do Allegro
    if (!al_init()) {
        std::cerr << "Falha ao inicializar o Allegro!" << std::endl;
        return -1;
    }

    // Inicializar complementos essenciais
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_install_mouse();
    al_install_keyboard();

    // 2. Criar a janela e a fila de eventos
    ALLEGRO_DISPLAY* janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) {
        std::cerr << "Falha ao criar a janela!" << std::endl;
        return -1;
    }
    al_set_window_title(janela, "Menu do Jogo - Allegro 5");

    ALLEGRO_EVENT_QUEUE* fila_eventos = al_create_event_queue();
    if (!fila_eventos) {
        std::cerr << "Falha ao criar a fila de eventos!" << std::endl;
        al_destroy_display(janela);
        return -1;
    }

    // Carregar fonte (Certifique-se de ter uma fonte .ttf válida na pasta ou use a padrão)
    ALLEGRO_FONT* fonte = al_create_builtin_font(); // Fonte padrão segura para testes
    // Se quiser carregar uma fonte externa: ALLEGRO_FONT* fonte = al_load_ttf_font("arial.ttf", 24, 0);

    // 3. Configurar Botões do Menu
    Botao btn_jogar = { 300, 220, 200, 50, "JOGAR", false };
    Botao btn_opcoes = { 300, 300, 200, 50, "OPCOES", false };
    Botao btn_sair = { 300, 380, 200, 50, "SAIR", false };

    // Registrar fontes de eventos
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    // Timer para controlar os quadros por segundo (FPS)
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));
    al_start_timer(timer);

    bool rodando = true;
    bool redesenhar = true;
    float mouse_x = 0, mouse_y = 0;

    // 4. Loop Principal do Jogo/Menu
    while (rodando) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_eventos, &evento);

        if (evento.type == ALLEGRO_EVENT_TIMER) {
            redesenhar = true;
        }
        else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            rodando = false;
        }
        else if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {
            // Atualizar posição do mouse para detectar hover
            mouse_x = evento.mouse.x;
            mouse_y = evento.mouse.y;

            btn_jogar.hover = mouse_sobre_botao(mouse_x, mouse_y, btn_jogar);
            btn_opcoes.hover = mouse_sobre_botao(mouse_x, mouse_y, btn_opcoes);
            btn_sair.hover = mouse_sobre_botao(mouse_x, mouse_y, btn_sair);
        }
        else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (evento.mouse.button == 1) { // Botão esquerdo do mouse
                if (mouse_sobre_botao(mouse_x, mouse_y, btn_jogar)) {
                    std::cout << "Opção selecionada: JOGAR" << std::endl;
                    // Aqui você mudaria o estado do jogo para iniciar a partida
                }
                else if (mouse_sobre_botao(mouse_x, mouse_y, btn_opcoes)) {
                    std::cout << "Opção selecionada: OPÇÕES" << std::endl;
                }
                else if (mouse_sobre_botao(mouse_x, mouse_y, btn_sair)) {
                    rodando = false;
                }
            }
        }
        else if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                rodando = false;
            }
        }

        // 5. Renderização na Tela
        if (redesenhar && al_is_event_queue_empty(fila_eventos)) {
            redesenhar = false;

            // Limpar tela com uma cor de fundo (Azul escuro)
            al_clear_to_color(al_map_rgb(30, 30, 50));

            // Desenhar Título do Jogo
            al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA_TELA / 2, 100, ALLEGRO_ALIGN_CENTRE, "MEU JOGO EM ALLEGRO");

            // Função local para desenhar os botões dinamicamente
            auto desenhar_botao = [&](const Botao& b) {
                ALLEGRO_COLOR cor_fundo = b.hover ? al_map_rgb(80, 120, 200) : al_map_rgb(60, 60, 90);
                ALLEGRO_COLOR cor_borda = al_map_rgb(200, 200, 200);

                // Caixa do botão
                al_draw_filled_rectangle(b.x, b.y, b.x + b.largura, b.y + b.altura, cor_fundo);
                al_draw_rectangle(b.x, b.y, b.x + b.largura, b.y + b.altura, cor_borda, 2);

                // Texto centralizado no botão
                al_draw_text(fonte, al_map_rgb(255, 255, 255), b.x + b.largura / 2, b.y + 18, ALLEGRO_ALIGN_CENTRE, b.texto);
            };

            desenhar_botao(btn_jogar);
            desenhar_botao(btn_opcoes);
            desenhar_botao(btn_sair);

            al_flip_display();
        }
    }

    // 6. Limpeza de Memória
    al_destroy_font(fonte);
    al_destroy_timer(timer);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}
