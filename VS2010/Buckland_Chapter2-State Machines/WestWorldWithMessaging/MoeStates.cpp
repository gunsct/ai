#include "MinersWifeOwnedStates.h"
#include "MinerOwnedStates.h"
#include "MoeStates.h"
#include "Moe.h"
#include "Locations.h"
#include "Time/CrudeTimer.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//-----------------------------------------------------------------------Global state

MoeGlobalState* MoeGlobalState::Instance()
{
  static MoeGlobalState instance;

  return &instance;
}


void MoeGlobalState::Execute(Moe* moe)
{
  //1 in 10 chance of needing the bathroom (provided she is not already
  //in the bathroom)
  if ( moe->AllSaled() == true && !moe->GetFSM()->isInState(*BringAlcohol::Instance()) )
  {
    moe->GetFSM()->ChangeState(BringAlcohol::Instance());
  }

  if(moe->Lonlied() == true && !moe->GetFSM()->isInState(*Phone::Instance()) )
  {
    moe->GetFSM()->ChangeState(Phone::Instance());
  }
}

bool MoeGlobalState::OnMessage(Moe* moe, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

  switch(msg.Msg)
  {
  case Msg_HiMoe:
   {
       cout << "\nMessage handled by " << GetNameOfEntity(moe->ID()) << " at time: " 
       << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);

     cout << "\n" << GetNameOfEntity(moe->ID()) << 
          ": Welcome Bob I'll drink a cool drink";

     moe->GetFSM()->ChangeState(MakeDrink::Instance());
   }

  /* case Msg_CutCall:
   {
       cout << "\nMessage handled by " << GetNameOfEntity(moe->ID()) << " at time: " 
       << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY);

     cout << "\n" << GetNameOfEntity(moe->ID()) << 
          ": Bye Elsa I love you";

     moe->GetFSM()->ChangeState(DoBarWork::Instance());
   }*/

	

   return true;

  }//end switch

  return false;
}

//-------------------------------------------------------------------------DoBarWork

DoBarWork* DoBarWork::Instance()
{
  static DoBarWork instance;

  return &instance;
}


void DoBarWork::Enter(Moe* moe)
{
  cout << "\n" << GetNameOfEntity(moe->ID()) << ": Yeah start saling!";
}


void DoBarWork::Execute(Moe* moe)
{
	if(moe->AllSaled() == false){
	  switch(RandInt(0,2))
	  {
	  case 0:

		cout << "\n" << GetNameOfEntity(moe->ID()) << ": Drink Vodka came out";
		
		break;

	  case 1:

		cout << "\n" << GetNameOfEntity(moe->ID()) << ": Drink Beer came out";

		break;

	  case 2:

		cout << "\n" << GetNameOfEntity(moe->ID()) << ": Drink Gin came out";

		break;
	  }
	  moe->DecreaseAlcohol();
	  if(moe->AllSaled()){
		  moe->GetFSM()->ChangeState(BringAlcohol::Instance());
	  }
	}
}

void DoBarWork::Exit(Moe* moe)
{
}

bool DoBarWork::OnMessage(Moe* moe, const Telegram& msg)
{
  return false;
}

//------------------------------------------------------------------------BringAlcohol

BringAlcohol* BringAlcohol::Instance()
{
  static BringAlcohol instance;

  return &instance;
}


void BringAlcohol::Enter(Moe* moe)
{  
  cout << "\n" << GetNameOfEntity(moe->ID()) << ": hou..."; 
}


void BringAlcohol::Execute(Moe* moe)
{
	if(moe->GetAclohol() != MaxHold){
	 cout << "\n" << GetNameOfEntity(moe->ID()) << ": bring alcohol 2box";
	 moe->IecreaseAlcohol();
	}

  //moe->GetFSM()->RevertToPreviousState();
}

void BringAlcohol::Exit(Moe* moe)
{
  cout << "\n" << GetNameOfEntity(moe->ID()) << ": Excellent!";
  //moe->GetFSM()->ChangeState(DoBarWork::Instance());
}


bool BringAlcohol::OnMessage(Moe* moe, const Telegram& msg)
{
  return false;
}


//------------------------------------------------------------------------CookStew

MakeDrink* MakeDrink::Instance()
{
  static MakeDrink instance;

  return &instance;
}


void MakeDrink::Enter(Moe* moe)
{
  //if not already cooking put the stew in the oven
  if (!moe->Saleing())
  {
     cout << "\n" << GetNameOfEntity(moe->ID()) << ": wait a minute";
  
    //send a delayed message myself so that I know when to take the stew
    //out of the oven
    Dispatch->DispatchMessage(1.5,                  //time delay
                              moe->ID(),           //sender ID
							  ent_Miner_Bob,           //receiver ID
                              Msg_WelcomBob,        //msg
                              NO_ADDITIONAL_INFO); 

    moe->SetSaleing(true);
  }
}


void MakeDrink::Execute(Moe* moe)
{
  cout << "\n" << GetNameOfEntity(moe->ID()) << ": It's your very own potion";
  moe->GetFSM()->RevertToPreviousState();
}

void MakeDrink::Exit(Moe* moe)
{
  SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
  
  cout << "\n" << GetNameOfEntity(moe->ID()) << ": The first cup is service!";
}


bool MakeDrink::OnMessage(Moe* moe, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

  switch(msg.Msg)
  {
   /* case Msg_HiMoe:
    {
      cout << "\nMessage received by " << GetNameOfEntity(moe->ID()) <<
           " at time: " << Clock->GetCurrentTime();

      SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
     
	   cout << "\n" << GetNameOfEntity(moe->ID()) << ": shake! shake!";
      //let hubby know the stew is ready
      Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
                                moe->ID(),
                                ent_Miner_Bob,
                                Msg_WelcomBob,
                                NO_ADDITIONAL_INFO);

      moe->SetSaleing(false);

      moe->GetFSM()->ChangeState(DoBarWork::Instance());               
    }*/

    return true;

  }//end switch

  return false;
}


Phone* Phone::Instance()
{
  static Phone instance;

  return &instance;
}


void Phone::Enter(Moe* moe)
{
  //if not already cooking put the stew in the oven
  if (!moe->Saleing())
  {
    
  
    //send a delayed message myself so that I know when to take the stew
    //out of the oven
    Dispatch->DispatchMessage(1.5,                  //time delay
                              moe->ID(),           //sender ID
							  ent_Elsa,           //receiver ID
							  Msg_HiElasImLonly,        //msg
                              NO_ADDITIONAL_INFO); 

    moe->SetSaleing(true);
  }
}


void Phone::Execute(Moe* moe)
{
  cout << "\n" << GetNameOfEntity(moe->ID()) << ": Um.. hi elsa";
}

void Phone::Exit(Moe* moe)
{
  SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
  
  cout << "\n" << GetNameOfEntity(moe->ID()) << ": ...";
}


bool Phone::OnMessage(Moe* moe, const Telegram& msg)
{
  SetTextColor(BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);

  switch(msg.Msg)
  {
	  case Msg_HiMoeImLonly:
	{
       cout << "\nMessage handled by " << GetNameOfEntity(moe->ID()) << " at time: " 
       << Clock->GetCurrentTime();

     SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);

     cout << "\n" << GetNameOfEntity(moe->ID()) << 
          ": me too i miss you";
   }

    case Msg_CutCall:
    {
      cout << "\nMessage received by " << GetNameOfEntity(moe->ID()) <<
           " at time: " << Clock->GetCurrentTime();

      SetTextColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY);
      cout << "\n" << GetNameOfEntity(moe->ID()) << ": it's a pity";

      moe->SetSaleing(false);

	  moe->DecreaseLonly();
      moe->GetFSM()->ChangeState(DoBarWork::Instance());               
    }


    return true;

  }//end switch

  return false;
}