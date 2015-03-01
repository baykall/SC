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

enum State {
	Paused;
	Running;
}


class PlayState extends FlxState{
	private var tileMap:FlxTilemap;
	static var TILE_WIDTH:Int = 32;
	static var TILE_HEIGHT:Int = 32;
	static var LEVEL_WIDTH:Int = 50;
	static var LEVEL_HEIGHT:Int = 50;
	static var CAMERA_SPEED:Int = 8;

	private var camera:FlxCamera;
	private var cameraFocus:FlxSprite;
	private var hud:HUD;

	private var time:Time;
	private var state:State;

	override public function create():Void{
		super.create();
		
		tileMap = new FlxTilemap();
		tileMap.loadMap(Assets.getText("assets/data/map.csv"), "assets/images/terrain.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);		
		add(tileMap);
		
		cameraFocus = new FlxSprite();
		cameraFocus.makeGraphic(1, 1, FlxColor.TRANSPARENT);
		add(cameraFocus);
		
		camera = FlxG.camera;
		camera.follow(cameraFocus, FlxCamera.STYLE_LOCKON);

		hud = new HUD();
		add(hud);

		time = new Time(12,"January",1678,20);
		state = Running;
	}


	override public function destroy():Void{
		super.destroy();
	}

	override public function update():Void{
		super.update();

		move_camera();
		bound_camera();
		input_keyboard();
		
		if(state == Running)
			update_time();

		/*
		if(time%100==0){
			tileMap.setTile(3, 3, 0, true);		
		}
		*/

	}

	public function input_keyboard(){
	    if (FlxG.keys.justPressed.SPACE){
			if(state == Running)
				state = Paused;
			else
				state = Running;				
	    }	

	}

	public function update_time():Void{
		var calendar_day;
		time.update();
		calendar_day = time.calendar_day;
		hud.update_time(calendar_day);
	}

	public function move_camera():Void{
		if (FlxG.keys.anyPressed(["DOWN", "S"]))
			cameraFocus.y += CAMERA_SPEED;
		if (FlxG.keys.anyPressed(["UP", "W"]))
			cameraFocus.y -= CAMERA_SPEED;
		if (FlxG.keys.anyPressed(["RIGHT", "D"]))
			cameraFocus.x += CAMERA_SPEED;
		if (FlxG.keys.anyPressed(["LEFT", "A"])) 
			cameraFocus.x -= CAMERA_SPEED;
	}

	public function bound_camera():Void{
		if (cameraFocus.x < FlxG.width / 2) 
			cameraFocus.x = FlxG.width / 2;
		else if (cameraFocus.x > LEVEL_WIDTH * TILE_WIDTH - FlxG.width / 2) 
			cameraFocus.x = LEVEL_WIDTH * TILE_WIDTH - FlxG.width / 2;
		if (cameraFocus.y < FlxG.height / 2) 
			cameraFocus.y = FlxG.height / 2;
		else if (cameraFocus.y > LEVEL_HEIGHT * TILE_HEIGHT - FlxG.height / 2)
			cameraFocus.y = LEVEL_HEIGHT * TILE_HEIGHT - FlxG.height / 2;
	}

}