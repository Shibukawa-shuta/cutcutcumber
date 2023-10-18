#include "Model.h"
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

private:
	// ワールド変換
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
};
