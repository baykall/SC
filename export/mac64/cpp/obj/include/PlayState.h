#ifndef INCLUDED_PlayState
#define INCLUDED_PlayState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxState.h>
HX_DECLARE_CLASS0(BuildMode)
HX_DECLARE_CLASS0(City)
HX_DECLARE_CLASS0(HUD)
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS0(State)
HX_DECLARE_CLASS0(TTime)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxCamera)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxSpriteGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,text,FlxText)
HX_DECLARE_CLASS2(flixel,tile,FlxTilemap)
HX_DECLARE_CLASS2(flixel,ui,FlxButton)
HX_DECLARE_CLASS2(flixel,ui,FlxTypedButton)
HX_DECLARE_CLASS2(flixel,util,FlxPath)


class HXCPP_CLASS_ATTRIBUTES  PlayState_obj : public ::flixel::FlxState_obj{
	public:
		typedef ::flixel::FlxState_obj super;
		typedef PlayState_obj OBJ_;
		PlayState_obj();
		Void __construct(Dynamic MaxSize);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PlayState_obj > __new(Dynamic MaxSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PlayState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PlayState"); }

		::flixel::tile::FlxTilemap terrain;
		::flixel::tile::FlxTilemap plants;
		::flixel::tile::FlxTilemap roads;
		::flixel::tile::FlxTilemap towns;
		::flixel::tile::FlxTilemap buildings;
		::flixel::FlxSprite mouseicon;
		::flixel::FlxCamera camera;
		::flixel::FlxSprite cameraFocus;
		::HUD hud;
		::flixel::ui::FlxButton companyButton;
		::flixel::ui::FlxButton resourcesButton;
		::flixel::ui::FlxButton optionsButton;
		::State state;
		::BuildMode buildMode;
		bool stateSwitch;
		bool buildModeSwitch;
		::TTime ttime;
		Array< ::Dynamic > trucks;
		Array< ::Dynamic > truck_paths;
		Array< ::Dynamic > cities;
		Array< ::Dynamic > city_labels;
		Float truck_def_speed;
		virtual Void create( );

		virtual Void destroy( );

		virtual Void update( );

		virtual Void init_parameters( );
		Dynamic init_parameters_dyn();

		virtual Void init_time( );
		Dynamic init_time_dyn();

		virtual Void init_cities( );
		Dynamic init_cities_dyn();

		virtual Void init_graphics( );
		Dynamic init_graphics_dyn();

		virtual Void init_camera( );
		Dynamic init_camera_dyn();

		virtual Void init_HUD( );
		Dynamic init_HUD_dyn();

		virtual Void init_buttons( );
		Dynamic init_buttons_dyn();

		virtual Void init_trucks( );
		Dynamic init_trucks_dyn();

		virtual ::String get_map( ::String _type);
		Dynamic get_map_dyn();

		virtual Void move_camera( );
		Dynamic move_camera_dyn();

		virtual Void bound_camera( );
		Dynamic bound_camera_dyn();

		virtual Void input_keyboard( );
		Dynamic input_keyboard_dyn();

		virtual Void input_mouse( );
		Dynamic input_mouse_dyn();

		virtual Void update_state_dependent_items( );
		Dynamic update_state_dependent_items_dyn();

		virtual Void update_time( );
		Dynamic update_time_dyn();

		virtual Void move_trucks( );
		Dynamic move_trucks_dyn();

		virtual Void remove_arrived_trucks( );
		Dynamic remove_arrived_trucks_dyn();

		virtual Void execute_todays_events( );
		Dynamic execute_todays_events_dyn();

		virtual Void pause_game( );
		Dynamic pause_game_dyn();

		virtual Void resume_game( );
		Dynamic resume_game_dyn();

		virtual Void ship_truck( int from_x,int from_y,int to_x,int to_y);
		Dynamic ship_truck_dyn();

		virtual Void goCompany( );
		Dynamic goCompany_dyn();

		virtual Void goResources( );
		Dynamic goResources_dyn();

		virtual Void goOptions( );
		Dynamic goOptions_dyn();

		static int TILE_WIDTH;
		static int TILE_HEIGHT;
		static int LEVEL_WIDTH;
		static int LEVEL_HEIGHT;
		static int PIXEL_WIDTH;
		static int PIXEL_HEIGHT;
		static int CAMERA_SPEED;
		static ::String font;
		static int topButtonsSize;
		static int timeTextSize;
		static int cityTextSize;
		static int HUDHeight;
};


#endif /* INCLUDED_PlayState */ 
