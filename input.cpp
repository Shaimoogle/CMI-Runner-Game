#include "input.hpp"

using namespace std;

void UpdateInput(int& input)
{
    SDL_Event event;

    input = -1;

    SDL_WaitEventTimeout(&event, 17);

    switch (event.type)
    {
      case SDL_QUIT:
        input = 0;
        break;

      case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            input = 0;
            cout << "PRESSED ESCAPE" << endl;
            break;

          case SDLK_q:
            input = 1;
            cout << "PRESSED Q" << endl;
            break;

          case SDLK_s:
            input = 2;
            cout << "PRESSED S" << endl;
            break;

          case SDLK_d:
            input = 3;
            cout << "PRESSED D  " << endl;
            break;
        }
      }

}
