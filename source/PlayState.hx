package ;

import flixel.FlxCamera;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.tile.FlxTilemap;
import flixel.ui.FlxButton;
import flixel.util.FlxColor;
import flixel.util.FlxMath;
import openfl.Assets;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	private var tileMap:FlxTilemap;
	static var TILE_WIDTH:Int = 16;
	static var TILE_HEIGHT:Int = 16;
	static var LEVEL_WIDTH:Int = 50;
	static var LEVEL_HEIGHT:Int = 50;
	static var CAMERA_SPEED:Int = 8;
	private var camera:FlxCamera;
	private var cameraFocus:FlxSprite;
	/**
	 * Function that is called up when to state is created to set it up.
	 */
	override public function create():Void
	{
		super.create();
		
		tileMap = new FlxTilemap();
		tileMap.loadMap(Assets.getText("assets/data/map.csv"), "assets/images/tileset.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);
		add(tileMap);
		
		cameraFocus = new FlxSprite();
		cameraFocus.makeGraphic(1, 1, FlxColor.TRANSPARENT);
		add(cameraFocus);
		
		camera = FlxG.camera;
		camera.follow(cameraFocus, FlxCamera.STYLE_LOCKON);
	}

	/**
	 * Function that is called when this state is destroyed - you might want to
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{
		super.update();
		
		// Camera movement
		if (FlxG.keys.anyPressed(["DOWN", "S"])) {
			cameraFocus.y += CAMERA_SPEED;
		}
		if (FlxG.keys.anyPressed(["UP", "W"])) {
			cameraFocus.y -= CAMERA_SPEED;
		}
		if (FlxG.keys.anyPressed(["RIGHT", "D"])) {
			cameraFocus.x += CAMERA_SPEED;
		}
		if (FlxG.keys.anyPressed(["LEFT", "A"])) {
			cameraFocus.x -= CAMERA_SPEED;
		}
		
		// Camera bounds
		if (cameraFocus.x < FlxG.width / 2) {
			cameraFocus.x = FlxG.width / 2;
		}
		if (cameraFocus.x > LEVEL_WIDTH * TILE_WIDTH - FlxG.width / 2) {
			cameraFocus.x = LEVEL_WIDTH * TILE_WIDTH - FlxG.width / 2;
		}
		if (cameraFocus.y < FlxG.height / 2) {
			cameraFocus.y = FlxG.height / 2;
		}
		if (cameraFocus.y > LEVEL_HEIGHT * TILE_HEIGHT - FlxG.height / 2) {
			cameraFocus.y = LEVEL_HEIGHT * TILE_HEIGHT - FlxG.height / 2;
		}
	}
}