#include "GameScene.h"
#include "TextureManager.h"
#include"ImGuiManager.h"
#include <cassert>


GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {


	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	//ワールド
	worldTransform_.Initialize();
	viewProjection_.translation_ = {-2.0f, 5.0f, -9.0f};
	viewProjection_.rotation_ = {3.14f/10.0f,3.14f/10.0f,0.0f};
	
	//
	viewProjection_.Initialize();

	// きゅうりの作成
	cucumber_ = std::make_unique<cucumber>();
	cucumberModel_.reset(Model::CreateFromOBJ("cucumber", true));
	cucumber_->Initialize(cucumberModel_.get());
	//まな板の作成
	manaita_ = std::make_unique<manaita>();
	manaitaModel_.reset(Model::CreateFromOBJ("manaita", true));
	manaita_->Initialize(manaitaModel_.get());
}

void GameScene::Update() {
	cucumber_->Update(); 
	manaita_->Update();

	ImGui::Begin("View");
	ImGui::DragFloat3("tr", &viewProjection_.translation_.x, 0.1f);
	ImGui::DragFloat3("rot", &viewProjection_.rotation_.x, 0.1f);
	ImGui::End();
	
	worldTransform_.UpdateMatrix();

}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	/*for (cucumber* cucumber : cucumber_)
	{*/
		
	
	
	 cucumber_->Draw(viewProjection_);
	 manaita_->Draw(viewProjection_);
	
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	/*debugText_->Print("", 200, 10, 2);*/

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
