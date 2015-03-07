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
	public static var TILE_WIDTH:Int = 64;
	public static var TILE_HEIGHT:Int = 64;
	static var LEVEL_WIDTH:Int = 50;
	static var LEVEL_HEIGHT:Int = 50;
	static var PIXEL_WIDTH:Int = TILE_WIDTH * LEVEL_WIDTH;
	static var PIXEL_HEIGHT:Int = TILE_HEIGHT * LEVEL_HEIGHT;	
	static var CAMERA_SPEED:Int = 8;

	// Graphics
	private var terrain:FlxTilemap;
	private var plants:FlxTilemap;
	private var roads:FlxTilemap;	
	private var towns:FlxTilemap;	
	private var terrain_map:String;	
	private var plants_map:String;	
	private var roads_map:String;	
	private var towns_map:String;	
		
	// Camera
	private var camera:FlxCamera;
	private var cameraFocus:FlxSprite;

	// Graphic Parameters
	public static var font:String = "Quicksand-Bold.otf";
	public static var topButtonsSize:Int = 24;
	public static var timeSize:Int = 18;
	public static var HUDHeight:Int = 40;
	
	// HUD
	private var hud:HUD;

	// Buttons	
	private var companyButton:FlxButton;	
	private var resourcesButton:FlxButton;	
	private var optionsButton:FlxButton;
	
	// Game engine
	private var time:Time;
	private var state:State;

	// Game entities
	private var trucks:Array<FlxSprite>;
	private var truck_paths:Array<FlxPath>;
	private var cities:Array<City>;	
	private var city_labels:Array<FlxText>;	

	override public function create():Void{
		super.create();
		
		init_time();	
		init_cities();	

		init_graphics();	
		init_camera();	
		init_HUD();
		init_buttons();

		init_trucks();
	}

	override public function destroy():Void{
		super.destroy();
	}

	override public function update():Void{
		super.update();

		// Game handling
		move_camera();
		bound_camera();
		input_keyboard();

		// Time update
		if(state == Running)
			update_time();
		
		// Game features update
		move_trucks();
		remove_arrived_trucks();
		if(time.moment == NewDay)
			execute_todays_events();

	}

	public function execute_todays_events(){
		if(time.total_days==2)
			ship_truck(26,34,16,6);
		if(time.total_days==3)
			ship_truck(30,19,15,20);
		if(time.total_days==4)
			ship_truck(30,19,15,20);			
	}

	public function move_trucks(){
		for(i in 0...trucks.length){
			if (!truck_paths[i].finished && truck_paths[i].nodes!=null) {
				if (truck_paths[i].angle == 0)
					trucks[i].animation.play("up");
				else if (truck_paths[i].angle == 180) 
					trucks[i].animation.play("down");
				else if (truck_paths[i].angle == 90) 
					trucks[i].animation.play("right");
				else if (truck_paths[i].angle == -90) 
					trucks[i].animation.play("left");
			} 
			else{
				trucks[i].animation.curAnim.curFrame = 0;
				trucks[i].animation.curAnim.stop();
			}
		}		
	}

	public function remove_arrived_trucks(){
		var truck_no:Int;

		truck_no = -1;
		for(i in 0...trucks.length){	
			if(truck_paths[i].finished){
				remove(trucks[i]);		
				truck_no = i;	
			}
		}

		if(truck_no >= 0){
			trucks.splice(truck_no,1);
			truck_paths.splice(truck_no,1);
		}
	}	

	public function ship_truck(from_x,from_y,to_x,to_y){

		var truck:FlxSprite;
		var truck_path:FlxPath;

		truck = new FlxSprite((from_x - 1) * TILE_WIDTH, (from_y - 1) * TILE_HEIGHT);
		truck.loadGraphic("assets/images/truck.png", true, TILE_WIDTH, TILE_HEIGHT);
		truck.animation.add("left", [0]);	
		truck.animation.add("right", [1]);			
		truck.animation.add("down", [2]);
		truck.animation.add("up", [3]);		
		
		trucks.push(truck);

		add(trucks[trucks.length - 1]);

		truck_path = new FlxPath();	
		truck_paths.push(truck_path);	
	
		var nodes:Array<FlxPoint> = roads.findPath(FlxPoint.get(truck.x, truck.y), FlxPoint.get((to_x - 0.5) * TILE_WIDTH, (to_y - 0.5) * TILE_HEIGHT));

		if (nodes != null) 
			truck_paths[truck_paths.length - 1].start(trucks[trucks.length - 1], nodes);

	}

	public function init_trucks(){
		trucks = new Array<FlxSprite>();
		truck_paths = new Array<FlxPath>();
	}

	public function init_graphics(){
		city_labels = new Array<FlxText>();	
		var label:FlxText;

		terrain_map = Assets.getText("assets/data/terrain_map.csv");
		plants_map = Assets.getText("assets/data/resources_map.csv");
		roads_map = Assets.getText("assets/data/roads_map.csv");
		towns_map = get_cities_map();

		terrain = new FlxTilemap();
		terrain.loadMap(terrain_map, "assets/images/terrain.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);	
		add(terrain);	
	
		plants = new FlxTilemap();
		plants.loadMap(plants_map, "assets/images/resources.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);				
		add(plants);

		roads = new FlxTilemap();
		roads.loadMap(roads_map, "assets/images/roads.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);				
		add(roads);	

		roads.setTileProperties(0, FlxObject.ANY);	
		for(i in 1...8)
			roads.setTileProperties(i, FlxObject.NONE);			

		towns = new FlxTilemap();
		towns.loadMap(towns_map, "assets/images/towns.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);				
		add(towns);	

		for(i in 0...cities.length){
			label = new FlxText(cities[i].label_coordinate_x, cities[i].label_coordinate_y);
			label.setFormat("assets/fonts/" + font, timeSize, FlxColor.WHITE, "center");		
			label.text = cities[i].name;
			add(label);

		}				

	}

	public function init_camera(){
		cameraFocus = new FlxSprite();
		cameraFocus.makeGraphic(1, 1, FlxColor.TRANSPARENT);
		cameraFocus.x = PIXEL_WIDTH/2;
		cameraFocus.y = PIXEL_HEIGHT/2;
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

	public function init_cities(){
		cities = new Array<City>();

		var city:City;

		city = new City("Ann Arbor", 14, 6, [500,200,50]);
		cities.push(city);	
		city = new City("Atlanta", 33, 19, [400,300,50]);
		cities.push(city);	
		city = new City("New York", 12, 20, [1000,400,0]);
		cities.push(city);	
		city = new City("Phoenix", 14, 34, [800,100,25]);
		cities.push(city);			
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

	private function get_cities_map():String{
		var map = "";
		var x_cor:Int;
		var y_cor:Int;
		for(row in 0...LEVEL_HEIGHT){
			y_cor = row + 1;		
			for(col in 0...LEVEL_WIDTH){
				var town_loc = false;
				x_cor = col + 1;
				for(i in 0...cities.length){
					if(cities[i].coordinate_x <= x_cor+1 && cities[i].coordinate_x >= x_cor-1 && cities[i].coordinate_y <= y_cor+1 && cities[i].coordinate_y >= y_cor-1)
						town_loc = true;
				}
				if(town_loc == true)
					map = map + "1";
				else
					map = map + "0";	
				if(col < LEVEL_WIDTH - 1)
					map = map + ",";	
				else if(row < LEVEL_HEIGHT - 1)
					map = map + "\n";														
			}
		}
		return map;
	}				

}