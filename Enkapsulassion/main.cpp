#include "SDLWindow.h"
#include "RaylibWindow.h"
#include "RaylibSprite.h"

int main(int argc, char* argv[])
{
	RaylibWindow* window = new RaylibWindow();
	RaylibSprite* sprite = new RaylibSprite();
	window->Init();
	window->CreateWindow();
	sprite->LoadImage(".//pngtree-plant-in-pot-pixel-art-png-image_6681713.png");
	sprite->SetPosition(0, 0);
	while (true) {
		window->ClearWindow();
		sprite->Render();
		window->DrawWindow();
	}

	return 0;
}