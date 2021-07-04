// 242-ZombieBuster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Classes.h"
#include <cstdlib>
#include <fstream>
#include <string>
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
    if (w->getSymbol() == 'D') { cout << "Battle Start!!!\nDerick\t\tZombie\n"; }
    else cout << "Battle Start!!!\nChichonne\tZombie\n";
    printWarriorHealthBar(*w);
    cout << "\t";
    printZombieHealthBar(z);
    cout << "\n\n";
    while ((w->getLife() > 0) && (z.getZombieLife() > 0))
    {

        if ((w->getLife() > 0) && (w->getSymbol() == 'D'))
        {
        choice = BattleMenu(*w);
        if (choice == 1) 
        {
            if (w->getAmmo() > 0) { cout << "Derick uses Gun Shot\n";  Damage = BulletDamage(); w->setAmmo(w->getAmmo() - 1); }
            else { cout << "You tried to fire the gun but it was completely empty\n"; }
        }
        else if (choice == 2) 
        { 
            if (w->getAmmo() > 1) { cout << "Derick uses Gun Salvo\n"; Damage = BulletDamage() + BulletDamage(); w->setAmmo(w->getAmmo() - 2); }
            else if (w->getAmmo() == 1) { "You try to pull off a cool salvo but you only has enough bullets for one shot"; Damage = BulletDamage(); w->setAmmo(w->getAmmo() - 1); }
            else { cout << "You tried to fire the gun but it was completely empty\n"; }
        }
        else if (choice == 3) { cout << "Derick uses Knife\n"; Damage = 2; }
        cout << "Derick attacks for " << Damage << " Damage\n";
        z.setZombieLife(z.getZombieLife() - Damage);
        cout << "Derick\t\tZombie\n";
        printWarriorHealthBar(*w);
        cout << "\t";
        printZombieHealthBar(z);
        cout << "\n\n";
        }

        else if ((w->getLife() > 0) && (w->getSymbol() == 'C'))
        {
            choice = BattleMenu(*w);
            if (choice == 1) 
            { 
                if (w->getAmmo() > 0) { cout << "Chichonne uses Gun Shot\n";  Damage = BulletDamage(); w->setAmmo(w->getAmmo() - 1); }
                else { cout << "You tried to fire the gun but it was completely empty\n"; }
            }
            else if (choice == 2) 
            { 
                if (w->getKills() < 2) { cout << "Chichonne uses Katana Slash\n"; Damage = 4; }
                else { cout << "Chichonne uses Dai-Katana Slash\n"; Damage = 6; }
            }
            cout << "Chichonne attacks for " << Damage << " Damage\n";
            z.setZombieLife(z.getZombieLife() - Damage);
            cout << "Chichonne\tZombie\n";
            printWarriorHealthBar(*w);
            cout << "\t";
            printZombieHealthBar(z);
            cout << "\n\n";
        }

        if (z.getZombieLife() > 0) 
        {
            if (z.getSymbol() == 'L') { cout << "Large Zombie attack for " << z.getZombieDamage() << " Damage\n"; }
            else if (z.getSymbol() == 'M') { cout << "Medium Zombie attack for " << z.getZombieDamage() << " Damage\n"; }
            else { cout << "Small Zombie attack for " << z.getZombieDamage() << " Damage\n"; }
            w->setLife(w->getLife() - z.getZombieDamage());
            if (w->getSymbol() == 'D') {cout << "Derick\t\tZombie\n"; }
            else cout << "Chichonne\tZombie\n";
            printWarriorHealthBar(*w);
            cout << "\t";
            printZombieHealthBar(z);
            cout << "\n\n";
        }
    }
}

int main()
{
    Derick d;
    char c;
    srand(time(0));
    Grid g1(5);
    g1.printGrid();
    cout << "\n==========================================\n";
    for (int i = 0; i < 8; i++)
    {
        c = g1.moveGrid(i, d.getSymbol());
        g1.printGrid();
        cout << "\n\n" << c << endl;
        cout << "\n!==========================================!\n";
    }


    //c = g1.moveGrid(1, d.getSymbol());
    //g1.printGrid();

   // cout << "\n\n" << c << endl;
    /*
    char player;
    char cont = 'Y';
    Derick Dboi;
    Chichonne Cboi;
    LargeZombie lz;
    MediumZombie mz;
    SmallZombie sz;

    Grid g = Grid(10);
    g.printGrid();

    string myText;
    ifstream MyReadFile("Death.txt");

    cout << "Choose your player [Derick | Chichonne] (D/C) : ";
    cin >> player;
    for (; player != 'D' && player != 'C';)
    {
        cout << "Incorrect Choice! Please Choose Again [Derick | Chichonne] (D/C) : ";
        cin >> player;
    }

    while (cont != 'N')
    {
        int currentHealth = 1;
        int score = 0;
        char opponent;
        cout << "\nChoose your opponent : (L)arge Zombie | (M)edium Zombie | (S)mall Zombie : ";
        cin >> opponent;
        if (player == 'D') 
        {
            if (opponent == 'L') { Battle(&Dboi, lz); currentHealth = Dboi.getLife(); Dboi.incKills(); score = Dboi.getKills(); }
            else if (opponent == 'M') { Battle(&Dboi, mz); currentHealth = Dboi.getLife(); Dboi.incKills(); score = Dboi.getKills(); }
            else if (opponent == 'S') { Battle(&Dboi, sz); currentHealth = Dboi.getLife(); Dboi.incKills(); score = Dboi.getKills(); }
            else cout << "\nInccorrect Opponent Option\n";
        }
        else if (player == 'C') 
        { 
            if (opponent == 'L') { Battle(&Cboi, lz); currentHealth = Cboi.getLife(); Cboi.incKills(); score = Cboi.getKills(); }
            else if (opponent == 'M') { Battle(&Cboi, mz); currentHealth = Cboi.getLife(); Cboi.incKills(); score = Cboi.getKills(); }
            else if (opponent == 'S') { Battle(&Cboi, sz); currentHealth = Cboi.getLife(); Cboi.incKills(); score = Cboi.getKills(); }
            else cout << "\nIncorrect Opponent Option\n";
        }
        if (Cboi.getKills() == 2) { cout << "\nChichonnes Katana has been upgraded to a Dai-Katana"; }
        if (currentHealth > 0) { cout << "\nWould you like to fight again? (Y/N) : "; cin >> cont; }
        else {
            cont = 'N'; cout << "Total Kills : " << score << endl; while (getline(MyReadFile, myText)) { cout << myText << endl; }
        }
        if (cont == 'N') { cout << "Total Kills : " << score << endl; };
    }

    // Close the file
    MyReadFile.close();
    */
}
