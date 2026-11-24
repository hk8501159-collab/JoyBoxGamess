# JoyBoxGamess

JoyBoxGamess is an Unreal Engine 5 C++ starter for an open-world exploration game set across an Indian city and village. The project brief calls for PC and Android, player exploration, vehicles, buildings, and missions.

## What is in this starter

- A native Unreal project and C++ game module.
- A third-person character with keyboard and mouse movement, camera look, jump, and sprint.
- A game mode that creates a player start and a temporary city-to-village blockout when play begins.
- A short design brief and a practical build order in [`Docs/`](Docs/).
- Empty content folders for maps, characters, environment, vehicles, UI, and missions.

The blockout is made from Unreal's built-in cube mesh so the source can be reviewed without art assets. It is a greybox, not a finished world. This starter contains no packaged game, binary Unreal map, vehicle system, mission system, mobile touch controls, or final art.

## Open and run

1. Install an Unreal Engine 5 version and a C++ toolchain supported by that engine version.
2. Open `JoyBoxGamess.uproject` and let Unreal build the C++ project when prompted.
3. Create a **Basic** level in the editor and save it as `Content/Maps/MainMap`.
4. In **Project Settings → Maps & Modes**, set **Game Default Map** and **Editor Startup Map** to `MainMap`. The project config already selects `JoyBoxGameMode` as the default game mode.
5. Press **Play**. The game mode adds a player start and builds the temporary road, city blocks, and village houses.

The project intentionally starts without a binary `.umap` asset. Unreal creates those assets in the editor; the first setup is to save the basic level described above.

## Controls

| Action | Keyboard / mouse |
| --- | --- |
| Move | W, A, S, D |
| Look | Mouse |
| Jump | Space |
| Sprint | Left Shift |

## Project layout

```text
Config/       Unreal project and input defaults
Content/      Unreal assets, organized into feature folders
Docs/         Game brief and next-step roadmap
Source/       C++ game module, character, game mode, and blockout builder
```

## First development milestones

1. Save and commit the first playable greybox map.
2. Replace placeholder blocks with a small, optimized city and village environment.
3. Add a drivable vehicle and a basic interaction system.
4. Add one mission loop and a simple save/checkpoint flow.
5. Add touch controls and profile the Android build before expanding the world.

See [`Docs/GAME_BRIEF.md`](Docs/GAME_BRIEF.md) and [`Docs/ROADMAP.md`](Docs/ROADMAP.md) for scope and implementation notes.
