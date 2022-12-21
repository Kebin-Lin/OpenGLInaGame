#include <vector>
#include <iostream>
#include "Foundry.h"
#include "Entity.h"
#include "Text.h"

constexpr int PADDING = 48;
constexpr int BOT_LANE = PADDING;
constexpr int MID_LANE = BOT_LANE + 300;
constexpr int TOP_LANE = MID_LANE + 300;
constexpr int INITIAL_WAVE_INTERVAL = FRAMES_PER_SECOND * 3;
constexpr int SPEED_UP_RATE = FRAMES_PER_SECOND * 30;

class Fall22Game : public Foundry::FoundryApp {
    private:

        unsigned int framesUntilNextWave{ 0 };
        unsigned int frameNum{ 0 };

        enum GAME_STATE {RUNNING, GAME_OVER} currentGameState{ RUNNING };

        int score{ 0 };
        Text scoreDisplay{ "Wave " };

        Entity player{
            {
                "assets/textures/holoCureInaRun/0.png", "assets/textures/holoCureInaRun/1.png", "assets/textures/holoCureInaRun/2.png",
                "assets/textures/holoCureInaRun/3.png", "assets/textures/holoCureInaRun/4.png", "assets/textures/holoCureInaRun/5.png"
            }
        };

        Foundry::Picture background{"assets/textures/tenshiikisu-bg.png"}; // Period of 412 pixels
        Foundry::Picture gameover{"assets/textures/gameover.png"};
        Anim cookieAnim{{"assets/textures/cookie.png"}};
        Entity tako{{"assets/textures/holoCureTako/0.png", "assets/textures/holoCureTako/1.png", "assets/textures/holoCureTako/2.png"}};
        std::vector<Entity> cookies{};
        std::vector<Entity> takos{};

        int clamp(int input, int high, int low) {
            if (input > high) {return high;}
            if (input < low) {return low;}
            return input;
        }

        void onKeyPress(const Foundry::KeyPressedEvent& event) {
            switch (currentGameState) {
                case RUNNING: {
                    switch (event.getKeyCode()) {
                        case FOUNDRY_KEY_UP:
                            player.setCoords(PADDING, clamp(player.getY() + 300, TOP_LANE, BOT_LANE), 0);
                            break;
                        case FOUNDRY_KEY_DOWN:
                            player.setCoords(PADDING, clamp(player.getY() - 300, TOP_LANE, BOT_LANE), 0);
                            break;
                        // case FOUNDRY_KEY_RIGHT:
                        //     player.setCoords(PADDING, MID_LANE, 0);
                        //     break;
                        // case FOUNDRY_KEY_LEFT:
                        //     break;
                    }
                } break;
                case GAME_OVER: {
                    if (event.getKeyCode() == FOUNDRY_KEY_R) {
                        score = 0;
                        scoreDisplay.setText("");
                        frameNum = 0;
                        framesUntilNextWave = 0;
                        takos.clear();
                        cookies.clear();
                        currentGameState = RUNNING;
                    }
                }
            }
        }

        void onKeyRelease(const Foundry::KeyReleasedEvent& event) {
            // switch (event.getKeyCode()) {
            //     case FOUNDRY_KEY_UP:
            //         break;
            //     case FOUNDRY_KEY_DOWN:
            //         break;
            //     case FOUNDRY_KEY_RIGHT:
            //         break;
            //     case FOUNDRY_KEY_LEFT:
            //         break;
            // }
        }
        
    public:
        Fall22Game() {
            Foundry::FoundryWindow::getWindow()->setKeyPressedCallback([this](const Foundry::KeyPressedEvent& event) {onKeyPress(event);});
            Foundry::FoundryWindow::getWindow()->setKeyReleasedCallback([this](const Foundry::KeyReleasedEvent& event) {onKeyRelease(event);});
            player.setCoords(PADDING, BOT_LANE, 0);
            srand(time(NULL));
        }

        void onUpdate() override {
            Foundry::Renderer::draw(background, -412 + (frameNum * -5) % 412, 0, -1);
            for (int i = 0; i < takos.size(); i++) {
                takos[i].draw(frameNum / 3);
            }
            player.draw(frameNum / 2);
            scoreDisplay.draw(PADDING, 900 - PADDING - 30, 1);
            switch (currentGameState) {
                case RUNNING: {
                    frameNum++;
                    if (framesUntilNextWave <= 0) { // Spawn next wave
                        double difficultyMultiplier = std::pow(2, ((double)frameNum / SPEED_UP_RATE));
                        int firstPos = rand() % 3;
                        int secondPos = rand() % 3;
                        tako.setCoords(1600, PADDING + firstPos * 300, 0);
                        tako.setXVel(-5 * difficultyMultiplier);
                        takos.push_back(tako);
                        if (firstPos != secondPos) {
                            tako.setCoords(1600, PADDING + secondPos * 300, 0);
                            tako.setXVel(-5 * difficultyMultiplier);
                            takos.push_back(tako);
                        }
                        score++;
                        scoreDisplay.setText("Wave " + std::to_string(score));
                        framesUntilNextWave = INITIAL_WAVE_INTERVAL / difficultyMultiplier;
                    }
                    std::vector<int> toErase;
                    for (int i = 0; i < takos.size(); i++) {
                        if (takos[i].overlapsWith(player)) {
                            currentGameState = GAME_OVER;
                        }
                        takos[i].move();
                        if (takos[i].getX() < -300) {
                            toErase.push_back(i);
                        }
                    }
                    for (int i = toErase.size() - 1; i > 0; i--) {
                        takos.erase(takos.begin() + i);
                    }
                    framesUntilNextWave--;
                } break;
                case GAME_OVER: {
                    Foundry::Renderer::draw(gameover, 0, 0, 1);
                } break;
            }
        };
};


START_FOUNDRY_GAME(Fall22Game);
