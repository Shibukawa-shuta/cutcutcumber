#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "cucumber.h"
#include "manaita.h"
//#include "DebugText.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {
	/*DebugText* debugText_ = nullptr;*/

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;


	WorldTransform worldTransform_;
	ViewProjection viewProjection_;

	std::unique_ptr<Model> cucumberModel_;
	std::unique_ptr<cucumber> cucumber_;

	std::unique_ptr<Model> manaitaModel_;
	std::unique_ptr<manaita> manaita_;
	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
