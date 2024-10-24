//
//  main.cpp
//  one-armed banditvaleria
//
//  Created by Valeria  Bukova on 24.10.2024.
//

#include <iostream>
using namespace std;

class SlotMachine
{
private:
    char symbols[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char reels[3];
    int position;

public:
   
    SlotMachine() : position(0) {}

   
    void spin()
    {
        for (int i = 0; i < 3; ++i)
        {
            reels[i] = symbols[(position + i) % 6];
        }
        position = (position + 1) % 6;
    }

   
    void displayReels() const
    {
        for (int i = 0; i < 3; ++i)
        {
            cout << reels[i] << " ";
        }
        cout << endl;
    }

    
    
    bool checkWin() const
    {
        return (reels[0] == reels[1] && reels[1] == reels[2]);
    }

    
    void showResult() const
    {
        if (checkWin())
        {
            cout << "YOU WIN!" << endl;
        }
        else
        {
            cout << "You lost. Try again!" << endl;
        }
    }
};

int main()
{
    SlotMachine machine;
    char playAgain;

    do
    {
        cout << "Press Enter to spin the reels...";
        cin.get();

        machine.spin();
        machine.displayReels();

        machine.showResult();

        cout << "Play again? (y/n): ";
        cin >> playAgain;
        cin.ignore();
    }
    while (playAgain == 'y' || playAgain == 'Y');  // Повтор игры, если выбрано 'y'

    return 0;
}
