#include "Moe.h"

bool Moe::HandleMessage(const Telegram& msg)
{
  return m_pStateMachine->HandleMessage(msg);
}


void Moe::Update()
{
  //set text color to green
  SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
 
  m_pStateMachine->Update();
}

bool Moe::Lonlied()const
{
	if(m_iLonly > MaxLonly)return true;

	else return false;
}

bool Moe::AllSaled()const
{
	if(m_iAlcohol <= 0)return true;

	else return false;
}