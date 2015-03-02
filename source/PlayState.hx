package;

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
	//Static Variables
	static var TILE_WIDTH:Int = 64;
	static var TILE_HEIGHT:Int = 64;
	static var LEVEL_WIDTH:Int = 50;
	static var LEVEL_HEIGHT:Int = 50;
	static var PIXEL_WIDTH:Int = TILE_WIDTH * LEVEL_WIDTH;
	static var PIXEL_HEIGHT:Int = TILE_HEIGHT * LEVEL_HEIGHT;	
	static var CAMERA_SPEED:Int = 8;

	//Graphics
	private var terrain:FlxTilemap;
	private var plants:FlxTilemap;

	private var camera:FlxCamera;
	private var cameraFocus:FlxSprite;
	private var hud:HUD;

	//Game engine
	private var time:Time;
	private var state:State;

	override public function create():Void{
		super.create();
		
		terrain = new FlxTilemap();
		terrain.loadMap(Assets.getText("assets/data/terrain_map.csv"), "assets/images/terrain.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);	
		add(terrain);		
		plants = new FlxTilemap();
		plants.loadMap(Assets.getText("assets/data/plants_map.csv"), "assets/images/plants.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);				
		add(plants);
		
		cameraFocus = new FlxSprite();
		cameraFocus.makeGraphic(1, 1, FlxColor.TRANSPARENT);
		cameraFocus.x = PIXEL_WIDTH/2;
		cameraFocus.y = PIXEL_HEIGHT/2;
		add(cameraFocus);

		
		camera = FlxG.camera;
		camera.follow(cameraFocus, FlxCamera.STYLE_LOCKON);

		hud = new HUD(FlxG.width);
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

		//terrain.setTile(3, 3, 0, true);		

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