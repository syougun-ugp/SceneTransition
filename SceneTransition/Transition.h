// -----------------------------------------------
// シーンのトランジョン効果 処理
//
// ここで様々な効果をコーディングしていく
// 
// 現在は、状態で効果を見ているが、
// 本来は、オブジェクトを分けるほうが将来性はある
// -----------------------------------------------
#pragma once


class Transition
{
public:
	Transition();

	// 効果の状態
	// 効果をここに追加していく
	enum class State
	{
		None,
		BackOut,
		BackIn,
		WhiteOut,
		WhiteIn,
		End,
	};
	
	// 状態を設定してスタートする
	void Start(const State state);

	void Update();

	// 終了したかの処理
	bool IsEnd();

private:
	// フェード状態
	State state;


};

