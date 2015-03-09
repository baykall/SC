package ;

import flixel.FlxG;
import flixel.group.FlxSpriteGroup;
import flixel.text.FlxText;
import flixel.ui.FlxBar;
import flixel.util.FlxColor;
import flixel.FlxSprite;
import flixel.ui.FlxButton;

class HUD extends FlxSpriteGroup{

	private var timeDisplay:FlxText;
	private var newDisplay:FlxText;		
	private var time:String;
	private var value:String;	
	
	public function new(){
		super();
		scrollFactor.x = 0;
		scrollFactor.y = 0;

		var background = new FlxSprite();
		background.makeGraphic(FlxG.width, PlayState.HUDHeight, FlxColor.BLACK, true);
		add(background);

		timeDisplay = new FlxText(FlxG.width - 150, 10);
		timeDisplay.setFormat("assets/fonts/" + PlayState.font, PlayState.timeTextSize, FlxColor.WHITE, "center");	
		add(timeDisplay);	

		newDisplay = new FlxText(50, 10);
		newDisplay.setFormat("assets/fonts/" + PlayState.font, PlayState.timeTextSize, FlxColor.WHITE, "center");	
		add(newDisplay);			

		time = "";
		value = "";
	}
	
	override public function update(){
		timeDisplay.text = time;
		newDisplay.text = value;
	}

	public function update_time(cal):Void {
		time=cal;
	}	

	public function update_hud(val):Void {
		value=val;
	}		
	
}