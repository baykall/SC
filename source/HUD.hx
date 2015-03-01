package ;
import flixel.group.FlxSpriteGroup;
import flixel.text.FlxText;
import flixel.ui.FlxBar;
import flixel.util.FlxColor;

class HUD extends FlxSpriteGroup{

	private var timeDisplay:FlxText;	
	private var time:String;	
	
	public function new(){
		super();
		scrollFactor.x = 0;
		scrollFactor.y = 0;

		timeDisplay = new FlxText(2, 12);
		timeDisplay.setFormat("assets/fonts/Quicksand-Bold.otf", 24, FlxColor.BLACK, "center");	
		add(timeDisplay);		

		time = "";
	}

	public function update_time(cal):Void {
		time=cal;
	}		
	
	override public function update(){
		timeDisplay.text = time;
	}
	
	
}