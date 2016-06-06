#ifndef MOE_H
#define MOE_H
//------------------------------------------------------------------------
//
//  Name: MinersWife.h
//
//  Desc: class to implement Miner Bob's wife.
//
//  Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

#include <string>

#include "fsm/State.h"
#include "BaseGameEntity.h"
#include "Locations.h"
#include "MoeStates.h"
#include "misc/ConsoleUtils.h"
#include "Miner.h"
#include "MinersWife.h"
#include "fsm/StateMachine.h"
#include "misc/Utils.h"


const int MaxLonly = 10;//최대 외로움
const int MaxHold = 10;//술 최대보유량

class Moe : public BaseGameEntity
{
private:

  //an instance of the state machine class
  StateMachine<Moe>* m_pStateMachine;

  location_type   m_Location;

  bool            m_bSaleing;
  bool m_bBring;
  bool m_bCalling;

  int m_iAlcohol;//술보유량
  int m_iLonly;//외로움 정도

public:

  Moe(int id):m_Location(shack),
                     m_bSaleing(false),
                     BaseGameEntity(id),
					 m_iAlcohol(MaxHold),
					 m_iLonly(0)
                                        
  {
    //set up the state machine
    m_pStateMachine = new StateMachine<Moe>(this);

    m_pStateMachine->SetCurrentState(DoBarWork::Instance());

    m_pStateMachine->SetGlobalState(MoeGlobalState::Instance());
  }

  ~Moe(){delete m_pStateMachine;}


  //this must be implemented
  void          Update();

  //so must this
  virtual bool  HandleMessage(const Telegram& msg);

  StateMachine<Moe>* GetFSM()const{return m_pStateMachine;}

  //----------------------------------------------------accessors
  location_type Location()const{return m_Location;}
  void          ChangeLocation(location_type loc){m_Location=loc;}

  void DecreaseLonly(){m_iLonly =0;}
  void IncreaseLonly(){m_iLonly += 1;}
  void DecreaseAlcohol(){m_iAlcohol -= 1;}
  void IecreaseAlcohol(){m_iAlcohol += 2;}

  bool Lonlied()const;
  bool AllSaled()const;

  int GetAclohol(){return m_iAlcohol;}
  bool          Saleing()const{return m_bSaleing;}
  void          SetSaleing(bool val){m_bSaleing = val;}


   
};

#endif
