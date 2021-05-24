#pragma once
#include "BaseComponent.h"
#include "Texture2D.h"
#include <array>
#include <Structs.h>

namespace dae
{
	enum class TileState
	{
		Spawn, Wall, Tile, ChangedTile
	};

	enum class TileConnections
	{
		Up, Down, Left, Right, Default
	};

	class GridTile : public BaseComponent
	{
	public:
		GridTile(Float2 center);
		~GridTile() override = default;

		GridTile(const GridTile& other) = delete;
		GridTile(GridTile&& other) noexcept = delete;
		GridTile& operator=(const GridTile& other) = delete;
		GridTile& operator=(GridTile&& other) noexcept = delete;

		void Initialize() override;
		void Update() override;
		void Render() override;

		void AddTileConnections(GridTile* tileToLink, TileConnections connection);
		std::array<GridTile*, 4> GetTileConnections() const
		{
			return m_pAdjacentTiles;
		}

		bool HasConnectedTileAt(TileConnections dir) const
		{
			if (m_pAdjacentTiles.at((int)dir) != nullptr)
			{
				return true;
			}
			return false;
		};

		GridTile* GetConnectedTileAt(TileConnections dir) const
		{
			return m_pAdjacentTiles.at((int)dir);
		};

		void SetEdgeCaseRow(bool edgeCase)
		{
			m_edgecaseRow = edgeCase;
		};
		void SetEdgeCaseCol(bool edgeCase)
		{
			m_edgecaseCol = edgeCase;
		}
		
		Float2 GetCenter() const
		{
			return m_tileCenter;
		}
		void SetCenter(Float2 center)
		{
			m_tileCenter = center;
		}

		void ToggleState()
		{
			if (m_state == TileState::Tile)
				m_state = TileState::ChangedTile;
		}
		TileState GetTileState() const
		{
			return m_state;
		}
		void SetTileState(TileState state)
		{
			m_state = state;
		}

		std::shared_ptr<Texture2D> GetDefaultTexture() const
		{
			return m_pTextDefault;
		}
		
	private:
		Float2 m_tileCenter{};
		TileState m_state = TileState::Tile;

		std::array<GridTile*, 4> m_pAdjacentTiles;
		
		std::shared_ptr<Texture2D> m_pTextDefault, m_pTextChanged;

		bool m_NeedUpdate = true;
		bool m_edgecaseRow{ false }, m_edgecaseCol{ false };
	};

}
