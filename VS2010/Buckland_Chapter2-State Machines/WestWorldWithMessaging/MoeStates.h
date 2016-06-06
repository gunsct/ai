#ifndef MOE_STATES_H
#define MOE_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MoeStates.h
//
//  Desc:   All the states that can be assigned to the Moe class
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"

class Moe;



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class MoeGlobalState : public State<Moe>
{  
private:
  
  MoeGlobalState(){}

  //copy ctor and assignment should be private
  MoeGlobalState(const MoeGlobalState&);
  MoeGlobalState& operator=(const MoeGlobalState&);
 
public:

  //this is a singleton
  static MoeGlobalState* Instance();
  
  virtual void Enter(Moe* moe){}

  virtual void Execute(Moe* moe);

  virtual void Exit(Moe* moe){}

  virtual bool OnMessage(Moe* moe, const Telegram& msg);
};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class DoBarWork : public State<Moe>
{
private:

  DoBarWork(){}
  
  //copy ctor and assignment should be private
  DoBarWork(const DoBarWork&);
  DoBarWork& operator=(const DoBarWork&);

public:

  //this is a singleton
  static DoBarWork* Instance();
  
  virtual void Enter(Moe* moe);

  virtual void Execute(Moe* moe);

  virtual void Exit(Moe* moe);
  
  virtual bool OnMessage(Moe* moe, const Telegram& msg);

};



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class BringAlcohol : public State<Moe>
{
private:
  
  BringAlcohol(){}

  //copy ctor and assignment should be private
  BringAlcohol(const BringAlcohol&);
  BringAlcohol& operator=(const BringAlcohol&);
 
public:

  //this is a singleton
  static BringAlcohol* Instance();
  
  virtual void Enter(Moe* moe);

  virtual void Execute(Moe* moe);

  virtual void Exit(Moe* moe);

  virtual bool OnMessage(Moe* moe, const Telegram& msg);

};

//------------------------------------------------------------------------
class MakeDrink : public State<Moe>
{
private:
  
  MakeDrink(){}

  //copy ctor and assignment should be private
  MakeDrink(const MakeDrink&);
  MakeDrink& operator=(const MakeDrink&);
 
public:

  //this is a singleton
  static MakeDrink* Instance();
  
  virtual void Enter(Moe* moe);

  virtual void Execute(Moe* moe);

  virtual void Exit(Moe* moe);

  virtual bool OnMessage(Moe* moe, const Telegram& msg);
};


class Phone : public State<Moe>
{
private:
  
  Phone(){}

  //copy ctor and assignment should be private
  Phone(const Phone&);
  Phone& operator=(const Phone&);
 
public:

  //this is a singleton
  static Phone* Instance();
  
  virtual void Enter(Moe* moe);

  virtual void Execute(Moe* moe);

  virtual void Exit(Moe* moe);

  virtual bool OnMessage(Moe* moe, const Telegram& msg);
};
#endif