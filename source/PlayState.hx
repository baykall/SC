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
enum BuildMode{
	None;
	WheatFarm;
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
	private var buildings:FlxTilemap;	

	private var mouseicon:FlxSprite;


// Load the sprite's graphic to the cursor
//FlxG.mouse.load(sprite.pixels);	
		
	// Camera
	private var camera:FlxCamera;
	private var cameraFocus:FlxSprite;

	// Graphic Parameters
	public static var font:String = "Quicksand-Bold.otf";
	public static var topButtonsSize:Int = 24;
	public static var timeTextSize:Int = 18;
	public static var cityTextSize:Int = 24;	
	public static var HUDHeight:Int = 40;
	
	// HUD
	private var hud:HUD;

	// Buttons	
	private var companyButton:FlxButton;	
	private var resourcesButton:FlxButton;	
	private var optionsButton:FlxButton;
	
	// Game status
	private var state:State = Running;	
	private var buildMode:BuildMode = None;
	private var stateSwitch:Bool = false;
	private var buildModeSwitch:Bool = false;	

	// Game entities
	private var time:Time;	
	private var trucks:Array<FlxSprite>;
	private var truck_paths:Array<FlxPath>;
	private var cities:Array<City>;	
	private var city_labels:Array<FlxText>;	

	private var truck_def_speed:Float;

	// Main Functions

	override public function create():Void{
		super.create();

		init_parameters();
		
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

		// Inputs from keyboard and mouse
		input_keyboard();
		input_mouse();

		// Update items dependent on the inputs
		update_state_dependent_items();

		if(state == Running){
			update_time();
			move_trucks();
			remove_arrived_trucks();
			if(time.moment == NewDay)
				execute_todays_events();
		}
	}

	// Initialization Functions

	public function init_parameters(){

		truck_def_speed = 150;
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

	public function init_graphics(){
		city_labels = new Array<FlxText>();	
		var label:FlxText;

		var terrain_map:String;	
		var plants_map:String;	
		var roads_map:String;	
		var towns_map:String;
		var buildings_map:String;	

		terrain_map = Assets.getText("assets/data/terrain_map.csv");
		plants_map = Assets.getText("assets/data/resources_map.csv");
		roads_map = Assets.getText("assets/data/roads_map.csv");
		towns_map = get_map("Cities");
		buildings_map = get_map("Buildings");		

		// Terrain
		terrain = new FlxTilemap();
		terrain.loadMap(terrain_map, "assets/images/terrain.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);	
		add(terrain);	
	
		// Plants
		plants = new FlxTilemap();
		plants.loadMap(plants_map, "assets/images/resources.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);				
		add(plants);

		// Roads
		roads = new FlxTilemap();
		roads.loadMap(roads_map, "assets/images/roads.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);				
		add(roads);	

		roads.setTileProperties(0, FlxObject.ANY);	
		for(i in 1...11)
			roads.setTileProperties(i, FlxObject.NONE);			

		// Cities
		towns = new FlxTilemap();
		towns.loadMap(towns_map, "assets/images/towns.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);				
		add(towns);	

		// Buildings
		buildings = new FlxTilemap();
		buildings.loadMap(buildings_map, "assets/images/buildings.png", TILE_WIDTH, TILE_HEIGHT, 0, 1);				
		add(buildings);	

		// City labels
		for(i in 0...cities.length){
			label = new FlxText(cities[i].label_coordinate_x, cities[i].label_coordinate_y);
			label.setFormat("assets/fonts/" + font, cityTextSize, FlxColor.WHITE, "center");		
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
		hud = new HUD();
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

	public function init_trucks(){
		trucks = new Array<FlxSprite>();
		truck_paths = new Array<FlxPath>();
	}

	// Initialization Aux Functions

	private function get_map(_type):String{
		var map = "";
		var x_cor:Int;
		var y_cor:Int;
		for(row in 0...LEVEL_HEIGHT){
			y_cor = row + 1;		
			for(col in 0...LEVEL_WIDTH){
				x_cor = col + 1;
				var val = "";
				if(_type == "Cities"){
					var town_loc = false;
					for(i in 0...cities.length){
						if(cities[i].coordinate_x <= x_cor+1 && cities[i].coordinate_x >= x_cor-1 && cities[i].coordinate_y <= y_cor+1 && cities[i].coordinate_y >= y_cor-1)
							town_loc = true;
					}
					if(town_loc == true)
						val = "1";
					else
						val = "0";
				}
				else if(_type == "Buildings"){
					val = "0";
				}				
				map = map + val;
				if(col < LEVEL_WIDTH - 1)
					map = map + ",";	
				else if(row < LEVEL_HEIGHT - 1)
					map = map + "\n";														
			}
		}
		return map;
	}		

	// Update functions

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

	public function input_keyboard(){
	    if (FlxG.keys.justPressed.SPACE){
			if(state == Running)
				state = Paused;
			else
				state = Running;	
			stateSwitch = true;			
	    }	
	}
	
	public function input_mouse(){
		var x;
		/*
	    if (buildMode == WheatFarm){
			if(state == Running)
				state = Paused;
			else
				state = Running;				
	    }
	    */	
	}	

	public function update_state_dependent_items(){
		if(stateSwitch == true){
			if(state == Running)
				resume_game();
			else
				pause_game();
			stateSwitch = false;		
		}
	}

	public function update_time():Void{
		var calendar_day;
		time.update();
		calendar_day = time.calendar_day;
		hud.update_time(calendar_day);
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
				truck_paths[i].destroy();	
				truck_no = i;	
			}
		}

		if(truck_no >= 0){
			trucks.splice(truck_no,1);
			truck_paths.splice(truck_no,1);
		}
	}	

	public function execute_todays_events(){
		if(time.total_days==1)
			buildMode = WheatFarm;
		if(time.total_days==2)
			ship_truck(26,34,16,6);
		if(time.total_days==3)
			ship_truck(30,19,15,20);
		
		if(time.total_days==4){
			//hud.update_hud(get_map("Cities"));

		}
			
	}	


	// Update Aux Functions

	public function pause_game(){
		for(i in 0...truck_paths.length){
			truck_paths[i].speed = 0;
		}
	}

	public function resume_game(){
		for(i in 0...truck_paths.length){
			truck_paths[i].speed = truck_def_speed;
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
		//truck_path.speed = 10;
		truck_paths.push(truck_path);	
	
		var nodes:Array<FlxPoint> = roads.findPath(FlxPoint.get(truck.x, truck.y), FlxPoint.get((to_x - 0.5) * TILE_WIDTH, (to_y - 0.5) * TILE_HEIGHT));

		truck_paths[truck_paths.length - 1].start(trucks[trucks.length - 1], nodes, truck_def_speed);
	}	

	// Menu handling

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