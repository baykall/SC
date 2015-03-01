package ;
import flixel.group.FlxSpriteGroup;
import flixel.text.FlxText;
import flixel.ui.FlxBar;
import flixel.util.FlxColor;
import flixel.FlxSprite;

class HUD extends FlxSpriteGroup{

	private var timeDisplay:FlxText;	
	private var time:String;	
	
	public function new(width){
		super();
		scrollFactor.x = 0;
		scrollFactor.y = 0;

		var background = new FlxSprite();
		background.makeGraphic(width, 40, FlxColor.BLACK, true);
		add(background);

		timeDisplay = new FlxText(2, 12);
		timeDisplay.setFormat("assets/fonts/Quicksand-Bold.otf", 18, FlxColor.WHITE, "center");	
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