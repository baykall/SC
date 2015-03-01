package;


import haxe.Timer;
import haxe.Unserializer;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.MovieClip;
import openfl.events.Event;
import openfl.text.Font;
import openfl.media.Sound;
import openfl.net.URLRequest;
import openfl.utils.ByteArray;
import openfl.Assets;

#if (flash || js)
import openfl.display.Loader;
import openfl.events.Event;
import openfl.net.URLLoader;
#end

#if sys
import sys.FileSystem;
#end

#if ios
import openfl._v2.utils.SystemPath;
#end


@:access(openfl.media.Sound)
class DefaultAssetLibrary extends AssetLibrary {
	
	
	public var className (default, null) = new Map <String, Dynamic> ();
	public var path (default, null) = new Map <String, String> ();
	public var type (default, null) = new Map <String, AssetType> ();
	
	private var lastModified:Float;
	private var timer:Timer;
	
	
	public function new () {
		
		super ();
		
		#if flash
		
		path.set ("assets/data/data-goes-here.txt", "assets/data/data-goes-here.txt");
		type.set ("assets/data/data-goes-here.txt", AssetType.TEXT);
		path.set ("assets/data/map.csv", "assets/data/map.csv");
		type.set ("assets/data/map.csv", AssetType.TEXT);
		path.set ("assets/fonts/OpenSans-Bold.ttf", "assets/fonts/OpenSans-Bold.ttf");
		type.set ("assets/fonts/OpenSans-Bold.ttf", AssetType.FONT);
		path.set ("assets/fonts/OpenSans-BoldItalic.ttf", "assets/fonts/OpenSans-BoldItalic.ttf");
		type.set ("assets/fonts/OpenSans-BoldItalic.ttf", AssetType.FONT);
		path.set ("assets/fonts/OpenSans-ExtraBold.ttf", "assets/fonts/OpenSans-ExtraBold.ttf");
		type.set ("assets/fonts/OpenSans-ExtraBold.ttf", AssetType.FONT);
		path.set ("assets/fonts/OpenSans-ExtraBoldItalic.ttf", "assets/fonts/OpenSans-ExtraBoldItalic.ttf");
		type.set ("assets/fonts/OpenSans-ExtraBoldItalic.ttf", AssetType.FONT);
		path.set ("assets/fonts/OpenSans-Italic.ttf", "assets/fonts/OpenSans-Italic.ttf");
		type.set ("assets/fonts/OpenSans-Italic.ttf", AssetType.FONT);
		path.set ("assets/fonts/OpenSans-Light.ttf", "assets/fonts/OpenSans-Light.ttf");
		type.set ("assets/fonts/OpenSans-Light.ttf", AssetType.FONT);
		path.set ("assets/fonts/OpenSans-LightItalic.ttf", "assets/fonts/OpenSans-LightItalic.ttf");
		type.set ("assets/fonts/OpenSans-LightItalic.ttf", AssetType.FONT);
		path.set ("assets/fonts/OpenSans-Regular.ttf", "assets/fonts/OpenSans-Regular.ttf");
		type.set ("assets/fonts/OpenSans-Regular.ttf", AssetType.FONT);
		path.set ("assets/fonts/OpenSans-Semibold.ttf", "assets/fonts/OpenSans-Semibold.ttf");
		type.set ("assets/fonts/OpenSans-Semibold.ttf", AssetType.FONT);
		path.set ("assets/fonts/OpenSans-SemiboldItalic.ttf", "assets/fonts/OpenSans-SemiboldItalic.ttf");
		type.set ("assets/fonts/OpenSans-SemiboldItalic.ttf", AssetType.FONT);
		path.set ("assets/fonts/Quicksand-Bold.otf", "assets/fonts/Quicksand-Bold.otf");
		type.set ("assets/fonts/Quicksand-Bold.otf", AssetType.FONT);
		path.set ("assets/fonts/Quicksand-BoldItalic.otf", "assets/fonts/Quicksand-BoldItalic.otf");
		type.set ("assets/fonts/Quicksand-BoldItalic.otf", AssetType.FONT);
		path.set ("assets/fonts/Quicksand-Italic.otf", "assets/fonts/Quicksand-Italic.otf");
		type.set ("assets/fonts/Quicksand-Italic.otf", AssetType.FONT);
		path.set ("assets/fonts/Quicksand-Light.otf", "assets/fonts/Quicksand-Light.otf");
		type.set ("assets/fonts/Quicksand-Light.otf", AssetType.FONT);
		path.set ("assets/fonts/Quicksand-LightItalic.otf", "assets/fonts/Quicksand-LightItalic.otf");
		type.set ("assets/fonts/Quicksand-LightItalic.otf", AssetType.FONT);
		path.set ("assets/fonts/Quicksand-Regular.otf", "assets/fonts/Quicksand-Regular.otf");
		type.set ("assets/fonts/Quicksand-Regular.otf", AssetType.FONT);
		path.set ("assets/fonts/Quicksand_Dash.otf", "assets/fonts/Quicksand_Dash.otf");
		type.set ("assets/fonts/Quicksand_Dash.otf", AssetType.FONT);
		path.set ("assets/images/From other Games/grass.png", "assets/images/From other Games/grass.png");
		type.set ("assets/images/From other Games/grass.png", AssetType.IMAGE);
		path.set ("assets/images/From other Games/terrain.png", "assets/images/From other Games/terrain.png");
		type.set ("assets/images/From other Games/terrain.png", AssetType.IMAGE);
		path.set ("assets/images/From other Games/water.png", "assets/images/From other Games/water.png");
		type.set ("assets/images/From other Games/water.png", AssetType.IMAGE);
		path.set ("assets/images/From Photos/Snip20150228_1.png", "assets/images/From Photos/Snip20150228_1.png");
		type.set ("assets/images/From Photos/Snip20150228_1.png", AssetType.IMAGE);
		path.set ("assets/images/From Photos/Snip20150228_2.png", "assets/images/From Photos/Snip20150228_2.png");
		type.set ("assets/images/From Photos/Snip20150228_2.png", AssetType.IMAGE);
		path.set ("assets/images/From Photos/Snip20150228_3.png", "assets/images/From Photos/Snip20150228_3.png");
		type.set ("assets/images/From Photos/Snip20150228_3.png", AssetType.IMAGE);
		path.set ("assets/images/From Photos/Snip20150228_5.png", "assets/images/From Photos/Snip20150228_5.png");
		type.set ("assets/images/From Photos/Snip20150228_5.png", AssetType.IMAGE);
		path.set ("assets/images/From Photos/Snip20150228_6.png", "assets/images/From Photos/Snip20150228_6.png");
		type.set ("assets/images/From Photos/Snip20150228_6.png", AssetType.IMAGE);
		path.set ("assets/images/From Photos/Snip20150228_7.png", "assets/images/From Photos/Snip20150228_7.png");
		type.set ("assets/images/From Photos/Snip20150228_7.png", AssetType.IMAGE);
		path.set ("assets/images/From Photos/Snip20150228_8.png", "assets/images/From Photos/Snip20150228_8.png");
		type.set ("assets/images/From Photos/Snip20150228_8.png", AssetType.IMAGE);
		path.set ("assets/images/From Photos/tileset1.png", "assets/images/From Photos/tileset1.png");
		type.set ("assets/images/From Photos/tileset1.png", AssetType.IMAGE);
		path.set ("assets/images/images-go-here.txt", "assets/images/images-go-here.txt");
		type.set ("assets/images/images-go-here.txt", AssetType.TEXT);
		path.set ("assets/images/terrain.png", "assets/images/terrain.png");
		type.set ("assets/images/terrain.png", AssetType.IMAGE);
		path.set ("assets/images/tileset.png", "assets/images/tileset.png");
		type.set ("assets/images/tileset.png", AssetType.IMAGE);
		path.set ("assets/music/music-goes-here.txt", "assets/music/music-goes-here.txt");
		type.set ("assets/music/music-goes-here.txt", AssetType.TEXT);
		path.set ("assets/sounds/sounds-go-here.txt", "assets/sounds/sounds-go-here.txt");
		type.set ("assets/sounds/sounds-go-here.txt", AssetType.TEXT);
		path.set ("assets/sounds/beep.ogg", "assets/sounds/beep.ogg");
		type.set ("assets/sounds/beep.ogg", AssetType.SOUND);
		path.set ("assets/sounds/flixel.ogg", "assets/sounds/flixel.ogg");
		type.set ("assets/sounds/flixel.ogg", AssetType.SOUND);
		
		
		#elseif html5
		
		var id;
		id = "assets/data/data-goes-here.txt";
		path.set (id, id);
		type.set (id, AssetType.TEXT);
		id = "assets/data/map.csv";
		path.set (id, id);
		type.set (id, AssetType.TEXT);
		id = "assets/fonts/OpenSans-Bold.ttf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/OpenSans-BoldItalic.ttf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/OpenSans-ExtraBold.ttf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/OpenSans-ExtraBoldItalic.ttf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/OpenSans-Italic.ttf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/OpenSans-Light.ttf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/OpenSans-LightItalic.ttf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/OpenSans-Regular.ttf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/OpenSans-Semibold.ttf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/OpenSans-SemiboldItalic.ttf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/Quicksand-Bold.otf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/Quicksand-BoldItalic.otf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/Quicksand-Italic.otf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/Quicksand-Light.otf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/Quicksand-LightItalic.otf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/Quicksand-Regular.otf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/fonts/Quicksand_Dash.otf";
		path.set (id, id);
		type.set (id, AssetType.FONT);
		id = "assets/images/From other Games/grass.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/From other Games/terrain.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/From other Games/water.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/From Photos/Snip20150228_1.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/From Photos/Snip20150228_2.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/From Photos/Snip20150228_3.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/From Photos/Snip20150228_5.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/From Photos/Snip20150228_6.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/From Photos/Snip20150228_7.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/From Photos/Snip20150228_8.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/From Photos/tileset1.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/images-go-here.txt";
		path.set (id, id);
		type.set (id, AssetType.TEXT);
		id = "assets/images/terrain.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/images/tileset.png";
		path.set (id, id);
		type.set (id, AssetType.IMAGE);
		id = "assets/music/music-goes-here.txt";
		path.set (id, id);
		type.set (id, AssetType.TEXT);
		id = "assets/sounds/sounds-go-here.txt";
		path.set (id, id);
		type.set (id, AssetType.TEXT);
		id = "assets/sounds/beep.ogg";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		id = "assets/sounds/flixel.ogg";
		path.set (id, id);
		type.set (id, AssetType.SOUND);
		
		
		#else
		
		
		
		
		Font.registerFont (__ASSET__assets_fonts_opensans_bold_ttf);
		Font.registerFont (__ASSET__assets_fonts_opensans_bolditalic_ttf);
		Font.registerFont (__ASSET__assets_fonts_opensans_extrabold_ttf);
		Font.registerFont (__ASSET__assets_fonts_opensans_extrabolditalic_ttf);
		Font.registerFont (__ASSET__assets_fonts_opensans_italic_ttf);
		Font.registerFont (__ASSET__assets_fonts_opensans_light_ttf);
		Font.registerFont (__ASSET__assets_fonts_opensans_lightitalic_ttf);
		Font.registerFont (__ASSET__assets_fonts_opensans_regular_ttf);
		Font.registerFont (__ASSET__assets_fonts_opensans_semibold_ttf);
		Font.registerFont (__ASSET__assets_fonts_opensans_semibolditalic_ttf);
		Font.registerFont (__ASSET__assets_fonts_quicksand_bold_otf);
		Font.registerFont (__ASSET__assets_fonts_quicksand_bolditalic_otf);
		Font.registerFont (__ASSET__assets_fonts_quicksand_italic_otf);
		Font.registerFont (__ASSET__assets_fonts_quicksand_light_otf);
		Font.registerFont (__ASSET__assets_fonts_quicksand_lightitalic_otf);
		Font.registerFont (__ASSET__assets_fonts_quicksand_regular_otf);
		Font.registerFont (__ASSET__assets_fonts_quicksand_dash_otf);
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		#if (windows || mac || linux)
		
		var useManifest = false;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		
		
		if (useManifest) {
			
			loadManifest ();
			
			if (Sys.args ().indexOf ("-livereload") > -1) {
				
				var path = FileSystem.fullPath ("manifest");
				lastModified = FileSystem.stat (path).mtime.getTime ();
				
				timer = new Timer (2000);
				timer.run = function () {
					
					var modified = FileSystem.stat (path).mtime.getTime ();
					
					if (modified > lastModified) {
						
						lastModified = modified;
						loadManifest ();
						
						if (eventCallback != null) {
							
							eventCallback (this, "change");
							
						}
						
					}
					
				}
				
			}
			
		}
		
		#else
		
		loadManifest ();
		
		#end
		#end
		
	}
	
	
	public override function exists (id:String, type:AssetType):Bool {
		
		var assetType = this.type.get (id);
		
		#if pixi
		
		if (assetType == IMAGE) {
			
			return true;
			
		} else {
			
			return false;
			
		}
		
		#end
		
		if (assetType != null) {
			
			if (assetType == type || ((type == SOUND || type == MUSIC) && (assetType == MUSIC || assetType == SOUND))) {
				
				return true;
				
			}
			
			#if flash
			
			if ((assetType == BINARY || assetType == TEXT) && type == BINARY) {
				
				return true;
				
			} else if (path.exists (id)) {
				
				return true;
				
			}
			
			#else
			
			if (type == BINARY || type == null || (assetType == BINARY && type == TEXT)) {
				
				return true;
				
			}
			
			#end
			
		}
		
		return false;
		
	}
	
	
	public override function getBitmapData (id:String):BitmapData {
		
		#if pixi
		
		return BitmapData.fromImage (path.get (id));
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), BitmapData);
		
		#elseif openfl_html5
		
		return BitmapData.fromImage (ApplicationMain.images.get (path.get (id)));
		
		#elseif js
		
		return cast (ApplicationMain.loaders.get (path.get (id)).contentLoaderInfo.content, Bitmap).bitmapData;
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), BitmapData);
		else return BitmapData.load (path.get (id));
		
		#end
		
	}
	
	
	public override function getBytes (id:String):ByteArray {
		
		#if (flash)
		
		return cast (Type.createInstance (className.get (id), []), ByteArray);

		#elseif (js || openfl_html5 || pixi)
		
		var bytes:ByteArray = null;
		var data = ApplicationMain.urlLoaders.get (path.get (id)).data;
		
		if (Std.is (data, String)) {
			
			bytes = new ByteArray ();
			bytes.writeUTFBytes (data);
			
		} else if (Std.is (data, ByteArray)) {
			
			bytes = cast data;
			
		} else {
			
			bytes = null;
			
		}

		if (bytes != null) {
			
			bytes.position = 0;
			return bytes;
			
		} else {
			
			return null;
		}
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), ByteArray);
		else return ByteArray.readFile (path.get (id));
		
		#end
		
	}
	
	
	public override function getFont (id:String):Font {
		
		#if pixi
		
		return null;
		
		#elseif (flash || js)
		
		return cast (Type.createInstance (className.get (id), []), Font);
		
		#else
		
		if (className.exists(id)) {
			var fontClass = className.get(id);
			Font.registerFont(fontClass);
			return cast (Type.createInstance (fontClass, []), Font);
		} else return new Font (path.get (id));
		
		#end
		
	}
	
	
	public override function getMusic (id:String):Sound {
		
		#if pixi
		
		return null;
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif openfl_html5
		
		var sound = new Sound ();
		sound.__buffer = true;
		sound.load (new URLRequest (path.get (id)));
		return sound; 
		
		#elseif js
		
		return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), Sound);
		else return new Sound (new URLRequest (path.get (id)), null, true);
		
		#end
		
	}
	
	
	public override function getPath (id:String):String {
		
		#if ios
		
		return SystemPath.applicationDirectory + "/assets/" + path.get (id);
		
		#else
		
		return path.get (id);
		
		#end
		
	}
	
	
	public override function getSound (id:String):Sound {
		
		#if pixi
		
		return null;
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif js
		
		return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), Sound);
		else return new Sound (new URLRequest (path.get (id)), null, type.get (id) == MUSIC);
		
		#end
		
	}
	
	
	public override function getText (id:String):String {
		
		#if js
		
		var bytes:ByteArray = null;
		var data = ApplicationMain.urlLoaders.get (path.get (id)).data;
		
		if (Std.is (data, String)) {
			
			return cast data;
			
		} else if (Std.is (data, ByteArray)) {
			
			bytes = cast data;
			
		} else {
			
			bytes = null;
			
		}
		
		if (bytes != null) {
			
			bytes.position = 0;
			return bytes.readUTFBytes (bytes.length);
			
		} else {
			
			return null;
		}
		
		#else
		
		var bytes = getBytes (id);
		
		if (bytes == null) {
			
			return null;
			
		} else {
			
			return bytes.readUTFBytes (bytes.length);
			
		}
		
		#end
		
	}
	
	
	public override function isLocal (id:String, type:AssetType):Bool {
		
		#if flash
		
		if (type != AssetType.MUSIC && type != AssetType.SOUND) {
			
			return className.exists (id);
			
		}
		
		#end
		
		return true;
		
	}
	
	
	public override function list (type:AssetType):Array<String> {
		
		var items = [];
		
		for (id in this.type.keys ()) {
			
			if (type == null || exists (id, type)) {
				
				items.push (id);
				
			}
			
		}
		
		return items;
		
	}
	
	
	public override function loadBitmapData (id:String, handler:BitmapData -> Void):Void {
		
		#if pixi
		
		handler (getBitmapData (id));
		
		#elseif (flash || js)
		
		if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event:Event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBitmapData (id));
			
		}
		
		#else
		
		handler (getBitmapData (id));
		
		#end
		
	}
	
	
	public override function loadBytes (id:String, handler:ByteArray -> Void):Void {
		
		#if pixi
		
		handler (getBytes (id));
		
		#elseif (flash || js)
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.addEventListener (Event.COMPLETE, function (event:Event) {
				
				var bytes = new ByteArray ();
				bytes.writeUTFBytes (event.currentTarget.data);
				bytes.position = 0;
				
				handler (bytes);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBytes (id));
			
		}
		
		#else
		
		handler (getBytes (id));
		
		#end
		
	}
	
	
	public override function loadFont (id:String, handler:Font -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getFont (id));
			
		//}
		
		#else
		
		handler (getFont (id));
		
		#end
		
	}
	
	
	#if (!flash && !html5)
	private function loadManifest ():Void {
		
		try {
			
			#if blackberry
			var bytes = ByteArray.readFile ("app/native/manifest");
			#elseif tizen
			var bytes = ByteArray.readFile ("../res/manifest");
			#elseif emscripten
			var bytes = ByteArray.readFile ("assets/manifest");
			#else
			var bytes = ByteArray.readFile ("manifest");
			#end
			
			if (bytes != null) {
				
				bytes.position = 0;
				
				if (bytes.length > 0) {
					
					var data = bytes.readUTFBytes (bytes.length);
					
					if (data != null && data.length > 0) {
						
						var manifest:Array<Dynamic> = Unserializer.run (data);
						
						for (asset in manifest) {
							
							if (!className.exists (asset.id)) {
								
								path.set (asset.id, asset.path);
								type.set (asset.id, Type.createEnum (AssetType, asset.type));
								
							}
							
						}
						
					}
					
				}
				
			} else {
				
				trace ("Warning: Could not load asset manifest (bytes was null)");
				
			}
		
		} catch (e:Dynamic) {
			
			trace ('Warning: Could not load asset manifest (${e})');
			
		}
		
	}
	#end
	
	
	public override function loadMusic (id:String, handler:Sound -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getMusic (id));
			
		//}
		
		#else
		
		handler (getMusic (id));
		
		#end
		
	}
	
	
	public override function loadSound (id:String, handler:Sound -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getSound (id));
			
		//}
		
		#else
		
		handler (getSound (id));
		
		#end
		
	}
	
	
	public override function loadText (id:String, handler:String -> Void):Void {
		
		#if js
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.addEventListener (Event.COMPLETE, function (event:Event) {
				
				handler (event.currentTarget.data);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getText (id));
			
		}
		
		#else
		
		var callback = function (bytes:ByteArray):Void {
			
			if (bytes == null) {
				
				handler (null);
				
			} else {
				
				handler (bytes.readUTFBytes (bytes.length));
				
			}
			
		}
		
		loadBytes (id, callback);
		
		#end
		
	}
	
	
}


#if pixi
#elseif flash








































#elseif html5



@:keep #if display private #end class __ASSET__assets_fonts_opensans_bold_ttf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Open Sans Bold"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_opensans_bolditalic_ttf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Open Sans Bold Italic"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_opensans_extrabold_ttf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Open Sans Extrabold"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_opensans_extrabolditalic_ttf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Open Sans Extrabold Italic"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_opensans_italic_ttf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Open Sans Italic"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_opensans_light_ttf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Open Sans Light"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_opensans_lightitalic_ttf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Open Sans Light Italic"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_opensans_regular_ttf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Open Sans"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_opensans_semibold_ttf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Open Sans Semibold"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_opensans_semibolditalic_ttf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Open Sans Semibold Italic"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_quicksand_bold_otf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Quicksand Bold"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_quicksand_bolditalic_otf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Quicksand Bold Italic"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_quicksand_italic_otf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Quicksand Italic"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_quicksand_light_otf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Quicksand Light"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_quicksand_lightitalic_otf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Quicksand Light Italic"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_quicksand_regular_otf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Quicksand Regular"; } #end }
@:keep #if display private #end class __ASSET__assets_fonts_quicksand_dash_otf extends flash.text.Font { #if (!openfl_html5_dom) public function new () { super (); fontName = "Quicksand Dash Regular"; } #end }




















#else

#if (windows || mac || linux)





@:keep class __ASSET__assets_fonts_opensans_bold_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-Bold.ttf"; fontName = "Open Sans Bold"; }}
@:keep class __ASSET__assets_fonts_opensans_bolditalic_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-BoldItalic.ttf"; fontName = "Open Sans Bold Italic"; }}
@:keep class __ASSET__assets_fonts_opensans_extrabold_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-ExtraBold.ttf"; fontName = "Open Sans Extrabold"; }}
@:keep class __ASSET__assets_fonts_opensans_extrabolditalic_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-ExtraBoldItalic.ttf"; fontName = "Open Sans Extrabold Italic"; }}
@:keep class __ASSET__assets_fonts_opensans_italic_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-Italic.ttf"; fontName = "Open Sans Italic"; }}
@:keep class __ASSET__assets_fonts_opensans_light_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-Light.ttf"; fontName = "Open Sans Light"; }}
@:keep class __ASSET__assets_fonts_opensans_lightitalic_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-LightItalic.ttf"; fontName = "Open Sans Light Italic"; }}
@:keep class __ASSET__assets_fonts_opensans_regular_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-Regular.ttf"; fontName = "Open Sans"; }}
@:keep class __ASSET__assets_fonts_opensans_semibold_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-Semibold.ttf"; fontName = "Open Sans Semibold"; }}
@:keep class __ASSET__assets_fonts_opensans_semibolditalic_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-SemiboldItalic.ttf"; fontName = "Open Sans Semibold Italic"; }}
@:keep class __ASSET__assets_fonts_quicksand_bold_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-Bold.otf"; fontName = "Quicksand Bold"; }}
@:keep class __ASSET__assets_fonts_quicksand_bolditalic_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-BoldItalic.otf"; fontName = "Quicksand Bold Italic"; }}
@:keep class __ASSET__assets_fonts_quicksand_italic_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-Italic.otf"; fontName = "Quicksand Italic"; }}
@:keep class __ASSET__assets_fonts_quicksand_light_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-Light.otf"; fontName = "Quicksand Light"; }}
@:keep class __ASSET__assets_fonts_quicksand_lightitalic_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-LightItalic.otf"; fontName = "Quicksand Light Italic"; }}
@:keep class __ASSET__assets_fonts_quicksand_regular_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-Regular.otf"; fontName = "Quicksand Regular"; }}
@:keep class __ASSET__assets_fonts_quicksand_dash_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand_Dash.otf"; fontName = "Quicksand Dash Regular"; }}


#else


class __ASSET__assets_fonts_opensans_bold_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-Bold.ttf"; fontName = "Open Sans Bold";  }}
class __ASSET__assets_fonts_opensans_bolditalic_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-BoldItalic.ttf"; fontName = "Open Sans Bold Italic";  }}
class __ASSET__assets_fonts_opensans_extrabold_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-ExtraBold.ttf"; fontName = "Open Sans Extrabold";  }}
class __ASSET__assets_fonts_opensans_extrabolditalic_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-ExtraBoldItalic.ttf"; fontName = "Open Sans Extrabold Italic";  }}
class __ASSET__assets_fonts_opensans_italic_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-Italic.ttf"; fontName = "Open Sans Italic";  }}
class __ASSET__assets_fonts_opensans_light_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-Light.ttf"; fontName = "Open Sans Light";  }}
class __ASSET__assets_fonts_opensans_lightitalic_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-LightItalic.ttf"; fontName = "Open Sans Light Italic";  }}
class __ASSET__assets_fonts_opensans_regular_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-Regular.ttf"; fontName = "Open Sans";  }}
class __ASSET__assets_fonts_opensans_semibold_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-Semibold.ttf"; fontName = "Open Sans Semibold";  }}
class __ASSET__assets_fonts_opensans_semibolditalic_ttf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/OpenSans-SemiboldItalic.ttf"; fontName = "Open Sans Semibold Italic";  }}
class __ASSET__assets_fonts_quicksand_bold_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-Bold.otf"; fontName = "Quicksand Bold";  }}
class __ASSET__assets_fonts_quicksand_bolditalic_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-BoldItalic.otf"; fontName = "Quicksand Bold Italic";  }}
class __ASSET__assets_fonts_quicksand_italic_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-Italic.otf"; fontName = "Quicksand Italic";  }}
class __ASSET__assets_fonts_quicksand_light_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-Light.otf"; fontName = "Quicksand Light";  }}
class __ASSET__assets_fonts_quicksand_lightitalic_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-LightItalic.otf"; fontName = "Quicksand Light Italic";  }}
class __ASSET__assets_fonts_quicksand_regular_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand-Regular.otf"; fontName = "Quicksand Regular";  }}
class __ASSET__assets_fonts_quicksand_dash_otf extends openfl.text.Font { public function new () { super (); __fontPath = "assets/fonts/Quicksand_Dash.otf"; fontName = "Quicksand Dash Regular";  }}


#end

#end
