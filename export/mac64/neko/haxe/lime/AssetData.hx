package lime;


import lime.utils.Assets;


class AssetData {

	private static var initialized:Bool = false;
	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();	
	
	public static function initialize():Void {
		
		if (!initialized) {
			
			path.set ("assets/data/data-goes-here.txt", "assets/data/data-goes-here.txt");
			type.set ("assets/data/data-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/data/plants_map.csv", "assets/data/plants_map.csv");
			type.set ("assets/data/plants_map.csv", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/data/terrain_map.csv", "assets/data/terrain_map.csv");
			type.set ("assets/data/terrain_map.csv", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/fonts/OpenSans-Bold.ttf", "assets/fonts/OpenSans-Bold.ttf");
			type.set ("assets/fonts/OpenSans-Bold.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/OpenSans-BoldItalic.ttf", "assets/fonts/OpenSans-BoldItalic.ttf");
			type.set ("assets/fonts/OpenSans-BoldItalic.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/OpenSans-ExtraBold.ttf", "assets/fonts/OpenSans-ExtraBold.ttf");
			type.set ("assets/fonts/OpenSans-ExtraBold.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/OpenSans-ExtraBoldItalic.ttf", "assets/fonts/OpenSans-ExtraBoldItalic.ttf");
			type.set ("assets/fonts/OpenSans-ExtraBoldItalic.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/OpenSans-Italic.ttf", "assets/fonts/OpenSans-Italic.ttf");
			type.set ("assets/fonts/OpenSans-Italic.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/OpenSans-Light.ttf", "assets/fonts/OpenSans-Light.ttf");
			type.set ("assets/fonts/OpenSans-Light.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/OpenSans-LightItalic.ttf", "assets/fonts/OpenSans-LightItalic.ttf");
			type.set ("assets/fonts/OpenSans-LightItalic.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/OpenSans-Regular.ttf", "assets/fonts/OpenSans-Regular.ttf");
			type.set ("assets/fonts/OpenSans-Regular.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/OpenSans-Semibold.ttf", "assets/fonts/OpenSans-Semibold.ttf");
			type.set ("assets/fonts/OpenSans-Semibold.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/OpenSans-SemiboldItalic.ttf", "assets/fonts/OpenSans-SemiboldItalic.ttf");
			type.set ("assets/fonts/OpenSans-SemiboldItalic.ttf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/Quicksand-Bold.otf", "assets/fonts/Quicksand-Bold.otf");
			type.set ("assets/fonts/Quicksand-Bold.otf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/Quicksand-BoldItalic.otf", "assets/fonts/Quicksand-BoldItalic.otf");
			type.set ("assets/fonts/Quicksand-BoldItalic.otf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/Quicksand-Italic.otf", "assets/fonts/Quicksand-Italic.otf");
			type.set ("assets/fonts/Quicksand-Italic.otf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/Quicksand-Light.otf", "assets/fonts/Quicksand-Light.otf");
			type.set ("assets/fonts/Quicksand-Light.otf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/Quicksand-LightItalic.otf", "assets/fonts/Quicksand-LightItalic.otf");
			type.set ("assets/fonts/Quicksand-LightItalic.otf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/Quicksand-Regular.otf", "assets/fonts/Quicksand-Regular.otf");
			type.set ("assets/fonts/Quicksand-Regular.otf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/fonts/Quicksand_Dash.otf", "assets/fonts/Quicksand_Dash.otf");
			type.set ("assets/fonts/Quicksand_Dash.otf", Reflect.field (AssetType, "font".toUpperCase ()));
			path.set ("assets/images/background.png", "assets/images/background.png");
			type.set ("assets/images/background.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Internet/grass.png", "assets/images/From Internet/grass.png");
			type.set ("assets/images/From Internet/grass.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Internet/water.png", "assets/images/From Internet/water.png");
			type.set ("assets/images/From Internet/water.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Internet/wheat.png", "assets/images/From Internet/wheat.png");
			type.set ("assets/images/From Internet/wheat.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Internet/wheat2.png", "assets/images/From Internet/wheat2.png");
			type.set ("assets/images/From Internet/wheat2.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From other Games/grass.png", "assets/images/From other Games/grass.png");
			type.set ("assets/images/From other Games/grass.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From other Games/terrain.png", "assets/images/From other Games/terrain.png");
			type.set ("assets/images/From other Games/terrain.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From other Games/tileset.png", "assets/images/From other Games/tileset.png");
			type.set ("assets/images/From other Games/tileset.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From other Games/water.png", "assets/images/From other Games/water.png");
			type.set ("assets/images/From other Games/water.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Photos/Snip20150228_1.png", "assets/images/From Photos/Snip20150228_1.png");
			type.set ("assets/images/From Photos/Snip20150228_1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Photos/Snip20150228_2.png", "assets/images/From Photos/Snip20150228_2.png");
			type.set ("assets/images/From Photos/Snip20150228_2.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Photos/Snip20150228_3.png", "assets/images/From Photos/Snip20150228_3.png");
			type.set ("assets/images/From Photos/Snip20150228_3.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Photos/Snip20150228_5.png", "assets/images/From Photos/Snip20150228_5.png");
			type.set ("assets/images/From Photos/Snip20150228_5.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Photos/Snip20150228_6.png", "assets/images/From Photos/Snip20150228_6.png");
			type.set ("assets/images/From Photos/Snip20150228_6.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Photos/Snip20150228_7.png", "assets/images/From Photos/Snip20150228_7.png");
			type.set ("assets/images/From Photos/Snip20150228_7.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Photos/Snip20150228_8.png", "assets/images/From Photos/Snip20150228_8.png");
			type.set ("assets/images/From Photos/Snip20150228_8.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From Photos/tileset1.png", "assets/images/From Photos/tileset1.png");
			type.set ("assets/images/From Photos/tileset1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/images-go-here.txt", "assets/images/images-go-here.txt");
			type.set ("assets/images/images-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/images/plants.png", "assets/images/plants.png");
			type.set ("assets/images/plants.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/terrain.png", "assets/images/terrain.png");
			type.set ("assets/images/terrain.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/music/music-goes-here.txt", "assets/music/music-goes-here.txt");
			type.set ("assets/music/music-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/sounds/sounds-go-here.txt", "assets/sounds/sounds-go-here.txt");
			type.set ("assets/sounds/sounds-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/sounds/beep.ogg", "assets/sounds/beep.ogg");
			type.set ("assets/sounds/beep.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/sounds/flixel.ogg", "assets/sounds/flixel.ogg");
			type.set ("assets/sounds/flixel.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			
			
			initialized = true;
			
		} //!initialized
		
	} //initialize
	
	
} //AssetData
