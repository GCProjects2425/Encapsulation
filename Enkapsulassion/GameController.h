#pragma once

#include <memory>
#include <vector>
#include "Window.h"
#include "EntityBall.h"
#include "EntityPaddle.h"

class GameController {
public:
    static GameController& GetInstance() {
        static GameController m_Instance;
        return m_Instance;
    }

    // Supprimer les constructeurs par copie pour le singleton
    GameController(const GameController&) = delete;
    GameController& operator=(const GameController&) = delete;

    void Init(Window* window);
    void Run();

    EntityPaddle* GetLeftPaddle() { return m_LeftPaddle; }
    EntityPaddle* GetRightPaddle() { return m_RightPaddle; }
private:
    // Constructeur privé pour le singleton
    GameController() = default;

    // Membres
    Window* m_Window;
    EntityBall* m_Ball;
    EntityPaddle* m_LeftPaddle;
    EntityPaddle* m_RightPaddle;

    std::vector<Entity*> m_EntityVector;

    bool m_IsRunning = true;
};

