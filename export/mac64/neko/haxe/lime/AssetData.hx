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
			path.set ("assets/data/map.csv", "assets/data/map.csv");
			type.set ("assets/data/map.csv", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/images/From other Games/grass.png", "assets/images/From other Games/grass.png");
			type.set ("assets/images/From other Games/grass.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/From other Games/terrain.png", "assets/images/From other Games/terrain.png");
			type.set ("assets/images/From other Games/terrain.png", Reflect.field (AssetType, "image".toUpperCase ()));
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
			path.set ("assets/images/terrain.png", "assets/images/terrain.png");
			type.set ("assets/images/terrain.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/tileset.png", "assets/images/tileset.png");
			type.set ("assets/images/tileset.png", Reflect.field (AssetType, "image".toUpperCase ()));
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
