#include <iostream>
using namespace std;

class enemy{
  private:
    float health;
    float damage;
  public:
    float get_HP()const{return health - damage;}
    void set_HP(int h){health = h;};
    void set_damage(int d){damage = d;}
};

class boss: public enemy{
  private:
    int gauge;
    int max_health;
  public:
    int get_max_health()const{return max_health - gauge;}
    void set_max_health(int m){max_health = m;}
    void set_gauge(int g){gauge = g;}
};

int main(){
  //The enemies
  enemy minion_1;
  boss elite;

  int option, target;
  float HP = 0.0;
  float sub_HP_B = 0.0;
  int main_HP_B = 0;
  int bar = 0;
  float damage = 0.0;

  //Initializing minion HP parameters
  minion_1.set_HP(30);
  minion_1.set_damage(0);
  HP = minion_1.get_HP();

  //Initializing boss HP parameters
  elite.set_HP(30);
  elite.set_damage(0);
  elite.set_max_health(2);
  elite.set_gauge(0);
  sub_HP_B = elite.get_HP();
  main_HP_B = elite.get_max_health(); 

  //Battle Intro!
  cout<<"Enemy Encounter!\n";
  cout<<">\tWily is guarding!\n";
  cout<<">\tLiki pulled out Slumber Incense!\n";
  cout<<">\tAll enemies are now asleep!\n";
  cout<<"\nWhat will you do?\n";
  cout<<"Option:\tAttack (1)\n";
  cout<<"\tDefend (2)\n";

  //Selecting the first options
  cin>>option;

  /*//If player chooses to attack
  cout<<"Target:\t Minion (1)\n";
  cout<<"\t Elite (2)\n";
  cin>>target;*/

  //While the Boss is still alive
  while(main_HP_B > 0){

  //Scenario 1 - Both the Boss and Minion is alive
  //		 Boss' HP bars have not dropped yet
    while(main_HP_B > 1 && HP > 0){ 
      //If the player chooses to attack
      if(option == 1){

	//Player chooses target
        cout<<"Target:\t Minion (1)\n";
        cout<<"\t Elite (2)\n";
        cin>>target;
        cout<<">\tPlayer attacks!\n";
      
        //If player selcted minion
        if(target == 1){
          cout<<">\tMinion took 4 damage!\n";
        
          //Damage Calculation
          minion_1.set_HP(HP);
          minion_1.set_damage(4);
          HP = minion_1.get_HP();
        
        }

        //If player selected boss
        else if(target == 2){
	  cout<<">\tElite took 4 damage!\n";	
          //Damage Calculation
          elite.set_HP(sub_HP_B);
          elite.set_damage(4);
          sub_HP_B = elite.get_HP();
        }

      }
      
      //If the player chooses to defend
      else if(option == 2){
        cout<<">\tYou kept your guard up!\n";

        //Damage Calculation
        minion_1.set_HP(HP);
        minion_1.set_damage(0);
        elite.set_HP(sub_HP_B);
        elite.set_damage(0);
        HP = minion_1.get_HP();
        sub_HP_B = elite.get_HP();
      }
    
      //If the minion is still alive
      //If the boss still has HP remaining
      if(HP > 0 && sub_HP_B > 0){
        cout<<">\tEnemies are still fast asleep!";
      }
      //If the player defeats the minion
      else if(HP < 0 && sub_HP_B > 0){  
	//Heading to scenario 2
        cout<<">\tThe Minion has fallen!\n";
        cout<<">\tThe Elite is still fast asleep!";
      }
      //If the player knocks out all of the boss' sub-HP
      else if(sub_HP_B <0){
	//Max HP calculation
	elite.set_gauge(1);
        elite.set_max_health(main_HP_B);
	main_HP_B = elite.get_max_health();
	elite.set_HP(30);
	elite.set_damage(0);
	sub_HP_B = elite.get_HP();

        //Heading to scenario 3
        cout<<">\tThe boss grew weaker!\n";
	cout<<">\tEnemies are still asleep!";
      }

      //Selecting an option again
      cout<<"\nWhat will you do?\n";
      cout<<"Option:\tAttack (1)\n";
      cout<<"\tDefend (2)\n";
      cin>>option;  
    }

    //Scenario 2: Boss is still alive (2 bars remain)
    //		  Minion is dead
    while(main_HP_B > 1 && HP < 0){
      //If the player chooses to attack
      if(option == 1){
	cout<<">\tElite took 4 damage!\n";

        //Damage Calculation
        elite.set_HP(sub_HP_B);
        elite.set_damage(4);
        sub_HP_B = elite.get_HP();
      }
      else if(option == 2){
        //If the player chooses to defend
        cout<<">\tYou kept your guard up!\n";

        //Damage Calculation
        minion_1.set_HP(HP);
        minion_1.set_damage(0);
        elite.set_HP(sub_HP_B);
        elite.set_damage(0);
        HP = minion_1.get_HP();
        sub_HP_B = elite.get_HP();
      }

      //If the boss still has HP remaining
      if(sub_HP_B > 0){
	cout<<">\tThe elite is still asleep!";
      }

      //If the player knocks out all of the boss' sub-HP
      else if(sub_HP_B <0){
        //Max HP calculation
        elite.set_gauge(1);
        elite.set_max_health(main_HP_B);
        main_HP_B = elite.get_max_health();
	elite.set_HP(30);
	elite.set_damage(0);
	sub_HP_B = elite.get_HP();

        //Heading to scenario 4
        cout<<">\tThe Elite grew weaker!\n";
	cout<<">\tThe Elite is still asleep!\n";
      }

      //Selecting an option again
      cout<<"\nWhat will you do?\n";
      cout<<"Option:\tAttack (1)\n";
      cout<<"\tDefend (2)\n";
      cin>>option;
    }

    //Scenario 3: Boss is still alive (1 bar remain)
    //		  Minion is still alive
    while(main_HP_B > 0 && HP > 0){
      //If the player chooses to attack
      if(option == 1){

        //Player chooses target
        cout<<"Target:\t Minion (1)\n";
        cout<<"\t Elite (2)\n";
        cin>>target;
        cout<<">\tPlayer attacks!\n";

        //If player selcted minion
        if(target == 1){
          cout<<">\tMinion took 4 damage!\n";

          //Damage Calculation
          minion_1.set_HP(HP);
          minion_1.set_damage(4);
          HP = minion_1.get_HP();

        }

        //If player selected boss
        else if(target == 2){
	  cout<<">\tElite took 4 damage!\n";

          //Damage Calculation
          elite.set_HP(sub_HP_B);
          elite.set_damage(4);
          sub_HP_B = elite.get_HP();
        }
      }

      //If the player chooses to defend
      else if(option == 2){
        cout<<">\tYou kept your guard up!\n";

        //Damage Calculation
        minion_1.set_HP(HP);
        minion_1.set_damage(0);
        elite.set_HP(sub_HP_B);
        elite.set_damage(0);
        HP = minion_1.get_HP();
        sub_HP_B = elite.get_HP();
      }
    
      //If the minion is still alive
      //If the boss still has HP remaining
      if(HP > 0 && sub_HP_B > 0){
        cout<<">\tEnemies are still fast asleep!";

        //Selecting an option again
        cout<<"\nWhat will you do?\n";
        cout<<"Option:\tAttack (1)\n";
        cout<<"\tDefend (2)\n";
        cin>>option;

      }
      //If the player defeats the minion
      else if(HP < 0 && sub_HP_B > 0){
        //Heading to scenario 2
        cout<<">\tThe Minion has fallen!\n";
        cout<<">\tThe Elite is still fast asleep!";

        //Selecting an option again
        cout<<"\nWhat will you do?\n";
        cout<<"Option:\tAttack (1)\n";
        cout<<"\tDefend (2)\n";
        cin>>option;

      }
      //If the player knocks out all of the boss' sub-HP
      else if(sub_HP_B <0){
        //Max HP calculation
        elite.set_gauge(1);
        elite.set_max_health(main_HP_B);
        main_HP_B = elite.get_max_health();
	elite.set_HP(30);
	elite.set_damage(0);
	sub_HP_B = elite.get_HP();

        //Heading to scenario 5
        cout<<">\tThe Elite has fallen!\n";
      }
    }

    //Scenario 4: Boss is still alive (1 bar remain)
    //		  Minion is dead
    while(main_HP_B > 0 && HP < 0){
      //If the player chooses to attack
      if(option == 1){
        cout<<">\tElite took 4 damage!\n";

        //Damage Calculation
        elite.set_HP(sub_HP_B);
        elite.set_damage(4);
        sub_HP_B = elite.get_HP();
      }
      else if(option == 2){
        //If the player chooses to defend
        cout<<">\tYou kept your guard up!\n";

        //Damage Calculation
        minion_1.set_HP(HP);
        minion_1.set_damage(0);
        elite.set_HP(sub_HP_B);
        elite.set_damage(0);
        HP = minion_1.get_HP();
        sub_HP_B = elite.get_HP();
      }

      //If the boss still has HP remaining
      if(sub_HP_B > 0){
        cout<<">\tThe elite is still asleep!\n";

        //Selecting an option again
        cout<<"\nWhat will you do?\n";
        cout<<"Option:\tAttack (1)\n";
        cout<<"\tDefend (2)\n";
        cin>>option;

      }

      //If the player knocks out all of the boss' sub-HP
      else if(sub_HP_B <0){
        //Max HP calculation
        elite.set_gauge(1);
        elite.set_max_health(main_HP_B);
        main_HP_B = elite.get_max_health();

        //The fight ends
        cout<<">\tThe Elite has fallen!\n";
      }
    }
  }

  //Scenario 5: Boss is dead
  //		Minion is still alive
  if(HP > 0){
    cout<<">\tThe minion woke up!\n";
    cout<<">\tThe minion became scared and ran away!\n";
  }  
  
  cout<<"\t\t\tVICTORY!!!\n!";
}
