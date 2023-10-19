#include "cucumber.h"
#include"Mymath.h"
#include <cassert>

void cucumber::Initialize(Model* model) {
	assert(model);
	model_ = model;

	for (int i = 0; i < 100; i++) {
		
		worldTransform_[i].scale_ = {1.0f, 1.0f, 4.0f};
		worldTransform_[i].translation_ = {(float)i,0,0};
		worldTransform_[i].rotation_ = {0, 3.14f/2.0f, 0};
		worldTransform_[i].Initialize();
	}
	
}

void cucumber::Update() {
	Move();
	Born();
	for (int i = 0; i < 100; i++) {
		worldTransform_[i].UpdateMatrix();
	}
}

void cucumber::Start(){
	for (int i = 0; i < 100; i++) {
		alive_[i] = 0;
	}
}

void cucumber::Move(){
	for (int i = 0; i < 100; i++) {
	
		if (alive_[i] == 1) {
			worldTransform_[i].translation_.x -= 0.1f;
			if (worldTransform_[i].translation_.x <= -8) {
				alive_[i] = 0;
			}
		}
	}
};

void cucumber::Born(){ 
	time_ -= 1;
	if (time_ == 0) {
		time_ = 2;
		for (int i = 0; i < 100; i++) {
			if (alive_[i] == 0) {  
				alive_[i] = 1;
				worldTransform_[i].translation_ = {12.0f, 0, 0};
				break;
			}
		}
	}
	

};

void cucumber::Space() { 
	if (input_->PushKey(DIK_SPACE)) {
		count_ += 1;
	}
};

void cucumber::Draw(const ViewProjection& viewProjection) {
	for (int i = 0; i < 100; i++) {
		if (alive_[i] == 1) {
       	model_->Draw(worldTransform_[i], viewProjection);
		}
	}
}