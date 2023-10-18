#include "cucumber.h"
#include <cassert>

void cucumber::Initialize(Model* model) {
	assert(model);
	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.scale_ = {0.0f, 0.0f, 0.0f};
}

void cucumber::Update() {
	worldTransform_.UpdateMatrix();
	worldTransform_.TransferMatrix();
}

void cucumber::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection);
}