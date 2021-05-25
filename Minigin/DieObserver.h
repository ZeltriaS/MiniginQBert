#pragma once
#include "Observer.h"

namespace dae
{
	class DieObserver : public Observer
	{
	public:
		void Notify(Event event) override;
		int GetNumberDied() const
		{
			return m_DiedCounter;
		}

	private:
		int m_DiedCounter{};
		bool m_AchievementTriggered = false;
	};
}