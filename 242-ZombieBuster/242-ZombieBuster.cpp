// 242-ZombieBuster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Classes.h"
#include <cstdlib>

int DiceRoll(void)
{
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

int BulletDamage()
{
    int roll = DiceRoll();
    if (roll > 4) { cout << "\nCRITICAL HIT!!!!\n"; return 10; }
    else if (roll < 3) { cout << "\nMinor Scratch\n"; return 2; }
    else { cout << "\nNormal Hit\n"; return 5; }
}

int BattleMenu(Warrior w)
{
    int choice;
    cout << " ____________________________________________________\n";
    cout << "|    ____________________________________________    |\n";
    cout << "|   |                                            |   |\n";
    cout << "|   |      (1) Gun Shot  [Fire One Bullet]       |   |\n";
    if (w.getSymbol() == 'D') 
    {
        cout << "|   |      (2) Gun Salvo [Fire Two Bullets]      |   |\n";
        cout << "|   |      (3) Knife Slash [Knife Melee]         |   |\n";
    }
    else if ((w.getSymbol() == 'C') && (w.getKills() < 2)) { cout << "|   |      (2) Katana Slash [Katana Melee]       |   |\n"; }
    else if ((w.getSymbol() == 'C') && (w.getKills() >= 2)) {cout << "|   |    (2) Dai-Katana Slash [Katana Melee]     |   |\n"; }

    cout << "|   |____________________________________________|   |\n";
    cout << "|____________________________________________________|\n";
    cout << "\n                 Enter Your Choice : ";
    cin >> choice;
    return choice;
}

void Battle(Warrior *w, Zombie z)
{
    int Damage = 0;
    int choice;
    if (w->getSymbol() == 'D') { cout << "Battle Start!!!\nDerick\tLarge Zombie\n"; }
    else cout << "Battle Start!!!\nChichonne\tLarge Zombie\n";
    printWarriorHealthBar(*w);
    cout << "\t";
    printZombieHealthBar(z);
    cout << "\n\n";
    while ((w->getLife() > 0) && (z.getZombieLife() > 0))
    {

        if ((w->getLife() > 0) && (w->getSymbol() == 'D'))
        {
        choice = BattleMenu(*w);
        if (choice == 1) { cout << "Derick uses Gun Shot\n";  Damage = BulletDamage(); }
        else if (choice == 2) { cout << "Derick uses Gun Salvo\n"; Damage = BulletDamage() + BulletDamage(); }
        else if (choice == 3) { cout << "Derick uses Knife\n"; Damage = 2; }
        cout << "Chichonne attacks for " << Damage << " Damage\n";
        z.setZombieLife(z.getZombieLife() - Damage);
        cout << "Chichonne\tLarge Zombie\n";
        printWarriorHealthBar(*w);
        cout << "\t";
        printZombieHealthBar(z);
        cout << "\n\n";
        }

        else if ((w->getLife() > 0) && (w->getSymbol() == 'C'))
        {
            choice = BattleMenu(*w);
            if (choice == 1) { cout << "Chichonne uses Gun Shot\n";  Damage = BulletDamage(); }
            else if ((choice == 2) && (w->getKills() < 2)) { cout << "Chichonne uses Katana Slash\n"; Damage = 4; }
            else if ((choice == 2) && (w->getKills() >= 2)) { cout << "Chichonne uses Dai-Katana Slash\n"; Damage = 6; }
            cout << "Chichonne attacks for " << Damage << " Damage\n";
            z.setZombieLife(z.getZombieLife() - Damage);
            cout << "Chichonne\tLarge Zombie\n";
            printWarriorHealthBar(*w);
            cout << "\t";
            printZombieHealthBar(z);
            cout << "\n\n";
        }

        if (z.getZombieLife() > 0) 
        {
            cout << "Large Zombie attack for " << z.getZombieDamage() << " Damage\n";
            w->setLife(w->getLife() - z.getZombieDamage());
            cout << "Chichonne\tLarge Zombie\n";
            printWarriorHealthBar(*w);
            cout << "\t";
            printZombieHealthBar(z);
            cout << "\n\n";
        }
    }
}

int main()
{
    srand(time(0));
    char player;
    char cont = 'Y';
    Derick Dboi;
    Chichonne Cboi;
    LargeZombie lz;

    cout << "Choose your player [Derick | Chichonne] (D/C) : ";
    cin >> player;


    while (cont != 'N')
    {
        int currentHealth;
        if (player == 'D') { Battle(&Dboi, lz); currentHealth = Dboi.getLife(); Dboi.incKills(); }
        else if (player == 'C') { Battle(&Cboi, lz); currentHealth = Cboi.getLife(); Cboi.incKills(); }
        if (Cboi.getKills() == 2) { cout << "\nChichonnes Katana has been upgraded to a Dai-Katana"; }
        if (currentHealth > 0) { cout << "\nWould you like to fight again? (Y/N) : "; cin >> cont; }
        else { cont = 'N'; }
    }

    

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
