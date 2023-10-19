#include "Model.h"
#include "Input.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

// きゅうり
class cucumber {
public:
	// 初期化
	void Initialize(Model* model);

	// 更新
	void Update();

	void Draw(const ViewProjection& viewProjection);

	void Start();

	void Move();

	void Born();

	void Space();


private:
	// ワールド変換
	WorldTransform worldTransform_[100];
	// モデル
	Model* model_ = nullptr;

	int alive_[100] = {};
	int time_ = 5;
	int count_ = 0;
	Input* input_ = nullptr;
};
