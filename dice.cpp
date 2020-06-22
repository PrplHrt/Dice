#include <iostream>
#include <ctime>
#include <limits>

int Dice(int side);
void Highest(int &total);
void Add(int &total);
int Side();
void Stats();
int Highest(int all,int highest,int side);

int main(){
  srand(time(NULL));
  int total{0}, choice{0};

  std::cout << "Welcome to this BASIC AS BREAD dice function!\n";

  //Menu
  std::cout << "What would you like to do?\n\t1. Highest of a number of rolls\n\t2. Add a few die and subtract some\n\t3. Roll just one dice (BASIC)\n\t4. STAT rolling go brrrrr\n";
  while(true)
  {
    if(std::cin >> choice && choice > 0 && choice < 5)
    {
      std::cout << "Ayt leggo->\n";
      break;
    }
    else
    {
      std::cout << "Now that wasn't nice. Bad Input >:(\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Another one: ";
    }
  }

  switch(choice)
  {
    case 1:
      Highest(total);
      break;
    case 2:
      Add(total);
      break;
    case 3:
      Dice(Side());
      break;
    case 4:
      Stats();
  }

  if(choice != 4)
    std::cout << "Here's your result: " << total << std::endl;

  std::cout << "Thanks :3\n";

  return 0;
}

//Stat roll
void Stats(){
  std::cout << "Hey you want some STATS???? I'll give you STATS!!!!\n";

  for(int i{1}; i <= 6; i++)
  {
    std::cout << "STAT " << i << ": " << Highest(4, 3, 6) << '\n';
  }
}

//Take highest X of Y rolls
void Highest(int &total){
  total = 0;

  int side = Side();

  int all{0};
  std::cout << "Ayt, how many die we rolling: ";
  while(true)
  {
    if(std::cin >> all && all > 0)
    {
      std::cout << "Coolio!\n";
      break;
    }
    else
    {
      std::cout << "Bruh... Only numbers, and not less than one...\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Now do it again: ";
    }
  }

  int* rolls = new int[all];

  for(int i{0}; i < all; i++)
  {
    rolls[i] = Dice(side);
  }

  int highest{0};
  std::cout << "So how many we actually taking: ";
  while(true)
  {
    if(std::cin >> highest && highest >= 0 && highest < all)
    {
      std::cout << "Coolio!\n";
      break;
    }
    else
    {
      std::cout << "Bruh... Only numbers... and you cannot pick more die than you have\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Now do it again: ";
    }
  }

  int temp{0};
  for(int i{0}; i<(all-1); i++)
  {
    for(int j{i+1}; j < all; j++)
    {
      if(rolls[i] < rolls[j])
      {
        temp = rolls[i];
        rolls[i] = rolls[j];
        rolls[j] = temp;
      }
    }
  }

  for(int i{0}; i < highest; i++)
  {
    total += rolls[i];
  }

  delete[] rolls;
  }

//Add and subtract
void Add(int &total){
  total = 0;

  int side = Side();

  int add{0};
  std::cout << "First enter how many dice you want to roll and add: ";
  while(true)
  {
    if(std::cin >> add && add > 0)
    {
      std::cout << "Coolio!\n";
      break;
    }
    else
    {
      std::cout << "Bruh... Only numbers, and not less than one...\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Now do it again: ";
    }
  }

  for(int i{0}; i < add; i++)
  {
    total += Dice(side);
  }

  int minus{0};
  std::cout << "Now, all you gotta do is tell me how many dice you wanna roll to subtract from the addition you just did: ";
  std::cin >> minus;
  while(true)
  {
    if(std::cin >> minus && minus < add && minus > 0)
    {
      std::cout << "Coolio!\n";
      break;
    }
    else
    {
      std::cout << "Bruh... Only numbers, and not less than one... and for goodness' sake don't subtract more dice than you add :(\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Now do it again: ";
    }
  }

  for(int i{0}; i < minus; i++)
  {
    total -= Dice(side);
  }

}


int Side(){
  int side{0};
  std::cout << "Real quick how many sides are in the die: ";
  while(true)
  {
    if(std::cin >> side)
    {
      switch (side)
      {
        case 4:
        case 6:
        case 8:
        case 10:
        case 12:
        case 20:
        case 100:
          std::cout << "Arigatou!\n";
          return side;
        default:
          std::cout << "There are no die with " << side << " sides\n AGAIN!: ";
        }
      }
      else
      {
        std::cout << "You trying to crash this thing?\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Once more bugger: ";
      }
    }

}


//Dice function
int Dice(int side){
    //result variable to output the result
    int result{ 0 };
    //Limit function to only allow 4, 6, 8, 10, 12, 20, 100 sided die
    switch (side)
    {
    case 4:
    case 6:
    case 8:
    case 10:
    case 12:
    case 20:
    case 100:
        result = ((rand() % side) + 1); //Add 1 to result since '0' is not a possible role
        //std::cout << "Rolled " << side << "-sided die, result: " << result << std::endl;
        return result;
    default:
        return 0;
    }
}

int Highest(int all,int highest,int side){
  int total{0};

  int* rolls = new int[all];

  for(int i{0}; i < all; i++)
  {
    rolls[i] = Dice(side);
  }

  int temp{0};
  for(int i{0}; i<(all-1); i++)
  {
    for(int j{i+1}; j < all; j++)
    {
      if(rolls[i] < rolls[j])
      {
        temp = rolls[i];
        rolls[i] = rolls[j];
        rolls[j] = temp;
      }
    }
  }

  for(int i{0}; i < highest; i++)
  {
    total += rolls[i];
  }

  delete[] rolls;
  return total;
  }
