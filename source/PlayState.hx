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
import flixel.util.FlxPath;
import flixel.util.FlxPoint;
import flixel.FlxObject;

import openfl.Assets;

enum State {
	Paused;
	Running;
}

class PlayState extends FlxState{
	// Static variables
	static var TILE_WIDTH:Int = 64;
	static var TILE_HEIGHT:Int = 64;
	static var LEVEL_WIDTH:Int = 50;
	static var LEVEL_HEIGHT:Int = 50;
	static var PIXEL_WIDTH:Int = TILE_WIDTH * LEVEL_WIDTH;
	static var PIXEL_HEIGHT:Int = TILE_HEIGHT * LEVEL_HEIGHT;	
	static var CAMERA_SPEED:Int = 8;

	// Graphics
	private var terrain:FlxTilemap;
	private var plants:FlxTilemap;
	private var roads:FlxTilemap;	
	private var cities:FlxTilemap;		

	// Camera
	private var camera:FlxCamera;
	private var cameraFocus:FlxSprite;

	// Graphic Parameters
	private var font:String;
	private var topButtonsSize:Int;
	private var timeSize:Int;
	private var HUDHeight:Int;
	
	// HUD
	private var hud:HUD;

	// Buttons	
	private var companyButton:FlxButton;	
	private var resourcesButton:FlxButton;	
	private var optionsButton:FlxButton;

	// Sprites
	//private var trucks:Array<FlxSprite>;
	//private var truck_paths:Array<FlxPath>;
	private var truck:FlxSprite;
	private var truck_path:FlxPath;	

	// Game engine
	private var time:Time;
	private var state:State;


	override public function create():Void{
		super.create();
		
		init_parameters();
		init_graphics();	
		init_camera();	
		init_HUD();
		init_buttons();
		init_time();	

		create_truck();
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

		if (!truck_path.finished && truck_path.nodes!=null) {
			if (truck_path.angle == 0)
				truck.animation.play("up");
			else if (truck_path.angle == 180) 
				truck.animation.play("down");
			else if (truck_path.angle == 90) 
				truck.animation.play("right");
			else if (truck_path.angle == -90) 
				truck.animation.play("left");
			
		} 
		else {
			truck.animation.curAnim.curFrame = 0;
			truck.animation.curAnim.stop();
		}			
	
	}

	public function create_truck(){

		truck = new FlxSprite(25 * TILE_WIDTH, 33 * TILE_HEIGHT);
		truck.loadGraphic("assets/images/truck.png", true, 64, 64);
		truck.animation.add("left", [0]);	
		truck.animation.add("right", [1]);			
		truck.animation.add("down", [2]);
		truck.animation.add("up", [3]);		
		
		add(truck);

		truck_path = new FlxPath();		
	
		var nodes:Array<FlxPoint> = roads.findPath(FlxPoint.get(truck.x, truck.y), FlxPoint.get(14.5 * TILE_WIDTH, 5.5 * TILE_HEIGHT));

		if (nodes != null) 
			truck_path.start(truck, nodes);
		
	}

	public function init_parameters(){
		font = "Quicksand-Bold.otf";
		topButtonsSize = 24;
		timeSize = 18;
		HUDHeight = 40;
	}

	public function init_graphics(){
		terrain = new FlxTilemap();
		terrain.loadMap(Assets.getText("assets/data/terrain_map.csv"), "assets/images/terrain.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);	
		add(terrain);	
	
		plants = new FlxTilemap();
		plants.loadMap(Assets.getText("assets/data/resources_map.csv"), "assets/images/resources.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);				
		add(plants);

		roads = new FlxTilemap();
		roads.loadMap(Assets.getText("assets/data/roads_map.csv"), "assets/images/roads.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);				
		add(roads);	

		roads.setTileProperties(0, FlxObject.ANY);	
		for(i in 1...8)
			roads.setTileProperties(i, FlxObject.NONE);			

		cities = new FlxTilemap();
		cities.loadMap(Assets.getText("assets/data/cities_map.csv"), "assets/images/cities.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);				
		add(cities);		

	}

	public function init_camera(){
		cameraFocus = new FlxSprite();
		cameraFocus.makeGraphic(1, 1, FlxColor.TRANSPARENT);
		cameraFocus.x = PIXEL_WIDTH/2;
		cameraFocus.y = PIXEL_HEIGHT/2 + 400;
		add(cameraFocus);

		camera = FlxG.camera;
		camera.follow(cameraFocus, FlxCamera.STYLE_LOCKON);	
	}

	public function init_HUD(){
		hud = new HUD(font, timeSize, HUDHeight);
		add(hud);		
	}

	public function init_buttons(){
		companyButton = new FlxButton(10, 0, "Company", goCompany);
		companyButton.label.setFormat("assets/fonts/" + font, topButtonsSize, FlxColor.WHITE, "left");
		companyButton.loadGraphic("assets/images/empty.png");
		add(companyButton);	

		resourcesButton = new FlxButton(160, 0, "Resources", goResources);
		resourcesButton.label.setFormat("assets/fonts/" + font, topButtonsSize, FlxColor.WHITE, "left");
		resourcesButton.loadGraphic("assets/images/empty.png");
		add(resourcesButton);	

		optionsButton = new FlxButton(310, 0, "Options", goOptions);
		optionsButton.label.setFormat("assets/fonts/" + font, topButtonsSize, FlxColor.WHITE, "left");
		optionsButton.loadGraphic("assets/images/empty.png");
		add(optionsButton);							
	}	

	public function init_time(){
		time = new Time(12, "January", 1678, 100);
		state = Running;	
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

	private function goCompany():Void {
		FlxG.switchState(new MenuState());
	}	

	private function goResources():Void {
		FlxG.switchState(new MenuState());
	}	

	private function goOptions():Void {
		FlxG.switchState(new MenuState());
	}			

}