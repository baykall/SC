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
	private var time:String;
	
	public function new(font, timeSize, HUDHeight){
		super();
		scrollFactor.x = 0;
		scrollFactor.y = 0;

		var background = new FlxSprite();
		background.makeGraphic(FlxG.width, HUDHeight, FlxColor.BLACK, true);
		add(background);

		timeDisplay = new FlxText(FlxG.width - 150, 10);
		timeDisplay.setFormat("assets/fonts/" + font, timeSize, FlxColor.WHITE, "center");	
		add(timeDisplay);			

		time = "";
	}
	
	override public function update(){
		timeDisplay.text = time;
	}

	public function update_time(cal):Void {
		time=cal;
	}	
	
}