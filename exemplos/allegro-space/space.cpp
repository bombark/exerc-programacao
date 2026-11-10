#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

struct Player {
    float x, y;
    float width, height;
    float speed;
};

struct Bullet {
    float x, y;
    float speed;
    bool active;
};

struct Alien {
    float x, y;
    float width, height;
    bool alive;
};

int main() {
    // Inicialização do Allegro e seus addons
    if (!al_init()) return -1;
    if (!al_install_keyboard()) return -1;
    if (!al_init_primitives_addon()) return -1;
    if (!al_init_font_addon()) return -1;
    if (!al_init_ttf_addon()) return -1;

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

    if (!display || !timer || !queue) return -1;

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_keyboard_event_source());

    ALLEGRO_FONT* font = al_create_builtin_font();

    // Configuração do Jogador
    Player player = { SCREEN_WIDTH / 2.0f - 25, SCREEN_HEIGHT - 60.0f, 50, 20, 6.0f };
    std::vector<Bullet> bullets;

    // Configuração dos Aliens (Grade 8x4)
    std::vector<Alien> aliens;
    int alienRows = 4;
    int alienCols = 8;
    float alienWidth = 40, alienHeight = 25;
    float alienSpacingX = 25, alienSpacingY = 20;
    float startX = 120, startY = 60;

    for (int r = 0; r < alienRows; ++r) {
        for (int c = 0; c < alienCols; ++c) {
            Alien alien;
            alien.x = startX + c * (alienWidth + alienSpacingX);
            alien.y = startY + r * (alienHeight + alienSpacingY);
            alien.width = alienWidth;
            alien.height = alienHeight;
            alien.alive = true;
            aliens.push_back(alien);
        }
    }

    float alienSpeed = 1.2f;
    int alienDirection = 1; // 1 para direita, -1 para esquerda

    bool keys[2] = { false, false }; // [0] = Esquerda, [1] = Direita
    bool running = true;
    bool redraw = true;
    int score = 0;
    bool gameOver = false;
    bool victory = false;

    al_start_timer(timer);

    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) {
            if (!gameOver && !victory) {
                // Movimento do Jogador
                if (keys[0] && player.x > 10) player.x -= player.speed;
                if (keys[1] && player.x < SCREEN_WIDTH - player.width - 10) player.x += player.speed;

                // Atualizar posição dos tiros
                for (auto& b : bullets) {
                    if (b.active) {
                        b.y -= b.speed;
                        if (b.y < 0) b.active = false;
                    }
                }

                // Movimento e Limites dos Aliens
                bool changeDir = false;
                for (const auto& a : aliens) {
                    if (!a.alive) continue;
                    if ((alienDirection == 1 && a.x + a.width >= SCREEN_WIDTH - 20) ||
                        (alienDirection == -1 && a.x <= 20)) {
                        changeDir = true;
                        break;
                    }
                }

                if (changeDir) {
                    alienDirection *= -1;
                    for (auto& a : aliens) {
                        a.y += 15; // Descem uma linha
                        if (a.y + a.height >= player.y) {
                            gameOver = true;
                        }
                    }
                } else {
                    for (auto& a : aliens) {
                        if (a.alive) a.x += alienSpeed * alienDirection;
                    }
                }

                // Colisão: Tiro do jogador x Aliens
                bool allDead = true;
                for (auto& a : aliens) {
                    if (a.alive) {
                        allDead = false;
                        for (auto& b : bullets) {
                            if (b.active &&
                                b.x >= a.x && b.x <= a.x + a.width &&
                                b.y >= a.y && b.y <= a.y + a.height) {
                                a.alive = false;
                                b.active = false;
                                score += 100;
                            }
                        }
                    }
                }
                if (allDead) {
                    victory = true;
                }
            }
            redraw = true;
        }
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) running = false;
            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) keys[0] = true;
            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) keys[1] = true;
            if (event.keyboard.keycode == ALLEGRO_KEY_SPACE && !gameOver && !victory) {
                bullets.push_back({ player.x + player.width / 2 - 2, player.y, 7.0f, true });
            }
        }
        else if (event.type == ALLEGRO_EVENT_KEY_UP) {
            if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) keys[0] = false;
            if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) keys[1] = false;
        }

        if (redraw && al_is_event_queue_empty(queue)) {
            redraw = false;
            al_clear_to_color(al_map_rgb(15, 15, 25)); // Fundo azul escuro

            // Desenhar Jogador (Verde)
            al_draw_filled_rectangle(player.x, player.y, player.x + player.width, player.y + player.height, al_map_rgb(0, 255, 100));

            // Desenhar Tiros (Branco)
            for (const auto& b : bullets) {
                if (b.active) {
                    al_draw_filled_rectangle(b.x, b.y, b.x + 4, b.y + 12, al_map_rgb(255, 255, 255));
                }
            }

            // Desenhar Aliens (Vermelho/Rosa)
            for (const auto& a : aliens) {
                if (a.alive) {
                    al_draw_filled_rectangle(a.x, a.y, a.x + a.width, a.y + a.height, al_map_rgb(255, 50, 80));
                }
            }

            // Placar
            al_draw_textf(font, al_map_rgb(255, 255, 255), 20, 20, 0, "SCORE: %d", score);

            // Mensagens de Fim de Jogo
            if (gameOver) {
                al_draw_text(font, al_map_rgb(255, 0, 0), SCREEN_WIDTH / 2 - 40, SCREEN_HEIGHT / 2, 0, "GAME OVER");
            } else if (victory) {
                al_draw_text(font, al_map_rgb(0, 255, 0), SCREEN_WIDTH / 2 - 40, SCREEN_HEIGHT / 2, 0, "YOU WIN!");
            }

            al_flip_display();
        }
    }

    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}
