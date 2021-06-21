// 242-ZombieBuster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Classes.h"

int DiceRoll()
{
    srand(time(0));
    int dice = (int)(1 + rand() % 6);
    return dice;
}

void printWarriorHealthBar(Warrior w)
{
    int bars;
    bars = (w.getLife() * 10) / (w.getMaxLife());
    if (((w.getLife() * 10) % (w.getMaxLife())) != 0) { bars++; }
    if (w.getLife() <= 0) { bars = 0; }
    cout << "|";
    for (int i = 0; i < 10; i++)
    {
        if (i < bars) cout << "*";
        else cout << "-";
    }
    cout << "|";
}

void printZombieHealthBar(Zombie z)
{
    int bars;
    bars = (z.getZombieLife() * 10) / (z.getZombieMaxLife());
    if (((z.getZombieLife() * 10) % (z.getZombieMaxLife())) != 0) { bars++; }
    if (z.getZombieLife() <= 0) { bars = 0; }
    cout << "|";
    for (int i = 0; i < 10; i++)
    {
        if (i < bars) cout << "*";
        else cout << "-";
    }
    cout << "|";
}

void Battle(Warrior *w, Zombie z)
{
    cout << "Battle Start!!!\nChichonne\tLarge Zombie\n";
    printWarriorHealthBar(*w);
    cout << "\t";
    printZombieHealthBar(z);
    cout << "\n\n";
    while ((w->getLife() > 0) && (z.getZombieLife() > 0))
    {
        cout << "Chichonne attacks for 5 Damage\n";
        z.setZombieLife(z.getZombieLife() - 5);
        cout << "Chichonne\tLarge Zombie\n";
        printWarriorHealthBar(*w);
        cout << "\t";
        printZombieHealthBar(z);
        cout << "\n\n";
        cout << "Large Zombie attack for " << z.getZombieDamage() << " Damage\n";
        w->setLife(w->getLife() - z.getZombieDamage());
        cout << "Chichonne\tLarge Zombie\n";
        printWarriorHealthBar(*w);
        cout << "\t";
        printZombieHealthBar(z);
        cout << "\n\n";
    }
    cout << "Dice Roll : " << DiceRoll() << endl;
    w->setLife(w->getLife() - z.getZombieDamage());
}

int main()
{
    Derick Dboi;
    Chichonne Cboi;
    LargeZombie lz;

    Battle(&Cboi, lz);
    cout << Cboi.getLife();


    

    /*
    cout << "\nDerick : " << Dboi.getSize() << " " << Dboi.getSymbol() << " " << Dboi.getLife() << " " << Dboi.getAmmo();
    cout << "\nChichonne : " << Cboi.getSize() << " " << Cboi.getSymbol() << " " << Cboi.getLife() << " " << Cboi.getAmmo();

    cout << "\n\nLarge Health";
    LargeMedKit a;
    Cboi = a.Effect(Cboi);
    cout << "\nChichonne : " << Cboi.getSize() << " " << Cboi.getSymbol() << " " << Cboi.getLife() << " " << Cboi.getAmmo();

    cout << "\n\nSmall Health";
    SmallMedKit b;
    Dboi = b.Effect(Dboi);
    cout << "\nDerick : " << Dboi.getSize() << " " << Dboi.getSymbol() << " " << Dboi.getLife() << " " << Dboi.getAmmo();

    cout << "\n\nAmmunaation";
    Ammunation c;
    Dboi = c.Effect(Dboi);
    cout << "\nDerick : " << Dboi.getSize() << " " << Dboi.getSymbol() << " " << Dboi.getLife() << " " << Dboi.getAmmo();

    LargeZombie lz;
    cout << "\nLarge Zombie : " << lz.getSize() << " " << lz.getSymbol() << " " << lz.getZombieLife() << " " << lz.getZombieDamage() << " " << lz.getZombieScore();
    
    MediumZombie mz;
    cout << "\nMedium Zombie : " << mz.getSize() << " " << mz.getSymbol() << " " << mz.getZombieLife() << " " << mz.getZombieDamage() << " " << mz.getZombieScore();
   
    SmallZombie sz;
    cout << "\nSmall Zombie : " << sz.getSize() << " " << sz.getSymbol() << " " << sz.getZombieLife() << " " << sz.getZombieDamage() << " " << sz.getZombieScore();
    cout << "\n\n";
    */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
