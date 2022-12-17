#include "Foundry.h"

class Fall22Game : public Foundry::FoundryApp {
    private:
        Foundry::Unit amogus{"assets/textures/amogus.png", 1};

        void onKeyPress(const Foundry::KeyPressedEvent& event) {
            switch (event.getKeyCode()) {
                case FOUNDRY_KEY_UP:
                    amogus.changeY(10);
                    break;
                case FOUNDRY_KEY_DOWN:
                    amogus.changeY(-10);
                    break;
                case FOUNDRY_KEY_RIGHT:
                    amogus.changeX(10);
                    break;
                case FOUNDRY_KEY_LEFT:
                    amogus.changeX(-10);
                    break;
            }
        }

        void onKeyRelease(const Foundry::KeyReleasedEvent& event) {

        }
        
    public:
        Fall22Game() {
            Foundry::FoundryWindow::getWindow()->setKeyPressedCallback([this](const Foundry::KeyPressedEvent& event) {onKeyPress(event);});
            Foundry::FoundryWindow::getWindow()->setKeyReleasedCallback([this](const Foundry::KeyReleasedEvent& event) {onKeyRelease(event);});
            amogus.setCoord(0,0,0);
        }

        void onUpdate() override {
            Foundry::Renderer::draw(amogus);
        };
};


START_FOUNDRY_GAME(Fall22Game);
