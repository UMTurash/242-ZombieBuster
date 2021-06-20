// 242-ZombieBuster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Classes.h"

int main()
{
    Derick Dboi;
    Chichonne Cboi;

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
