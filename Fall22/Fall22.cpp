// Add additional include directory since this will not be in the same directory
// $(SolutionDir)Foundry
#include "Foundry.h"

class Fall22Game : public Foundry::FoundryApp {
    private:
        void onKeyPress(const Foundry::KeyPressedEvent& event) {

        }

        void onKeyRelease(const Foundry::KeyPressedEvent& event) {

        }
        
    public:
        Fall22Game() {
            Foundry::FoundryWindow::getWindow()->setKeyPressedCallback([this](const Foundry::KeyPressedEvent& event) {onKeyPress(event);});
            Foundry::FoundryWindow::getWindow()->setKeyPressedCallback([this](const Foundry::KeyPressedEvent& event) {onKeyRelease(event);});
        }
        void onUpdate() override{};
};


START_FOUNDRY_GAME(Fall22Game);
