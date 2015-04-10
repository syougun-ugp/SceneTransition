#include "Transition.h"
#include <iostream>


Transition::Transition()
{
}


// 状態を設定してスタートする
void Transition::Start(const State state)
{
	this->state = state;
}

void Transition::Update()
{
	if (state == State::None) return;

	// 終わったら、状態をEndにしてください！

	switch (state)
	{
	case Transition::State::BackOut:

		break;
	
	case Transition::State::BackIn:

		break;
	
	case Transition::State::WhiteOut:
		state = State::End;
		break;
	
	case Transition::State::WhiteIn:
		break;

	default:
		break;
	}
}

bool Transition::IsEnd()
{
	if (state == State::End)
	{
		state = State::None;
		return true;
	}
	return false;
}

