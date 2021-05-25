#pragma once
#include "Scene.h"
#include "Structs.h"

namespace dae
{
	class ScoreObserver;
	class TextComponent;
	class WorldGrid;
	class Player;

	class TitleScreenScene final : public dae::Scene
	{
	public:
		TitleScreenScene();

		void Initialize() override;
		void Update() override;
		//virtual void Draw() const override;
	private:
		bool _isCoop = true;

		ScoreObserver* m_obs{ nullptr };
		TextComponent* m_score{ nullptr };
		WorldGrid* m_world{ nullptr };
		Player* m_player{ nullptr };
	};

}