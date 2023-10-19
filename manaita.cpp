#include "Mymath.h"
#include "manaita.h"
#include <cassert>
#include "ImGuiManager.h"
void manaita::Initialize(Model* model) {
	assert(model);
	model_ = model;
	worldTransform_.Initialize();
		
		worldTransform_.translation_ = {2.4f, -1.0f, 1.0f};
	    worldTransform_.rotation_ = {0.0f,55.0f,0.0f};
	    worldTransform_.scale_ = {8.0f, 8.0f, 8.0f};
}

void manaita::Update() {
	    ImGui::Begin("mana");
	    ImGui::DragFloat3("tr", &worldTransform_.translation_.x, 0.1f);
	    ImGui::DragFloat3("rot", &worldTransform_.rotation_.x, 0.1f);
	    ImGui::DragFloat3("sc", &worldTransform_.scale_.x, 0.1f);
	    ImGui::End();
	    worldTransform_.UpdateMatrix();
}

void manaita::Draw(const ViewProjection& viewProjection) {
	    model_->Draw(worldTransform_, viewProjection);
}