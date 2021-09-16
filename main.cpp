#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

class Item{
private:
    string type;
    int price;
public:
    Item(){
        type="gold";
        price=100;
    }
    Item(string type,int price){
        this->type=type;
        this->price=price;
    }
    string getType(){
        return type;
    }
    int getPrice(){
        return price;
    }
};
class Inventory{
private:
    vector<Item> items;
    int size;
public:
    Inventory(){
        items = vector<Item>();
        size=0;
    }
    void changeItem(Item item){
        swap(items[0],item);
    }
    void sortInventory() {
        for(int i=0;i<items.size();i++){
            for(int j=i+1;j<items.size();j++){
                if(items[i].getPrice()>items[j].getPrice()){
                    swap(items[i],items[j]);
                }
            }
        }
    }
    void addItem(Item item){
        if(size==3) {
            sortInventory();
            if(items[0].getPrice()<item.getPrice()) changeItem(item);
        }
        else {
            items.push_back(item);
            size++;
        }
    }

};
class Character{
private:
    int HP ;
    int attack;
    int exp ;
    int maxHP ;
    int money ;
    int forUp;
    string name  ;
    Inventory inventory;
public:
    Character(){
        HP=100;
        attack=10;
        exp=0;
        maxHP=100;
        money=0;
        forUp=100;
        name="Default";
        inventory = Inventory();
    }

    Character(const string &name) : name(name) {}

    Character(int HP,int attack,int exp,int maxHP,int money,string name) {
        this->HP = HP;
        this->attack = attack;
        this->exp = exp;
        this->maxHP = maxHP;
        this->money = money;
        this->name = name;
        forUp = 100;
    }

    int getHp() const {
        return HP;
    }

    void setHp(int hp) {
        HP = hp;
    }

    int getAttack() const {
        return attack;
    }

    void setAttack(int attack) {
        Character::attack = attack;
    }

    int getExp() const {
        return exp;
    }

    void setExp(int exp) {
        Character::exp = exp;
    }

    int getMaxHp() const {
        return maxHP;
    }

    void setMaxHp(int maxHp) {
        maxHP = maxHp;
    }

    int getMoney() const {
        return money;
    }

    void setMoney(int money) {
        Character::money = money;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Character::name = name;
    }
    void levelUp(){
        maxHP+=maxHP/10;
        exp=0;
        attack+=5;
        HP=maxHP;
        forUp+=(forUp/2);
    }
};
class Game{
private:
    Character hero;
public:
    Game(){
       hero = Character();
    }
    const Character &getHero() const {
        return hero;
    }

    Game( Character newHero){
        hero = Character(newHero.getHp(),newHero.getAttack(),newHero.getExp(),newHero.getMaxHp(),newHero.getMoney(),newHero.getName());
    }

    void createHero(){
        cout<<"Enter Character's name: ";
        string name;
        cin>>name;
        hero = Character(name);
    }
    void playFromSaved(){

    }
    bool fight(Character enemy){
        int a=0;
        while(enemy.getHp()>0&&hero.getHp()>0){
            if(a==0) {
                enemy.setHp(enemy.getHp()-hero.getAttack());
                a=1;
                cout<<enemy.getName()<<"'s HP is "<<enemy.getHp()<<"\n";
            }
            else {
                hero.setHp(hero.getHp()-enemy.getAttack());
                a=0;
                cout<<hero.getName()<<"'s HP is "<<hero.getHp()<<"\n";
            }
        }
        if(enemy.getHp()<=0) return true;
        else return false;
    }
};
void explore(Character hero){
    Game game;
    Character enemy;
    int a;
    a = abs(rand()%3);
    if(a == 0){
        hero.inventory.addItem() ;
    }
    else if(a == 1){
        hero.setMoney(hero.getMoney()+abs(rand()%100));
    }
    else {
        game.fight(enemy) ;
    }
}
int main() {
    int d;
    cout<<"1. New Game\n2.Play Saved Game\n3.Quit Game";
    cout<<"\nEnter your choice: ";
    cin>>d;
    Game game;
    if(d==1){
        game.createHero();
    }
    Character Kainar =  Character (100,20,56,100,2000,"Kainar");
    Game ourGame = Game (Kainar);
    Character Kamila =  Character (100,15,56,100,2000,"Kamila");
    if(ourGame.fight(Kamila)) cout<<ourGame.getHero().getName()<<" won";
    else cout<<Kamila.getName()<<" won";

}
