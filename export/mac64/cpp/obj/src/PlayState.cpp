#include <hxcpp.h>

#ifndef INCLUDED_BuildMode
#include <BuildMode.h>
#endif
#ifndef INCLUDED_City
#include <City.h>
#endif
#ifndef INCLUDED_HUD
#include <HUD.h>
#endif
#ifndef INCLUDED_MMoment
#include <MMoment.h>
#endif
#ifndef INCLUDED_MenuState
#include <MenuState.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_State
#include <State.h>
#endif
#ifndef INCLUDED_TTime
#include <TTime.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimation
#include <flixel/animation/FlxAnimation.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_animation_FlxBaseAnimation
#include <flixel/animation/FlxBaseAnimation.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxSpriteGroup
#include <flixel/group/FlxSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyList
#include <flixel/input/keyboard/FlxKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_ui_FlxButton
#include <flixel/ui/FlxButton.h>
#endif
#ifndef INCLUDED_flixel_ui_FlxTypedButton
#include <flixel/ui/FlxTypedButton.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPath
#include <flixel/util/FlxPath.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPool_flixel_util_FlxPoint
#include <flixel/util/FlxPool_flixel_util_FlxPoint.h>
#endif
#ifndef INCLUDED_openfl__v2_Assets
#include <openfl/_v2/Assets.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObject
#include <openfl/_v2/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_DisplayObjectContainer
#include <openfl/_v2/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__v2_display_IBitmapDrawable
#include <openfl/_v2/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__v2_display_InteractiveObject
#include <openfl/_v2/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__v2_display_Sprite
#include <openfl/_v2/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__v2_events_EventDispatcher
#include <openfl/_v2/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__v2_events_IEventDispatcher
#include <openfl/_v2/events/IEventDispatcher.h>
#endif

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",27,0xb30d7781)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(73)
	this->buildModeSwitch = false;
	HX_STACK_LINE(72)
	this->stateSwitch = false;
	HX_STACK_LINE(71)
	this->buildMode = ::BuildMode_obj::None;
	HX_STACK_LINE(70)
	this->state = ::State_obj::Running;
	HX_STACK_LINE(27)
	super::__construct(MaxSize);
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(MaxSize);
	return result;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",86,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(87)
		this->super::create();
		HX_STACK_LINE(89)
		this->init_parameters();
		HX_STACK_LINE(91)
		this->init_time();
		HX_STACK_LINE(92)
		this->init_cities();
		HX_STACK_LINE(94)
		this->init_graphics();
		HX_STACK_LINE(95)
		this->init_camera();
		HX_STACK_LINE(96)
		this->init_HUD();
		HX_STACK_LINE(97)
		this->init_buttons();
		HX_STACK_LINE(99)
		this->init_trucks();
	}
return null();
}


Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",103,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(103)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",106,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(107)
		this->super::update();
		HX_STACK_LINE(110)
		this->move_camera();
		HX_STACK_LINE(111)
		this->bound_camera();
		HX_STACK_LINE(114)
		this->input_keyboard();
		HX_STACK_LINE(115)
		this->input_mouse();
		HX_STACK_LINE(118)
		this->update_state_dependent_items();
		HX_STACK_LINE(120)
		if (((this->state == ::State_obj::Running))){
			HX_STACK_LINE(121)
			this->update_time();
			HX_STACK_LINE(122)
			this->move_trucks();
			HX_STACK_LINE(123)
			this->remove_arrived_trucks();
			HX_STACK_LINE(124)
			if (((this->ttime->mmoment == ::MMoment_obj::NewDay))){
				HX_STACK_LINE(125)
				this->execute_todays_events();
			}
		}
	}
return null();
}


Void PlayState_obj::init_parameters( ){
{
		HX_STACK_FRAME("PlayState","init_parameters",0xd8db3ba8,"PlayState.init_parameters","PlayState.hx",133,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(133)
		this->truck_def_speed = (int)150;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,init_parameters,(void))

Void PlayState_obj::init_time( ){
{
		HX_STACK_FRAME("PlayState","init_time",0xc4c5568b,"PlayState.init_time","PlayState.hx",136,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(137)
		::TTime _g = ::TTime_obj::__new((int)12,HX_CSTRING("January"),(int)1678,(int)100);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(137)
		this->ttime = _g;
		HX_STACK_LINE(138)
		this->state = ::State_obj::Running;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,init_time,(void))

Void PlayState_obj::init_cities( ){
{
		HX_STACK_FRAME("PlayState","init_cities",0xba430cc7,"PlayState.init_cities","PlayState.hx",141,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(142)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(142)
		this->cities = _g;
		HX_STACK_LINE(144)
		::City city;		HX_STACK_VAR(city,"city");
		HX_STACK_LINE(146)
		::City _g1 = ::City_obj::__new(HX_CSTRING("Ann Arbor"),(int)14,(int)6,Array_obj< int >::__new().Add((int)500).Add((int)200).Add((int)50));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(146)
		city = _g1;
		HX_STACK_LINE(147)
		this->cities->push(city);
		HX_STACK_LINE(148)
		::City _g2 = ::City_obj::__new(HX_CSTRING("Atlanta"),(int)33,(int)19,Array_obj< int >::__new().Add((int)400).Add((int)300).Add((int)50));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(148)
		city = _g2;
		HX_STACK_LINE(149)
		this->cities->push(city);
		HX_STACK_LINE(150)
		::City _g3 = ::City_obj::__new(HX_CSTRING("New York"),(int)12,(int)20,Array_obj< int >::__new().Add((int)1000).Add((int)400).Add((int)0));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(150)
		city = _g3;
		HX_STACK_LINE(151)
		this->cities->push(city);
		HX_STACK_LINE(152)
		::City _g4 = ::City_obj::__new(HX_CSTRING("Phoenix"),(int)14,(int)34,Array_obj< int >::__new().Add((int)800).Add((int)100).Add((int)25));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(152)
		city = _g4;
		HX_STACK_LINE(153)
		this->cities->push(city);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,init_cities,(void))

Void PlayState_obj::init_graphics( ){
{
		HX_STACK_FRAME("PlayState","init_graphics",0xe6ba9a49,"PlayState.init_graphics","PlayState.hx",156,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(157)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(157)
		this->city_labels = _g;
		HX_STACK_LINE(158)
		::flixel::text::FlxText label;		HX_STACK_VAR(label,"label");
		HX_STACK_LINE(160)
		::String terrain_map;		HX_STACK_VAR(terrain_map,"terrain_map");
		HX_STACK_LINE(161)
		::String plants_map;		HX_STACK_VAR(plants_map,"plants_map");
		HX_STACK_LINE(162)
		::String roads_map;		HX_STACK_VAR(roads_map,"roads_map");
		HX_STACK_LINE(163)
		::String towns_map;		HX_STACK_VAR(towns_map,"towns_map");
		HX_STACK_LINE(164)
		::String buildings_map;		HX_STACK_VAR(buildings_map,"buildings_map");
		HX_STACK_LINE(166)
		::String _g1 = ::openfl::_v2::Assets_obj::getText(HX_CSTRING("assets/data/terrain_map.csv"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(166)
		terrain_map = _g1;
		HX_STACK_LINE(167)
		::String _g2 = ::openfl::_v2::Assets_obj::getText(HX_CSTRING("assets/data/resources_map.csv"));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(167)
		plants_map = _g2;
		HX_STACK_LINE(168)
		::String _g3 = ::openfl::_v2::Assets_obj::getText(HX_CSTRING("assets/data/roads_map.csv"));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(168)
		roads_map = _g3;
		HX_STACK_LINE(169)
		::String _g4 = this->get_map(HX_CSTRING("Cities"));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(169)
		towns_map = _g4;
		HX_STACK_LINE(170)
		::String _g5 = this->get_map(HX_CSTRING("Buildings"));		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(170)
		buildings_map = _g5;
		HX_STACK_LINE(173)
		::flixel::tile::FlxTilemap _g6 = ::flixel::tile::FlxTilemap_obj::__new();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(173)
		this->terrain = _g6;
		HX_STACK_LINE(174)
		this->terrain->loadMap(terrain_map,HX_CSTRING("assets/images/terrain.png"),::PlayState_obj::TILE_WIDTH,::PlayState_obj::TILE_HEIGHT,(int)0,(int)1,null(),null());
		HX_STACK_LINE(175)
		this->add(this->terrain);
		HX_STACK_LINE(178)
		::flixel::tile::FlxTilemap _g7 = ::flixel::tile::FlxTilemap_obj::__new();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(178)
		this->plants = _g7;
		HX_STACK_LINE(179)
		this->plants->loadMap(plants_map,HX_CSTRING("assets/images/resources.png"),::PlayState_obj::TILE_WIDTH,::PlayState_obj::TILE_HEIGHT,(int)0,(int)1,null(),null());
		HX_STACK_LINE(180)
		this->add(this->plants);
		HX_STACK_LINE(183)
		::flixel::tile::FlxTilemap _g8 = ::flixel::tile::FlxTilemap_obj::__new();		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(183)
		this->roads = _g8;
		HX_STACK_LINE(184)
		this->roads->loadMap(roads_map,HX_CSTRING("assets/images/roads.png"),::PlayState_obj::TILE_WIDTH,::PlayState_obj::TILE_HEIGHT,(int)0,(int)1,null(),null());
		HX_STACK_LINE(185)
		this->add(this->roads);
		HX_STACK_LINE(187)
		this->roads->setTileProperties((int)0,(int)4369,null(),null(),null());
		HX_STACK_LINE(188)
		{
			HX_STACK_LINE(188)
			int _g9 = (int)1;		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(188)
			while((true)){
				HX_STACK_LINE(188)
				if ((!(((_g9 < (int)11))))){
					HX_STACK_LINE(188)
					break;
				}
				HX_STACK_LINE(188)
				int i = (_g9)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(189)
				this->roads->setTileProperties(i,(int)0,null(),null(),null());
			}
		}
		HX_STACK_LINE(192)
		::flixel::tile::FlxTilemap _g9 = ::flixel::tile::FlxTilemap_obj::__new();		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(192)
		this->towns = _g9;
		HX_STACK_LINE(193)
		this->towns->loadMap(towns_map,HX_CSTRING("assets/images/towns.png"),::PlayState_obj::TILE_WIDTH,::PlayState_obj::TILE_HEIGHT,(int)0,(int)1,null(),null());
		HX_STACK_LINE(194)
		this->add(this->towns);
		HX_STACK_LINE(197)
		::flixel::tile::FlxTilemap _g10 = ::flixel::tile::FlxTilemap_obj::__new();		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(197)
		this->buildings = _g10;
		HX_STACK_LINE(198)
		this->buildings->loadMap(buildings_map,HX_CSTRING("assets/images/buildings.png"),::PlayState_obj::TILE_WIDTH,::PlayState_obj::TILE_HEIGHT,(int)0,(int)1,null(),null());
		HX_STACK_LINE(199)
		this->add(this->buildings);
		HX_STACK_LINE(202)
		{
			HX_STACK_LINE(202)
			int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(202)
			int _g12 = this->cities->length;		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(202)
			while((true)){
				HX_STACK_LINE(202)
				if ((!(((_g11 < _g12))))){
					HX_STACK_LINE(202)
					break;
				}
				HX_STACK_LINE(202)
				int i = (_g11)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(203)
				::flixel::text::FlxText _g111 = ::flixel::text::FlxText_obj::__new(this->cities->__get(i).StaticCast< ::City >()->label_coordinate_x,this->cities->__get(i).StaticCast< ::City >()->label_coordinate_y,null(),null(),null(),null());		HX_STACK_VAR(_g111,"_g111");
				HX_STACK_LINE(203)
				label = _g111;
				HX_STACK_LINE(204)
				label->setFormat((HX_CSTRING("assets/fonts/") + ::PlayState_obj::font),::PlayState_obj::cityTextSize,(int)-1,HX_CSTRING("center"),null(),null(),null());
				HX_STACK_LINE(205)
				label->set_text(this->cities->__get(i).StaticCast< ::City >()->name);
				HX_STACK_LINE(206)
				this->add(label);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,init_graphics,(void))

Void PlayState_obj::init_camera( ){
{
		HX_STACK_FRAME("PlayState","init_camera",0x1a6aeca3,"PlayState.init_camera","PlayState.hx",210,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(211)
		::flixel::FlxSprite _g = ::flixel::FlxSprite_obj::__new(null(),null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(211)
		this->cameraFocus = _g;
		HX_STACK_LINE(212)
		this->cameraFocus->makeGraphic((int)1,(int)1,(int)0,null(),null());
		HX_STACK_LINE(213)
		this->cameraFocus->set_x((Float(::PlayState_obj::PIXEL_WIDTH) / Float((int)2)));
		HX_STACK_LINE(214)
		this->cameraFocus->set_y((Float(::PlayState_obj::PIXEL_HEIGHT) / Float((int)2)));
		HX_STACK_LINE(215)
		this->add(this->cameraFocus);
		HX_STACK_LINE(217)
		this->camera = ::flixel::FlxG_obj::camera;
		HX_STACK_LINE(218)
		this->camera->follow(this->cameraFocus,(int)0,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,init_camera,(void))

Void PlayState_obj::init_HUD( ){
{
		HX_STACK_FRAME("PlayState","init_HUD",0x07a3bbd9,"PlayState.init_HUD","PlayState.hx",221,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(222)
		::HUD _g = ::HUD_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(222)
		this->hud = _g;
		HX_STACK_LINE(223)
		this->add(this->hud);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,init_HUD,(void))

Void PlayState_obj::init_buttons( ){
{
		HX_STACK_FRAME("PlayState","init_buttons",0xea67ea83,"PlayState.init_buttons","PlayState.hx",226,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(227)
		::flixel::ui::FlxButton _g = ::flixel::ui::FlxButton_obj::__new((int)10,(int)0,HX_CSTRING("Company"),this->goCompany_dyn());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(227)
		this->companyButton = _g;
		HX_STACK_LINE(228)
		this->companyButton->label->__Field(HX_CSTRING("setFormat"),true)((HX_CSTRING("assets/fonts/") + ::PlayState_obj::font),::PlayState_obj::topButtonsSize,(int)-1,HX_CSTRING("left"),null(),null(),null());
		HX_STACK_LINE(229)
		this->companyButton->loadGraphic(HX_CSTRING("assets/images/empty.png"),null(),null(),null(),null(),null());
		HX_STACK_LINE(230)
		this->add(this->companyButton);
		HX_STACK_LINE(232)
		::flixel::ui::FlxButton _g1 = ::flixel::ui::FlxButton_obj::__new((int)160,(int)0,HX_CSTRING("Resources"),this->goResources_dyn());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(232)
		this->resourcesButton = _g1;
		HX_STACK_LINE(233)
		this->resourcesButton->label->__Field(HX_CSTRING("setFormat"),true)((HX_CSTRING("assets/fonts/") + ::PlayState_obj::font),::PlayState_obj::topButtonsSize,(int)-1,HX_CSTRING("left"),null(),null(),null());
		HX_STACK_LINE(234)
		this->resourcesButton->loadGraphic(HX_CSTRING("assets/images/empty.png"),null(),null(),null(),null(),null());
		HX_STACK_LINE(235)
		this->add(this->resourcesButton);
		HX_STACK_LINE(237)
		::flixel::ui::FlxButton _g2 = ::flixel::ui::FlxButton_obj::__new((int)310,(int)0,HX_CSTRING("Options"),this->goOptions_dyn());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(237)
		this->optionsButton = _g2;
		HX_STACK_LINE(238)
		this->optionsButton->label->__Field(HX_CSTRING("setFormat"),true)((HX_CSTRING("assets/fonts/") + ::PlayState_obj::font),::PlayState_obj::topButtonsSize,(int)-1,HX_CSTRING("left"),null(),null(),null());
		HX_STACK_LINE(239)
		this->optionsButton->loadGraphic(HX_CSTRING("assets/images/empty.png"),null(),null(),null(),null(),null());
		HX_STACK_LINE(240)
		this->add(this->optionsButton);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,init_buttons,(void))

Void PlayState_obj::init_trucks( ){
{
		HX_STACK_FRAME("PlayState","init_trucks",0xb59415f2,"PlayState.init_trucks","PlayState.hx",243,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(244)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(244)
		this->trucks = _g;
		HX_STACK_LINE(245)
		Array< ::Dynamic > _g1 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(245)
		this->truck_paths = _g1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,init_trucks,(void))

::String PlayState_obj::get_map( ::String _type){
	HX_STACK_FRAME("PlayState","get_map",0x7108fd22,"PlayState.get_map","PlayState.hx",250,0xb30d7781)
	HX_STACK_THIS(this)
	HX_STACK_ARG(_type,"_type")
	HX_STACK_LINE(251)
	::String map = HX_CSTRING("");		HX_STACK_VAR(map,"map");
	HX_STACK_LINE(252)
	int x_cor;		HX_STACK_VAR(x_cor,"x_cor");
	HX_STACK_LINE(253)
	int y_cor;		HX_STACK_VAR(y_cor,"y_cor");
	HX_STACK_LINE(254)
	{
		HX_STACK_LINE(254)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(254)
		int _g = ::PlayState_obj::LEVEL_HEIGHT;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(254)
		while((true)){
			HX_STACK_LINE(254)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(254)
				break;
			}
			HX_STACK_LINE(254)
			int row = (_g1)++;		HX_STACK_VAR(row,"row");
			HX_STACK_LINE(255)
			y_cor = (row + (int)1);
			HX_STACK_LINE(256)
			{
				HX_STACK_LINE(256)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(256)
				int _g2 = ::PlayState_obj::LEVEL_WIDTH;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(256)
				while((true)){
					HX_STACK_LINE(256)
					if ((!(((_g3 < _g2))))){
						HX_STACK_LINE(256)
						break;
					}
					HX_STACK_LINE(256)
					int col = (_g3)++;		HX_STACK_VAR(col,"col");
					HX_STACK_LINE(257)
					x_cor = (col + (int)1);
					HX_STACK_LINE(258)
					::String val = HX_CSTRING("");		HX_STACK_VAR(val,"val");
					HX_STACK_LINE(259)
					if (((_type == HX_CSTRING("Cities")))){
						HX_STACK_LINE(260)
						bool town_loc = false;		HX_STACK_VAR(town_loc,"town_loc");
						HX_STACK_LINE(261)
						{
							HX_STACK_LINE(261)
							int _g5 = (int)0;		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(261)
							int _g4 = this->cities->length;		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(261)
							while((true)){
								HX_STACK_LINE(261)
								if ((!(((_g5 < _g4))))){
									HX_STACK_LINE(261)
									break;
								}
								HX_STACK_LINE(261)
								int i = (_g5)++;		HX_STACK_VAR(i,"i");
								HX_STACK_LINE(262)
								if (((bool((bool((bool((this->cities->__get(i).StaticCast< ::City >()->coordinate_x <= (x_cor + (int)1))) && bool((this->cities->__get(i).StaticCast< ::City >()->coordinate_x >= (x_cor - (int)1))))) && bool((this->cities->__get(i).StaticCast< ::City >()->coordinate_y <= (y_cor + (int)1))))) && bool((this->cities->__get(i).StaticCast< ::City >()->coordinate_y >= (y_cor - (int)1)))))){
									HX_STACK_LINE(263)
									town_loc = true;
								}
							}
						}
						HX_STACK_LINE(265)
						if (((town_loc == true))){
							HX_STACK_LINE(266)
							val = HX_CSTRING("1");
						}
						else{
							HX_STACK_LINE(268)
							val = HX_CSTRING("0");
						}
					}
					else{
						HX_STACK_LINE(270)
						if (((_type == HX_CSTRING("Buildings")))){
							HX_STACK_LINE(271)
							val = HX_CSTRING("0");
						}
					}
					HX_STACK_LINE(273)
					map = (map + val);
					HX_STACK_LINE(274)
					if (((col < (::PlayState_obj::LEVEL_WIDTH - (int)1)))){
						HX_STACK_LINE(275)
						map = (map + HX_CSTRING(","));
					}
					else{
						HX_STACK_LINE(276)
						if (((row < (::PlayState_obj::LEVEL_HEIGHT - (int)1)))){
							HX_STACK_LINE(277)
							map = (map + HX_CSTRING("\n"));
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(280)
	return map;
}


HX_DEFINE_DYNAMIC_FUNC1(PlayState_obj,get_map,return )

Void PlayState_obj::move_camera( ){
{
		HX_STACK_FRAME("PlayState","move_camera",0x3a7cb6c2,"PlayState.move_camera","PlayState.hx",285,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(286)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("DOWN")).Add(HX_CSTRING("S")),(int)1))){
			HX_STACK_LINE(287)
			::flixel::FlxSprite _g = this->cameraFocus;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(287)
			_g->set_y((_g->y + ::PlayState_obj::CAMERA_SPEED));
		}
		HX_STACK_LINE(288)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("UP")).Add(HX_CSTRING("W")),(int)1))){
			HX_STACK_LINE(289)
			::flixel::FlxSprite _g = this->cameraFocus;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(289)
			_g->set_y((_g->y - ::PlayState_obj::CAMERA_SPEED));
		}
		HX_STACK_LINE(290)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("RIGHT")).Add(HX_CSTRING("D")),(int)1))){
			HX_STACK_LINE(291)
			::flixel::FlxSprite _g = this->cameraFocus;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(291)
			_g->set_x((_g->x + ::PlayState_obj::CAMERA_SPEED));
		}
		HX_STACK_LINE(292)
		if ((::flixel::FlxG_obj::keys->checkKeyStatus(Array_obj< ::String >::__new().Add(HX_CSTRING("LEFT")).Add(HX_CSTRING("A")),(int)1))){
			HX_STACK_LINE(293)
			::flixel::FlxSprite _g = this->cameraFocus;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(293)
			_g->set_x((_g->x - ::PlayState_obj::CAMERA_SPEED));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,move_camera,(void))

Void PlayState_obj::bound_camera( ){
{
		HX_STACK_FRAME("PlayState","bound_camera",0x2a69bf77,"PlayState.bound_camera","PlayState.hx",296,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(297)
		if (((this->cameraFocus->x < (Float(::flixel::FlxG_obj::width) / Float((int)2))))){
			HX_STACK_LINE(298)
			this->cameraFocus->set_x((Float(::flixel::FlxG_obj::width) / Float((int)2)));
		}
		else{
			HX_STACK_LINE(299)
			if (((this->cameraFocus->x > ((::PlayState_obj::LEVEL_WIDTH * ::PlayState_obj::TILE_WIDTH) - (Float(::flixel::FlxG_obj::width) / Float((int)2)))))){
				HX_STACK_LINE(300)
				this->cameraFocus->set_x(((::PlayState_obj::LEVEL_WIDTH * ::PlayState_obj::TILE_WIDTH) - (Float(::flixel::FlxG_obj::width) / Float((int)2))));
			}
		}
		HX_STACK_LINE(301)
		if (((this->cameraFocus->y < (Float(::flixel::FlxG_obj::height) / Float((int)2))))){
			HX_STACK_LINE(302)
			this->cameraFocus->set_y((Float(::flixel::FlxG_obj::height) / Float((int)2)));
		}
		else{
			HX_STACK_LINE(303)
			if (((this->cameraFocus->y > ((::PlayState_obj::LEVEL_HEIGHT * ::PlayState_obj::TILE_HEIGHT) - (Float(::flixel::FlxG_obj::height) / Float((int)2)))))){
				HX_STACK_LINE(304)
				this->cameraFocus->set_y(((::PlayState_obj::LEVEL_HEIGHT * ::PlayState_obj::TILE_HEIGHT) - (Float(::flixel::FlxG_obj::height) / Float((int)2))));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,bound_camera,(void))

Void PlayState_obj::input_keyboard( ){
{
		HX_STACK_FRAME("PlayState","input_keyboard",0xb6f0a0ad,"PlayState.input_keyboard","PlayState.hx",308,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(308)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)32,::flixel::FlxG_obj::keys->justPressed->checkStatus))){
			HX_STACK_LINE(309)
			if (((this->state == ::State_obj::Running))){
				HX_STACK_LINE(310)
				this->state = ::State_obj::Paused;
			}
			else{
				HX_STACK_LINE(312)
				this->state = ::State_obj::Running;
			}
			HX_STACK_LINE(313)
			this->stateSwitch = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,input_keyboard,(void))

Void PlayState_obj::input_mouse( ){
{
		HX_STACK_FRAME("PlayState","input_mouse",0xd23a125f,"PlayState.input_mouse","PlayState.hx",318,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(318)
		Dynamic x;		HX_STACK_VAR(x,"x");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,input_mouse,(void))

Void PlayState_obj::update_state_dependent_items( ){
{
		HX_STACK_FRAME("PlayState","update_state_dependent_items",0xa86394cd,"PlayState.update_state_dependent_items","PlayState.hx",330,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(330)
		if (((this->stateSwitch == true))){
			HX_STACK_LINE(331)
			if (((this->state == ::State_obj::Running))){
				HX_STACK_LINE(332)
				this->resume_game();
			}
			else{
				HX_STACK_LINE(334)
				this->pause_game();
			}
			HX_STACK_LINE(335)
			this->stateSwitch = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,update_state_dependent_items,(void))

Void PlayState_obj::update_time( ){
{
		HX_STACK_FRAME("PlayState","update_time",0x5bc72eb2,"PlayState.update_time","PlayState.hx",339,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(340)
		::String calendar_day;		HX_STACK_VAR(calendar_day,"calendar_day");
		HX_STACK_LINE(341)
		this->ttime->update();
		HX_STACK_LINE(342)
		calendar_day = this->ttime->calendar_day;
		HX_STACK_LINE(343)
		this->hud->update_time(calendar_day);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,update_time,(void))

Void PlayState_obj::move_trucks( ){
{
		HX_STACK_FRAME("PlayState","move_trucks",0xd5a5e011,"PlayState.move_trucks","PlayState.hx",347,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(347)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(347)
		int _g = this->trucks->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(347)
		while((true)){
			HX_STACK_LINE(347)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(347)
				break;
			}
			HX_STACK_LINE(347)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(348)
			if (((bool(!(this->truck_paths->__get(i).StaticCast< ::flixel::util::FlxPath >()->finished)) && bool((this->truck_paths->__get(i).StaticCast< ::flixel::util::FlxPath >()->nodes != null()))))){
				HX_STACK_LINE(349)
				if (((this->truck_paths->__get(i).StaticCast< ::flixel::util::FlxPath >()->angle == (int)0))){
					HX_STACK_LINE(350)
					this->trucks->__get(i).StaticCast< ::flixel::FlxSprite >()->animation->play(HX_CSTRING("up"),null(),null());
				}
				else{
					HX_STACK_LINE(351)
					if (((this->truck_paths->__get(i).StaticCast< ::flixel::util::FlxPath >()->angle == (int)180))){
						HX_STACK_LINE(352)
						this->trucks->__get(i).StaticCast< ::flixel::FlxSprite >()->animation->play(HX_CSTRING("down"),null(),null());
					}
					else{
						HX_STACK_LINE(353)
						if (((this->truck_paths->__get(i).StaticCast< ::flixel::util::FlxPath >()->angle == (int)90))){
							HX_STACK_LINE(354)
							this->trucks->__get(i).StaticCast< ::flixel::FlxSprite >()->animation->play(HX_CSTRING("right"),null(),null());
						}
						else{
							HX_STACK_LINE(355)
							if (((this->truck_paths->__get(i).StaticCast< ::flixel::util::FlxPath >()->angle == (int)-90))){
								HX_STACK_LINE(356)
								this->trucks->__get(i).StaticCast< ::flixel::FlxSprite >()->animation->play(HX_CSTRING("left"),null(),null());
							}
						}
					}
				}
			}
			else{
				struct _Function_3_1{
					inline static ::flixel::animation::FlxAnimation Block( int &i,hx::ObjectPtr< ::PlayState_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","PlayState.hx",359,0xb30d7781)
						{
							HX_STACK_LINE(359)
							::flixel::animation::FlxAnimationController _this = __this->trucks->__get(i).StaticCast< ::flixel::FlxSprite >()->animation;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(359)
							::flixel::animation::FlxAnimation anim = null();		HX_STACK_VAR(anim,"anim");
							HX_STACK_LINE(359)
							if (((bool((bool((_this->_curAnim != null())) && bool((_this->_curAnim->delay > (int)0)))) && bool(((bool(_this->_curAnim->looped) || bool(!(_this->_curAnim->finished)))))))){
								HX_STACK_LINE(359)
								anim = _this->_curAnim;
							}
							HX_STACK_LINE(359)
							return anim;
						}
						return null();
					}
				};
				HX_STACK_LINE(359)
				(_Function_3_1::Block(i,this))->set_curFrame((int)0);
				struct _Function_3_2{
					inline static ::flixel::animation::FlxAnimation Block( int &i,hx::ObjectPtr< ::PlayState_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","PlayState.hx",360,0xb30d7781)
						{
							HX_STACK_LINE(360)
							::flixel::animation::FlxAnimationController _this = __this->trucks->__get(i).StaticCast< ::flixel::FlxSprite >()->animation;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(360)
							::flixel::animation::FlxAnimation anim = null();		HX_STACK_VAR(anim,"anim");
							HX_STACK_LINE(360)
							if (((bool((bool((_this->_curAnim != null())) && bool((_this->_curAnim->delay > (int)0)))) && bool(((bool(_this->_curAnim->looped) || bool(!(_this->_curAnim->finished)))))))){
								HX_STACK_LINE(360)
								anim = _this->_curAnim;
							}
							HX_STACK_LINE(360)
							return anim;
						}
						return null();
					}
				};
				HX_STACK_LINE(360)
				(_Function_3_2::Block(i,this))->stop();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,move_trucks,(void))

Void PlayState_obj::remove_arrived_trucks( ){
{
		HX_STACK_FRAME("PlayState","remove_arrived_trucks",0x878333d0,"PlayState.remove_arrived_trucks","PlayState.hx",365,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(366)
		int truck_no;		HX_STACK_VAR(truck_no,"truck_no");
		HX_STACK_LINE(368)
		truck_no = (int)-1;
		HX_STACK_LINE(369)
		{
			HX_STACK_LINE(369)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(369)
			int _g = this->trucks->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(369)
			while((true)){
				HX_STACK_LINE(369)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(369)
					break;
				}
				HX_STACK_LINE(369)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(370)
				if ((this->truck_paths->__get(i).StaticCast< ::flixel::util::FlxPath >()->finished)){
					HX_STACK_LINE(371)
					this->remove(this->trucks->__get(i).StaticCast< ::flixel::FlxSprite >(),null());
					HX_STACK_LINE(372)
					this->truck_paths->__get(i).StaticCast< ::flixel::util::FlxPath >()->destroy();
					HX_STACK_LINE(373)
					truck_no = i;
				}
			}
		}
		HX_STACK_LINE(377)
		if (((truck_no >= (int)0))){
			HX_STACK_LINE(378)
			this->trucks->splice(truck_no,(int)1);
			HX_STACK_LINE(379)
			this->truck_paths->splice(truck_no,(int)1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,remove_arrived_trucks,(void))

Void PlayState_obj::execute_todays_events( ){
{
		HX_STACK_FRAME("PlayState","execute_todays_events",0x4bed98cb,"PlayState.execute_todays_events","PlayState.hx",383,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(384)
		if (((this->ttime->total_days == (int)1))){
			HX_STACK_LINE(385)
			this->buildMode = ::BuildMode_obj::WheatFarm;
		}
		HX_STACK_LINE(386)
		if (((this->ttime->total_days == (int)2))){
			HX_STACK_LINE(387)
			this->ship_truck((int)26,(int)34,(int)16,(int)6);
		}
		HX_STACK_LINE(388)
		if (((this->ttime->total_days == (int)3))){
			HX_STACK_LINE(389)
			this->ship_truck((int)30,(int)19,(int)15,(int)20);
		}
		HX_STACK_LINE(391)
		if (((this->ttime->total_days == (int)4))){
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,execute_todays_events,(void))

Void PlayState_obj::pause_game( ){
{
		HX_STACK_FRAME("PlayState","pause_game",0xc5d3b28c,"PlayState.pause_game","PlayState.hx",402,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(402)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(402)
		int _g = this->truck_paths->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(402)
		while((true)){
			HX_STACK_LINE(402)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(402)
				break;
			}
			HX_STACK_LINE(402)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(403)
			this->truck_paths->__get(i).StaticCast< ::flixel::util::FlxPath >()->speed = (int)0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,pause_game,(void))

Void PlayState_obj::resume_game( ){
{
		HX_STACK_FRAME("PlayState","resume_game",0x3e5ac073,"PlayState.resume_game","PlayState.hx",408,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(408)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(408)
		int _g = this->truck_paths->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(408)
		while((true)){
			HX_STACK_LINE(408)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(408)
				break;
			}
			HX_STACK_LINE(408)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(409)
			this->truck_paths->__get(i).StaticCast< ::flixel::util::FlxPath >()->speed = this->truck_def_speed;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,resume_game,(void))

Void PlayState_obj::ship_truck( int from_x,int from_y,int to_x,int to_y){
{
		HX_STACK_FRAME("PlayState","ship_truck",0x58c9bd0d,"PlayState.ship_truck","PlayState.hx",413,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(from_x,"from_x")
		HX_STACK_ARG(from_y,"from_y")
		HX_STACK_ARG(to_x,"to_x")
		HX_STACK_ARG(to_y,"to_y")
		HX_STACK_LINE(414)
		::flixel::FlxSprite truck;		HX_STACK_VAR(truck,"truck");
		HX_STACK_LINE(415)
		::flixel::util::FlxPath truck_path;		HX_STACK_VAR(truck_path,"truck_path");
		HX_STACK_LINE(417)
		::flixel::FlxSprite _g = ::flixel::FlxSprite_obj::__new((((from_x - (int)1)) * ::PlayState_obj::TILE_WIDTH),(((from_y - (int)1)) * ::PlayState_obj::TILE_HEIGHT),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(417)
		truck = _g;
		HX_STACK_LINE(418)
		truck->loadGraphic(HX_CSTRING("assets/images/truck.png"),true,::PlayState_obj::TILE_WIDTH,::PlayState_obj::TILE_HEIGHT,null(),null());
		HX_STACK_LINE(419)
		truck->animation->add(HX_CSTRING("left"),Array_obj< int >::__new().Add((int)0),null(),null());
		HX_STACK_LINE(420)
		truck->animation->add(HX_CSTRING("right"),Array_obj< int >::__new().Add((int)1),null(),null());
		HX_STACK_LINE(421)
		truck->animation->add(HX_CSTRING("down"),Array_obj< int >::__new().Add((int)2),null(),null());
		HX_STACK_LINE(422)
		truck->animation->add(HX_CSTRING("up"),Array_obj< int >::__new().Add((int)3),null(),null());
		HX_STACK_LINE(424)
		this->trucks->push(truck);
		HX_STACK_LINE(426)
		this->add(this->trucks->__get((this->trucks->length - (int)1)).StaticCast< ::flixel::FlxSprite >());
		HX_STACK_LINE(428)
		::flixel::util::FlxPath _g1 = ::flixel::util::FlxPath_obj::__new(null(),null(),null(),null(),null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(428)
		truck_path = _g1;
		HX_STACK_LINE(430)
		this->truck_paths->push(truck_path);
		HX_STACK_LINE(432)
		::flixel::util::FlxPoint _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(432)
		{
			HX_STACK_LINE(432)
			::flixel::util::FlxPoint point = ::flixel::util::FlxPoint_obj::_pool->get()->set(truck->x,truck->y);		HX_STACK_VAR(point,"point");
			HX_STACK_LINE(432)
			point->_inPool = false;
			HX_STACK_LINE(432)
			_g2 = point;
		}
		HX_STACK_LINE(432)
		::flixel::util::FlxPoint _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(432)
		{
			HX_STACK_LINE(432)
			::flixel::util::FlxPoint point = ::flixel::util::FlxPoint_obj::_pool->get()->set((((to_x - 0.5)) * ::PlayState_obj::TILE_WIDTH),(((to_y - 0.5)) * ::PlayState_obj::TILE_HEIGHT));		HX_STACK_VAR(point,"point");
			HX_STACK_LINE(432)
			point->_inPool = false;
			HX_STACK_LINE(432)
			_g3 = point;
		}
		HX_STACK_LINE(432)
		Array< ::Dynamic > nodes = this->roads->findPath(_g2,_g3,null(),null(),null());		HX_STACK_VAR(nodes,"nodes");
		HX_STACK_LINE(434)
		this->truck_paths->__get((this->truck_paths->length - (int)1)).StaticCast< ::flixel::util::FlxPath >()->start(this->trucks->__get((this->trucks->length - (int)1)).StaticCast< ::flixel::FlxSprite >(),nodes,this->truck_def_speed,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(PlayState_obj,ship_truck,(void))

Void PlayState_obj::goCompany( ){
{
		HX_STACK_FRAME("PlayState","goCompany",0x390dbba4,"PlayState.goCompany","PlayState.hx",440,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(440)
		::flixel::FlxState State = ::MenuState_obj::__new(null());		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(440)
		::flixel::FlxG_obj::game->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,goCompany,(void))

Void PlayState_obj::goResources( ){
{
		HX_STACK_FRAME("PlayState","goResources",0x1e99260c,"PlayState.goResources","PlayState.hx",444,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(444)
		::flixel::FlxState State = ::MenuState_obj::__new(null());		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(444)
		::flixel::FlxG_obj::game->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,goResources,(void))

Void PlayState_obj::goOptions( ){
{
		HX_STACK_FRAME("PlayState","goOptions",0x95a2d9c5,"PlayState.goOptions","PlayState.hx",448,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(448)
		::flixel::FlxState State = ::MenuState_obj::__new(null());		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(448)
		::flixel::FlxG_obj::game->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,goOptions,(void))

int PlayState_obj::TILE_WIDTH;

int PlayState_obj::TILE_HEIGHT;

int PlayState_obj::LEVEL_WIDTH;

int PlayState_obj::LEVEL_HEIGHT;

int PlayState_obj::PIXEL_WIDTH;

int PlayState_obj::PIXEL_HEIGHT;

int PlayState_obj::CAMERA_SPEED;

::String PlayState_obj::font;

int PlayState_obj::topButtonsSize;

int PlayState_obj::timeTextSize;

int PlayState_obj::cityTextSize;

int PlayState_obj::HUDHeight;


PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(terrain,"terrain");
	HX_MARK_MEMBER_NAME(plants,"plants");
	HX_MARK_MEMBER_NAME(roads,"roads");
	HX_MARK_MEMBER_NAME(towns,"towns");
	HX_MARK_MEMBER_NAME(buildings,"buildings");
	HX_MARK_MEMBER_NAME(mouseicon,"mouseicon");
	HX_MARK_MEMBER_NAME(camera,"camera");
	HX_MARK_MEMBER_NAME(cameraFocus,"cameraFocus");
	HX_MARK_MEMBER_NAME(hud,"hud");
	HX_MARK_MEMBER_NAME(companyButton,"companyButton");
	HX_MARK_MEMBER_NAME(resourcesButton,"resourcesButton");
	HX_MARK_MEMBER_NAME(optionsButton,"optionsButton");
	HX_MARK_MEMBER_NAME(state,"state");
	HX_MARK_MEMBER_NAME(buildMode,"buildMode");
	HX_MARK_MEMBER_NAME(stateSwitch,"stateSwitch");
	HX_MARK_MEMBER_NAME(buildModeSwitch,"buildModeSwitch");
	HX_MARK_MEMBER_NAME(ttime,"ttime");
	HX_MARK_MEMBER_NAME(trucks,"trucks");
	HX_MARK_MEMBER_NAME(truck_paths,"truck_paths");
	HX_MARK_MEMBER_NAME(cities,"cities");
	HX_MARK_MEMBER_NAME(city_labels,"city_labels");
	HX_MARK_MEMBER_NAME(truck_def_speed,"truck_def_speed");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(terrain,"terrain");
	HX_VISIT_MEMBER_NAME(plants,"plants");
	HX_VISIT_MEMBER_NAME(roads,"roads");
	HX_VISIT_MEMBER_NAME(towns,"towns");
	HX_VISIT_MEMBER_NAME(buildings,"buildings");
	HX_VISIT_MEMBER_NAME(mouseicon,"mouseicon");
	HX_VISIT_MEMBER_NAME(camera,"camera");
	HX_VISIT_MEMBER_NAME(cameraFocus,"cameraFocus");
	HX_VISIT_MEMBER_NAME(hud,"hud");
	HX_VISIT_MEMBER_NAME(companyButton,"companyButton");
	HX_VISIT_MEMBER_NAME(resourcesButton,"resourcesButton");
	HX_VISIT_MEMBER_NAME(optionsButton,"optionsButton");
	HX_VISIT_MEMBER_NAME(state,"state");
	HX_VISIT_MEMBER_NAME(buildMode,"buildMode");
	HX_VISIT_MEMBER_NAME(stateSwitch,"stateSwitch");
	HX_VISIT_MEMBER_NAME(buildModeSwitch,"buildModeSwitch");
	HX_VISIT_MEMBER_NAME(ttime,"ttime");
	HX_VISIT_MEMBER_NAME(trucks,"trucks");
	HX_VISIT_MEMBER_NAME(truck_paths,"truck_paths");
	HX_VISIT_MEMBER_NAME(cities,"cities");
	HX_VISIT_MEMBER_NAME(city_labels,"city_labels");
	HX_VISIT_MEMBER_NAME(truck_def_speed,"truck_def_speed");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"hud") ) { return hud; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"font") ) { return font; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"roads") ) { return roads; }
		if (HX_FIELD_EQ(inName,"towns") ) { return towns; }
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		if (HX_FIELD_EQ(inName,"ttime") ) { return ttime; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"plants") ) { return plants; }
		if (HX_FIELD_EQ(inName,"camera") ) { return camera; }
		if (HX_FIELD_EQ(inName,"trucks") ) { return trucks; }
		if (HX_FIELD_EQ(inName,"cities") ) { return cities; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"terrain") ) { return terrain; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"get_map") ) { return get_map_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"init_HUD") ) { return init_HUD_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"HUDHeight") ) { return HUDHeight; }
		if (HX_FIELD_EQ(inName,"buildings") ) { return buildings; }
		if (HX_FIELD_EQ(inName,"mouseicon") ) { return mouseicon; }
		if (HX_FIELD_EQ(inName,"buildMode") ) { return buildMode; }
		if (HX_FIELD_EQ(inName,"init_time") ) { return init_time_dyn(); }
		if (HX_FIELD_EQ(inName,"goCompany") ) { return goCompany_dyn(); }
		if (HX_FIELD_EQ(inName,"goOptions") ) { return goOptions_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_WIDTH") ) { return TILE_WIDTH; }
		if (HX_FIELD_EQ(inName,"pause_game") ) { return pause_game_dyn(); }
		if (HX_FIELD_EQ(inName,"ship_truck") ) { return ship_truck_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TILE_HEIGHT") ) { return TILE_HEIGHT; }
		if (HX_FIELD_EQ(inName,"LEVEL_WIDTH") ) { return LEVEL_WIDTH; }
		if (HX_FIELD_EQ(inName,"PIXEL_WIDTH") ) { return PIXEL_WIDTH; }
		if (HX_FIELD_EQ(inName,"cameraFocus") ) { return cameraFocus; }
		if (HX_FIELD_EQ(inName,"stateSwitch") ) { return stateSwitch; }
		if (HX_FIELD_EQ(inName,"truck_paths") ) { return truck_paths; }
		if (HX_FIELD_EQ(inName,"city_labels") ) { return city_labels; }
		if (HX_FIELD_EQ(inName,"init_cities") ) { return init_cities_dyn(); }
		if (HX_FIELD_EQ(inName,"init_camera") ) { return init_camera_dyn(); }
		if (HX_FIELD_EQ(inName,"init_trucks") ) { return init_trucks_dyn(); }
		if (HX_FIELD_EQ(inName,"move_camera") ) { return move_camera_dyn(); }
		if (HX_FIELD_EQ(inName,"input_mouse") ) { return input_mouse_dyn(); }
		if (HX_FIELD_EQ(inName,"update_time") ) { return update_time_dyn(); }
		if (HX_FIELD_EQ(inName,"move_trucks") ) { return move_trucks_dyn(); }
		if (HX_FIELD_EQ(inName,"resume_game") ) { return resume_game_dyn(); }
		if (HX_FIELD_EQ(inName,"goResources") ) { return goResources_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"LEVEL_HEIGHT") ) { return LEVEL_HEIGHT; }
		if (HX_FIELD_EQ(inName,"PIXEL_HEIGHT") ) { return PIXEL_HEIGHT; }
		if (HX_FIELD_EQ(inName,"CAMERA_SPEED") ) { return CAMERA_SPEED; }
		if (HX_FIELD_EQ(inName,"timeTextSize") ) { return timeTextSize; }
		if (HX_FIELD_EQ(inName,"cityTextSize") ) { return cityTextSize; }
		if (HX_FIELD_EQ(inName,"init_buttons") ) { return init_buttons_dyn(); }
		if (HX_FIELD_EQ(inName,"bound_camera") ) { return bound_camera_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"companyButton") ) { return companyButton; }
		if (HX_FIELD_EQ(inName,"optionsButton") ) { return optionsButton; }
		if (HX_FIELD_EQ(inName,"init_graphics") ) { return init_graphics_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"topButtonsSize") ) { return topButtonsSize; }
		if (HX_FIELD_EQ(inName,"input_keyboard") ) { return input_keyboard_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"resourcesButton") ) { return resourcesButton; }
		if (HX_FIELD_EQ(inName,"buildModeSwitch") ) { return buildModeSwitch; }
		if (HX_FIELD_EQ(inName,"truck_def_speed") ) { return truck_def_speed; }
		if (HX_FIELD_EQ(inName,"init_parameters") ) { return init_parameters_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"remove_arrived_trucks") ) { return remove_arrived_trucks_dyn(); }
		if (HX_FIELD_EQ(inName,"execute_todays_events") ) { return execute_todays_events_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"update_state_dependent_items") ) { return update_state_dependent_items_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"hud") ) { hud=inValue.Cast< ::HUD >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"font") ) { font=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"roads") ) { roads=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"towns") ) { towns=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< ::State >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ttime") ) { ttime=inValue.Cast< ::TTime >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"plants") ) { plants=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"camera") ) { camera=inValue.Cast< ::flixel::FlxCamera >(); return inValue; }
		if (HX_FIELD_EQ(inName,"trucks") ) { trucks=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cities") ) { cities=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"terrain") ) { terrain=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"HUDHeight") ) { HUDHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"buildings") ) { buildings=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseicon") ) { mouseicon=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"buildMode") ) { buildMode=inValue.Cast< ::BuildMode >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_WIDTH") ) { TILE_WIDTH=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TILE_HEIGHT") ) { TILE_HEIGHT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LEVEL_WIDTH") ) { LEVEL_WIDTH=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PIXEL_WIDTH") ) { PIXEL_WIDTH=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cameraFocus") ) { cameraFocus=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stateSwitch") ) { stateSwitch=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"truck_paths") ) { truck_paths=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"city_labels") ) { city_labels=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"LEVEL_HEIGHT") ) { LEVEL_HEIGHT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PIXEL_HEIGHT") ) { PIXEL_HEIGHT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CAMERA_SPEED") ) { CAMERA_SPEED=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timeTextSize") ) { timeTextSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cityTextSize") ) { cityTextSize=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"companyButton") ) { companyButton=inValue.Cast< ::flixel::ui::FlxButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"optionsButton") ) { optionsButton=inValue.Cast< ::flixel::ui::FlxButton >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"topButtonsSize") ) { topButtonsSize=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"resourcesButton") ) { resourcesButton=inValue.Cast< ::flixel::ui::FlxButton >(); return inValue; }
		if (HX_FIELD_EQ(inName,"buildModeSwitch") ) { buildModeSwitch=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"truck_def_speed") ) { truck_def_speed=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("terrain"));
	outFields->push(HX_CSTRING("plants"));
	outFields->push(HX_CSTRING("roads"));
	outFields->push(HX_CSTRING("towns"));
	outFields->push(HX_CSTRING("buildings"));
	outFields->push(HX_CSTRING("mouseicon"));
	outFields->push(HX_CSTRING("camera"));
	outFields->push(HX_CSTRING("cameraFocus"));
	outFields->push(HX_CSTRING("hud"));
	outFields->push(HX_CSTRING("companyButton"));
	outFields->push(HX_CSTRING("resourcesButton"));
	outFields->push(HX_CSTRING("optionsButton"));
	outFields->push(HX_CSTRING("state"));
	outFields->push(HX_CSTRING("buildMode"));
	outFields->push(HX_CSTRING("stateSwitch"));
	outFields->push(HX_CSTRING("buildModeSwitch"));
	outFields->push(HX_CSTRING("ttime"));
	outFields->push(HX_CSTRING("trucks"));
	outFields->push(HX_CSTRING("truck_paths"));
	outFields->push(HX_CSTRING("cities"));
	outFields->push(HX_CSTRING("city_labels"));
	outFields->push(HX_CSTRING("truck_def_speed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TILE_WIDTH"),
	HX_CSTRING("TILE_HEIGHT"),
	HX_CSTRING("LEVEL_WIDTH"),
	HX_CSTRING("LEVEL_HEIGHT"),
	HX_CSTRING("PIXEL_WIDTH"),
	HX_CSTRING("PIXEL_HEIGHT"),
	HX_CSTRING("CAMERA_SPEED"),
	HX_CSTRING("font"),
	HX_CSTRING("topButtonsSize"),
	HX_CSTRING("timeTextSize"),
	HX_CSTRING("cityTextSize"),
	HX_CSTRING("HUDHeight"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,terrain),HX_CSTRING("terrain")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,plants),HX_CSTRING("plants")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,roads),HX_CSTRING("roads")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,towns),HX_CSTRING("towns")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,buildings),HX_CSTRING("buildings")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,mouseicon),HX_CSTRING("mouseicon")},
	{hx::fsObject /*::flixel::FlxCamera*/ ,(int)offsetof(PlayState_obj,camera),HX_CSTRING("camera")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(PlayState_obj,cameraFocus),HX_CSTRING("cameraFocus")},
	{hx::fsObject /*::HUD*/ ,(int)offsetof(PlayState_obj,hud),HX_CSTRING("hud")},
	{hx::fsObject /*::flixel::ui::FlxButton*/ ,(int)offsetof(PlayState_obj,companyButton),HX_CSTRING("companyButton")},
	{hx::fsObject /*::flixel::ui::FlxButton*/ ,(int)offsetof(PlayState_obj,resourcesButton),HX_CSTRING("resourcesButton")},
	{hx::fsObject /*::flixel::ui::FlxButton*/ ,(int)offsetof(PlayState_obj,optionsButton),HX_CSTRING("optionsButton")},
	{hx::fsObject /*::State*/ ,(int)offsetof(PlayState_obj,state),HX_CSTRING("state")},
	{hx::fsObject /*::BuildMode*/ ,(int)offsetof(PlayState_obj,buildMode),HX_CSTRING("buildMode")},
	{hx::fsBool,(int)offsetof(PlayState_obj,stateSwitch),HX_CSTRING("stateSwitch")},
	{hx::fsBool,(int)offsetof(PlayState_obj,buildModeSwitch),HX_CSTRING("buildModeSwitch")},
	{hx::fsObject /*::TTime*/ ,(int)offsetof(PlayState_obj,ttime),HX_CSTRING("ttime")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PlayState_obj,trucks),HX_CSTRING("trucks")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PlayState_obj,truck_paths),HX_CSTRING("truck_paths")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PlayState_obj,cities),HX_CSTRING("cities")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PlayState_obj,city_labels),HX_CSTRING("city_labels")},
	{hx::fsFloat,(int)offsetof(PlayState_obj,truck_def_speed),HX_CSTRING("truck_def_speed")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("terrain"),
	HX_CSTRING("plants"),
	HX_CSTRING("roads"),
	HX_CSTRING("towns"),
	HX_CSTRING("buildings"),
	HX_CSTRING("mouseicon"),
	HX_CSTRING("camera"),
	HX_CSTRING("cameraFocus"),
	HX_CSTRING("hud"),
	HX_CSTRING("companyButton"),
	HX_CSTRING("resourcesButton"),
	HX_CSTRING("optionsButton"),
	HX_CSTRING("state"),
	HX_CSTRING("buildMode"),
	HX_CSTRING("stateSwitch"),
	HX_CSTRING("buildModeSwitch"),
	HX_CSTRING("ttime"),
	HX_CSTRING("trucks"),
	HX_CSTRING("truck_paths"),
	HX_CSTRING("cities"),
	HX_CSTRING("city_labels"),
	HX_CSTRING("truck_def_speed"),
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("init_parameters"),
	HX_CSTRING("init_time"),
	HX_CSTRING("init_cities"),
	HX_CSTRING("init_graphics"),
	HX_CSTRING("init_camera"),
	HX_CSTRING("init_HUD"),
	HX_CSTRING("init_buttons"),
	HX_CSTRING("init_trucks"),
	HX_CSTRING("get_map"),
	HX_CSTRING("move_camera"),
	HX_CSTRING("bound_camera"),
	HX_CSTRING("input_keyboard"),
	HX_CSTRING("input_mouse"),
	HX_CSTRING("update_state_dependent_items"),
	HX_CSTRING("update_time"),
	HX_CSTRING("move_trucks"),
	HX_CSTRING("remove_arrived_trucks"),
	HX_CSTRING("execute_todays_events"),
	HX_CSTRING("pause_game"),
	HX_CSTRING("resume_game"),
	HX_CSTRING("ship_truck"),
	HX_CSTRING("goCompany"),
	HX_CSTRING("goResources"),
	HX_CSTRING("goOptions"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(PlayState_obj::TILE_WIDTH,"TILE_WIDTH");
	HX_MARK_MEMBER_NAME(PlayState_obj::TILE_HEIGHT,"TILE_HEIGHT");
	HX_MARK_MEMBER_NAME(PlayState_obj::LEVEL_WIDTH,"LEVEL_WIDTH");
	HX_MARK_MEMBER_NAME(PlayState_obj::LEVEL_HEIGHT,"LEVEL_HEIGHT");
	HX_MARK_MEMBER_NAME(PlayState_obj::PIXEL_WIDTH,"PIXEL_WIDTH");
	HX_MARK_MEMBER_NAME(PlayState_obj::PIXEL_HEIGHT,"PIXEL_HEIGHT");
	HX_MARK_MEMBER_NAME(PlayState_obj::CAMERA_SPEED,"CAMERA_SPEED");
	HX_MARK_MEMBER_NAME(PlayState_obj::font,"font");
	HX_MARK_MEMBER_NAME(PlayState_obj::topButtonsSize,"topButtonsSize");
	HX_MARK_MEMBER_NAME(PlayState_obj::timeTextSize,"timeTextSize");
	HX_MARK_MEMBER_NAME(PlayState_obj::cityTextSize,"cityTextSize");
	HX_MARK_MEMBER_NAME(PlayState_obj::HUDHeight,"HUDHeight");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PlayState_obj::TILE_WIDTH,"TILE_WIDTH");
	HX_VISIT_MEMBER_NAME(PlayState_obj::TILE_HEIGHT,"TILE_HEIGHT");
	HX_VISIT_MEMBER_NAME(PlayState_obj::LEVEL_WIDTH,"LEVEL_WIDTH");
	HX_VISIT_MEMBER_NAME(PlayState_obj::LEVEL_HEIGHT,"LEVEL_HEIGHT");
	HX_VISIT_MEMBER_NAME(PlayState_obj::PIXEL_WIDTH,"PIXEL_WIDTH");
	HX_VISIT_MEMBER_NAME(PlayState_obj::PIXEL_HEIGHT,"PIXEL_HEIGHT");
	HX_VISIT_MEMBER_NAME(PlayState_obj::CAMERA_SPEED,"CAMERA_SPEED");
	HX_VISIT_MEMBER_NAME(PlayState_obj::font,"font");
	HX_VISIT_MEMBER_NAME(PlayState_obj::topButtonsSize,"topButtonsSize");
	HX_VISIT_MEMBER_NAME(PlayState_obj::timeTextSize,"timeTextSize");
	HX_VISIT_MEMBER_NAME(PlayState_obj::cityTextSize,"cityTextSize");
	HX_VISIT_MEMBER_NAME(PlayState_obj::HUDHeight,"HUDHeight");
};

#endif

Class PlayState_obj::__mClass;

void PlayState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PlayState"), hx::TCanCast< PlayState_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void PlayState_obj::__boot()
{
	TILE_WIDTH= (int)64;
	TILE_HEIGHT= (int)64;
	LEVEL_WIDTH= (int)50;
	LEVEL_HEIGHT= (int)50;
	PIXEL_WIDTH= (::PlayState_obj::TILE_WIDTH * ::PlayState_obj::LEVEL_WIDTH);
	PIXEL_HEIGHT= (::PlayState_obj::TILE_HEIGHT * ::PlayState_obj::LEVEL_HEIGHT);
	CAMERA_SPEED= (int)8;
	font= HX_CSTRING("Quicksand-Bold.otf");
	topButtonsSize= (int)24;
	timeTextSize= (int)18;
	cityTextSize= (int)24;
	HUDHeight= (int)40;
}

