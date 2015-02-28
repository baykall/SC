package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;

/**
 * A FlxState which can be used for the game's menu.
 */
class MenuState extends FlxState
{
	/**
	 * Function that is called up when to state is created to set it up. 
	 */

	override public function create():Void
	{
		super.create();
		
		var init_x:Int = Math.floor(FlxG.width / 2 - 40);
		
		var btn_new = new FlxButton(init_x, 50, "New game", onNew);
		var btn_load = new FlxButton(init_x, 80, "Load", onLoad);
		
		add(btn_new);
		add(btn_load);
	}

	private function onNew():Void {
		FlxG.switchState(new PlayState());
	}

	private function onLoad():Void {
		trace("Load...");
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
	}	
}