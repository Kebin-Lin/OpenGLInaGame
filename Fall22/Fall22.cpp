#include <vector>
#include <iostream>
#include "Foundry.h"
#include "Entity.h"

constexpr int PADDING = 48;
constexpr int BOT_LANE = PADDING;
constexpr int MID_LANE = BOT_LANE + 300;
constexpr int TOP_LANE = MID_LANE + 300;
constexpr int INITIAL_WAVE_INTERVAL = FRAMES_PER_SECOND * 3;
constexpr int SPEED_UP_RATE = FRAMES_PER_SECOND * 30;

class Fall22Game : public Foundry::FoundryApp {
    private:

        unsigned int framesUntilNextWave = 0;

        unsigned int frameNum = 0;
        Entity player{
            {
                "assets/textures/holoCureInaRun/0.png", "assets/textures/holoCureInaRun/1.png", "assets/textures/holoCureInaRun/2.png",
                "assets/textures/holoCureInaRun/3.png", "assets/textures/holoCureInaRun/4.png", "assets/textures/holoCureInaRun/5.png"
            }
        };

        Anim cookieAnim{{"assets/textures/cookie.png"}};
        Anim takodachi{{"assets/textures/holoCureTako/0.png", "assets/textures/holoCureTako/1.png", "assets/textures/holoCureTako/2.png"}};
        Entity tako{takodachi};
        std::vector<Entity> cookies{};
        std::vector<Entity> takos{};

        void onKeyPress(const Foundry::KeyPressedEvent& event) {
            switch (event.getKeyCode()) {
                case FOUNDRY_KEY_UP:
                    player.setCoords(PADDING, TOP_LANE, 0);
                    break;
                case FOUNDRY_KEY_DOWN:
                    player.setCoords(PADDING, BOT_LANE, 0);
                    break;
                case FOUNDRY_KEY_RIGHT:
                    player.setCoords(PADDING, MID_LANE, 0);
                    break;
                // case FOUNDRY_KEY_LEFT:
                //     break;
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
            player.draw(frameNum / 2);
            frameNum++;
            if (framesUntilNextWave <= 0) { // Spawn next wave
                double difficultyMultiplier = (((double)frameNum / SPEED_UP_RATE) + 1);
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
                framesUntilNextWave = INITIAL_WAVE_INTERVAL / difficultyMultiplier;
            }
            std::vector<int> toErase;
            for (int i = 0; i < takos.size(); i++) {
                if (takos[i].overlapsWith(player)) {
                    std::cout << "L";
                }
                takos[i].move();
                takos[i].draw(frameNum / 3);
                if (takos[i].getX() < -300) {
                    toErase.push_back(i);
                }
            }
            for (int i = toErase.size() - 1; i > 0; i--) {
                takos.erase(takos.begin() + i);
            }
            framesUntilNextWave--;
        };
};


START_FOUNDRY_GAME(Fall22Game);
