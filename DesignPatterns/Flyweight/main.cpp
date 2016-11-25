#include<iostream>
#include<string>
#include<map>

using namespace std;

class Character
{
public:
  virtual void Display(int extrinsicState) = 0;

protected:
  char symbol_;
  int width_;
  int height_;
  int ascent_;
  int descent_;
  int extrinsicState_;
};

class CharacterA : public Character
{
public:
  CharacterA()
  {
    symbol_    = 'A';
    width_     = 120;
    height_    = 100;
    ascent_    = 70;
    descent_   = 0;
    extrinsicState_= 0; //initialise
  }
  void Display(int extrinsicState)
  {
    extrinsicState_ = extrinsicState;
    cout<<symbol_<<" (extrinsicState "<<extrinsicState_<<" )"<<endl;
  }
};

class CharacterB : public Character
{
public:
  CharacterB()
  {
    symbol_    = 'B';
    width_     = 140;
    height_    = 100;
    ascent_    = 72;
    descent_   = 0;
    extrinsicState_ = 0; //initialise
  }
  void Display(int extrinsicState)
  {
    extrinsicState_ = extrinsicState;
    cout<<symbol_<<" (extrinsicState "<<extrinsicState_<<" )"<<endl;
  }
};

/* ...*/


class CharacterZ : public Character
{
public:
  CharacterZ()
  {
    symbol_    = 'Z';
    width_     = 100;
    height_    = 100;
    ascent_    = 68;
    descent_   = 0;
    extrinsicState_ = 0; //initialise
  }
  void Display(int extrinsicState)
  {
    extrinsicState_ = extrinsicState;
    cout<<symbol_<<" (extrinsicState "<<extrinsicState_<<" )"<<endl;
  }
};

// The 'FlyweightFactory' class
class CharacterFactory
{
public:
  virtual ~CharacterFactory()
  {
    while(!characters_.empty())
    {
      map<char, Character*>::iterator it = characters_.begin();
      delete it->second;
      characters_.erase(it);
    }
  }
  Character* GetCharacter(char key)
  {
    Character* character = NULL;
    if(characters_.find(key) != characters_.end())
    {
      character = characters_[key];
    }
    else
    {
      switch(key)
      {
      case 'A':
        character = new CharacterA();
        break;
      case 'B':
        character = new CharacterB();
        break;
      //...
      case 'Z':
        character = new CharacterZ();
        break;
      default:
        cout<<"Not Implemented"<<endl;
        throw("Not Implemented");
      }
      characters_[key] = character;
    }
    return character;
  }
private:
  map<char, Character*> characters_;
};


//The Main method
int main()
{
  string document = "AAZZBBZB";
  const char* chars = document.c_str();

  CharacterFactory* factory = new CharacterFactory;

  // extrinsic state
  int extrinsicState = 0;

  // For each character use a flyweight object
  for(size_t i = 0; i < document.length(); i++)
  {
    extrinsicState++;
    Character* character = factory->GetCharacter(chars[i]);
    character->Display(extrinsicState);
  }

  //Clean memory
  delete factory;

  return 0;
}
