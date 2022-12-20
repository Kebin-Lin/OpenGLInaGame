#include "Foundry.h"
#include "Entity.h"

constexpr int PADDING = 48;
constexpr int BOT_LANE = PADDING;
constexpr int MID_LANE = BOT_LANE + 300;
constexpr int TOP_LANE = MID_LANE + 300;

class Fall22Game : public Foundry::FoundryApp {
    private:

        unsigned int frameNum = 0;
        Entity player{
            {
                "assets/textures/holoCureInaRun/0.png", "assets/textures/holoCureInaRun/1.png", "assets/textures/holoCureInaRun/2.png",
                "assets/textures/holoCureInaRun/3.png", "assets/textures/holoCureInaRun/4.png", "assets/textures/holoCureInaRun/5.png"
            }
        };

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
        }

        void onUpdate() override {
            player.draw(frameNum / 2);
            frameNum++;
        };
};


START_FOUNDRY_GAME(Fall22Game);
