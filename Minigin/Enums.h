#pragma once

enum class RequiredKeyState
{
	KeyDown,
	KeyUp,
	KeyPressed,

	Default
};

enum class GameEvent
{
	Default,
	Died,
	Killed,
	TileChanged
};

enum class PlayerIndex
{
	PlayerOne,
	PlayerTwo
};

enum class Input
{
	Default,
	Up,
	Down,
	Left,
	Right
};