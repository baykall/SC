#include <hxcpp.h>

#ifndef INCLUDED_HUD
#include <HUD.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
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
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void HUD_obj::__construct()
{
HX_STACK_FRAME("HUD","new",0xf45a2509,"HUD.new","HUD.hx",18,0xe7d70e87)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(19)
	super::__construct(null(),null(),null());
	HX_STACK_LINE(20)
	this->scrollFactor->set_x((int)0);
	HX_STACK_LINE(21)
	this->scrollFactor->set_y((int)0);
	HX_STACK_LINE(23)
	::flixel::FlxSprite background = ::flixel::FlxSprite_obj::__new(null(),null(),null());		HX_STACK_VAR(background,"background");
	HX_STACK_LINE(24)
	background->makeGraphic(::flixel::FlxG_obj::width,::PlayState_obj::HUDHeight,(int)-16777216,true,null());
	HX_STACK_LINE(25)
	this->add(background);
	HX_STACK_LINE(27)
	::flixel::text::FlxText _g = ::flixel::text::FlxText_obj::__new((::flixel::FlxG_obj::width - (int)150),(int)10,null(),null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(27)
	this->timeDisplay = _g;
	HX_STACK_LINE(28)
	this->timeDisplay->setFormat((HX_CSTRING("assets/fonts/") + ::PlayState_obj::font),::PlayState_obj::timeTextSize,(int)-1,HX_CSTRING("center"),null(),null(),null());
	HX_STACK_LINE(29)
	this->add(this->timeDisplay);
	HX_STACK_LINE(31)
	::flixel::text::FlxText _g1 = ::flixel::text::FlxText_obj::__new((int)50,(int)10,null(),null(),null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(31)
	this->newDisplay = _g1;
	HX_STACK_LINE(32)
	this->newDisplay->setFormat((HX_CSTRING("assets/fonts/") + ::PlayState_obj::font),::PlayState_obj::timeTextSize,(int)-1,HX_CSTRING("center"),null(),null(),null());
	HX_STACK_LINE(33)
	this->add(this->newDisplay);
	HX_STACK_LINE(35)
	this->ttime = HX_CSTRING("");
	HX_STACK_LINE(36)
	this->value = HX_CSTRING("");
}
;
	return null();
}

//HUD_obj::~HUD_obj() { }

Dynamic HUD_obj::__CreateEmpty() { return  new HUD_obj; }
hx::ObjectPtr< HUD_obj > HUD_obj::__new()
{  hx::ObjectPtr< HUD_obj > result = new HUD_obj();
	result->__construct();
	return result;}

Dynamic HUD_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HUD_obj > result = new HUD_obj();
	result->__construct();
	return result;}

Void HUD_obj::update( ){
{
		HX_STACK_FRAME("HUD","update",0x5060c100,"HUD.update","HUD.hx",39,0xe7d70e87)
		HX_STACK_THIS(this)
		HX_STACK_LINE(40)
		this->timeDisplay->set_text(this->ttime);
		HX_STACK_LINE(41)
		this->newDisplay->set_text(this->value);
	}
return null();
}


Void HUD_obj::update_time( ::String cal){
{
		HX_STACK_FRAME("HUD","update_time",0x345186ec,"HUD.update_time","HUD.hx",45,0xe7d70e87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cal,"cal")
		HX_STACK_LINE(45)
		this->ttime = cal;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HUD_obj,update_time,(void))

Void HUD_obj::update_hud( ::String val){
{
		HX_STACK_FRAME("HUD","update_hud",0x956fd6b8,"HUD.update_hud","HUD.hx",49,0xe7d70e87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(val,"val")
		HX_STACK_LINE(49)
		this->value = val;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HUD_obj,update_hud,(void))


HUD_obj::HUD_obj()
{
}

void HUD_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HUD);
	HX_MARK_MEMBER_NAME(timeDisplay,"timeDisplay");
	HX_MARK_MEMBER_NAME(newDisplay,"newDisplay");
	HX_MARK_MEMBER_NAME(ttime,"ttime");
	HX_MARK_MEMBER_NAME(value,"value");
	::flixel::group::FlxTypedSpriteGroup_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HUD_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(timeDisplay,"timeDisplay");
	HX_VISIT_MEMBER_NAME(newDisplay,"newDisplay");
	HX_VISIT_MEMBER_NAME(ttime,"ttime");
	HX_VISIT_MEMBER_NAME(value,"value");
	::flixel::group::FlxTypedSpriteGroup_obj::__Visit(HX_VISIT_ARG);
}

Dynamic HUD_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"ttime") ) { return ttime; }
		if (HX_FIELD_EQ(inName,"value") ) { return value; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"newDisplay") ) { return newDisplay; }
		if (HX_FIELD_EQ(inName,"update_hud") ) { return update_hud_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"timeDisplay") ) { return timeDisplay; }
		if (HX_FIELD_EQ(inName,"update_time") ) { return update_time_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HUD_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"ttime") ) { ttime=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"newDisplay") ) { newDisplay=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"timeDisplay") ) { timeDisplay=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HUD_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("timeDisplay"));
	outFields->push(HX_CSTRING("newDisplay"));
	outFields->push(HX_CSTRING("ttime"));
	outFields->push(HX_CSTRING("value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(HUD_obj,timeDisplay),HX_CSTRING("timeDisplay")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(HUD_obj,newDisplay),HX_CSTRING("newDisplay")},
	{hx::fsString,(int)offsetof(HUD_obj,ttime),HX_CSTRING("ttime")},
	{hx::fsString,(int)offsetof(HUD_obj,value),HX_CSTRING("value")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("timeDisplay"),
	HX_CSTRING("newDisplay"),
	HX_CSTRING("ttime"),
	HX_CSTRING("value"),
	HX_CSTRING("update"),
	HX_CSTRING("update_time"),
	HX_CSTRING("update_hud"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HUD_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HUD_obj::__mClass,"__mClass");
};

#endif

Class HUD_obj::__mClass;

void HUD_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("HUD"), hx::TCanCast< HUD_obj> ,sStaticFields,sMemberFields,
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

void HUD_obj::__boot()
{
}

