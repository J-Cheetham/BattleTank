# BattleTank
Prototype for testing movement, aiming, firing and AI pathfinding in Unreal.

Controls:

Aim: Right joystick

Move: Left joystick / Gamepad Left & Right Shoulder

Fire: Gamepad Face Button Left (XBox X)

Swap Camera: Gamepad Face Button Top (XBox Y)

Quit: Gamepad Back Button


Know bugs:

Tank_BP has a couple of bugs. 

TankTrackLeft/Right can lose their static mesh (tank_fbx_Track) as well as the physics material. Collision presets need to be set to OverlapAllDynamic.

TankAiming1 can forget the Projectile Blueprint (Projectile_BP) in Setup.
